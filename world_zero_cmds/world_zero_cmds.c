#include "./world_zero_cmds.h"
#include "../keyboard_and_click/keyboard_and_click.h"
#include "../cmds_core/timer_clock/timer_clock.h"
#include <stdio.h>

#define PK_NAME "World Zero Cmds"

#define INVENTORY_SLOT_SIZE 120
#define INVENTORY_SLOT_GAP_X 14
#define INVENTORY_SLOT_GAP_Y 18

#define INVENTORY_FIRST_SLOT_X 1300
#define INVENTORY_FIRST_SLOT_Y 630

#define INVENTORY_UPPER_MARKER_X 1255
#define INVENTORY_UPPER_MARKER_Y 540
#define INVENTORY_UPPER_MARKER_COLOR 16759552

#define INVENTORY_BTN_X 2455
#define INVENTORY_BTN_Y 475

#define INVENTORY_TAB_BTNS_Y 1105
#define INVENTORY_BTN_ALL_X 1350
#define INVENTORY_BTN_COSMETICS_X 1590
#define INVENTORY_BTN_OUTFITS_X 1825

#define INVENTORY_BTN_ALL 5329233
#define INVENTORY_BTN_COSMETICS 15406500
#define INVENTORY_BTN_OUTFITS 42219

#define INVENTORY_SLOT_I(x, y)                                                                \
            (INVENTORY_FIRST_SLOT_X + (INVENTORY_SLOT_SIZE + INVENTORY_SLOT_GAP_X) * (x - 1)),\
            (INVENTORY_FIRST_SLOT_Y + (INVENTORY_SLOT_SIZE + INVENTORY_SLOT_GAP_Y) * (y - 1)) \


struct anym_wait_for_item_swap_click_ctx{
    int x;
    int y;
};
short anym_wait_for_item_swap_click(void* ctx){
    struct anym_wait_for_item_swap_click_ctx coordonate = *(struct anym_wait_for_item_swap_click_ctx*)ctx;
    move_mouse(INVENTORY_SLOT_I(coordonate.x, coordonate.y));
    
    return is_clicked();
}
short anym_wait_for_open_inventory(void* ctx){
    color inventory_btn_all = get_pixel_color(INVENTORY_BTN_ALL_X, INVENTORY_TAB_BTNS_Y); 
    color inventory_btn_cosmetics = get_pixel_color(INVENTORY_BTN_COSMETICS_X, INVENTORY_TAB_BTNS_Y); 
    color inventory_btn_outfits = get_pixel_color(INVENTORY_BTN_OUTFITS_X, INVENTORY_TAB_BTNS_Y); 

    return inventory_btn_all == INVENTORY_BTN_ALL && 
           inventory_btn_cosmetics == INVENTORY_BTN_COSMETICS &&
           inventory_btn_outfits == INVENTORY_BTN_OUTFITS;
}
void switch_item(void* ctx){
    wait_expression(anym_wait_for_open_inventory, NULL, SECOND);

    color inventory_upper_marker_color = get_pixel_color(INVENTORY_UPPER_MARKER_X, INVENTORY_UPPER_MARKER_Y);    
    if(inventory_upper_marker_color != INVENTORY_UPPER_MARKER_COLOR){
        move_mouse(INVENTORY_FIRST_SLOT_X, INVENTORY_FIRST_SLOT_Y);
        is_mouse_moved(SECOND * 5);

        scroll_up(100);
        sleep_ms(DELAY);
        scroll_down(3);
        sleep_ms(DELAY);
    }
    wait_expression(anym_wait_for_item_swap_click, ctx, SECOND * 3);
}
void world_zero_cmds_register(cmd_list* cmds_list){
    cmd_manager temp_cm[1];

    struct anym_wait_for_item_swap_click_ctx charm = {1, 3};

    key_code switch_charm_keys[] = {KEY_B, KEY_LCONTROL}; 
    init_cmd_manager(temp_cm, switch_charm_keys, sizeof(switch_charm_keys), switch_item, &charm);   

    cmds_register(cmds_list, temp_cm, sizeof(temp_cm));
    PRINT_PK_CMD_NB(PK_NAME, temp_cm);
}
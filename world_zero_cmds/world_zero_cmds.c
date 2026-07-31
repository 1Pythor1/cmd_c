#include "./world_zero_cmds.h"
#include "../keyboard_and_click/keyboard_and_click.h"
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

void switch_charm(void* ctx);

void world_zero_cmds_register(cmd_list* cmds_list){
    cmd_manager temp_cm[1];

    key_code switch_charm_keys[] = {KEY_B, KEY_LCONTROL}; 
    init_cmd_manager(temp_cm, switch_charm_keys, sizeof(switch_charm_keys), switch_charm, NULL);   

    cmds_register(cmds_list, temp_cm, sizeof(temp_cm));
    PRINT_PK_CMD_NB(PK_NAME, temp_cm);
}
void switch_charm(void* ctx){
    move_mouse(INVENTORY_FIRST_SLOT_X, INVENTORY_FIRST_SLOT_Y);
    sleep_ms(DELAY);

    color inventory_upper_marker_color = get_pixel_color(INVENTORY_UPPER_MARKER_X, INVENTORY_UPPER_MARKER_Y);    
    if(inventory_upper_marker_color != INVENTORY_UPPER_MARKER_COLOR){
        scroll_up(100);
        sleep_ms(DELAY);
        scroll_down(3);
        sleep_ms(DELAY);
    }
    printf("%u\n", inventory_upper_marker_color);
}
/*
void switch_charm(void* ctx){
    click(INVENTORY_BTN_X, INVENTORY_BTN_Y);
    sleep_ms(DELAY);
    
    color inventory_upper_marker_color = get_pixel_color(INVENTORY_UPPER_MARKER_X, INVENTORY_UPPER_MARKER_Y);    
    if(inventory_upper_marker_color != INVENTORY_UPPER_MARKER_COLOR){
        scroll_up(100);
        sleep_ms(DELAY);
        scroll_down(3);
        sleep_ms(DELAY);
    }
    printf("%u\n", inventory_upper_marker_color);
}
*/
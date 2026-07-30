#include "./world_zero_cmds.h"
#include "../keyboard_and_click/keyboard_and_click.h"
#include <stdio.h>

#define PK_NAME "World Zero Cmds"

#define INVENTORY_SLOT_SIZE 120

#define INVENTORY_UPPER_MARKER_X 1255
#define INVENTORY_UPPER_MARKER_Y 540
#define INVENTORY_UPPER_MARKER_COLOR 16759552

#define INVENTORY_BTN_X 2455
#define INVENTORY_BTN_Y 475

void switch_charm(void* ctx);

void world_zero_cmds_register(cmd_list* cmds_list){
    cmd_manager temp_cm[] = {
        {KEY_NUMPAD8, 0, switch_charm, NULL},
    };

    cmds_register(cmds_list, temp_cm, sizeof(temp_cm));
    PRINT_PK_CMD_NB(PK_NAME, temp_cm);
}


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
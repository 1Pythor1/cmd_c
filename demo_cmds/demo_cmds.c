#include "./demo_cmds.h"
#include "../keyboard_and_click/keyboard_and_click.h"
#include <stdio.h>

#define PK_NAME "Demo"

void say_demacia(void* ctx);
void say_hasagui(void* ctx);

void demo_cmds_register(cmd_list* cmds_list){
    cmd_manager temp_cm[2];

    key_code demacia_keys[] = {KEY_NUMPAD0}; 
    init_cmd_manager(temp_cm, demacia_keys, sizeof(demacia_keys), say_demacia, NULL);   
    
    key_code hasagui_keys[] = {KEY_NUMPAD1, KEY_SPACE}; 
    init_cmd_manager(temp_cm + 1, hasagui_keys, sizeof(hasagui_keys), say_hasagui, NULL);  

    cmds_register(cmds_list, temp_cm, sizeof(temp_cm));
    PRINT_PK_CMD_NB(PK_NAME, temp_cm);
}

void say_demacia(void* ctx){
    hold_key(KEY_LSHIFT);
    press_key(KEY_D);
    press_key(KEY_E);
    press_key(KEY_M);
    press_key(KEY_A);
    press_key(KEY_C);
    press_key(KEY_I);
    press_key(KEY_A);
    release_key(KEY_LSHIFT);
}
void say_hasagui(void* ctx){
    hold_key(KEY_LSHIFT);
    press_key(KEY_H);
    release_key(KEY_LSHIFT);
    press_key(KEY_A);
    press_key(KEY_S);
    press_key(KEY_A);
    press_key(KEY_G);
    press_key(KEY_U);
    press_key(KEY_I);
    
}
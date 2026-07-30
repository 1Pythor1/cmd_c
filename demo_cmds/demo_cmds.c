#include "./demo_cmds.h"
#include "../keyboard_and_click/keyboard_and_click.h"
#include <stdio.h>

#define PK_NAME "Demo"

void say_demacia(void* ctx);

void demo_cmds_register(cmd_list* cmds_list){
    cmd_manager temp_cm[] = {
        {KEY_NUMPAD0, 0, say_demacia, NULL},
    };

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
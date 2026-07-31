#include "./world_zero_cmds/world_zero_cmds.h"
#include "./demo_cmds/demo_cmds.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
/*
world_zero_cmds_register(&list); ./world_zero_cmds/world_zero_cmds.c
demo_cmds_register(&list); ./demo_cmds/demo_cmds.c
-luser32 -lgdi32

gcc main.c ./demo_cmds/demo_cmds.c  ./keyboard_and_click/keyboard_and_click_windows.c ./cmds_core/cmds_core.c ./cmds_core/cmd_manager/cmd_manager.c -o program.exe -luser32 -lgdi32
gcc main.c ./world_zero_cmds/world_zero_cmds.c  ./keyboard_and_click/keyboard_and_click_windows.c ./cmds_core/cmds_core.c ./cmds_core/cmd_manager/cmd_manager.c -o program.exe -luser32 -lgdi32
*/

int main(void){
    cmd_list list = {
        .size = 0,
        .data = NULL
    };

    world_zero_cmds_register(&list);
    return init_cmds_core(&list);
}
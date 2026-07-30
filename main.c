#include "./world_zero_cmds/world_zero_cmds.h"
//gcc main.c ./world_zero_cmds/world_zero_cmds.c ./keyboard_and_click/keyboard_and_click.c ./cmds_core/cmds_core.c -o programme.exe -luser32 -lgdi32

int main(void){
    cmd_list list = {
        .size = 0,
        .data = NULL
    };
    world_zero_cmds_register(&list);
    return init_cmds_core(&list);
}

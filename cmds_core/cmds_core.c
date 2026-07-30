#include "cmds_core.h"
#include <stdio.h>

void stop(short* sw);
void stop_cmd(void* ctx);

int init_cmds_core(cmd_list* cmds_list){
    short run = 1;

    cmd_manager* tmp = realloc(cmds_list->data, (cmds_list->size + 1) * sizeof(cmd_manager));
    if (tmp == NULL){
        return 1;
    }
    cmds_list->data = tmp;
    cmds_list->size += 1;

    cmds_list->data[cmds_list->size - 1] = (cmd_manager){VK_NUMPAD7, 0, stop_cmd, &run};

    while (run)
    {
        for(int i = 0; i < cmds_list->size; i++){
            int down = GetAsyncKeyState(cmds_list->data[i].key_code) & 0x8000;

            if (down && !cmds_list->data[i].state){
                printf("Appui detecte %hu\n", cmds_list->data[i].key_code);
                cmds_list->data[i].cmd(cmds_list->data[i].context);
            }

            cmds_list->data[i].state = down;
        }
        Sleep(10);
    }    
    free(cmds_list->data);
    return 0;
}

void stop_cmd(void* ctx){
    stop((short*)ctx);
}

void stop(short* sw){
    *sw = 0;
}


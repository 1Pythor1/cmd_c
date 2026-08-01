#include "cmds_core.h"
#include "timer_clock/timer_clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MANAGER_SIZE  sizeof(cmd_manager)

//--- Cmds ---
void stop(short* sw){
    *sw = 0;
}
void stop_cmd(void* ctx){
    stop((short*)ctx);
}
//---======---

void free_cmd_list(cmd_list* self){
    for(int i = 0; i < self->size; i++){        
        free(self->data[i].key_code);
    } 
    free(self->data);
}

void cmds_register(cmd_list* cmds_list, cmd_manager* cmds_m, int cmds_m_size){
    cmds_list->data = realloc(
        cmds_list->data, 
        cmds_list->size * CMD_MANAGER_SIZE + cmds_m_size);

    memcpy(
        cmds_list->data + cmds_list->size, 
        cmds_m, 
        cmds_m_size);

    cmds_list->size += cmds_m_size / CMD_MANAGER_SIZE;
}

int init_cmds_core(cmd_list* cmds_list){
    short run = 1;

    cmd_manager* tmp = realloc(cmds_list->data, (cmds_list->size + 1) * CMD_MANAGER_SIZE);
    if (tmp == NULL){
        return 1;
    }
    cmds_list->data = tmp;
    cmds_list->size += 1;

    key_code exit_keys[] = {KEY_NUMPAD7}; 
    init_cmd_manager(cmds_list->data + cmds_list->size - 1, exit_keys, sizeof(exit_keys), stop_cmd, &run);    

    while (run)
    {
        for(int i = 0; i < cmds_list->size; i++){
            short down = get_keys_states_cmd_manager(cmds_list->data + i);

            if (down && !cmds_list->data[i].state){
                printf("Appui detecte %hu\n", cmds_list->data[i].key_code);
                cmds_list->data[i].cmd(cmds_list->data[i].context);
            }

            cmds_list->data[i].state = down;
        }
        sleep_ms(10);
    }
    
    free_cmd_list(cmds_list);
    return 0;
}


#include "cmds_core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MANAGER_SIZE  sizeof(cmd_manager)

void stop(short* sw);
void stop_cmd(void* ctx);

void init_cmd_manager(cmd_manager* self, key_code* keys_codes, int keys_codes_size, void (*cmd)(void*), void* context){
    self->cmd = cmd;
    self->context = context;
    self->state = 0;
    set_key_code_cmd_manager(self, keys_codes, keys_codes_size);
}
void set_key_code_cmd_manager(cmd_manager *self, key_code* values, int size){
    self->key_code = malloc(size);
    memcpy(
        self->key_code, 
        values, 
        size);
    self->key_codes_nb = size / sizeof(key_code);
}
short get_keys_states_cmd_manager(cmd_manager *self){
    short result = 1;
    
    for(int i = 0; i < self->key_codes_nb; i++){
        result &= get_async_key_state(self->key_code[i]);
    };
    return result;
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
    
    for(int i = 0; i < cmds_list->size; i++){        
        free(cmds_list->data[i].key_code);
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

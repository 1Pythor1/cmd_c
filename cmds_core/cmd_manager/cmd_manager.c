#include "cmd_manager.h"
#include <stdlib.h>
#include <string.h>

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

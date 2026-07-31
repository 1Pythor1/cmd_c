#ifndef CMD_MANAGER_H
#define CMD_MANAGER_H
#include "../../keyboard_and_click/keyboard_and_click.h"

typedef struct {
    key_code *key_code;
    int key_codes_nb;
    short state;
    void (*cmd)(void*);
    void* context;
} cmd_manager;

void init_cmd_manager(cmd_manager* self, key_code* keys_codes, int keys_codes_size, void (*cmd)(void*), void* context);
void set_key_code_cmd_manager(cmd_manager *self, key_code* values, int size);
short get_keys_states_cmd_manager(cmd_manager *self);
#endif
#ifndef CMDS_CORE_H
#define CMDS_CORE_H
#include "../keyboard_and_click/keyboard_and_click.h"

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))
#define PRINT_PK_CMD_NB(pk_name, arr) printf("%s: %d cmds register\n", (pk_name), ARRAY_LEN(arr))

typedef struct {
    key_code *key_code;
    int key_codes_nb;
    short state;
    void (*cmd)(void*);
    void* context;
} cmd_manager;

typedef struct {
    cmd_manager *data;
    int size;
} cmd_list;

void cmds_register(cmd_list* cmds_list, cmd_manager* cmds_m, int cmds_m_size);
int init_cmds_core(cmd_list* cmds_list);

void init_cmd_manager(cmd_manager* self, key_code* keys_codes, int keys_codes_size, void (*cmd)(void*), void* context);
void set_key_code_cmd_manager(cmd_manager *self, key_code* values, int size);
short get_keys_states_cmd_manager(cmd_manager *self);

#endif
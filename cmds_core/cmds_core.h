#ifndef CMDS_CORE_H
#define CMDS_CORE_H
#include "./cmd_manager/cmd_manager.h"

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))
#define PRINT_PK_CMD_NB(pk_name, arr) printf("%s: %d cmds register\n", (pk_name), ARRAY_LEN(arr))

typedef struct {
    cmd_manager *data;
    int size;
} cmd_list;

void cmds_register(cmd_list* cmds_list, cmd_manager* cmds_m, int cmds_m_size);
int init_cmds_core(cmd_list* cmds_list);

#endif
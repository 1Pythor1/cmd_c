#ifndef CMDS_CORE_H
#define CMDS_CORE_H
#include <windows.h>

typedef struct {
    WORD key_code;
    short state;
    void (*cmd)(void*);
    void* context;
} cmd_manager;

typedef struct {
    cmd_manager *data;
    int size;
} cmd_list;

int init_cmds_core(cmd_list* cmds_list);

#endif 
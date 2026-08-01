#include "./cmds_core/timer_clock/timer_clock.h"
#include "./keyboard_and_click/keyboard_and_click.h"
#include <stdio.h>

short anym_test_expression(void* ctx){
    int* c = ctx;
    (*c)++;    
    sleep_ms(90);
    return (*c) > 10;
}


int main(void){
    int c = 0;

    printf("Start...\n");
    printf("%hd\n", is_mouse_moved(2000));
    printf("...End\n");
    return 0;
}
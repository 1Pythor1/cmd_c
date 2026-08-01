#include "timer_clock.h"
#include <windows.h>
#include <stdlib.h>

struct timer_clock {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    int timer_duration_ms;
};

void init_timer_clock(timer_clock* self){
    QueryPerformanceFrequency(&self->frequency);
}
timer_clock* new_timer_clock(void){
    timer_clock* tc = malloc(sizeof(timer_clock));
    init_timer_clock(tc);
    return tc;
}
void free_timer_clock(timer_clock* self){
    free(self);
}
void start_timer_clock(timer_clock *self,int timer_duration_ms){
    QueryPerformanceCounter(&self->start);
    self->timer_duration_ms = timer_duration_ms;
}
short check_timer_clock(timer_clock *self){
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    
    LONGLONG  duration_ms = (double)(now.QuadPart - self->start.QuadPart) * 1000.0 / self->frequency.QuadPart;
    return duration_ms >=  self->timer_duration_ms;
}
short wait_expression(short (*expression)(void*), void* ctx,  int duration){
    short result = 0;
    timer_clock* timer = new_timer_clock();
    start_timer_clock(timer, duration);

    while(!((result = expression(ctx)) || check_timer_clock(timer)));
    
    free_timer_clock(timer);
    return result;
}
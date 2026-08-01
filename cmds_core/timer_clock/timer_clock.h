#ifndef TIMER_CLOCK_H
#define TIMER_CLOCK_H

#define SECOND 1000

typedef struct timer_clock timer_clock;

timer_clock* new_timer_clock(void);
void free_timer_clock(timer_clock* self);
void start_timer_clock(timer_clock *self,int timer_duration_ms);
short check_timer_clock(timer_clock *self);

short wait_expression(short (*expression)(void*), void* ctx, int duration);

#endif
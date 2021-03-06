#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>

void timer_init (uint16_t timer_freq);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

void timer_print_stats (void);

/* used by thread test programs */
extern uint16_t TIMER_FREQ;

#endif /* devices/timer.h */

#ifndef TIMER_H_
#define TIMER_H_
extern int total_alarms;
void increment_alarm();
void sigint_handler(int signum);
#endif
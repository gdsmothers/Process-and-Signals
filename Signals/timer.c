#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

int total_alarms = 0;
void increment_alarm() {
  total_alarms += 1;
}

void sigint_handler(int signum)
{ // SIGINT signal handler
  printf("\nTotal alarms occured: %d\n", total_alarms);
  printf("Hence, the program was executed for %d seconds.\n", total_alarms);
  exit(0);
}
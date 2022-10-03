#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

unsigned int run_time;

void sig_alarm(int signum) {
  run_time++;
  alarm(1);
}

void sigint(int signum) {
  printf("\n%d alarm(s) occurred i.e the program ran for approximately %d seconds\n", run_time, run_time);
  exit(1);
}

int main() {
  run_time = 0;
  signal(SIGALRM, sig_alarm);
  signal(SIGINT, sigint);
  alarm(1);
  while(1);
}
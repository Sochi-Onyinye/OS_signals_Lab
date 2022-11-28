/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int complete;

unsigned int run_time;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  complete = 1;
  run_time++;
  alarm(1);
  //exit(1); //exit after printing
}

void sigint(int signum) {
  printf("\n%d alarm(s) occurred i.e the program ran for approximately %d seconds\n", run_time, run_time);
  exit(1);
}

int main(int argc, char * argv[])
{
  run_time = 0;
  complete = 0;
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, sigint);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1)
  {
    while(!complete);
    printf("Turing was right!\n");
    complete = 0;
    alarm(1);
  } //busy wait for signal to be delivered
  return 0; //never reached
}


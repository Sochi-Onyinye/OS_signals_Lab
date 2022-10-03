/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int complete;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  complete = 1;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  complete = 0;
  signal(SIGALRM,handler); //register handler to handle SIGALRM
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


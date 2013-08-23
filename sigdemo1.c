#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  void g(int);
  int i;

  signal(SIGINT, g);
  while(1)
    {
      printf("%6d\n",++i);
      if(i%10 == 0)
	printf("\n");
      sleep(2);
    }
  return 0;
}

void g(int signum)
{
  printf("\n\nSIGINT recieved\n");
}

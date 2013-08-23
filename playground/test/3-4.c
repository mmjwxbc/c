#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>

main()
{
  struct termios info;
  int values, c;

  if (values = tcgetattr(0, &info) == -1)
    perror("tcgetattr");
  else
  {
    printf("Do you want the ISIG bit set or unset? usage s/u\n");
    while((c = getchar()) != NULL)
    {
      if(strchr("sS", c))
      {
	info.c_lflag |= ISIG;
	if(tcsetattr(0,TCSANOW, &info) == -1)
	  perror("tcsetatr");
	printf("set\n");
	return 0;
      }
      else if(strchr("uU",c))
      {
	info.c_lflag &=~ ISIG;
	if(tcsetattr(0,TCSANOW, &info) == -1)
	  perror("tcsetatr");
	printf("unset\n");
	return -1;
      }
      else
	printf("Error usage: s for set u for unset\n");
    }
  }
}

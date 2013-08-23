#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

main()
{
  int fd, fd1;
  char buf[BUFSIZ];

  fd = open("/home/seven/testtest.txt", O_WRONLY);
  if (fd == -1)
    perror("testtest.txt/dev/pts/0");
  
  while (fgets(buf, BUFSIZ, stdin) != NULL)
    if (write(fd, buf, strlen(buf)) == -1)
      {
	printf("error writing\n");
	break;
      }

  while (read(fd, buf, sizeof(buf)) != 0)
    printf("%s", buf);
  close(fd
);
}

#include <sys/ioctl.h>
#include <linux/cdrom.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int ac, char *av[])
{
  int fd;
  if (fd = open(av[1], O_RDONLY) == -1)
    perror("eee");


  ioctl(fd, CDROMEJECT);
  //  perror("/dev/cdrom");
  close(fd);
}

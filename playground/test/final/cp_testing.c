#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd;
	if ((fd = creat("seven.txt", 0777)) == -1)
		fprintf(stderr, "Error: cannot create seven");
	else
		printf("File seven.txt created successfuly.\n");
	close(fd);
}


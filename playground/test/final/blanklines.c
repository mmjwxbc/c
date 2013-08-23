#include <stdio.h>
#include <string.h>

#define maxCount 256

int main (int argc,char *argv[]) 
{
	FILE *fp;
	int i;
	char dat [maxCount];

	fp = fopen("input.txt", "rb");
	if(!fp) return -1;
	while (fgets (dat, maxCount, fp))
	{
		i = strlen (dat) - 1;
		while ((i >= 0) && (dat [i] == '\n') || (dat [i] == '\r')) 
			dat [i--] = '\0';
		if (dat [0]) printf ("%s\n", dat);
	}
	fclose (fp);

	return 0;
}

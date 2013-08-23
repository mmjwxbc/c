#include <stdio.h>

main()
{
	float c, nt, nl, ns;

	nt, nl, ns = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
		if (c == ' ')
			++ns;
	}
	printf("NT = %f\nNL = %f\nNS = %f\n", nt, nl, ns);
}
	
	 

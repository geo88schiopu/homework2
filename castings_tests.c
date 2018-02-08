#include <stdlib.h>
#include <stdio.h>

void print_k_hex(void *pp,int k)
{
	char *symbols;
	unsigned char *uc;
	int i;	
	
	symbols = "0123456789abcdef";
	while (i < k)
	{
		uc = (unsigned char *)(pp + i);
		printf("%c", symbols[*uc/16]);
		printf("%c\n", symbols[*uc%16]);
		i++;
	}
	return ;
}

void main(int argc, char **argv)
{
	int i;

	i = atoi(argv[1]);
	print_k_hex((void *)&i, 4);
	return ;
}


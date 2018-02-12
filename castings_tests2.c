#include <stdlib.h>
#include <stdio.h>

//it simply takes a pointer to a memory space
//and prints k bytes from it! 
void print_k_hex(void *pp, int k)
{
	char *symbols;
	unsigned char *uc;
	int i;

	i = 0;
	symbols = "0123456789abcdef";
	while (i < k)
	{
		uc = (unsigned char *)(pp) + i;
		printf("%c", symbols[*uc/16]);
		printf("%c\n", symbols[*uc%16]);
		i++;
	}
	return ;
}
/*
void main(int argc, char **argv)
{
	char *c;

	c = argv[1];

	print_k_hex((void *)c, 4);
	return ;
}
*/

void main()
{
	char c;
	unsigned uc;
	int ic;

	c = '\xaa';
	ic = (int)c;
	uc = (unsigned char)c;
	print_k_hex((void *)&uc, 1);
	print_k_hex((void *)&ic, 4);
	print_k_hex((void *)&c, 1);
	printf("as integer: %d\n", ic);
	printf("as char: %o \n", c);
	return ;
}

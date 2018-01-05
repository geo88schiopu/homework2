#include <stdlib.h>
#include <stdio.h>

void print_k_hex(void *pp,int k)
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
		
//	use the escape sequence inside the string literal
//	to test any byte value
//	'\xNN' is the hexadecimal  escape sequence; '\NNN' is the octal one
//	neither of which is very easy to read!!!
	c = '\xaa';
	ic = (int)c;
	uc = (unsigned char)c;
	printf("the tested value, as a char, is: %d \n", ic);
	print_k_hex((void *)&uc, 1);
	print_k_hex((void *)&ic, 4);
	print_k_hex((void *)&c, 1);
	printf("as integer: %d\n", ic);
	printf("as char: %o \n", c);
	return ;
}


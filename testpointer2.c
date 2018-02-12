#include <stdio.h>

int main()
{
	int *p1;
	int	*p2;
	int myint;
	int newint;

	myint = 12;
	p1 = &myint;
	p2 = p1;
	printf ("p1 is: %p, p2 is: %p, address myint is: %p \n", p1, p2, &myint);
	newint = 15;
	myint = 234;

	p1 = 0;	
	printf ("p1 is: %p, p2 is: %p, address myint is: %p \n", p1, p2, &myint);
	return(1);
}

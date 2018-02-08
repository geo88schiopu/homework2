#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int **p;
	int *p2;
	int i;

	i = 1000;
	p2 = (int*)malloc(4);
	*p2 = 50;
//	*p = p2;
//	**p = 2000;
	printf("&p2 is:%p\n", &p2);
	printf("*p2 is:%d\n", *p2);
	printf("p2 is:%p\n", p2);
	printf("*p is:%p\n", *p);
	printf("p is:%p\n", p);
	printf("&i is:%p\n", &i);
	printf("&p is:%p\n", &p);
	return(1);
}

#include <stdio.h>

long long rec_factorial(int n)
{
	int i;

	i = n;
	if (i > 1)
	{	
		i--;
		return( (i + 1) * rec_factorial(i));
	}
	
}


void main()
{
	int ii;
	
	
	ii = 3;
	while (ii++ < 20) 
		printf("the factorial of %d is %lld \n",ii ,rec_factorial(ii));
}




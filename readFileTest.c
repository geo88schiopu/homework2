#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//allows read, malloc, free
//ssize_t read(int fd, void *buf, size_t count);
//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
//

int	len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_c(char *str, char c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(str[i++])
		if (str[i-1] == c)
			j++;
	return(j);
}

void main()
{
	char *str;
	char *path = "fopenman.txt";
	int n;
	int fd;

	//indeed, I allocated mem for str ... 
	str = malloc(sizeof(char) * (100 + 1));
	fd = open(path, O_RDONLY);
	while ((n = read(fd, str, 100)) > 0)
	{
		str[n] = '\0';
		printf("the length of read is: %d\n", n);
		printf("the number of of space c is: %d\n", count_c(str, ' '));
		printf("the length of the segment is: %d\n", len(str));
		printf("the read segment is: %s\n", str);
	}
	return;
}

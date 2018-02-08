#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int		main()
{
	char *bufread;
	int 					fd;
	long long					readcount;
	//create_file();
	readcount = 1;
	fd = open("fileManRead.txt",  O_RDONLY);
	bufread = (char *)malloc(sizeof(unsigned char) * 40);

	while (readcount > 0)
	{
		readcount = read(fd, (void *)bufread, 40);
		printf("I read: %zd\n", readcount);
	}
	printf("Last read: %zd\n", readcount);
	bufread = (char *)malloc(sizeof(unsigned char) * 40);
	printf("Last read: %zd\n", readcount);

	close(fd);
	return(1);
}

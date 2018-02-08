#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

typedef struct	s_gnl
{
	char		*buf;
	int		count;
	int		i;
	int		nl;
	int		fd;
}				t_gnl;

int				get_next_line(int const fd, char **line);





int		main()
{
	int		n;
	int		fd;
	char		*bbuf;

	bbuf = (char *)malloc(sizeof(char) * BUFF_SIZE);
	fd = open("fopenman.txt", bbuf, O_RDONLY);




}

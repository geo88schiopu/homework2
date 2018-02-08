#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 1000

typedef struct		s_list
{
	void							*content;
	size_t						content_size;
	struct s_list			*next;
}		t_list;

//read BSIZE each time;
/*
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
//so there are 3 types of operations - 1.add/new, 2.delete, 3.iterate/map
//
t_list			*ft_lstnew(const void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *n);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

 int get_next_line(int const fd, char ** line);
*/

typedef struct s_newstr
{
	char	*chardata;
	int 	start;
	int		end;
	int 	fd;
}	t_newstr;

//

t_newstr		*new_struct_newstr()
{
	t_newstr	*newstr;

	newstr = (t_newstr *)malloc(sizeof(t_newstr));
	newstr->chardata = (char*)malloc(sizeof(char) * BUFF_SIZE);
	newstr->start = 0;
	newstr->end = BUFF_SIZE;
	fd = -1;
	return (newstr);
}


char 			*export_line(t_newstr *head, int line_length)
{




}






//fd is a constant, don't mess with it!!
int get_next_line(int const fd, char **line)
{
	//char *readline;
	t_newstr	*newstr;
	int 	read_end;
	int		found_newline;
	int		line_length;
	int		i;

	line_length = 0;
	found_newline = 0;
	//if (!readline)
	//	return(-1);

	while (found_newline == 0)
	{
		newstr = new_struct_newstr();
		read_end = read(fd, newstr->chardata, BUFF_SIZE);
		
		while (i < read_end)
		{
			if (readline[i] == '\n')
			{
				found_newline = 1;
				line_length = line_length + i;
				return (export_line(  , line_length));
			}
		}
	}

return(0);
}



int		main()
{
	int			fd;
	char 		**p_line;


	fd = open("fileManRead.txt", O_RDONLY);
	get_next_line(fd, p_line);
	close(fd);

	//printf("read line %s\n", *p_line);

}

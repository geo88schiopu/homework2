#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 20

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


//this is the type of programming I want to do - good data structures
//where to store enough state - and use this state for data extraction
//this is what I do - data extraction from a character vector (R vocab)
//the reads are in a sequence - ok ... everytime you start

//ok, I added a next ... so now the structs can function as nodes in a list
typedef struct s_newstr
{
	char	*chardata;
	int 	start;
	int	end;
	int 	fd;
	int	posnewline;
	t_newstr *next;
}	t_newstr;

//nothing special here, simply fill out with default values (and 0s)
t_newstr		*new_struct_newstr()
{
	t_newstr	*newstr;

	newstr = (t_newstr *)malloc(sizeof(t_newstr));
	newstr->chardata = (char*)malloc(sizeof(char) * BUFF_SIZE);
	newstr->start = 0;
	newstr->end = BUFF_SIZE - 1;
	fd = -1;
	posnewline = -1;
	next = NULL;
	return (newstr);
}

void 			*del_struct_newstr(t_newstr *newstr)
{
		if (newstr)
		{
			free(newstr->chardata);
			free(newstr);
		}
}

//push them out into a list all read buffs?
//simply add the newest one at the beginning of the list?


//so I get back a char pointer - it should be either NULL or return a
//line ...
//I should simply count - how many chars did I read without finding a newline?
//where did I find the newline - so

//I get a list of newstrs, I know only the last one (the first in the list)
//has a newline - do I count the list first? do I check to see where it is?
//get rid of all the following list elements
char 			*export_line(t_newstr *head, int line_length)
{

}


//fd is a constant, don't mess with it!!
int get_next_line(int const fd, char **line)
{
	//char *readline;
	//ok, so the pointer is static ... and its memory is malloc-ed
	//so it should work well as storage across function calls - global
	static t_newstr	*newstr;
	int 					read_end;
	int					found_newline;
	int					line_length;
	int					i;

	line_length = 0;
	found_newline = 0;

	//first I should check whether I already have a newstr structure
	if (newstr)
	{

	}
//well, inside the read loop I easily compute the length of the line
//I can malloc-it and fillit up ... well, I could call the export_line
//just in order to reduce the number of lines of this function;
//and here I should
	while (found_newline == 0)
	{
		newstr = new_struct_newstr();
		read_end = read(fd, newstr->chardata, BUFF_SIZE);
		//				found_newline = 1;
		//				line_length = line_length + i;
		while (i < read_end)
		{
			if (readline[i] == '\n')
			{

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

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


//this is the type of programming I want to do - good data structures
//where to store enough state - and use this state for data extraction
//this is what I do - data extraction from a character vector (R vocab)
//the reads are in a sequence - ok ... everytime you start

//ok, I added a next ... so now the structs can function as nodes in a list

#define BUFF_SIZE 20

typedef struct		s_list
{
	void							*content;
	size_t						content_size;
	struct s_list			*next;
}		t_list;


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

//doesn't do anything to the next structure - that's alright, del_one
void 			*del_struct_newstr(t_newstr *newstr)
{
		if (newstr)
		{
			free(newstr->chardata);
			free(newstr);
		}
}

void	ft_lstadd_ppp(t_list **newnode, t_list *new)
{
	if (!new || !newnode)
		return ;
	if (*newnode)
		new->next = *newnode;
	*newnode = new;
}



//I get a list of newstrs, I know only the last one (the first in the list)
//has a newline - do I count the list first? do I check to see where it is?
//get rid of all the following list elements
//
static char 			*export_line(t_newstr **last, int line_length)
{
	char 			*line;
	t_newstr 	*newstr;
	t_newstr 	*newstr_old;
	void 			*dst;
	void 			*src;
	int 			written;
	int				keepgoing;

	keepgoing = 0;
	written = 0;
	line = (char *)malloc(line_length + 1);
	while(newstr->next)
	{
		size = (size_t)(newstr->end - newstr->start);
		dst = (void *)(line + written);
		src = (void *)(newstr->chardata + start);
		ft_memcpy(dst, src, size);
		if (newstr->next)
		{
			written += size;
			newstr_old = newstr;
			newstr = newstr->next;
			del_struct_newstr(newstr_old);
		}
		else
		{

		}
	}
}

//be careful with 0 chardata ... because you'll try to read from a NULL pointer
//you don't do any checks in this function
static int				check_new_line_pos(t_newstr	*newstr)
{
	int 	i;

	i = newstr->start;
	while (i >= newstr->start && i =< newstr->end)
		if (chardata[i] == '\n')
				return(i);
	return (-1);
}

//fd is a constant, don't mess with it!!
//it goes to export_line in 3 conditions
// 1. newline in the static structure;
// 2. read newline;
// 3. end of reading;
int 		get_next_line(int const fd, char **line)
{
	static t_newstr	*newstr;
	t_newstr				*newstr2;
	int							found_newline;
	int							line_length;

	line_length = 0;
	found_newline = -1;
	if (newstr)
	{
		found_newline = check_new_line_pos(newstr);
		if (found_newline > 0)
			return(export_line(&newstr, (found_newline - start)));
		else
			line_length = newstr->end - newstr->start;
	}
	while (found_newline < 0)
	{
		newstr2 = new_struct_newstr();
		newstr2->end = read(fd, newstr2->chardata, BUFF_SIZE);
		found_newline = check_new_line_pos(newstr2);
		newstr2->next = newstr;
		newstr = newstr2;
		if (found_newline >= 0)
		{
				export_line(&newstr, newline);
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

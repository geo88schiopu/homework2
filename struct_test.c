#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


typedef struct		s_list
{
	void							*content;
	size_t						content_size;
	struct s_list			*next;
}		t_list;



void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	f(lst); //base called first;
	if(lst->next)
	{
		ft_lstiter(lst->next);
	}
}

//this is just a simple lstiter
void ft_print_list(*lst)
{
	printf(lst);
	if(lst->next)
		printf(lst->next);	
}



int		main()
{
	int		n;
	int		fd;
	char		*bbuf;

	bbuf = (char *)malloc(sizeof(char) * BUFF_SIZE);
	fd = open("fopenman.txt", bbuf, O_RDONLY);




}

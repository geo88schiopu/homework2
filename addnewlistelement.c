#include <stdio.h>
#include <stdlib.h>

typedef struct s_list_elem
{
	void *content;
	int size;
	struct s_list_elem	*next;
} t_list;



void	ft_lstadd2(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return;
	new->next = *alst;
	*alst = new;
}





















void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	**old_start;

	old_start = alst;
	new->next = *alst;
	*alst = new;
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	current = *alst;
	next = current->next;
	while (current->next != NULL)
	{
		ft_lstdelone(&current, del);
		current = next;
		next = current->next;
	}
	ft_lstdelone(&current, del);
	*alst = NULL;
}


void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current;

	if (lst != NULL)
	{
		current = lst;
		while (current->next != NULL)
		{
			f(current);
			current = current->next;
		}
		f(current);
	}
}


t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_current;
	int		first;

	if (lst == NULL)
		return (NULL);
	first = 1;
	while (lst->next != NULL)
	{
		if (first == 1)
		{
			new_list = f(lst);
			new_current = new_list;
			first = 0;
		}
		else
		{
			new_current->next = f(lst);
			new_current = new_current->next;
		}
		lst = lst->next;
	}
	new_current->next = f(lst);
	return (new_list);
}





t_list		*free_list(t_list *list);
void		free_tetris(t_etris *tetri);
t_etris		*tetris_new(char **pos, int cols, int rows, char value);
void	free_map(t_map *map);
t_map	*map_new(int size);



t_list	*free_list(t_list *list)
{
	t_list *just_in_case;
	//so you call free on the list.content - which is a **pointer
	//
	ft_memdel(list->content);


}













t_list	*read_tetri(int fd)
{
	char	*buf;
	int		count;
	t_list	*list;
	t_etris	*tetris;
	char	cur;

	buf = ft_strnew(21);
	list = NULL;
	cur = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (check_counts(buf, count) != 0
				|| (tetris = get_piece(buf, cur++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buf);
	if (count != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}

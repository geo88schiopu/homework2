#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_list
{
	void							*content;
	size_t						content_size;
	struct s_list			*next;
}		t_list;


/*
t_list				*ft_lstnew(			const void *content, 			size_t content_size);
void					ft_lstdelone(		t_list **alst, 						void (*del)(void *, size_t));
void					ft_lstdel(			t_list **alst, 						void (*del)(void *, size_t));
void					ft_lstadd(			t_list **alst, 						t_list *n);
void					ft_lstiter(			t_list *lst, 							void (*f)(t_list *elem));
t_list				*ft_lstmap(			t_list *lst, 							t_list *(*f)(t_list *elem));
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	if (!content)
	{
		newnode->content = (void *)content;
		newnode->content_size = 0;
	}
	else
	{
		newnode->content = (void *)malloc(content_size);
		if (!newnode->content)
			return (NULL);
		ft_memcpy(newnode->content, content, content_size);
		newnode->content_size = content_size;
	}
	newnode->next = NULL;
	return (newnode);
}

t_list	*ft_lstnew2(void const *content, size_t content_size)
{
	t_list		*newnode;

	//allocate memory for the entire structure
	newnode = (t_list *)malloc(sizeof(t_list));
	//allocate memory (content_size) to point to it by ->content
	//only if you did get a NULL as  parameter
	newnode->content = malloc(content_size);
	ft_memcpy(newnode->content_size, content, content_size);
	//put the int in content_size ... when you write
	//so the list can link together different sized structures/arrays/strings ...
	newnode->content_size = content_size;

	newnode->next = NULL;
}

void	ft_lstadd(t_list **newnode, t_list *new)
{
	if (!new || !newnode)
		return ;
	//this sequence is nice - you check to see if there's an element
	//and if there isn't you simply place the new element at the head
	//of the list!!!
	//so you can use this function for any list!!
	if (*newnode)
	//so this is one of the operations - set the ->next to a pointer
	//of another element of the structure
		new->next = *newnode;
	*newnode = new;
}

void	ft_lstadd2(t_list **newnode, t_list *new)
{
		//to add a new node at the beginning of the s_list
		//you simply work with the next pointers;
		//the hard part is working with the pointer to pointer!!!
		//I got it!!!!!! - the pointer to pointer stays the same, but it'll
		//point to another element!!
		new->next = *newnode;
		*newnode = new;
}

//recursivitate!!! so nice here!!!
//very useful to navigate a sequence ...
//even if you don't need to accumulate the function results ...
//but you increase the function frame;

//if you want to accumulate, you need to call the function in
//the return statement;

//also you always need parameters ... which are part of a sequence ...
//you need an if statement to check the end of the sequence
void	ft_lstdel2(t_list **alst, void (*del)(void *, size_t))
{
	if(*alst->next)
		ft_lstdel(&(*alst)->next, del)
	ft_lstdelone(alst, del);
}



void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}


//so in 3 cases you pass function pointers!!
//del, iter, map ... well, del is a simple case of iter
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

//this is nice, how do you iterate over a list?
//of course, you don't have an iterator :)))
//you are almost forced to act recursively
//this is a single-linked list, you must start with the
//first element - this is why you always point to it!!!
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	f(lst);
	if (lst->next)
		ft_lstiter(lst->next, f);
}

//this one returns a pointer to a list!!!!
//so no more pointer to pointer, pass by address, bla bla
//you definitely need to create a new element!! ... well, the f function
//will create the element!!
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	//oh no, you simply add ... ft_lstadd ... which in fact is a siimple function
	//just points the pointer-to-pointer to the new elem, and the next of this content
	//to the former first elem!!
	t_list *newnode;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
//for element you apply the f function, and link the returned elements
	{
		newnode = ft_lstmap(lst->next, f);
		ft_lstadd(&newnode, f(lst));
	}
	else
	//the last element does what???
		newnode = f(lst);
	return (newnode);
}

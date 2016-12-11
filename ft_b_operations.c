#include "libft.h"
#include "checker.h"

void	ft_sb(long *a, long *b)
{
	if (b && b->next)
	{
		*(long*)b->content ^= *(long*)b->next->content;
		*(long*)b->next->content ^= *(long*)b->content;
		*(long*)b->content ^= *(long*)b->next->content;
	}
}

void	ft_pb(long *a, long *b)
{
    if (a)
		ft_lstadd(&b, a);
}

void	ft_rb(long *a, long *b)
{
	t_list	*tmp;
	
	if (b)
	{
		tmp = b;
		while (tmp->next)
			tmp = tmp->next;
		if (b != tmp)
			tmp->next = b;
		b->next = 0;
	}
}

void	ft_rrb(t_list *a, t_list *b)
{
	t_list	*tmp;
	t_list	*tmp_2;

	tmp = b;
	while (tmp->next)
	{
		if (!tmp->next->next)
			tmp_2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = b;
	// mettre b en t_list**
	tmp_2->next = NULL;
}


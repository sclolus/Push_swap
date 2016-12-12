#include "libft.h"
#include "checker.h"

void	ft_sa(t_list **a, t_list **b)
{
	if (a && (*a)->next)
	{
		*(long*)(*a)->content ^= *(long*)(*a)->next->content;
		*(long*)(*a)->next->content ^= *(long*)(*a)->content;
		*(long*)(*a)->content ^= *(long*)(*a)->next->content;
	}
}

void	ft_pa(t_list **a, t_list **b)
{
    if (*b)
		ft_lstadd(a, *b);
}

void	ft_ra(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a)
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		if (*a != tmp)
			tmp->next = *a;
		(*a)->next = 0;
	}
}

void	ft_rra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp_2;

	tmp = *a;
	while (tmp->next)
	{
		if (!tmp->next->next)
			tmp_2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = *a;
	*a = tmp;
	tmp_2->next = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:46:06 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/13 16:46:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_list	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		ft_lstadd(a, *b);
		*b = tmp;
	}
}

void	ft_ra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp_2;

	if (*a && (*a)->next)
	{
		tmp_2 = (*a)->next;
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		if (*a != tmp)
			tmp->next = *a;
		(*a)->next = 0;
		*a = tmp_2;
	}
}

void	ft_rra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp_2;

	tmp = *a;
	if (*a && (*a)->next)
	{
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
}

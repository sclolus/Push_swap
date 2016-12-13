/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:42:22 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/13 16:45:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	ft_sb(t_list **a, t_list **b)
{
	if (*b && (*b)->next)
	{
		*(long*)(*b)->content ^= *(long*)(*b)->next->content;
		*(long*)(*b)->next->content ^= *(long*)(*b)->content;
		*(long*)(*b)->content ^= *(long*)(*b)->next->content;
	}
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		ft_lstadd(b, *a);
		*a = tmp;
	}
}

void	ft_rb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp_2;

	if (*b && (*b)->next)
	{
		tmp_2 = (*b)->next;
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		if (*b != tmp)
			tmp->next = *b;
		(*b)->next = 0;
		*b = tmp_2;
	}
}

void	ft_rrb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp_2;

	tmp = *b;
	if (*b && (*b)->next)
	{
		while (tmp->next)
		{
			if (!tmp->next->next)
				tmp_2 = tmp;
			tmp = tmp->next;
		}
		tmp->next = *b;
		*b = tmp;
		tmp_2->next = NULL;
	}
}

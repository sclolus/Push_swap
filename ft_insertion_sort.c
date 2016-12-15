/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:07:32 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/15 20:21:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "checker.h"

t_list	*ft_get_right_position(t_list *base, t_list *to_move)
{
	t_list	*tmp;

	tmp = ft_get_prev(base, to_move);
	while (*(long*)tmp->content > *(long*)to_move->content)
		tmp = ft_get_prev(base, tmp);
	tmp = tmp->next;
	if (!tmp)
		tmp = base;
	return (tmp);
}

void	ft_insertion_sort(t_list **a, t_list **b, t_list **ops)
{
	t_list	*current;
	t_list	*tmp;

	current = *a;
	while (current->next)
	{
		if (ft_find_monotonie(a, ops))
			return ;
		if (*(long*)current->content > *(long*)current->next->content)
		{
/*			ft_print_stacks(*a, *b);*/
			tmp = current->next;
			current = ft_get_right_position(*a, tmp);
			if (current == *a && current->next == tmp)
			{
				ft_sa(a, b);
				ft_lstadd(ops, ft_lstnew(ft_strdup("sa"), ft_strlen("sa")));
				continue ;
			}
			ft_put_up_stack(a, tmp, ops);
/*			ft_print_stacks(*a, *b);*/
			ft_pb(a, b);
			ft_lstadd(ops, ft_lstnew(ft_strdup("pb"), ft_strlen("pb")));
/*			ft_print_stacks(*a, *b);*/
			ft_put_up_stack(a, current, ops);
			/*			ft_print_stacks(*a, *b);*/
			ft_pa(a, b);
			ft_lstadd(ops, ft_lstnew(ft_strdup("pa"), ft_strlen("pa")));
/*			ft_print_stacks(*a, *b);*/
		}
		current = current->next;
		if (!current->next && !ft_issorted(*a))
			current = *a;
	}
}

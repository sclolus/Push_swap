/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:07:32 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/16 04:32:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "checker.h"

/*void	ft_put_chain(t_list *a)
{
	ft_putnbr(*(long*)a->content);
	ft_putstr("->");
	if (a->next)
		ft_put_chain(a->next);
		}*/

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

unsigned int	ft_insert_swap(t_list **a, t_list **b, t_list **ops, t_list *current)
{
	t_list	*tmp;

	tmp = current->next;
	current = ft_get_right_position(*a, tmp);
	if (current == *a && current->next == tmp)
	{
		ft_sa(a, b);
		ft_lstadd(ops, ft_lstnew(ft_strdup("sa"), ft_strlen("sa")));
		return (1);
	}
	ft_put_up_stack(a, tmp, ops);
	ft_pb(a, b);
	ft_lstadd(ops, ft_lstnew(ft_strdup("pb"), ft_strlen("pb")));
	ft_put_up_stack(a, current, ops);
	ft_pa(a, b);
	ft_lstadd(ops, ft_lstnew(ft_strdup("pa"), ft_strlen("pa")));
	return (0);
}

unsigned int	ft_comb_swap(t_list **a, t_list **b, t_list **ops, t_list *current, t_list *lst)
{
	t_list	*tmp;
	t_list	*origin;

	origin = *a;
	if (current == *a)
		origin = lst;
	tmp = current->next;
	if (current == *a && current->next == lst)
	{
		ft_sa(a, b);
		ft_lstadd(ops, ft_lstnew(ft_strdup("sa"), ft_strlen("sa")));
		return (1);
	}
	ft_put_up_stack(a, current, ops);
	ft_pb(a, b);
	ft_lstadd(ops, ft_lstnew(ft_strdup("pb"), ft_strlen("pb")));
	ft_put_up_stack(a, lst, ops);
	ft_ra(a, b);
	ft_lstadd(ops, ft_lstnew(ft_strdup("ra"), ft_strlen("ra")));
	ft_pa(a, b);
	ft_lstadd(ops, ft_lstnew(ft_strdup("pa"), ft_strlen("pa")));
	ft_put_up_stack(a, lst, ops);
	ft_pb(a, b);
	ft_lstadd(ops, ft_lstnew(ft_strdup("pb"), ft_strlen("pb")));
/*	ft_putstr("salut");
	ft_putnbr((long)*a);
	ft_putchar('\n');
	ft_putnbr((long)tmp);*/
	ft_put_up_stack(a, tmp, ops);
	ft_putstr("salut");

	ft_pa(a, b);
	ft_lstadd(ops, ft_lstnew(ft_strdup("pa"), ft_strlen("pa")));
	ft_rra(a, b);
	ft_lstadd(ops, ft_lstnew(ft_strdup("rra"), ft_strlen("rra")));
	ft_put_up_stack(a, origin, ops);
	return (0);
}

void	ft_comb_sort(t_list **a, t_list **b, t_list **ops)
{
	t_list	*current;
	unsigned int	intervalle;
	unsigned int	i;
	t_list	*lst_intervalle;
	int				bool;
	t_list	*tmp;

	current = *a;
	intervalle = (ft_lstlen(*a));
	while (intervalle > 1 || bool || !ft_issorted(*a))
	{
		intervalle = (int)(intervalle / (double)1.3);
		intervalle = intervalle < 1 ? 1 : intervalle;
		i = 0;
		bool = 0;
		while (i < ft_lstlen(*a) - intervalle)
		{
			current = ft_lst_goto_index(*a, i);
			lst_intervalle = ft_lst_goto_index(current, intervalle);
			ft_print_stacks(*a, *b);
/*			ft_put_chain(*a);
			ft_putstr("\n");
			ft_put_chain(current);
			ft_putstr("\n");
			ft_put_chain(lst_intervalle);
			ft_putstr("\n");*/
			if (ft_find_monotonie(a, ops))
				return ;
			if (*(long*)current->content > *(long*)lst_intervalle->content)
			{
/*				ft_putnbr(*(long*)current->content);
				ft_putstr("->");
				ft_putnbr(*(long*)lst_intervalle->content);
				ft_putchar('\n');*/
				tmp = ft_get_right_position(*a, lst_intervalle);
				if (ft_comb_swap(a, b, ops, current, lst_intervalle))
					continue;
				bool = 1;
				current = tmp;
			}
			i++;
			ft_putnbr(i);
			ft_putchar('\n');
/*			lst_intervalle = lst_intervalle->next;*/
/*			if (!current->next && !ft_issorted(*a))
			current = *a;*/
		}
		/*		ft_putstr("exited loop");*/
		current = *a;
	}
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
			tmp = ft_get_right_position(*a, current->next);
			if (ft_insert_swap(a, b, ops, current))
				continue;
			current = tmp;
		}
		current = current->next;
		if (!current->next && !ft_issorted(*a))
			current = *a;
	}
}

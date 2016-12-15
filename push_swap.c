/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:04:48 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/15 09:21:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

t_list	*ft_get_prev(t_list *lst, t_list *stop)
{
	while (lst->next != stop && lst->next)
		lst = lst->next;
	if (lst->next == stop)
		return (lst);
	else
		return (0);
}

void	ft_lst_push_back(t_list *lst, t_list *new)
{
	if (lst->next)
		ft_lst_push_back(lst->next, new);
	else
		lst->next = new;
}

int		ft_lst_get_index(t_list *base, t_list *lst)
{
	int	i;

	i = 0;
	while (base->next && base != lst)
	{
		base = base->next;
		i++;
	}
	if (base == lst)
		return (i);
	return (-1);
}

t_list	*ft_lst_goto_index(t_list *base, unsigned int i)
{
	t_list	*tmp;

	while (base && i--)
	{
		tmp = base;
		base = base->next;
	}
	if (base)
		return (base);
	return (tmp);
}

void	ft_put_up_stack(t_list **stack, t_list *lst, t_list **ops)
{
	unsigned int	stack_len;
	unsigned int	lst_i;

	lst_i = ft_lst_get_index(*stack, lst) - 1;
	stack_len = ft_lstlen(*stack);
	if (lst_i > stack_len / 2)
	{
		while (*stack != lst)
		{
			ft_lstadd(ops, ft_lstnew(ft_strdup("rra"), 8));
			ft_rra(stack, &lst);
		}
	}
	else
	{
		while (*stack != lst)
		{
			ft_lstadd(ops, ft_lstnew(ft_strdup("ra"), 8));
			ft_ra(stack, &lst);
		}
	}
}

void	ft_stupid_sort(t_list **a, t_list **b, t_list **ops)
{
	t_list			*current;
	unsigned int	curr_i;

	current = *a;
	curr_i = 0;
	while (current->next)
	{
		ft_print_stacks(*a, *b);
		if (*(long*)current->content > *(long*)current->next->content)
		{
			while (*(long*)(*a)->content != *(long*)current->content)
			{
				ft_lstadd(ops, ft_lstnew(ft_strdup("ra"), 8));
				ft_ra(a, b);
			}
			ft_putnbr(*(long*)(*a)->content);
			ft_putchar(':');
			ft_lstadd(ops, ft_lstnew(ft_strdup("sa"), 8));
			ft_sa(a, b);
			ft_print_stacks(*a, *b);
			ft_ra(a, b);
			ft_lstadd(ops, ft_lstnew(ft_strdup("ra"), 8));
		}
/*		curr_i++;*/
		if (!current->next && !ft_issorted(*a))
			current = *a;
		else
			current = current->next;
/*		current = ft_lst_goto_index(*a, curr_i);*/
	}
/*	ft_print_stacks(*a, *b);*/
}

int		ft_find_monotonie(t_list **a, t_list **ops)
{
	t_list			*tmp;
	int				i;
	int				lst_len;

	i = 0;
	lst_len = ft_lstlen(*a);
	tmp = (*a);
	if (ft_issorted(*a))
		return (1);
	while (tmp != (*a))
	{
		if (ft_issorted(*a))
		{
			if (i > lst_len / 2)
			{
				while (i-- > 0)
					ft_lstadd(ops, ft_lstnew(ft_strdup("rra"), 8));
			}
			else
			{
				while (i-- > 0)
					ft_lstadd(ops, ft_lstnew(ft_strdup("ra"), 8));
			}
			return (1);
		}
		ft_rra(a, &tmp);
		i++;
	}
	return (0);
}

void	ft_insertion_sort(t_list **a, t_list **b, t_list **ops)
{
	t_list			*tmp;
	t_list			*tmp_2;
	t_list			*current;
	unsigned int	curr_i;

	current = *a;
	curr_i = 0;
	while (current->next)
	{
		if (ft_find_monotonie(a, ops))
			return ;
		if (*(long*)current->content > *(long*)current->next->content)
		{	
/*			ft_print_stacks(*a, *b);*/
			tmp = current->next;
			tmp_2 = current;
			while (*(long*)tmp->content < *(long*)tmp_2->content)
			{
				if (!(tmp_2 = ft_get_prev(*a, tmp_2)))
				{
					tmp_2 = (*a);
					break ;
				}
			}
			if (tmp_2->next == tmp)
			{
				ft_sa(a, b);
/*				ft_print_stacks(*a, *b);*/
				ft_lstadd(ops, ft_lstnew(ft_strdup("sa"), 8));
				current = ft_lst_goto_index(*a, curr_i);
				continue ;
			}
			else
			{
				ft_put_up_stack(a, tmp, ops);
/*				ft_print_stacks(*a, *b);*/
				ft_pb(a, b);
/*				ft_print_stacks(*a, *b);*/
				ft_lstadd(ops, ft_lstnew(ft_strdup("pb"), 8));
				ft_put_up_stack(a, tmp_2, ops);
/*				ft_print_stacks(*a, *b);*/
				ft_pa(a, b);
				ft_lstadd(ops, ft_lstnew(ft_strdup("pa"), 8));
/*				ft_print_stacks(*a, *b);*/
			}
		}
		curr_i++;
		current = ft_lst_goto_index(*a, curr_i);
		if (!current->next && !ft_issorted(*a))
		{
			current = *a;
			curr_i = 0;
		}
	}
}

void	ft_push_swap(t_list	*a)
{
	t_list			*b;
	t_list			*ops;
/*	unsigned int	lens[4];*/

	b = NULL;
	ops = 0;
/*	ft_print_stacks(a, b);*/
/*	ft_stupid_sort(&a, &b, &ops);*/
	ft_insertion_sort(&a, &b, &ops);
/*	ft_print_stacks(a, b);*/
	//ft_quicksort(&a, &b, ops + 1);
	//???
/*	lens[0] = ft_lstlen(ops);
	lens[1] = ft_lstlen(ops + 1);
	lens[2] = ft_lstlen(ops + 2);
	lens[3] = lens[0] < lens[1] ? 0 : 1;
	lens[3] = lens[lens[3]] < lens[2] ? lens[3] : 2;
	ft_putnbr(lens[3]);*/
/*	ft_putnbr(ft_lstlen(ops));
	ft_putchar('\n');*/
	unsigned int i;
	t_list		*tmp;

	i = ft_lstlen(ops);
	while (i > 0)
	{
		tmp = ft_lst_goto_index(ops, i-- - 1);
		ft_putstr((char*)(tmp)->content);
		ft_putchar('\n');
	}
/*	ft_print_ops(ops + lens[4]);*/
}

void	ft_long_del(void *nbr, size_t size)
{
	size = 0;
	free(nbr);
}

int		main(int argc, char **argv)
{
	int		i;
	long	tmp;
	t_list	*tmp_lst;
	t_list	*tab;

	i = argc - 1;
	if (argc != 1)
	{
		while (i > 0)
		{
			tmp = ft_isint(argv[i]);
			tmp_lst = tab;
			while (tmp_lst)
			{
				if (*(long*)tmp_lst->content == tmp)
					tmp = IS_NOT_INT;
				tmp_lst = tmp_lst->next;
			}
			ft_lstadd(&tab, ft_lstnew(&tmp, sizeof(long)));
			if (tmp == IS_NOT_INT)
			{
				ft_putstr("fdp");
				ft_putstr_fd("Error\n", 2);
				ft_lstdel(&tab, &ft_long_del);
				return (-1);
			}
			i--;
		}
		ft_push_swap(tab);
		ft_lstdel(&tab, &ft_long_del);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:04:48 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/14 02:26:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	ft_push_swap(t_list	*a)
{
	t_list			*b;
	t_list			ops[3];
	unsigned int	lens[4];

	b = NULL;
	ft_print_stacks(a, b);
	//ft_insertion_sort(&a, &b, ops);
	//ft_quicksort(&a, &b, ops + 1);
	//???
	lens[0] = ft_lstlen(ops);
	lens[1] = ft_lstlen(ops + 1);
	lens[2] = ft_lstlen(ops + 2);
	lens[3] = lens[0] < lens[1] ? 0 : 1;
	lens[3] = lens[lens[3]] < lens[2] ? lens[3] : 2;
	ft_putnbr(lens[3]);
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
	t_list	*tab;

	i = argc - 1;
	if (argc != 1)
	{
		while (i > 0)
		{
			tmp = ft_isint(argv[i]);
			ft_lstadd(&tab, ft_lstnew(&tmp, sizeof(long)));
			if (tmp == IS_NOT_INT)
			{
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:21:03 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/13 20:34:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void			ft_checker(long *tab, unsigned int len, t_op *ops)
{
	t_list			*b;
	t_list			*a;
	unsigned int	i;

	b = NULL;
	a = NULL;
	i = len;
	while (i > 0)
		ft_lstadd(&a, ft_lstnew(tab + --i, sizeof(long)));
	ft_print_stacks(a, b);
	if (ft_do_op(&a, &b, ops) == -1)
		return ;
	ft_print_stacks(a, b);
	if (ft_issorted(a) && !b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int				ft_issorted(t_list *a)
{
	long	tmp;

	if (a && a->next)
	{
		tmp = *(long*)a->content;
		while (a->next)
		{
			if (tmp > *(long*)a->next->content)
				return (0);
			tmp = *(long*)a->next->content;
			a = a->next;
		}
	}
	return (1);
}

int				main(int argc, char **argv)
{
	int		i;
	long	*tab;

	i = 1;
	if (!(tab = (long*)malloc(sizeof(*tab) * (argc - 1))))
		return (0);
	if (argc != 1)
	{
		while (i < argc)
		{
			if ((tab[i - 1] = ft_isint(argv[i])) == IS_NOT_INT)
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			i++;
		}
		ft_checker(tab, argc - 1, ft_get_op_tab());
		free(tab);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}

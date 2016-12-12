/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:21:03 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/12 15:38:17 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void			ft_checker(long *tab, unsigned int len, t_op *ops)
{
	t_list			*b;
	t_list			*a;
    unsigned int    i;
    char			*line;

	b = NULL;
	a = NULL;
	i = len;
	while (i > 0)
		ft_lstadd(&a, ft_lstnew(tab + --i, sizeof(long)));
/*    while (get_next_line(0, line) > 0)
    {
		while (i < NBR_OPERATIONS)
		{
			if (!ft_strcmp(ops[i].id, line))
				ops[i].f(tab, b);
			i++;
		}
		free(line);
    }
    if (ft_issorted(tab) && *(long*)b->content == IS_NOT_INT)
		ft_putstr("OK\n");
    else
	ft_putstr("KO\n");*/
}

int			ft_issorted(t_list *a)
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
	else
		return (1);
}

void			ft_init_op_ids(t_op *ops)
{
	ops[0].id = ft_strdup("sa");
	ops[1].id = ft_strdup("sb");
	ops[2].id = ft_strdup("ss");
	ops[3].id = ft_strdup("pa");
	ops[4].id = ft_strdup("pb");
	ops[5].id = ft_strdup("ra");
	ops[6].id = ft_strdup("rb");
	ops[7].id = ft_strdup("rr");
	ops[8].id = ft_strdup("rra");
	ops[9].id = ft_strdup("rrb");
	ops[10].id = ft_strdup("rrr");
}

void			ft_init_op_functions(t_op *ops)
{
	ops[0].f = &ft_sa;
	ops[1].f = &ft_sb;
	ops[2].f = &ft_ss;
	ops[3].f = &ft_sa;
	ops[4].f = &ft_pa;
	ops[5].f = &ft_pb;
	ops[6].f = &ft_ra;
	ops[7].f = &ft_ba;
	ops[8].f = &ft_rra;
	ops[9].f = &ft_rrb;
	ops[10].f = &ft_rrr;
}

t_op			*ft_get_op_tab(void)
{
    t_op    *ops;

    if (!(ops = (t_op*)malloc(sizeof(t_op) * NBR_OPERATIONS)))
	return (0);
	ft_init_op_ids(ops);
	ft_init_op_functions(ops);
	return (ops);
}

int			main(int argc, char **argv)
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
		ft_checker(tab, argc - 1, 0);
		free(tab);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:21:03 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/11 18:28:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void			ft_checker(long *tab, unsigned int len, t_op *ops)
{
    long	    b[len];
    unsigned int    i;
    char	    *line;

    ft_memset(b, 255, len * sizeof(len));
    while (get_next_line(0, line) > 0)
    {
	while (i < NBR_OPERATIONS)
	{
	    if (!ft_strcmp(g_op[i].id, line))
		g_op[i].f(tab, b);
	    i++;
	}
	free(line);
    }
    if (ft_issorted(tab, len) && b[0] == IS_NOT_INT)
	ft_putstr("OK\n");
    else
	ft_putstr("KO\n");
}

int			ft_issorted(long *tab, unsigned int len)
{
    int	    i;

    i = 0;
    while (i < len - 1)
    {
	if (tab[i] > tab[i + 1])
	    return (0);
	i++;
    }
    return (1);
}

t_op			*ft_get_op_tab(void)
{
    t_op    *ops;

    if (!(ops = (t_op*)malloc(sizeof(t_op) * NBR_OPERATIONS)))
	return (0);
    ops[0] = { "sa", &ft_sa };
    ops[1] = { "sb", &ft_sb };
    ops[2] = { "ss", &ft_ss };
    ops[3] = { "pa", &ft_pa };
    ops[4] = { "pb", &ft_pb };
    ops[5] = { "ra", &ft_ra };
    ops[6] = { "rb", &ft_rb };
    ops[7] = { "rr", &ft_rr };
    ops[8] = { "rra", &ft_rra };
    ops[9] = { "rrb", &ft_rrb };
    ops[10] = { "rrr", &ft_rrr };
    return (ops);
}

int			main(int argc, char **argv)
{
	int	i;
	t_list	*tab;

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
		ft_checker(tab, argc - 1, ft_get_op_tab);
		free(tab);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}

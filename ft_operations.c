/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:30:40 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/13 20:31:35 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

int			ft_do_op(t_list **a, t_list **b, t_op *ops)
{
	char			*line;
	unsigned int	i;

	while (get_next_line(0, &line) > 0 && *line)
	{
		i = 0;
		while (i < NBR_OPERATIONS)
		{
			if (!ft_strcmp(ops[i].id, line))
			{
				ops[i].f(a, b);
				break ;
			}
			if (i == NBR_OPERATIONS - 1 && *line != '\0')
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			i++;
		}
		ft_print_stacks(*a, *b);
		free(line);
	}
	return (1);
}

void		ft_ss(t_list **a, t_list **b)
{
	ft_sa(a, b);
	ft_sb(a, b);
}

void		ft_rr(t_list **a, t_list **b)
{
	ft_ra(a, b);
	ft_rb(a, b);
}

void		ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a, b);
	ft_rrb(a, b);
}

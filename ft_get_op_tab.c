/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:39:10 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/13 20:47:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void					ft_init_op_ids(t_op *ops)
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

void					ft_init_op_functions(t_op *ops)
{
	ops[0].f = &ft_sa;
	ops[1].f = &ft_sb;
	ops[2].f = &ft_ss;
	ops[3].f = &ft_pa;
	ops[4].f = &ft_pb;
	ops[5].f = &ft_ra;
	ops[6].f = &ft_rb;
	ops[7].f = &ft_rr;
	ops[8].f = &ft_rra;
	ops[9].f = &ft_rrb;
	ops[10].f = &ft_rrr;
}

t_op					*ft_get_op_tab(void)
{
	t_op	*ops;

	if (!(ops = (t_op*)malloc(sizeof(t_op) * NBR_OPERATIONS)))
		return (0);
	ft_init_op_ids(ops);
	ft_init_op_functions(ops);
	return (ops);
}

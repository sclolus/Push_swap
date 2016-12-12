/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:30:40 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/12 15:32:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "checker.c"

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

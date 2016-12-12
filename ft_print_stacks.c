/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:35:35 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/12 17:02:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	ft_print_stacks(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_putnbr(*(long*)a->content);
			a = a->next;
		}
		else
			ft_putstr("   |");
		ft_putstr("   ");
		if (b)
		{
			ft_putnbr(*(long*)b->content);
			b = b->next;
		}
		else
			ft_putstr("   |");
		ft_putchar('\n');
	}
	ft_putstr("___________________\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:04:45 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/14 21:05:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

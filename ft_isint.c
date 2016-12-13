/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:43:52 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/13 16:44:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

long	ft_isint(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (ft_isnbr(str) && nbr >= -2147483648 && nbr <= 2147483647)
		return (nbr);
	return (IS_NOT_INT);
}

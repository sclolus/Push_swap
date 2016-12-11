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


char		**ft_get_instruction(void)
{
	int			i;
	t_lst		*lst;
}

int			main(int argc, char **argv)
{
	int	i;
	int	*tab;

	i = 1;
	if (!(tab = (int*)malloc(sizeof(tab) * (argc - 1))))
		return (0);
	if (argc != 1)
	{
		while (i < argc)
		{
			if (!ft_isint(char *str))
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			tab[i] = ft_atoi(argv[i]);
			i++;
		}
		ft_checker(ft_get_instruction(), tab);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}

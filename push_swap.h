/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:30:22 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/14 17:31:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

t_list	*ft_get_prev(t_list *lst, t_list *stop);
void	ft_lst_push_back(t_list *lst, t_list *new);
int		ft_lst_get_index(t_list *base, t_list *lst);
t_list	*ft_lst_goto_index(t_list *base, unsigned int i);
void	ft_insertion_sort(t_list **a, t_list **b, t_list *ops);
#endif

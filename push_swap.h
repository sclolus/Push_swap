/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:30:22 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/16 03:37:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void	ft_put_chain(t_list *a);

t_list	*ft_get_prev(t_list *lst, t_list *stop);
t_list	*ft_lst_goto_index(t_list *base, unsigned int i);
void	ft_lst_push_back(t_list *lst, t_list *new);
int		ft_lst_get_index(t_list *base, t_list *lst);
t_list	*ft_lst_goto_index(t_list *base, unsigned int i);
void	ft_comb_sort(t_list **a, t_list **b, t_list **ops);
void	ft_insertion_sort(t_list **a, t_list **b, t_list **ops);
void	ft_put_up_stack(t_list **stack, t_list *lst, t_list **ops);
int		ft_find_monotonie(t_list **a, t_list **ops);
#endif

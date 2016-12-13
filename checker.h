/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:44:49 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/13 20:31:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define IS_NOT_INT 9999999999l
# define NBR_OPERATIONS 11

# include <stdlib.h>

typedef struct	s_op
{
	char	*id;
	void	(*f)(t_list **, t_list **);
}				t_op;

long			ft_isint(char *str);
t_op			*ft_get_op_tab(void);
int				ft_do_op(t_list **a, t_list **b, t_op *ops);
int				ft_issorted(t_list *a);
int				ft_isnbr(char *str);

void			ft_init_op_ids(t_op *ops);
void			ft_init_op_functions(t_op *ops);

void			ft_sa(t_list **a, t_list **b);
void			ft_pa(t_list **a, t_list **b);
void			ft_ra(t_list **a, t_list **b);
void			ft_rra(t_list **a, t_list **b);

void			ft_sb(t_list **a, t_list **b);
void			ft_pb(t_list **a, t_list **b);
void			ft_rb(t_list **a, t_list **b);
void			ft_rrb(t_list **a, t_list **b);

void			ft_ss(t_list **a, t_list **b);
void			ft_rr(t_list **a, t_list **b);
void			ft_rrr(t_list **a, t_list **b);

void			ft_print_stacks(t_list *a, t_list *b);

#endif

#ifndef CHECKER_H
# define CHECKER_H
# define IS_NOT_INT 9999999999l
# define NBR_OPERATIONS 11

# include <stdlib.h>

typedef struct	s_op
{
    char    *id;
    void    (*f)(long *tab, long *b);
}				t_op;

long			ft_isint(char *str);
t_op			*ft_get_op_tab(void);
int				ft_issorted(t_list *a);

void			ft_init_op_ids(t_op *ops);
void			ft_init_op_functions(t_op *ops);

#endif

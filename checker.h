#ifndef CHECKER_H
# define CHECKER_H
# define IS_NOT_INT 9999999999l

# include <stdlib.h>

typedef struct	s_op
{
    char    *str;
    void    (*f)(long *tab, long *b);
}		t_op;

long	ft_isint(char *str);
t_op	*ft_get_op_tab(void);
t_op	*ft_get_op_tab(void);

#endif

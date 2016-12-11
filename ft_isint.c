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

#include "./push_swap.h"

int ft_error_nbr(char *str)
{
    if (!(*str == '-' || (*str >= '0' && *str <= '9')))
        return (1);
    if (*str == '-' && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (*(++str))
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
    return (0);
}

void ft_error_free()
{
    /* tu musze jeszcze zwolnic pamiec ale to potem*/
    exit(1);
}
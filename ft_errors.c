#include "./push_swap.h"

int ft_error_nbr(char *str)
{
    if (!(*str == '-' || (*str >= '0' && *str <= '9')))
	{
			write(1, "Not only numbers\n\0", 18);
			return (1);
	}
    if (*str == '-' && !(str[1] >= '0' && str[1] <= '9'))
	{
			write(1, "Not only numbers\n\0", 18);
			return (1);
	}
    while (*(++str))
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			write(1, "Not only numbers\n\0", 18);
			return (1);
		}
	}
    return (0);
}

int ft_error_reapt(t_stack_node *node, long nbr)
{
	if (NULL == node)
		return (0);
	while (node)
	{
		if (node->number == nbr)
		{
			write(1, "Repetition\n\0", 12);
			return (1);
		}
		node = node->next;
	}
	return (0);
}
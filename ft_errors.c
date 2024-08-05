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

void	ft_free_table(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **argv)
{
	ft_free_stack(a);
	ft_free_table(argv);
	write(2, "Error\n", 6);
	exit(1);
}

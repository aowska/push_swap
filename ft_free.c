#include "./push_swap.h"

void	ft_free_table(char **argv)
{
	int	i;

	i = 0;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
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

void	ft_free(t_stack_node **a, char **argv, int argc)
{
	ft_free_stack(a);
	//if (argc == 2)
	//	ft_free_table(argv); when the table is i have leaks 
	exit(1);
}

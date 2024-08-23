#include "./push_swap.h"

void ft_stack(long n, t_stack_node **stack)
{
    t_stack_node *node;
    t_stack_node *last_node;

    node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!node)
        return;
    node->number = n;
    node->next = NULL;
    node->prev = NULL;
    if (*stack == NULL)
        *stack = node;
    else
    {
        last_node = *stack;
        while (last_node->next)
            last_node = last_node->next;
        last_node->next = node;
        node->prev = last_node;
    }
}

void ft_init_stack(t_stack_node **stack, char **argv, int argc)
{
    long n; 
    int i;

    i = 0;
    while (argv[i])
    {
        if (ft_error_nbr(argv[i]))
            ft_free(stack, argv, argc);
        n = ft_atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
        {
			write(1, "INT_MAX OR INT_MIN\n\0", 20);
            ft_free(stack, argv, argc);
        }
        if(ft_error_reapt(*stack, n))
            ft_free(stack, argv, argc);
        ft_stack(n, stack);
        i++;
    }
    if (argc == 2)
		ft_free_table(argv);
}

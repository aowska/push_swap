#include "./push_swap.h"

void    ft_check_top(t_stack_node **stack,
                        t_stack_node *top_node,
                        char stack_name) // Define a function that moves the required node to the top of the stack
{
    while (*stack != top_node) // Check if the required node is not already the first node
    {
        if (stack_name == 'a') // If not, and it is stack `a`, execute the following
        {
            if (top_node->above_median)
                ft_ra(stack);
            else
                ft_rra(stack);
        }
        else if (stack_name == 'b') // If not, and it is stack `b`, execute the following
        {
            if (top_node->above_median)
                ft_rb(stack);
            else
                ft_rrb(stack);
        }
    }
}

void    ft_current_position(t_stack_node *a)
{
     long i;
    long median;

    median = 0;
    i = 0;
    median = ft_stack_len(a) / 2;
    while (a)
    {
        a->position = i;
        if (i <= median)
            a->above_median = true;
        else
            a->above_median = false;
        a = a->next;
        i++;
    }
}

void ft_position_median(t_stack_node *a, long length)
{
    long i;
    long median;

    median = 0;
    i = 0;
    median = length / 2;
    while (a)
    {
        a->position = i;
        if (i <= median)
            a->above_median = true;
        else
            a->above_median = false;
        a = a->next;
        i++;
    }
}
#include "./push_swap.h"

int ft_not_stack_sorted(t_stack_node *stack)
{
    if(!stack)
        return (1);
    while(stack->next)
    {
        if(stack->number > stack->next->number)
            return (1);
        stack = stack->next;
    }
    return(0);
}
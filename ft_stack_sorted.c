#include "./push_swap.h"

bool stack_sorted(t_stack_node *stack)
{
    if(!stack)
        return (false);
    while(stack->next)
    {
        if(stack->number > stack->next->number)
            return (false);
        stack = stack->next;
    }
    return(true);
}
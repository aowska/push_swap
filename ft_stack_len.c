# include "./push_swap.h"

long ft_stack_len(t_stack_node *stack)
{
    long count;

    count = 0;
    if(!stack)
        return (0);
    while( stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}
# include "./push_swap.h"

int stack_len(t_stack_node *stack)
{
    int count;

    count = 0;
    if(!stack)
        return ;
    while( stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}
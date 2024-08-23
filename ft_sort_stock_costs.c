#include "./push_swap.h"

t_stack_node	*ft_current_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void ft_top_cost(t_stack_node *a, long length_a, long length_b)
{
    a->costs = 0;
    while(a)
    {
        a->costs = a->position;
        if(!(a->above_median))
            a->costs = length_a - (a->position);
        if(a->target_node->above_median)
            a->costs = a->costs + a->target_node->position;
        else
            a->costs = a->costs + (length_b - a->target_node->position);
        a = a->next;
    }

}

void    ft_cheapest(t_stack_node *a)
{
    t_stack_node *cost_node;

    if (!a)
        return ;
    t_stack_node *temp = a;
    while (temp)
    {
        temp->cheapest = false;
        temp = temp->next;
    }
    cost_node = a;
    while (a)
    {
        if (a->costs < cost_node->costs)
            cost_node = a;
        a = a->next;
    }
    cost_node->cheapest = true;
}
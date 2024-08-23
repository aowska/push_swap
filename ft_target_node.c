#include "./push_swap.h"

t_stack_node	*ft_max(t_stack_node *stack)
{
    t_stack_node    *max_node;

    if (!stack)
        return (NULL);

    max_node = stack;
    while (stack)
    {
        if (stack->number > max_node->number)
            max_node = stack;
        stack = stack->next;
    }
    return (max_node);
}

t_stack_node	*ft_min(t_stack_node *stack)
{
    t_stack_node    *min_node;

    if (!stack)
        return (NULL);

    min_node = stack;
    while (stack)
    {
        if (stack->number < min_node->number)
            min_node = stack;
        stack = stack->next;
    }
    return (min_node);
}

static t_stack_node *ft_find_best_match(t_stack_node *stack1, t_stack_node *stack2, char stack_a_b, long *best_match_index)
{
    t_stack_node    *current_node;
    t_stack_node    *target_node;

    current_node = stack2;
    target_node = NULL;
    while (current_node)
    {
        if (stack_a_b == 'a' && current_node->number < stack1->number && current_node->number > *best_match_index)
        {
            *best_match_index = current_node->number;
            target_node = current_node;
        }
        else if (stack_a_b == 'b' && current_node->number > stack1->number && current_node->number < *best_match_index)
        {
            *best_match_index = current_node->number;
            target_node = current_node;
        }
        current_node = current_node->next;
    }
    return target_node;
}

static void    ft_set_target_node(t_stack_node *stack1, t_stack_node *target_node, char stack_a_b, long best_match_index, t_stack_node *stack2)
{
    if (stack_a_b == 'a' && best_match_index == LONG_MIN)
        stack1->target_node = ft_max(stack2);
    else if (stack_a_b == 'b' && best_match_index == LONG_MAX)
        stack1->target_node = ft_min(stack2);
    else
        stack1->target_node = target_node;
}

 void	ft_target_node(t_stack_node *stack1, t_stack_node *stack2, char stack_a_b)
{
    long            best_match_index;
    t_stack_node    *target_node;

    while (stack1)
    {
        if (stack_a_b == 'a')
            best_match_index = LONG_MIN;
        else
            best_match_index = LONG_MAX;

        target_node = ft_find_best_match(stack1, stack2, stack_a_b, &best_match_index);
        ft_set_target_node(stack1, target_node, stack_a_b, best_match_index, stack2);

        stack1 = stack1->next;
    }
}
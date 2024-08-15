static void	ft_target_node(t_stack_node *stack1, t_stack_node *stack2, char stack_a_b)
{
    t_stack_node	*current_node;
    t_stack_node	*target_node;
    long			best_match_index;

    while (stack1)
    {
        if (stack_a_b == 'a')
            best_match_index = LONG_MIN;  // Wyszukiwanie mniejszej wartości dla `a`
        else
            best_match_index = LONG_MAX;  // Wyszukiwanie większej wartości dla `b`
        current_node = stack2;
        while (current_node)
        {
            if (stack_a_b == 'a' &&
                current_node->number < stack1->number &&
                current_node->number > best_match_index) // Logika dla TARGET_A
            {
                best_match_index = current_node->number;
                target_node = current_node;
            }
            else if (stack_a_b == 'b' &&
                     current_node->number > stack1->number &&
                     current_node->number < best_match_index) // Logika dla TARGET_B
            {
                best_match_index = current_node->number;
                target_node = current_node;
            }
            current_node = current_node->next;
        }
        if (stack_a_b == 'a' && best_match_index == LONG_MIN)
            stack1->target_node = ft_max(stack2);
        else if (stack_a_b == 'b' && best_match_index == LONG_MAX)
            stack1->target_node = ft_min(stack2);
        else
            stack1->target_node = target_node;
        stack1 = stack1->next;
    }
}

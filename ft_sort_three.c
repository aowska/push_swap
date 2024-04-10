#include "./push_swap.h"

void ft_sort_three( t_stack_node **stack)
{
    t_stack_node*huges_node;

    huges_node = ft_find_max(*a);
    if(huges_node == *a)
        ra(a);
    else if((*a)->next == huges_node)
        rra(a);
    if((*a)->number > (*a)->next->number)
        sa(a);
}
#include "./push_swap.h"

ft_max()
{

}

ft_min()
{

}

ft_cost()
{

}

ft_cheapest()
{
}

ft_min_on_top(a)
{
}

ft_move_to_stack(a, b, 'b')
{

}

void ft_position_median(t_stack_node *a, long length)
{
    long    i;
    long median;

    median = 0;
    i = 1;
    median = length / 2 ;
    while(a)
    {
        a->position = i;
        if(i <= median)
            a->above_median = true;
        else
            a->above_median = false;
        a = a->next;
        i++;
    }
}


void ft_init_nodes(t_stack_node *a, t_stack_node *b, char stack_a_b)
{
    long    len_a;
    long    len_b;
    
    len_a = 0;
    len_b = 0;
    len_a = ft_stack_len(a);
    len_b = ft_stack_len(b);
    ft_position_median(a, len_a);
    ft_position_median(b, len_b);
    ft_target_node(a, b, stack_a_b);
    if(stack_a_b == 'a')
    {
        ft_cost(a,b, len_a, len_b);
        ft_cheapest(a);
    }
}

void	ft_sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	length;

	length = ft_stack_len(*a);
	if (length > 4 && ft_not_stack_sorted(*a)) //If stack `a` has more than three nodes and aren't sorted
    {
		ft_pb(a, b);
        ft_pb(a, b);
    }
	else if (length > 3 && ft_not_stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
	    ft_pb(a, b);
	//while (length > 3 && ft_not_stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
	//{
		ft_init_nodes(*a, *b, 'a'); //Iniate all nodes from both stacks
	//	ft_move_to_stack(a, b, 'a');
    //    length--; //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	//}
	//ft_sort_three(a);
	/*while (*b) //Until the end of stack `b` is reached
	{
		ft_init_nodes(*a, *b, 'b'); //Initiate all nodes from both stacks
		ft_move_to_stack(a, b, 'b'); //Move all `b` nodes back to a sorted stack `a`
	}
	ft_position_median(*a); //Refresh the current position of stack `a`
	ft_min_on_top(a); //Ensure smallest number is on top*/
}



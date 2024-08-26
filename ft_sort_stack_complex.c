/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_complex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:37:25 by awacowsk          #+#    #+#             */
/*   Updated: 2024/08/26 22:07:11 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_min_on_top(t_stack_node **a)
{
	while ((*a)->number != ft_min(*a)->number)
	{
		if (ft_min(*a)->above_median)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

void	ft_move_to_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = ft_current_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			ft_rr(a, b);
		ft_current_position(*a);
		ft_current_position(*b);
	}
	else if (!(cheapest_node->above_median) && 
		!(cheapest_node->target_node->above_median))
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			ft_rrr(a, b);
		ft_current_position(*a);
		ft_current_position(*b);
	}
	ft_check_top(a, cheapest_node, 'a');
	ft_check_top(b, cheapest_node->target_node, 'b');
	ft_pb(a, b);
}

void	ft_move_cheapest_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top_node;

	if (!b || !*b)
		return ;
	top_node = (*b)->target_node;
	while (*a != top_node)
	{
		if (top_node->above_median)
			ft_ra(a);
		else
			ft_rra(a);
	}
	ft_pa(a, b);
}

void	ft_init_nodes(t_stack_node *a, t_stack_node *b, char stack_a_b)
{
	long	len_a;
	long	len_b;

	len_a = 0;
	len_b = 0;
	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	ft_position_median(a, len_a);
	ft_position_median(b, len_b);
	ft_target_node(a, b, stack_a_b);
	if (stack_a_b == 'a')
	{
		ft_top_cost(a, len_a, len_b);
		ft_cheapest(a);
	}
}

void	ft_sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	length;
	int	length_2;

	length = ft_stack_len(*a);
	length_2 = ft_stack_len(*a);
	if (length-- > 3 && ft_not_stack_sorted(*a))
		ft_pb(a, b);
	if (length-- > 3 && ft_not_stack_sorted(*a))
		ft_pb(a, b);
	while (length > 3 && ft_not_stack_sorted(*a))
	{
		ft_init_nodes(*a, *b, 'a');
		ft_move_to_stack(a, b);
		length--;
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodes(*b, *a, 'b');
		ft_move_cheapest_b_to_a(a, b);
	}
	ft_position_median(*a, length_2);
	ft_min_on_top(a);
}

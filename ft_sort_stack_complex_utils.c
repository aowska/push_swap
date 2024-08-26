/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_complex_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:33:07 by awacowsk          #+#    #+#             */
/*   Updated: 2024-08-26 11:33:07 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_check_top(t_stack_node **stack,
				t_stack_node *top_node,
				char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	ft_current_position(t_stack_node *a)
{
	long	i;
	long	median;

	median = 0;
	i = 0;
	median = ft_stack_len(a) / 2;
	while (a)
	{
		a->position = i;
		if (i <= median)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		i++;
	}
}

void	ft_position_median(t_stack_node *a, long length)
{
	long	i;
	long	median;

	median = 0;
	i = 0;
	median = length / 2;
	while (a)
	{
		a->position = i;
		if (i <= median)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		i++;
	}
}

t_stack_node	*ft_max(t_stack_node *stack)
{
	t_stack_node	*max_node;

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
	t_stack_node	*min_node;

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

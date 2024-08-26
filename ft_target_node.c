/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:44:17 by awacowsk          #+#    #+#             */
/*   Updated: 2024-08-26 11:44:17 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

long	ft_get_best_match_index(char stack_a_b)
{
	if (stack_a_b == 'a')
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

t_stack_node	*ft_find_best_match(t_stack_node *stack1, t_stack_node *stack2,
					char stack_a_b, long *best_match_index)
{
	t_stack_node	*current_node;
	t_stack_node	*target_node;

	current_node = stack2;
	target_node = NULL;
	while (current_node)
	{
		if (stack_a_b == 'a' && current_node->number < stack1->number &&
			current_node->number > *best_match_index)
		{
			*best_match_index = current_node->number;
			target_node = current_node;
		}
		else if (stack_a_b == 'b' && current_node->number > stack1->number &&
			current_node->number < *best_match_index)
		{
			*best_match_index = current_node->number;
			target_node = current_node;
		}
		current_node = current_node->next;
	}
	return (target_node);
}

void	ft_set_target_node_a(t_stack_node *stack1,
		t_stack_node *target_node, long best_match_index)
{
	if (best_match_index == LONG_MIN)
		stack1->target_node = ft_max(stack1->next);
	stack1->target_node = target_node;
}

void	ft_set_target_node_b(t_stack_node *stack1,
		t_stack_node *target_node, long best_match_index)
{
	if (best_match_index == LONG_MAX)
		stack1->target_node = ft_min(stack1->next);
	else
		stack1->target_node = target_node;
}

void	ft_target_node(t_stack_node *stack1,
					t_stack_node *stack2, char stack_a_b)
{
	long			best_match_index;
	t_stack_node	*target_node;

	while (stack1)
	{
		best_match_index = ft_get_best_match_index(stack_a_b);
		target_node = ft_find_best_match(stack1, stack2,
				stack_a_b, &best_match_index);
		if (stack_a_b == 'a')
			ft_set_target_node_a(stack1, target_node, best_match_index);
		else
			ft_set_target_node_b(stack1, target_node, best_match_index);
		stack1 = stack1->next;
	}
}

/*static t_stack_node *ft_find_best_match(t_stack_node *stack1, t_stack_node *stack2, char stack_a_b, long *best_match_index)
{
	t_stack_node *current_node;
	t_stack_node *target_node;

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

static void ft_set_target_node(t_stack_node *stack1, t_stack_node *target_node, char stack_a_b, long best_match_index, t_stack_node *stack2)
{
	if (stack_a_b == 'a' && best_match_index == LONG_MIN)
		stack1->target_node = ft_max(stack2);
	else if (stack_a_b == 'b' && best_match_index == LONG_MAX)
		stack1->target_node = ft_min(stack2);
	else
		stack1->target_node = target_node;
}

void ft_target_node(t_stack_node *stack1, t_stack_node *stack2, char stack_a_b)
{
	long best_match_index;
	t_stack_node *target_node;

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
/*/
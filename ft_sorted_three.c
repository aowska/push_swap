/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:40:01 by awacowsk          #+#    #+#             */
/*   Updated: 2024-08-26 11:40:01 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_sort_three(t_stack_node **stack)
{
	t_stack_node	*biggest_node;

	biggest_node = *stack;
	if (biggest_node->number < (*stack)->next->number)
		biggest_node = (*stack)->next;
	if (biggest_node->number < (*stack)->next->next->number)
		biggest_node = (*stack)->next->next;
	if (biggest_node == *stack)
		ft_ra(stack);
	else if ((*stack)->next == biggest_node)
		ft_rra(stack);
	if ((*stack)->number > (*stack)->next->number)
		ft_sa(stack);
}

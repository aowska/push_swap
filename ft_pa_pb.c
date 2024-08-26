/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:30:02 by awacowsk          #+#    #+#             */
/*   Updated: 2024-08-26 11:30:02 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	temp->next = *b;
	if (temp->next != NULL)
		temp->next->prev = temp;
	*b = temp;
}

void	ft_pb(t_stack_node **a, t_stack_node **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}

void	ft_pa(t_stack_node **a, t_stack_node **b)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

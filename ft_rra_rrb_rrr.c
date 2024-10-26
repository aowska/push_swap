/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:31:15 by awacowsk          #+#    #+#             */
/*   Updated: 2024-08-26 11:31:15 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_r_rotate(t_stack_node **head)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	last->next = *head;
	last->prev = NULL;
	(*head)->prev = last;
	*head = last;
	second_last->next = NULL;
}

void	ft_rra(t_stack_node **a)
{
	ft_r_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack_node **b)
{
	ft_r_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack_node **a, t_stack_node **b)
{
	ft_r_rotate(a);
	ft_r_rotate(b);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:19:46 by awacowsk          #+#    #+#             */
/*   Updated: 2024/08/26 23:56:26 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_stack(long n, t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->number = n;
	node->next = NULL;
	node->prev = NULL;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = node;
		node->prev = last_node;
	}
}

void	ft_init_stack(t_stack_node **stack, char **argv, int argc)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_error_nbr(argv[i]) == 1)
			ft_free(stack, argv, argc);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_free(stack, argv, argc);
		if (ft_error_reapt(*stack, n) == 1)
			ft_free(stack, argv, argc);
		ft_stack(n, stack);
		i++;
	}
	if (argc == 2)
		ft_free_table(argv);
}

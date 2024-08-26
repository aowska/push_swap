/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:45:51 by awacowsk          #+#    #+#             */
/*   Updated: 2024-08-26 11:45:51 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static char	**ft_get_arguments(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		write(1, "wrong number of argument\n", 26);
		return (NULL);
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (NULL);
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	long			i;

	a = NULL;
	b = NULL;
	i = 0;
	argv = ft_get_arguments(argc, argv);
	if (!argv)
		return (1);
	ft_init_stack(&a, argv + 1, argc);
	if (ft_not_stack_sorted(a))
	{
		i = ft_stack_len(a);
		if (i == 2)
			ft_sa(&a);
		else if (i == 3)
			ft_sort_three(&a);
		else
			ft_sort_stacks(&a, &b);
	}
	return (ft_free_stack(&a), 0);
}

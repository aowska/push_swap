#include "./push_swap.h"

static void	ft_swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	ft_sa(t_stack_node **a)
{
    ft_swap(a);
	write(1, "sa\n\0", 4);
}

void	ft_sb(t_stack_node **b)
{
    ft_swap(b);
	write(1, "sb\n\0", 4);
}

void	ft_ss(t_stack_node **a, t_stack_node **b)
{
    ft_swap(a);
    ft_swap(b);
	write(1, "ss\n\0", 4);
}
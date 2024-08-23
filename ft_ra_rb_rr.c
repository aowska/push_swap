#include "./push_swap.h"

static void ft_rotate(t_stack_node **head)
{
    t_stack_node    *first;
    t_stack_node    *last;

    if (!head || !(*head) || !(*head)->next)
        return;

    first = *head;
    last = *head;
    while (last->next)
        last = last->next;
    *head = first->next;
    first->next->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void    ft_ra(t_stack_node **a)
{
    ft_rotate(a);
    write(1, "ra\n", 3);
}

void    ft_rb(t_stack_node **b)
{
    ft_rotate(b);
    write(1, "rb\n", 3);
}

void    ft_rr(t_stack_node **a, t_stack_node **b)
{
    ft_rotate(a);
    ft_rotate(b);
    write(1, "rr\n", 3);
}
/*
t_stack_node	*find_last_node1(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = ft_stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = find_last_node1(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}	

void	ft_ra(t_stack_node **a)
{
	rotate(a);
	//if (!checker)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack_node **b)
{
	rotate(b);
	//if (!checker)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	
		write(1, "rr\n", 3);
}*/
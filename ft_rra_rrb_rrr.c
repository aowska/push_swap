#include "./push_swap.h"

static void ft_r_rotate(t_stack_node **head)
{
    t_stack_node    *last;
    t_stack_node    *second_last;

      if (!head || !(*head) || !(*head)->next)
        return;
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

void    ft_rra(t_stack_node **a)
{
    ft_r_rotate(a);
    write(1, "rra\n", 4);
}

void    ft_rrb(t_stack_node **b)
{
    ft_r_rotate(b);
    write(1, "rrb\n", 4);
}

void    ft_rrr(t_stack_node **a, t_stack_node **b)
{
    ft_r_rotate(a);
    ft_r_rotate(b);
    write(1, "rrr\n", 4);
}
/*
t_stack_node	*find_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = ft_stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	ft_rra(t_stack_node **a)
{
	reverse_rotate(a);
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack_node **b)
{
	reverse_rotate(b);
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
		write(1, "rrr\n", 4);
}*/
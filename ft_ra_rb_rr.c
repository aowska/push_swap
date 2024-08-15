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
    write(1, "ra\n\0", 4);
}

void    ft_rb(t_stack_node **b)
{
    ft_rotate(b);
    write(1, "rb\n\0", 4);
}

void    ft_rr(t_stack_node **a, t_stack_node **b)
{
    ft_rotate(a);
    ft_rotate(b);
    write(1, "rr\n\0", 4);
}
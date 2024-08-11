#include "./push_swap.h"

static void ft_r_rotate(t_stack_node **head)
{
    t_stack_node *first;
    t_stack_node *last;

    if (!head || !(*head) || !(*head)->next)
        return;

    first = *head;
    last = *head;

    while (last->next)
        last = last->next;

    (*head) = last;
    (*head)->next = first;
    (*head)->prev->next = NULL;
    (*head)->prev = NULL;
}

void ft_rra(t_stack_node **a)
{
    ft_r_rotate(a);
    write(1, "rra\n\0", 5);
}

void ft_rrb(t_stack_node **b)
{
    ft_r_rotate(b);
    write(1, "rrb\n\0", 5);
}

void ft_rrr(t_stack_node **a, t_stack_node **b)
{
    ft_r_rotate(a);
    ft_r_rotate(b);
    write(1, "rrr\n\0", 5);
}
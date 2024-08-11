#include "./push_swap.h"

static void ft_rotate(t_stack_node **head)
{
    t_stack_node *first;
    t_stack_node *last;

    // If the list is empty or has only one node, no rotation is needed.
    if (!head || !(*head) || !(*head)->next)
        return;

    first = *head;        // Store the reference to the first node
    last = *head;         // Start traversing from the first node

    // Find the last node in the stack
    while (last->next)
        last = last->next;

    // Move the first node to the end
    *head = first->next;          // The new head is the second node
    first->next->prev = NULL;     // Unlink the first node from the second node
    last->next = first;           // Link the last node to the former first node
    first->prev = last;           // Set the previous pointer of the first node to the last node
    first->next = NULL;           // The former first node is now the last node, so its next is NULL
}

void ft_ra(t_stack_node **a)
{
     ft_rotate(a);
     write(1, "ra\n\0", 4);
}

void ft_rb(t_stack_node **b)
{
    ft_rotate(b);
    write(1, "rb\n\0", 4);
}

void ft_rr(t_stack_node **a, t_stack_node **b)
{
    ft_rotate(a);
    ft_rotate(b);
    write(1, "rr\n\0", 4);
}
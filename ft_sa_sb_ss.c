#include "./push_swap.h"

static void	ft_swap(t_stack_node **head) //Define a function that swaps the positions of the top node and second node of a stack
{
	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
		return ;
	*head = (*head)->next; //Update `head` to point to the next node, effectively swapping the first and second nodes
	(*head)->prev->prev = *head; //Update the `prev` pointer of the node before the `new head` to point to the `new head`
	(*head)->prev->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
	if ((*head)->next) //Check if there's a `next` node after the `new head` and
		(*head)->next->prev = (*head)->prev; //If so, update its `prev` pointer to point back to the `new head`
	(*head)->next = (*head)->prev; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
	(*head)->prev = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap
}

void ft_sa(t_stack_node **a)
{
     ft_swap(a);
	 write(1, "sa\n\0", 4);
}

void ft_sb(t_stack_node **b)
{
    ft_swap(b);
	write(1, "sb\n\0", 4);
}

void ft_ss(t_stack_node **a, t_stack_node **b)
{
    ft_swap(a);
    ft_swap(b);
	write(1, "ss\n\0", 4);
}
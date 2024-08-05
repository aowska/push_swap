#include "./push_swap.h"

void ft_stack_(long n, t_stack_node **stack)
{
    t_stack_node *last_a;
    t_stack_node *a;

    if(stack == NULL)
        return ;
    a = malloc(sizeof(t_stack_node));
    if(a == NULL)
        return ;
    a->next = NULL;
    a->number= n;
    if(*stack = NULL)
    {
        *stack = a;
        a->prev = NULL;
    }
    else
    {
        while ((*stack)->next)
            (*stack) = (*stack)->next;  
        last_a = *stack;
        last_a->next = a;
        a->prev = last_a;
    }
}

void ft_init_stack(t_stack_node **stack, char **argv)
{
    long n; 
    int i;
    t_stack_node *node;

    i = 0;
    while (argv[i])
    {
        if ( ft_error_nbr(argv[i]))
        {
            write(1, "No number only\0", 14);
            ft_error_free();
        }
        n = ft_atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            ft_error_free();
        /*tu jeszcze sprawdzic czy sie powtarza */
        ft_stack_(n, stack);
        i++;
    }
}

/*int main()
{
    t_stack_node *a;
    a = NULL;

    char *v[4] = {v[0] = "\0", v[1] = "42", v[2] = "1337", v[3] = NULL};
    ft_stack_init(&a, v + 1);
    while(a)
    {
        a = a -> next;
    }
}*/


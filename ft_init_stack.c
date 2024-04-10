#include "./push_swap.h"

ft_stack_neighbors(t_stack_node *node, t_stack_node **stack)
{
      t_stack_node *last;

    if(!(stack))
    {
        *stack = node;
        node->prev = NULL; 
    }
    else
    {
        while (*stack->next)
            *stack = stack->next;
        last = stack;
        last->next = node;
        node->prev = last;
    }


}

void ft_init_stack(t_stack_node **stack, char **argv)
{
    int n; 
    int i;
    t_stack_node *node;

    i = 0;
    while (argv[i])
    {
        n = ft_atoi(argv);
        if (n > INT_MAX || n < INT_MIN)
            return ;
        else if(!stack)
            return ;
        node = malloc(sizeof(t_stack_node));  // poczytac o tym cholerstwie 
            if(!node)
        return ;
        node->next = NULL;
        node->number = n;
        ft_stack_neighbors(&node, *stack);
    }
}





typedef struct s_stack_node
{  
    int                     nbr;
    int                     index;
    int                     push_cost;
    bool                    above_median;
    bool                    cheapest;
    struct s_stack_node     *target_node;  
    struct s_stack_node     *next;  
    struct s_stack_node     *prev;
} t_stack_node;
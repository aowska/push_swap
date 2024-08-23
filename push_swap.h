#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
#include <stdlib.h>


typedef struct  s_stack_node
{  
    long                    number;
    long                    position;
    bool                    above_median;
    long                     costs;
    bool                    cheapest;
    struct s_stack_node     *target_node;
    struct s_stack_node     *next;  
    struct s_stack_node     *prev;
}                           t_stack_node;

/*Errors and Free*/
char            **ft_split(char const *s, char c);
int             ft_error_nbr(char *str);
void            ft_free(t_stack_node **stack, char **argv, int argc);
int             ft_error_reapt(t_stack_node *node, long nbr);
void            ft_free_table(char **argv);
void            ft_free_stack(t_stack_node **stack);
void            ft_init_stack(t_stack_node **stack, char **argv, int argc);
long            ft_atol(const char *str);

/*Sorting*/
void            ft_top_cost(t_stack_node *a, long length_a, long length_b);
int             ft_not_stack_sorted(t_stack_node *stack);
long            ft_stack_len(t_stack_node *stack);
t_stack_node    *ft_min(t_stack_node *stack);
void            ft_target_node(t_stack_node *stack1, t_stack_node *stack2, char stack_a_b);
void            ft_check_top(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void            ft_cheapest(t_stack_node *a);
t_stack_node	*ft_current_cheapest(t_stack_node *stack);
void            ft_sort_three( t_stack_node **stack);
void            ft_position_median(t_stack_node *a, long length);
void            ft_current_position(t_stack_node *stack);
void            ft_init_nodes(t_stack_node *a, t_stack_node *b, char stack_a_b);
void            ft_sort_stacks(t_stack_node **a, t_stack_node **b);

/*Commands*/
void            ft_sa(t_stack_node **a);
void            ft_sb(t_stack_node **b);
void            ft_ss(t_stack_node **a, t_stack_node **b);
void            ft_ra(t_stack_node **a);
void            ft_rb(t_stack_node **b);
void            ft_rr(t_stack_node **a, t_stack_node **b);
void            ft_rrr(t_stack_node **a, t_stack_node **b);
void            ft_rrb(t_stack_node **b);
void            ft_rra(t_stack_node **a);
void            ft_pa(t_stack_node **a, t_stack_node **b);
void            ft_pb(t_stack_node **a, t_stack_node **b);

#endif
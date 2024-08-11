#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include <stdio.h>
#include <stdlib.h>


typedef struct  s_stack_node
{  
    long                    number;
    /*int                     position;
    int                     id;
    int                     costs;
    bool                    above_median;
    bool                    cheapest;
    struct s_stack_node     *target_node;  */
    struct s_stack_node     *next;  
    struct s_stack_node     *prev;
}                           t_stack_node;

char            **ft_split(char const *s, char c);
int             ft_error_nbr(char *str);
void            ft_free(t_stack_node **stack, char **argv, int argc);
int             ft_error_reapt(t_stack_node *node, long nbr);
void            ft_free_table(char **argv);
void            ft_free_stack(t_stack_node **stack);
void            ft_init_stack(t_stack_node **stack, char **argv, int argc);
long            ft_atol(const char *str);
int             ft_not_stack_sorted(t_stack_node *stack);
long            ft_stack_len(t_stack_node *stack);
void            ft_sort_three( t_stack_node **stack);

/*Commands*/
static void     ft_swap(t_stack_node **c);
void            ft_sa(t_stack_node **a);
void            ft_sb(t_stack_node **b);
void            ft_ss(t_stack_node **a, t_stack_node **b);
static void     ft_r_rotate(t_stack_node **head);
static void     ft_rotate(t_stack_node **head);
void            ft_ra(t_stack_node **a);
void            ft_rb(t_stack_node **b);
void            ft_rr(t_stack_node **a, t_stack_node **b);
void            ft_rrr(t_stack_node **a, t_stack_node **b);
void            ft_rrb(t_stack_node **b);
void            ft_rra(t_stack_node **a);
static void     ft_push(t_stack_node **a, t_stack_node **b);
void            ft_pa(t_stack_node **a, t_stack_node **b);
void            ft_pb(t_stack_node **a, t_stack_node **b);

#endif
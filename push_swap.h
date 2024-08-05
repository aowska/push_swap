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


typedef struct s_stack_node
{  
    long                    number;
    int                     position;
    int                     id;
    int                     costs;
    bool                    above_median;
    bool                    cheapest;
    struct s_stack_node     *target_node;  
    struct s_stack_node     *next;  
    struct s_stack_node     *prev;
}                           t_stack_node;

//Handle errors

//Stack initiation

//Nodes initiation
char    **ft_split(char const *s, char c);
int ft_error_nbr(char *str);
void ft_error_free();
void ft_init_stack(t_stack_node **stack, char **argv);

/*Stack utils
ft_swap(t_stack_node **c);
ft_sa(t_stack_node **a);
ft_sb(t_stack_node **b);
ft_ss(t_stack_node **a, t_stack_node **b);
//Algorithms*/

#endif
#include "./push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;
    long             i;

    a = NULL;
    b = NULL;
    i = 0;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (write(1, "wrong number of argument\n\0", 26), 1);
    if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        if (!argv)
            return (1);
    }
    ft_init_stack(&a, argv + 1, argc);
    if (ft_not_stack_sorted(a))
    {
        i = ft_stack_len(a);
        if (i == 2)
            ft_sa(&a);
        else if (i == 3)
            ft_sort_three(&a);
        else
           ft_sort_stacks(&a, &b);
    }
    ft_free_stack(&a);
    return(0);
}

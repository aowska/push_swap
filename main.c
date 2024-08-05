#include "./push_swap.h"

int main (int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    int i = 1;

    if(argc == 1 || (argc == 2 && !argv[1][0])) //one value or 2 but empty 
        return (1);
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    ft_init_stack(&a, argv + 1);
    /*if(!ft_stack_sorted(a))
    {
        if(ft_stack_len(a) == 2)
            ft_sa(&a);
        else if (ft_stack_len(a) == 3)
            ft_sort_three(&a);
        else
            ft_sort_stacks(&a, &b);
    }
    ft_free_stack(&a);*/
   /* printf("%i", argc);
    while (argv[i] != NULL) {
        printf("Argument %d: %s\n", i, argv[i]);
        i++;
    }*/
    write(1, "0\0", 1);
    return(0);
}
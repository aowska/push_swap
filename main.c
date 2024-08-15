#include "./push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;
    long             i;
    int             j;

    a = NULL;
    b = NULL;
    i = 0;
    j = 0;

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
    t_stack_node *current = a;
    t_stack_node *current2 = b;
    while (current != NULL) {
        printf("Wartość number: %ld\n", current->number);
        printf("Wartość number Position: %ld\n", current->position);
        printf("Wartość number median: %d\n", current->above_median);
        current = current->next;
    }
    while (current2 != NULL) {
        printf("Wartość number for B: %ld\n", current2->number);
        printf("Wartość number Position: %ld\n", current2->position);
        printf("Wartość number median: %d\n", current2->above_median);
        current2 = current2->next;
    }
    write(1,"--\n\0",4);
    printf("Liczba argumentów: %i\n", argc);
    while (argv[j] != NULL) 
    {
        printf("Argument %d: %s\n", j, argv[j]);
        j++;
    }
    ft_free_stack(&a);
    write(1, "0\0", 1);
    return(0);
}

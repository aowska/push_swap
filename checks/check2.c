# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

# include <stdio.h>
#include <stdlib.h>
//https://pythontutor.com/render.html#code=%23%20include%20%3Cstdarg.h%3E%0A%23%20include%20%3Cunistd.h%3E%0A%23%20include%20%3Climits.h%3E%0A%23%20include%20%3Cstdbool.h%3E%0A%0A%23%20include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0A%0Atypedef%20struct%20s_stack_node%0A%7B%20%20%0A%20%20%20%20long%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20number%3B%0A%20%20%20%20struct%20s_stack_node%20%20%20%20%20*target_node%3B%20%20%0A%20%20%20%20struct%20s_stack_node%20%20%20%20%20*next%3B%20%20%0A%20%20%20%20struct%20s_stack_node%20%20%20%20%20*prev%3B%0A%7D%20t_stack_node%3B%0A%0A%0Aint%20ft_error_nbr%28char%20*str%29%0A%7B%0A%20%20%20%20if%20%28!%28*str%20%3D%3D%20'-'%20%7C%7C%20%28*str%20%3E%3D%20'0'%20%26%26%20*str%20%3C%3D%20'9'%29%29%29%0A%20%20%20%20%20%20%20%20return%20%281%29%3B%0A%20%20%20%20if%20%28*str%20%3D%3D%20'-'%20%26%26%20!%28str%5B1%5D%20%3E%3D%20'0'%20%26%26%20str%5B1%5D%20%3C%3D%20'9'%29%29%0A%20%20%20%20%20%20%20%20return%20%281%29%3B%0A%20%20%20%20while%20%28*%28%2B%2Bstr%29%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28!%28*str%20%3E%3D%20'0'%20%26%26%20*str%20%3C%3D%20'9'%29%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20%281%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%280%29%3B%0A%7D%0A%0Avoid%20%20%20%20ft_free_table%28char%20**argv%29%0A%7B%0A%20%20%20%20int%20%20%20%20i%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20if%20%28NULL%20%3D%3D%20argv%20%7C%7C%20NULL%20%3D%3D%20*argv%29%0A%20%20%20%20%20%20%20%20return%20%3B%0A%20%20%20%20while%20%28argv%5Bi%5D%29%0A%20%20%20%20%20%20%20%20free%28argv%5Bi%2B%2B%5D%29%3B%0A%20%20%20%20free%28argv%29%3B%0A%7D%0A%0Avoid%20%20%20%20ft_free_stack%28t_stack_node%20**stack%29%0A%7B%0A%20%20%20%20t_stack_node%20%20%20%20*tmp%3B%0A%20%20%20%20t_stack_node%20%20%20%20*current%3B%0A%0A%20%20%20%20if%20%28NULL%20%3D%3D%20stack%29%0A%20%20%20%20%20%20%20%20return%20%3B%0A%20%20%20%20current%20%3D%20*stack%3B%0A%20%20%20%20while%20%28current%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20tmp%20%3D%20current-%3Enext%3B%0A%20%20%20%20%20%20%20%20free%28current%29%3B%0A%20%20%20%20%20%20%20%20current%20%3D%20tmp%3B%0A%20%20%20%20%7D%0A%20%20%20%20*stack%20%3D%20NULL%3B%0A%7D%0A%0Avoid%20%20%20%20ft_error_free%28t_stack_node%20**a,%20char%20**argv%29%0A%7B%0A%20%20%20%20ft_free_stack%28a%29%3B%0A%20%20%20%20write%282,%20%22Error%5Cn%22,%206%29%3B%0A%20%20%20%20exit%281%29%3B%0A%7D%0A%0Avoid%20ft_stack_%28long%20n,%20t_stack_node%20**stack%29%0A%7B%0A%20%20%20%20t_stack_node%20*last_a%3B%0A%20%20%20%20t_stack_node%20*a%3B%0A%0A%20%20%20%20if%28stack%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%20%3B%0A%20%20%20%20a%20%3D%20malloc%28sizeof%28t_stack_node%29%29%3B%0A%20%20%20%20if%28a%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%20%3B%0A%20%20%20%20a-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20a-%3Enumber%3D%20n%3B%0A%20%20%20%20%20%20if%20%28*stack%20%3D%3D%20NULL%29%20//%20Poprawiono%20przypisanie%20na%20por%C3%B3wnanie%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20*stack%20%3D%20a%3B%0A%20%20%20%20%20%20%20%20a-%3Eprev%20%3D%20NULL%3B%0A%20%20%20%20%7D%0A%20%20%20%20else%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20t_stack_node%20*temp%20%3D%20*stack%3B%20//%20U%C5%BCycie%20tymczasowego%20wska%C5%BAnika%0A%20%20%20%20%20%20%20%20while%20%28temp-%3Enext%29%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20temp-%3Enext%3B%0A%20%20%20%20%20%20%20%20last_a%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20last_a-%3Enext%20%3D%20a%3B%0A%20%20%20%20%20%20%20%20a-%3Eprev%20%3D%20last_a%3B%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20ft_stack_init%28t_stack_node%20**stack,%20char%20**argv%29%0A%7B%0A%20%20%20%20long%20n%3B%20%0A%20%20%20%20int%20i%3B%0A%20%20%20%20t_stack_node%20*node%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28argv%5Bi%5D%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28ft_error_nbr%28argv%5Bi%5D%29%29%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20write%281,%20%22No%20number%20only%5C0%22,%2014%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20ft_error_free%28stack,%20argv%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20n%20%3D%20atol%28argv%5Bi%5D%29%3B%0A%20%20%20%20%20%20%20%20ft_stack_%28n,%20stack%29%3B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20ft_free_table%28argv%29%3B%0A%7D%0A%0Aint%20main%28%29%0A%7B%0A%20%20%20%20t_stack_node%20*a%20%3D%20NULL%3B%0A%20%20%20%20char%20**dynamic_argv%3B%0A%20%20%20%20int%20i%3B%0A%0A%20%20%20%20//%20Alokowanie%20pami%C4%99ci%20dla%204%20wska%C5%BAnik%C3%B3w%20na%20%C5%82a%C5%84cuchy%20znak%C3%B3w%0A%20%20%20%20dynamic_argv%20%3D%20malloc%284%20*%20sizeof%28char%20*%29%29%3B%0A%0A%20%20%20%20//%20Alokowanie%20i%20przypisywanie%20warto%C5%9Bci%20do%20dynamicznej%20tablicy%0A%20%20%20%20dynamic_argv%5B0%5D%20%3D%20malloc%284%20*%20sizeof%28char%29%29%3B%20//%20%2242%22%0A%20%20%20%20dynamic_argv%5B1%5D%20%3D%20malloc%286%20*%20sizeof%28char%29%29%3B%20//%20%221337%22%0A%20%20%20%20dynamic_argv%5B2%5D%20%3D%20malloc%285%20*%20sizeof%28char%29%29%3B%20//%20%2256%22%0A%20%20%20%20dynamic_argv%5B3%5D%20%3D%20NULL%3B%0A%0A%20%20%20%20strcpy%28dynamic_argv%5B0%5D,%20%2242%22%29%3B%0A%20%20%20%20strcpy%28dynamic_argv%5B1%5D,%20%221337%22%29%3B%0A%20%20%20%20strcpy%28dynamic_argv%5B2%5D,%20%2256%22%29%3B%0A%0A%20%20%20%20ft_stack_init%28%26a,%20dynamic_argv%29%3B%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=112&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
//https://pythontutor.com/visualize.html#code=%23%20include%20%3Cstdarg.h%3E%0A%23%20include%20%3Cunistd.h%3E%0A%23%20include%20%3Climits.h%3E%0A%23%20include%20%3Cstdbool.h%3E%0A%0A%23%20include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0A%0Atypedef%20struct%20s_stack_node%0A%7B%20%20%0A%20%20%20%20long%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20number%3B%0A%20%20%20%20struct%20s_stack_node%20%20%20%20%20*target_node%3B%20%20%0A%20%20%20%20struct%20s_stack_node%20%20%20%20%20*next%3B%20%20%0A%20%20%20%20struct%20s_stack_node%20%20%20%20%20*prev%3B%0A%7D%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_stack_node%3B%0Avoid%20%20%20%20ft_free_table%28char%20**argv%29%0A%7B%0A%20%20%20%20int%20%20%20%20i%3B%0A%0A%20%20%20%20i%20%3D%20-1%3B%0A%20%20%20%20if%20%28NULL%20%3D%3D%20argv%20%7C%7C%20NULL%20%3D%3D%20*argv%29%0A%20%20%20%20%20%20%20%20return%20%3B%0A%20%20%20%20while%20%28argv%5Bi%5D%29%0A%20%20%20%20%20%20%20%20free%28argv%5Bi%2B%2B%5D%29%3B%0A%20%20%20%20free%28argv%20-%201%29%3B%0A%7D%0A%0Avoid%20%20%20%20ft_free_stack%28t_stack_node%20**stack%29%0A%7B%0A%20%20%20%20t_stack_node%20%20%20%20*tmp%3B%0A%20%20%20%20t_stack_node%20%20%20%20*current%3B%0A%0A%20%20%20%20if%20%28NULL%20%3D%3D%20stack%29%0A%20%20%20%20%20%20%20%20return%20%3B%0A%20%20%20%20current%20%3D%20*stack%3B%0A%20%20%20%20while%20%28current%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20tmp%20%3D%20current-%3Enext%3B%0A%20%20%20%20%20%20%20%20free%28current%29%3B%0A%20%20%20%20%20%20%20%20current%20%3D%20tmp%3B%0A%20%20%20%20%7D%0A%20%20%20%20*stack%20%3D%20NULL%3B%0A%7D%0A%0Avoid%20%20%20%20ft_error_free%28t_stack_node%20**a,%20char%20**argv%29%0A%7B%0A%20%20%20%20ft_free_stack%28a%29%3B%0A%20%20%20%20ft_free_table%28argv%29%3B%0A%20%20%20%20write%282,%20%22Error%5Cn%22,%206%29%3B%0A%20%20%20%20exit%281%29%3B%0A%7D%0A%0Along%20%20%20%20ft_atol%28const%20char%20*str%29%0A%7B%0A%20%20%20%20int%20%20%20%20i%3B%0A%20%20%20%20int%20%20%20%20n%3B%0A%20%20%20%20int%20%20%20%20nb%3B%0A%20%20%20%20long%20%20%20%20v%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20n%20%3D%201%3B%0A%20%20%20%20nb%20%3D%200%3B%0A%20%20%20%20v%20%3D%200%3B%0A%20%20%20%20while%20%28str%5Bi%5D%20%3D%3D%2045%20%7C%7C%20str%5Bi%5D%20%3D%3D%2043%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20if%20%28str%5Bi%20%2B%201%5D%20%3D%3D%2045%20%7C%7C%20str%5Bi%20%2B%201%5D%20%3D%3D%2043%29%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20%280%29%3B%0A%20%20%20%20%20%20%20%20if%20%28str%5Bi%2B%2B%5D%20!%3D%2043%29%0A%20%20%20%20%20%20%20%20%20%20%20%20n%20%3D%20n%20*%20%28-1%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20while%20%28str%5Bi%5D%20%3E%2047%20%26%26%20str%5Bi%5D%20%3C%2058%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20nb%20%3D%20str%5Bi%2B%2B%5D%20-%20'0'%3B%0A%20%20%20%20%20%20%20%20v%20%3D%20v%20*%2010%20%2B%20nb%3B%0A%20%20%20%20%7D%0A%20%20%20%20v%20%3D%20v%20*%20n%3B%0A%20%20%20%20return%20%28v%29%3B%0A%7D%0A%0Avoid%20ft_stack_%28long%20n,%20t_stack_node%20**stack%29%0A%7B%0A%20%20%20%20t_stack_node%20*last_a%3B%0A%20%20%20%20t_stack_node%20*a%3B%0A%0A%20%20%20%20if%28stack%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%20%3B%0A%20%20%20%20a%20%3D%20malloc%28sizeof%28t_stack_node%29%29%3B%0A%20%20%20%20if%28a%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%20%3B%0A%20%20%20%20a-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20a-%3Enumber%3D%20n%3B%0A%20%20%20%20%20%20if%20%28*stack%20%3D%3D%20NULL%29%20//%20Poprawiono%20przypisanie%20na%20por%C3%B3wnanie%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20*stack%20%3D%20a%3B%0A%20%20%20%20%20%20%20%20a-%3Eprev%20%3D%20NULL%3B%0A%20%20%20%20%7D%0A%20%20%20%20else%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20t_stack_node%20*temp%20%3D%20*stack%3B%20//%20U%C5%BCycie%20tymczasowego%20wska%C5%BAnika%0A%20%20%20%20%20%20%20%20while%20%28temp-%3Enext%29%0A%20%20%20%20%20%20%20%20%20%20%20%20temp%20%3D%20temp-%3Enext%3B%0A%20%20%20%20%20%20%20%20last_a%20%3D%20temp%3B%0A%20%20%20%20%20%20%20%20last_a-%3Enext%20%3D%20a%3B%0A%20%20%20%20%20%20%20%20a-%3Eprev%20%3D%20last_a%3B%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20ft_stack_init%28t_stack_node%20**stack,%20char%20**argv%29%0A%7B%0A%20%20%20%20long%20n%3B%20%0A%20%20%20%20int%20i%3B%0A%20%20%20%20t_stack_node%20*node%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28argv%5Bi%5D%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20n%20%3D%20ft_atol%28argv%5Bi%5D%29%3B%0A%20%20%20%20%20%20%20%20ft_stack_%28n,%20stack%29%3B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20ft_error_free%28stack,%20argv%29%3B%0A%7D%0A%0Aint%20main%28%29%0A%7B%0A%20%20%20%20t_stack_node%20*a%3B%0A%20%20%20%20a%20%3D%20NULL%3B%0A%0A%20%20%20%20char%20*v%5B4%5D%20%3D%20%7Bv%5B0%5D%20%3D%20%22%5C0%22,%20v%5B1%5D%20%3D%20%2242%22,%20v%5B2%5D%20%3D%20%221337%22,%20v%5B3%5D%20%3D%20NULL%7D%3B%0A%20%20%20%20ft_stack_init%28%26a,%20v%20%2B%201%29%3B%0A%20%20%20%20while%28a%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20a%20%3D%20a%20-%3E%20next%3B%0A%20%20%20%20%7D%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
typedef struct s_stack_node
{  
    long                    number;
    struct s_stack_node     *target_node;  
    struct s_stack_node     *next;  
    struct s_stack_node     *prev;
} t_stack_node;


int ft_error_nbr(char *str)
{
    if (!(*str == '-' || (*str >= '0' && *str <= '9')))
        return (1);
    if (*str == '-' && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (*(++str))
    {
        if (!(*str >= '0' && *str <= '9'))
            return (1);
    }
    return (0);
}

void    ft_free_table(char **argv)
{
    int    i;

    i = 0;
    if (NULL == argv || NULL == *argv)
        return ;
    while (argv[i])
        free(argv[i++]);
    free(argv);
}

void    ft_free_stack(t_stack_node **stack)
{
    t_stack_node    *tmp;
    t_stack_node    *current;

    if (NULL == stack)
        return ;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void    ft_error_free(t_stack_node **a, char **argv)
{
    ft_free_stack(a);
    write(2, "Error\n", 6);
    exit(1);
}

void ft_stack_(long n, t_stack_node **stack)
{
    t_stack_node *last_a;
    t_stack_node *a;

    if(stack == NULL)
    a->number= n;
      if (*stack == NULL) // Poprawiono przypisanie na porównanie
    {
        *stack = a;
        a->prev = NULL;
    }
    else
    {
        t_stack_node *temp = *stack; // Użycie tymczasowego wskaźnika
        while (temp->next)
            temp = temp->next;
        last_a = temp;
        last_a->next = a;
        a->prev = last_a;
    }
}

void ft_stack_init(t_stack_node **stack, char **argv)
{
    long n; 
    int i;
    t_stack_node *node;

    i = 0;
    while (argv[i])
    {
        if (ft_error_nbr(argv[i]))
        {
            write(1, "No number only\0", 14);
            ft_error_free(stack, argv);
        }
        n = atol(argv[i]);
        ft_stack_(n, stack);
        i++;
    }
    ft_free_table(argv);
}

int main()
{
    t_stack_node *a = NULL;
    char **dynamic_argv;
    int i;

    // Alokowanie pamięci dla 4 wskaźników na łańcuchy znaków
    dynamic_argv = malloc(4 * sizeof(char *));

    // Alokowanie i przypisywanie wartości do dynamicznej tablicy
    dynamic_argv[0] = malloc(4 * sizeof(char)); // "42"
    dynamic_argv[1] = malloc(6 * sizeof(char)); // "1337"
    dynamic_argv[2] = malloc(5 * sizeof(char)); // "56"
    dynamic_argv[3] = NULL;

    strcpy(dynamic_argv[0], "42");
    strcpy(dynamic_argv[1], "1337");
    strcpy(dynamic_argv[2], "56");

    ft_stack_init(&a, dynamic_argv);
    return 0;
}



/*int main(int argc, char *argv[])
{
    t_stack_node *a = NULL;
    char **dynamic_argv;
    int i;

    if (argc < 2)
    {
        write(1, "Usage: ./program <number1> <number2> ...\n", 41);
        return 1;
    }

    dynamic_argv = malloc((argc) * sizeof(char *));
    if (dynamic_argv == NULL)
    {
        write(2, "Memory allocation failed\n", 25);
        return 1;
    }

    for (i = 1; i < argc; i++)
    {
        dynamic_argv[i - 1] = malloc((strlen(argv[i]) + 1) * sizeof(char));
        if (dynamic_argv[i - 1] == NULL)
        {
            write(2, "Memory allocation failed\n", 25);
            ft_free_table(dynamic_argv);
            return 1;
        }
        strcpy(dynamic_argv[i - 1], argv[i]);
    }
    dynamic_argv[argc - 1] = NULL;

    ft_stack_init(&a, dynamic_argv);

    // Wyświetlanie zawartości stosu
    while (a)
    {
        printf("%ld\n", a->number);
        a = a->next;
    }

    // Zwalnianie pamięci stosu
    ft_free_stack(&a);

    return 0;
}*/
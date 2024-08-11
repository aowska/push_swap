/*#include <stdio.h>
#include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{  
    long                    number;
    /*int                     position;
    int                     id;
    int                     costs;
    bool                    above_median;
    bool                    cheapest;
    struct s_stack_node     *target_node;  
    struct s_stack_node     *next;  
    struct s_stack_node     *prev;
}                           t_stack_node;


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
}

void ft_sb(t_stack_node **b)
{
    ft_swap(b);
}

void ft_ss(t_stack_node **a, t_stack_node **b)
{
    ft_swap(a);
    ft_swap(b);
}
int	check_atol(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	return (i);
}

long	ft_atol(const char *str)
{
	int	i;
	int	n;
	int	nb;
	long	v;

	i = 0;
	n = 1;
	nb = 0;
	v = 0;
	i = check_atol(str, i);
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i + 1] == 45 || str[i + 1] == 43)
			return (0);
		if (str[i++] != 43)
			n = n * (-1);
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = str[i++] - '0';
		v = v * 10 + nb;
	}
	v = v * n;
	return (v);
}


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

int ft_error_reapt(t_stack_node *node, long nbr)
{
	if (NULL == node)
		return (0);
	while (node)
	{
		if (node->number == nbr)
			return (1);
		node = node->next;
	}
	return (0);
}
void	ft_free_table(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

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

void	ft_error_free(t_stack_node **a, char **argv)
{
	ft_free_stack(a);
	ft_free_table(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void ft_stack(long n, t_stack_node **stack)
{
    t_stack_node *node;
    t_stack_node *last_node;

    node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!node)
    {
        return;
    }

    node->number = n;
    node->next = NULL;
    node->prev = NULL;

    if (*stack == NULL)
    {
        *stack = node;
    }
    else
    {
        last_node = *stack;
        while (last_node->next)
        {
            last_node = last_node->next;
        }
        
        last_node->next = node;
        node->prev = last_node;
    }
}

void ft_init_stack(t_stack_node **stack, char **argv)
{
    long n; 
    int i;

    i = 0;
    while (argv[i])
    {
        if (ft_error_nbr(argv[i]))
        {
            write(1, "No number only\0", 14);
            ft_error_free(stack, argv);
        }
        n = ft_atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            ft_error_free(stack, argv);
        if(ft_error_reapt(*stack, n))
            ft_error_free(stack, argv);
        ft_stack(n, stack);
        i++;
    }
}

int	ft_ile(char const *s, char c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!*s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

int    ft_ileword(char const *s, int *a, int *i, char c)
{
    while (s[*i] == c || s[*i] == '\0')
    {
        (*i)++;
        (*a)++;
    }
    while (s[*i] != c && s[*i] != '\0')
        (*i)++;
    return (*i - *a + 1);
}

char    **ft_split(char const *s, char c)
{
    char    **array;
    int        i;
    int        b;
    int        a;
    int        d;

    i = 0;
    b = 0;
    a = 0;
    d = 0;
	array = NULL;
    array = (char **)malloc((ft_ile(s, c) + 2) * sizeof(char *));
    if (!s || !array)
        return (0);
    while (s[b] != '\0')
    {
		if (a == 0)
		{
			array[a] = (char *)malloc((1) * sizeof(char));
			if(!array[a])
				return (NULL);
			array[a++][0] = '\0';
		}
        array[a] = (char *)malloc((ft_ileword(s, &b, &i, c)) * sizeof(char));
		if(!array[a])
				return (NULL);
        while (b < i)
            array[a][d++] = s[b++];
        array[a][d] = '\0';
        a++;
        d = 0;
    }
    array[a] = NULL;
    return (array);
}

int main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    int i = 1;

    if(argc == 1 || (argc == 2 && !argv[1][0])) // Jeden argument lub dwa, ale drugi pusty
        return (1);
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    ft_init_stack(&a, argv + 1);
    ft_sa(&a);

    // Dodanie printf dla wartości `number` w stosie `a`
    t_stack_node *current = a;
    while (current != NULL) {
        printf("Wartość number: %ld\n", current->number);
        current = current->next;
    }

    /*if(!ft_stack_sorted(a))
    {
        if(ft_stack_len(a) == 2)
            ft_sa(&a);
        else if (ft_stack_len(a) == 3)
            ft_sort_three(&a);
        else
            ft_sort_stacks(&a, &b);
    }
    ft_free_stack(&a);
   
    // Wyświetlanie argumentów programu
    printf("Liczba argumentów: %i\n", argc);
    while (argv[i] != NULL) {
        printf("Argument %d: %s\n", i, argv[i]);
        i++;
    }
    
    write(1, "0\0", 1);
    return(0);
}
*/
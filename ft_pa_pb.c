# include "./push_swap.h"

void ft_push(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *temp;

    if (*a == NULL)
        return;
    
    temp = *a;
    
    (*a) = (*a)->next;
    if (*a != NULL)
        (*a)->prev = NULL;
    temp->next = *b;
    if (temp->next != NULL)
        temp->next->prev = temp;
    *b = temp;
}

void ft_pb(t_stack_node **a, t_stack_node **b)
{
    ft_push(a, b);
      write(1, "pb\n", 3);
}

void ft_pa(t_stack_node **a, t_stack_node **b)
{
    ft_push(b, a);
      write(1, "pa\n", 3);
}

/*
// Funkcja tworząca nowy węzeł stosu
t_stack_node *new_node(long value)
{
    t_stack_node *node = (t_stack_node*)malloc(sizeof(t_stack_node));
    node->number = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Funkcja drukująca stos
void print_stack(t_stack_node *stack)
{
    while (stack)
    {
        printf("%ld ", stack->number);
        stack = stack->next;
    }
    printf("\n");
}

int main()
{
    // Tworzenie stosu A
    t_stack_node *a = new_node(3);
    a->next = new_node(2);
    a->next->prev = a;
    a->next->next = new_node(1);
    a->next->next->prev = a->next;
    
    // Pusty stos B
    t_stack_node *b = NULL;
    
    // Drukowanie początkowych stosów
    printf("Stos A: ");
    print_stack(a);
    printf("Stos B: ");
    print_stack(b);
    
    // Przenoszenie elementu ze stosu A do B
    ft_pb(&a, &b);
    
    // Drukowanie wynikowych stosów
    printf("\nPo przeniesieniu elementu ze stosu A do B:\n");
    printf("Stos A: ");
    print_stack(a);
    printf("Stos B: ");
    print_stack(b);
    
    return 0;
}*/
#include "push_swap.h"
#include <stdio.h>

int is_sorted(t_stack_node **stack)
{
    t_stack_node *head;

    head = *stack;
    while (head && head->next)
    {
        if (head->value > head->next->value)
        {
            return (0); // No está ordenado
        }
        head = head->next;
    }
    return (1); // Está ordenado
}

int main(int ac, char **av)
{
    t_stack_node **a;
    t_stack_node **b;


    if (ac < 2)
        return (-1); // No hay nada que ordenar
    check_all(ac, av); // Verificación de entrad
    if (!initialize_stacks(&a, &b))
        return (1); // Error al inicializar las pilas
    reading_input_to_stack(a, ac, av); // Cargar la entrada en las pilas
    assign_indices(a);
    if (is_sorted(a))
        return (0); 
    int size = ft_lstsize(*a);
    if (size <= 4)
        sort_short(a, b);
    else
        radix_sort(a, b);
    free(a);
    free(b); // Depuración
    return (0);
}


#include "push_swap.h"

void reading_input_to_stack(t_stack_node **a, int ac, char **av)
{
    int i;
    t_stack_node *new;

    i = 1;
    while(i < ac)
    {
        new = ft_lstnew(ft_atoi(av[i]));
        ft_lstadd_back(a, new);
        i++;
    }
}

   int	initialize_stacks(t_stack_node ***a, t_stack_node ***b)
{
	*a = malloc(sizeof(t_stack_node *));
	if (!a)
		return (0);
	*b = malloc(sizeof(t_stack_node *));
	if (!b)
	{
		free(a);
		return (0);
	}
	**a = NULL;
	**b = NULL;
	return (1);
}

static void insertion_sort(int *values, int size)
{
    int i, j, key;

    for (i = 1; i < size; i++)
    {
        key = values[i];
        j = i - 1;

        // Mover elementos mayores que `key` hacia adelante
        while (j >= 0 && values[j] > key)
        {
            values[j + 1] = values[j];
            j--;
        }
        values[j + 1] = key;
    }
}

void assign_indices(t_stack_node **stack)
{
    t_stack_node *current;
    int size = ft_lstsize(*stack);
    int *values;
    int i;

    // Reservar memoria para almacenar los valores
    values = malloc(size * sizeof(int));
    if (!values)
        return; // Manejo básico de errores

    // Copiar los valores de la pila al array
    current = *stack;
    for (i = 0; current; i++, current = current->next)
        values[i] = current->value;

    // Ordenar el array usando Insertion Sort
    insertion_sort(values, size);

    // Asignar índices a los nodos basados en el array ordenado
    current = *stack;
    while (current)
    {
        for (i = 0; i < size; i++)
        {
            if (current->value == values[i])
            {
                current->index = i;
                break;
            }
        }
        current = current->next;
    }

    // Liberar memoria del array temporal
    free(values);
}

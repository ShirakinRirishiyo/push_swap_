
#include "push_swap.h"

void	reading_input_to_stack(t_stack_node **a, int ac, char **av)
{
	int	i;
	t_stack_node	*new;

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
    i = 1;
    while (i < size)
    {
        key = values[i];
        j = i - 1;
        while (j >= 0 && values[j] > key)
        {
            values[j + 1] = values[j]; // Corregido: Mover el valor mayor
            j--;
        }
        values[j + 1] = key;
        i++;
    }
}

int	*get_sorted_values(t_stack_node *stack, int size)
{
	int	*values;
	int	i;
	t_stack_node *current;

	values = malloc(size * sizeof(int));
	if (!values)
		return (NULL);
	current = stack;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	insertion_sort(values, size);
	return (values);
}
void assign_indices(t_stack_node **stack)
{
    t_stack_node *current;
    int size;
    int *values;
    int i;

    if (!stack || !*stack || (size = ft_lstsize(*stack)) == 0) return;
    if (!(values = get_sorted_values(*stack, size))) return;

    current = *stack;
    while (current)
    {
        i = 0;
        while (i < size)
        {
            if (current->value == values[i])
            {
                current->index = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
    free(values);
}


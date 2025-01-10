#include "push_swap.h"


int numbercmp(int nbr, int *number, int size)
{
	int i;

	if(!number || size < 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (number[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int	find_max_pb(int size)
{
	if (size == 1)
		return (1);
	else if (size % 2 == 0)
		return (size / 2);
	else
		return ((size / 2) + 1);
}

int find_median(t_stack_node *stack, int size)
{
    int *values;
    int median;
    int i;

    if (!stack || size <= 0)
        return (0);

    values = malloc(sizeof(int) * size);
    if (!values)
        return (0);

    i = 0;
    while (i < size) {
        values[i] = stack->value;
        stack = stack->next;
        i++;
    }

    quick_sort(values, 0, size - 1);
    median = values[size / 2];
    free(values);
    return (median);
}


int free_stack(t_stack_node **stack)
{
	t_stack_node *tmp;

	if (!stack || !*stack)
		return (0);
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	return (1);
}


int is_sorted(t_stack_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;  // No está ordenada
        stack = stack->next;
    }
    return 1;  // Está ordenada
}


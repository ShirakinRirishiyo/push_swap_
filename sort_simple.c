#include "push_swap.h"


void sort_3(t_stack_node **a)
{
    int top = (*a)->value;
    int mid = (*a)->next->value;
    int bottom = (*a)->next->next->value;

    if (top > mid && top > bottom)
    {
        rotate_a(a); // Mueve el mayor al final
        if ((*a)->value > (*a)->next->value)
            swap_a(*a); // Asegura el orden entre los dos primeros
    }
    else if (mid > top && mid > bottom)
    {
        rev_rotate_a(a); 
        write(1, "\n", 1);// Mueve el mayor al inicio
        if ((*a)->value > (*a)->next->value)
            swap_a(*a); // Asegura el orden entre los dos primeros
    }
    else if (bottom > top && bottom > mid)
    {
        if ((*a)->value > (*a)->next->value)
            swap_a(*a); // Asegura el orden entre los dos primeros
    }
}

void sort_short(t_stack_node **a, t_stack_node **b)
{
	int size;
	size = ft_lstsize(*a);
	if(size == 2)
		swap_a(*a);
	if(size == 3)
		sort_3(a);
    if(size == 4)
        sort_4(a, b);
}

void	sort_4(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*current;
	int		min;
	int		index;
	// Paso 1: Encontrar el valor mínimo y su posición
	current = *stack_a;
	min = current->value;
	index = 0;
	int min_index = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	if (min_index <= 2) // Más cerca del tope
	{
		while (min_index-- > 0)
			rotate_a(stack_a);
	}
	else // Más cerca del final
	{
		while (min_index++ < 4)
			rev_rotate_a(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}


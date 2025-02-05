#include "push_swap.h"

static int	get_max_bits(t_stack_node **stack)
{
	t_stack_node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		int original_size = size; // Guardamos el tamaño original
		while (j < original_size) // No modificar "size" en medio del bucle
		{
			t_stack_node *head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)  // Si el bit actual es 1
				rotate_a(stack_a); // Mantener en A
			else
				pb(stack_a, stack_b); // Mover a B
			j++;
		}	// Asegurar que `pa()` devuelve elementos en el orden correcto
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

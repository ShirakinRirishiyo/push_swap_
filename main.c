#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_stack_node **stack)
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
	return (1);
}


int 	main(int ac, char **av)
{
	t_stack_node	**a;
    	t_stack_node	**b;

	if (ac < 2)
        	return (-1);
	check_all(ac, av); 
	if (!initialize_stacks(&a, &b))
		return (1);
	reading_input_to_stack(a, ac, av);
	assign_indices(a);
	if (is_sorted(a))
		return (0);
	int size = ft_lstsize(*a);
	if (size <= 4)
		sort_short(a, b);
	else
        radix_sort(a, b);
    free(a);
    free(b);
    return (0);
}

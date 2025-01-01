#include "push_swap.h"

int	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *temp;

	if(*b)
	{
		if((*b)->next)
			temp = (*b)->next;
		else
			temp = NULL;
		(*b)->next = *a;
		*a = *b;
		*b = temp;
		write(1, "pa\n", 3);
	}
	return (1);
}
int pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *temp;
	if(*a)
	{
		if((*a)->next)
			temp = (*a)->next;
		else 
			temp = NULL;
		(*a)->next = *b;
		*b = *a;
		*a = temp;
		write(1, "pb\n", 3);
	}
	return (1);
}



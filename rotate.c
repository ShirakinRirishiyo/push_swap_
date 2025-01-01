#include "push_swap.h"

static void rotate(t_stack_node **stack)
{
	t_stack_node *first;
	t_stack_node *temp;

	if(*stack && (*stack)->next)
	{
		first = *stack;
		*stack = (*stack)->next;
		temp = *stack;
		while(temp->next)
			temp = temp->next;
		temp->next = first;
		first->next = NULL;
		free(temp);
	}
}

int rotate_a(t_stack_node **s_a)
{
	rotate(s_a);
	write(1, "ra\n", 3);
	return (1);
}

int rotate_b(t_stack_node **s_b)
{
	rotate(s_b);
	write(1, "rb\n", 3);
	return (1);
}

int rotate_ab(t_stack_node **s_a, t_stack_node **s_b)
{
	rotate(s_a);
	rotate(s_b);
	write(1, "rr\n", 3);
	return (1);
}


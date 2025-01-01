#include "push_swap.h"

static void rev_rotate(t_stack_node **stack)
{
	t_stack_node *first;
	t_stack_node *temp;

	if(*stack && (*stack)->next)
	{
		first = *stack;
		temp = *stack;
		while(temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(stack, first);
	}
}

int rev_rotate_a(t_stack_node **s_a)
{
	rev_rotate(s_a);
	write(1, "rra\n", 3);
	return (1);
}

int rev_rotate_b(t_stack_node **s_b)
{
	rev_rotate(s_b);
	write(1, "rrb\n", 4);
	return (1);
}

int rev_rotate_ab(t_stack_node **s_a, t_stack_node **s_b)
{
	rev_rotate(s_a);
	rev_rotate(s_b);
	write(1, "rrr\n", 4);
	return (1);
}
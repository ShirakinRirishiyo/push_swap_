#include "push_swap.h"


int	push(t_stack_node **s_to, t_stack_node **s_from)
{
	t_stack_node	*tmp;
	t_stack_node	*head_to;
	t_stack_node	*head_from;

	if (ft_lstsize(*s_from) == 0)
		return (-1);
	head_to = *s_to;
	head_from = *s_from;
	tmp = head_from;
	head_from = head_from->next;
	*s_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*s_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*s_to = tmp;
	}
	return (0);
}

int	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}


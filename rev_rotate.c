/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:46:02 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/02/09 14:46:33 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

int	rev_rotate_a(t_stack_node **s_a)
{
	rev_rotate(s_a);
	write(1, "rra\n", 3);
	return (1);
}

int	rev_rotate_b(t_stack_node **s_b)
{
	rev_rotate(s_b);
	write(1, "rrb\n", 4);
	return (1);
}

int	rev_rotate_ab(t_stack_node **s_a, t_stack_node **s_b)
{
	rev_rotate(s_a);
	rev_rotate(s_b);
	write(1, "rrr\n", 4);
	return (1);
}

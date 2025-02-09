/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:59:08 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/02/09 15:00:05 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

int	rotate_a(t_stack_node **s_a)
{
	rotate(s_a);
	write(1, "ra\n", 3);
	return (1);
}

int	rotate_b(t_stack_node **s_b)
{
	rotate(s_b);
	write(1, "rb\n", 3);
	return (1);
}

int	rotate_ab(t_stack_node **s_a, t_stack_node **s_b)
{
	rotate(s_a);
	rotate(s_b);
	write(1, "rr\n", 3);
	return (1);
}

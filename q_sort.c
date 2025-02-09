/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:28:13 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/02/09 11:34:58 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack_node **stack)
{
	t_stack_node	*head;
	int				max;
	int				max_bits;

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
	t_variable	var;
	int			i;
	int			j;

	var.size = ft_lstsize(*stack_a);
	var.max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < var.max_bits)
	{
		var.original_size = var.size;
		j = 0;
		while (j < var.original_size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

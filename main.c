/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:37:19 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/02/05 11:38:19 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node **stack)
{
	t_stack_node	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack_node		**a;
	t_stack_node		**b;
	int					size;

	if (ac < 2)
		return (-1);
	check_all(ac, av);
	if (!initialize_stacks(&a, &b))
		return (1);
	reading_input_to_stack(a, ac, av);
	assign_indices(a);
	if (is_sorted(a))
		return (0);
	size = ft_lstsize(*a);
	if (size <= 4)
		sort_short(a, b);
	else
		radix_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

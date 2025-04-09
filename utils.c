/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:27:16 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/03/31 20:47:44 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numbercmp(int nbr, int *number, int size)
{
	int	i;

	if (!number || size < 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (number[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int	initialize_stacks(t_stack_node ***a, t_stack_node ***b)
{
	*a = malloc(sizeof(t_stack_node *));
	if (!*a)
		return (0);
	*b = malloc(sizeof(t_stack_node *));
	if (!*b)
	{
		free(*a);
		return (0);
	}
	**a = NULL;
	**b = NULL;
	return (1);
}

int	find_max_pb(int size)
{
	if (size == 1)
		return (1);
	else if (size % 2 == 0)
		return (size / 2);
	else
		return ((size / 2) + 1);
}

int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !*stack)
		return (0);
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	return (1);
}

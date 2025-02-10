/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:40 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/02/10 13:12:29 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reading_input_to_stack(t_stack_node **a, int ac, char **av)
{
	if (ac == 2)
		reading_auxiliar(a, av[1]);
	else
		reading_normal(a, ac, av);
}

static void	insertion_sort(int *values, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = values[i];
		j = i - 1;
		while (j >= 0 && values[j] > key)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = key;
		i++;
	}
}

int	*get_sorted_values(t_stack_node *stack, int size)
{
	int					*values;
	int					i;
	t_stack_node		*current;

	values = malloc(size * sizeof(int));
	if (!values)
		return (NULL);
	current = stack;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	insertion_sort(values, size);
	return (values);
}

static void	assign_index(t_stack_node *node, int *values, int i, int size)
{
	if (i >= size)
		return ;
	if (node->value == values[i])
	{
		node->index = i;
		return ;
	}
	assign_index(node, values, i + 1, size);
}

void	assign_indices(t_stack_node **stack)
{
	t_stack_node	*current;
	int				size;
	int				*values;

	if (!stack || !*stack)
		return ;
	size = ft_lstsize(*stack);
	if (size == 0)
		return ;
	values = get_sorted_values(*stack, size);
	if (!values)
		return ;
	current = *stack;
	while (current)
	{
		assign_index(current, values, 0, size);
		current = current->next;
	}
	free(values);
}

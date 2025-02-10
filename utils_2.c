/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:44:18 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/02/10 13:18:49 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int	error_handle(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

void	reading_auxiliar(t_stack_node **a, char *av)
{
	t_stack_node	*new;
	char			**numbers;
	int				j;

	numbers = ft_split(av, ' ');
	if (!numbers)
		return ;
	j = 0;
	while (numbers[j])
	{
		new = ft_lstnew(ft_atoi(numbers[j]));
		ft_lstadd_back(a, new);
		j++;
	}
	ft_free(numbers);
}

void	reading_normal(t_stack_node **a, int ac, char **av)
{
	t_stack_node	*new;
	int				i;

	i = 1;
	while (i < ac)
	{
		new = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(a, new);
		i++;
	}
}

t_stack_node	*find_smallest(t_stack_node **stack) //esta aquí por si acaso
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if ((*stack)->value < smallest)
		{
			smallest = (*stack)->value;
			smallest_node = *stack;
		}
		stack = &(*stack)->next;
	}
	return (smallest_node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:13:38 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/03/31 20:48:16 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include "././libft/libft.h"

typedef struct s_variable
{
	int		size;
	int		max_bits;
	int		original_size;
}			t_variable;

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	int					index;
	struct s_stack_node	*prev;
	int					content;
}				t_stack_node;

void			assign_indices(t_stack_node **stack);
void			sort_3(t_stack_node **a);
int				check_duplicate(char **argv);
int				check_number(char *argv);
void			check_all(int argc, char **argv);
int				count_arg(char **array);
void			reading_normal(t_stack_node **a, int ac, char **av);
void			reading_auxiliar(t_stack_node **a, char *av);
void			sort_4(t_stack_node **stack_a, t_stack_node **stack_b);
void			reading_input_to_stack(t_stack_node **a, int ac, char **av);
int				initialize_stacks(t_stack_node ***a, t_stack_node ***b);
void			check_all(int ac, char **av);
int				ft_lstsize(t_stack_node *head);
void			radix_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void			ft_lstadd_back(t_stack_node **stack, t_stack_node *new);
void			ft_lstadd_front(t_stack_node **stack, t_stack_node *new);
void			ft_free(char **str);
int				pb(t_stack_node **a, t_stack_node **b);
int				pa(t_stack_node **a, t_stack_node **b);
int				push(t_stack_node **s_to, t_stack_node **s_from);
int				is_sorted(t_stack_node **stack);
void			sort_short(t_stack_node **a, t_stack_node **b);
int				numbercmp(int nbr, int *number, int size);
int				free_stack(t_stack_node **stack);
int				find_max_pb(int size);
int				error_handle(char *str);
int				rev_rotate_a(t_stack_node **s_a);
int				rev_rotate_b(t_stack_node **s_b);
int				rev_rotate_ab(t_stack_node **s_a, t_stack_node **s_b);
int				rotate_a(t_stack_node **s_a);
int				rotate_b(t_stack_node **s_b);
int				rotate_ab(t_stack_node **s_a, t_stack_node **s_b);
int				swap_a(t_stack_node *s_a);
int				swap_b(t_stack_node *s_b);
int				free_stack(t_stack_node **stack);
int				swap_ab(t_stack_node *s_a, t_stack_node *s_b);
t_stack_node	*ft_lstlast(t_stack_node *head);
t_stack_node	*ft_lstnew(int value);

#endif


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include "././libft/libft.h"

typedef struct s_stack_node
{
	int value;
	int index;
	int data;
	int content;
	struct s_stack_node *next;
	struct s_stack_node *prev;
	void *context;
	int current_position;
} t_stack_node;



void quick_sort_a(t_stack_node **a, t_stack_node **b, int size);
void quick_sort_b(t_stack_node **a, t_stack_node **b, int size);
void recursive_call(t_stack_node **a, t_stack_node **b, int size, int is_a);
void sort_a_top2(t_stack_node **a);
void sort_b_top2(t_stack_node **b);
void sort_a_top3(t_stack_node **a);
void sort_b_top3(t_stack_node **b);
void print_list(t_stack_node *head);
void check_all(int ac, char **av);
void reading_input(t_stack_node **a, int ac, char **av);
int ft_lstsize(t_stack_node *head);
void	index_stack(t_stack_node **stack);
 t_stack_node	*get_next_min(t_stack_node **stack);
void ft_lstadd_back(t_stack_node **stack, t_stack_node *new);
t_stack_node	*ft_lstlast(t_stack_node *head);
int is_sorted(t_stack_node *stack);
t_stack_node *ft_lstnew(int value);
void ft_lstadd_front(t_stack_node **stack, t_stack_node *new);
void stack_init(t_stack_node **stack, int argc, char **argv);
int check_duplicates(int ac, char **av);
int check_intergers(int ac, char **av);
int check_size_int(int ac, char **av);
int numbercmp(int nbr, int *number, int size);
int free_stack(t_stack_node **stack);
int find_max_pb(int size);
int error_handle(char *str);
int find_median(t_stack_node *stack, int size);
void quick_sort(int *arr, int left, int right);
int rev_rotate_a(t_stack_node **s_a);
int rev_rotate_b(t_stack_node **s_b);
int rev_rotate_ab(t_stack_node **s_a, t_stack_node **s_b);
int rotate_a(t_stack_node **s_a);
int rotate_b(t_stack_node **s_b);
int rotate_ab(t_stack_node **s_a, t_stack_node **s_b);
int swap_a(t_stack_node *s_a);
int swap_b(t_stack_node *s_b);
void	ft_free(char **str);
int swap_ab(t_stack_node *s_a, t_stack_node *s_b);
int pa(t_stack_node **a, t_stack_node **b);
int pb(t_stack_node **a, t_stack_node **b);


#endif
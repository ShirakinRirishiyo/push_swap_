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
int error_handle(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void	print_stack_node(t_stack_node *head)
{
	t_stack_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
t_stack_node *find_smallest(t_stack_node **stack) //la dejaremos por si acaso
{
	long smallest;
	t_stack_node *smallest_node;

	if(NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while(stack)
	{
		if((*stack)->value < smallest)
		{
			smallest = (*stack)->value;
			smallest_node = *stack;
		}
		stack = &(*stack)->next;
	}
	return (smallest_node);
}
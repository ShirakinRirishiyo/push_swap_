 #include "push_swap.h"
 
 
 t_stack_node	*get_next_min(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

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
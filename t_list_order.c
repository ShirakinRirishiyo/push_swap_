#include "push_swap.h"


// Creates new node and returns the pointer of it
t_stack_node *ft_lstnew(int value)
{
	t_stack_node	*new;

	new = (t_stack_node *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

// Adds the specified node to a stack (list) making it the head
void	ft_lstadd_front(t_stack_node **stack, t_stack_node *new)
{
	new->next = *stack;
	*stack = new;
}

// Returns the last node of a list 
t_stack_node *ft_lstlast(t_stack_node *head)
{
    t_stack_node *tmp;

    tmp = head;
    // Avanzamos hasta llegar al último nodo, cuyo 'next' es NULL
    while (tmp && tmp->next)
    {
        tmp = tmp->next;
    }
    return (tmp);  // Devolvemos el último nodo
}


// Adds the specified node to a stack (list) making it the last node
void	ft_lstadd_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}


// Returns the size of the Linked List
int	ft_lstsize(t_stack_node *head)
{
	size_t	i;
	t_stack_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// Prints the Linked List

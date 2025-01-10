
#include "push_swap.h"

static void rev_rotate(t_stack_node **stack)
{
    t_stack_node *last;
    t_stack_node *temp;

    if (*stack && (*stack)->next)
    {
        temp = *stack;
        while (temp->next->next) // Encuentra el penúltimo nodo
            temp = temp->next;
        
        last = temp->next;      // Apunta al último nodo
        temp->next = NULL;      // Desconecta el último nodo
        last->next = *stack;    // Conecta el último nodo al inicio de la pila
        *stack = last;          // Actualiza el puntero de la pila
    }
}


int rev_rotate_a(t_stack_node **s_a)
{
	rev_rotate(s_a);
	write(1, "rra\n", 3);
	return (1);
}

int rev_rotate_b(t_stack_node **s_b)
{
	rev_rotate(s_b);
	write(1, "rrb\n", 4);
	return (1);
}

int rev_rotate_ab(t_stack_node **s_a, t_stack_node **s_b)
{
	rev_rotate(s_a);
	rev_rotate(s_b);
	write(1, "rrr\n", 4);
	return (1);
}
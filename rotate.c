#include "push_swap.h"

static void rotate(t_stack_node **stack)
{
    t_stack_node *first;
    t_stack_node *last;

    // Verifica que la lista tenga al menos dos nodos
    if (!(*stack) || !(*stack)->next)
        return;

    first = *stack;          // Guarda el nodo inicial
    *stack = (*stack)->next; // Mueve el inicio al segundo nodo
    (*stack)->prev = NULL;   // Elimina la referencia al nodo anterior

    // Encuentra el último nodo
    last = *stack;
    while (last->next)
        last = last->next;

    // Conecta el primer nodo al final
    last->next = first;
    first->prev = last;      // Actualiza el puntero prev del primer nodo
    first->next = NULL;      // Elimina la referencia al siguiente nodo
}

int rotate_a(t_stack_node **s_a)
{
	rotate(s_a);
	write(1, "ra\n", 3);
	return (1);
}

int rotate_b(t_stack_node **s_b)
{
	rotate(s_b);
	write(1, "rb\n", 3);
	return (1);
}

int rotate_ab(t_stack_node **s_a, t_stack_node **s_b)
{
	rotate(s_a);
	rotate(s_b);
	write(1, "rr\n", 3);
	return (1);
}


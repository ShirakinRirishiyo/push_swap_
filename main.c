#include "push_swap.h"


int main(int ac, char **av)
{
    t_stack_node **a;
    t_stack_node **b;

    if (ac < 2)
        return (-1);
    check_all(ac, av);
    a = (t_stack_node **)malloc(sizeof(t_stack_node *));
    b = (t_stack_node **)malloc(sizeof(t_stack_node *));
    if(!a || !b)
        return (-1);
    stack_init(a, ac, av);
    if (is_sorted(*a))
    {
        free_stack(a);
        free_stack(b);
        return (0);
    }
    recursive_call(a, b, ft_lstsize(*a), 1);
    free_stack(a);
    free_stack(b);
    return (0);
}


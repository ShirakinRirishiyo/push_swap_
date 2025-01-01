#include "push_swap.h"

void sort_a_top2(t_stack_node **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(*a);
}

void sort_b_top2(t_stack_node **b)
{
	if ((*b)->content < (*b)->next->content)
		swap_b(*b);
}

void sort_a_top3(t_stack_node **a)
{
	if ((*a)->content > (*a)->next->content && (*a)->content > (*a)->next->next->content)
	{
		rotate_a(a);
		swap_a(*a);
	}
	else if ((*a)->content > (*a)->next->content)
		rotate_a(a);
	else if ((*a)->content > (*a)->next->next->content)
		rev_rotate_a(a);
}

void sort_b_top3(t_stack_node **b)
{
	if ((*b)->content < (*b)->next->content && (*b)->content < (*b)->next->next->content)
	{
		rotate_b(b);
		swap_b(*b);
	}
	else if ((*b)->content < (*b)->next->content)
		rotate_b(b);
	else if ((*b)->content < (*b)->next->next->content)
		rev_rotate_b(b);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

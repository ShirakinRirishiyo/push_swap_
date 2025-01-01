#include "push_swap.h"

typedef struct s_struct {
    int data;
    struct s_struct *next;
} t_struct;

// Función recursiva para ordenar la pila
void recursive_call(t_stack_node **a, t_stack_node **b, int size, int is_a)
{
    if (size <= 3)
    {
        // Si hay 2 o 3 elementos, ordenamos de manera sencilla
        if (size == 2)
        {
            if (is_a)
                sort_a_top2(a);
            else
                sort_b_top2(b);
        }
        else if (size == 3)
        {
            if (is_a)
                sort_a_top3(a);
            else
                sort_b_top3(b);
        }
        return;
    }
    if (is_a)
        quick_sort_a(a, b, size);
    else
        quick_sort_b(a, b, size);
}

// Función de quicksort para la pila 'a'
void quick_sort_a(t_stack_node **a, t_stack_node **b, int size)
{
    int pivot;
    int pushed_to_b = 0;
    int i;

    // Calculamos la mediana para usarla como pivote
    pivot = find_median(*a, size);

    i = 0;
    while (i < size)
    {
        if ((*a)->content < pivot)
        {
            pb(a, b); // Mueve el elemento menor a B
            pushed_to_b++;
        }
        else
            rotate_a(a); // Rota la pila A para avanzar
        i++;
    }
    // Coloca de vuelta los elementos que movimos a B
    while (pushed_to_b--)
        pa(a, b);
    // Llamada recursiva para continuar ordenando
    recursive_call(a, b, size - pushed_to_b, 1);
}

// Función de quicksort para la pila 'b'
void quick_sort_b(t_stack_node **a, t_stack_node **b, int size)
{
    int pivot;
    int pushed_to_a = 0;
    int i;
    // Calculamos la mediana para usarla como pivote
    pivot = find_median(*b, size);

    i = 0;
    while (i < size)
    {
        if ((*b)->content >= pivot)
        {
            pa(a, b); // Mueve el elemento mayor o igual a A
            pushed_to_a++;
        }
        else
        {
            rotate_b(b); // Rota la pila B para avanzar
        }
        i++;
    }
    // Coloca de vuelta los elementos que movimos a A
    while (pushed_to_a--)
        pb(a, b);
  // Llamada recursiva para continuar ordenando
    recursive_call(a, b, size - pushed_to_a, 0);
}

void quick_sort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        while (i <= right && arr[i] < pivot) i++;
        while (j > left && arr[j] >= pivot) j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[j];
    arr[j] = pivot;

    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

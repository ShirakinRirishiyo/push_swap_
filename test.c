#include <stdio.h>
#include <stdlib.h>

typedef struct s_struct {
    int data;
    struct s_struct *next;
} t_struct;

t_struct *sort_list(t_struct **begin_list)
{
    int swap;
    t_struct *current;
    t_struct *prev;
    t_struct *next;

    if (!begin_list || !(*begin_list))
        return NULL;

    do {
        swap = 0;
        prev = NULL;
        current = *begin_list;

        while (current->next) {
            next = current->next;

            if (current->data > next->data) {
                swap = 1;

                // Swap the nodes
                if (prev) {
                    prev->next = next;
                } else {
                    *begin_list = next;
                }

                current->next = next->next;
                next->next = current;

                // Update pointers
                prev = next;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swap);

    return *begin_list;
}

int main()
{
    int stack_a[20] = {5, 4, 3, 2, 1, 10, 40, 25, 100};
    t_struct *begin_list = NULL;
    t_struct *tmp;
    int i;

    // Crear la lista enlazada a partir del arreglo
    for (i = 0; i < 10; i++) {
        tmp = malloc(sizeof(t_struct));
        tmp->data = stack_a[i];
        tmp->next = begin_list;
        begin_list = tmp;
    }

    // Ordenar la lista
    sort_list(&begin_list);

    // Imprimir la lista ordenada
    tmp = begin_list;
    while (tmp) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }

    // Liberar la memoria de la lista enlazada
    while (begin_list) {
        tmp = begin_list;
        begin_list = begin_list->next;
        free(tmp);
    }

    return 0;
}

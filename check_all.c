#include "push_swap.h"

// Función para verificar si un número ya está en el conjunto de elementos
static int ft_duplicated(long num, t_stack_node *set)
{
    t_stack_node *temp = set;
    while (temp)
    {
        if ((long)temp->content == num)
            return (1);  // Encontrado duplicado
        temp = temp->next;
    }
    return (0);  // No hay duplicado
}

// Función para verificar si un número es válido
static int ft_is_valid_number(char *num)
{
    int i = 0;

    if (num[0] == '-')  // Si el número empieza con signo negativo
        i++;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (0);  // Si contiene caracteres no numéricos
        i++;
    }
    return (1);
}

// Función para liberar la lista (sin usar 'del')
static void ft_lstclear(t_stack_node **lst)
{
    t_stack_node *temp;
    
    // Recorrer la lista y liberar cada nodo
    while (*lst)
    {
        temp = (*lst)->next;  // Guardar el siguiente nodo
        free(*lst);           // Liberar el nodo (no el contenido)
        *lst = temp;          // Avanzar al siguiente nodo
    }
    *lst = NULL;  // Asegurar que el puntero a la lista esté en NULL al final
}

// Función principal para verificar todos los argumentos
void check_all(int ac, char **av)
{
    int i;
    long tmp;
    char **args;
    t_stack_node *set = NULL;  // Conjunto para verificar duplicados

    i = 0;
    if (ac == 2)
        args = ft_split(av[1], ' ');  // Dividir si se pasa un solo argumento
    else
    {
        i = 1;
        args = av;
    }

    while (args[i])
    {
        if (!ft_is_valid_number(args[i]))  // Comprobamos si es un número válido
            error_handle("Error");

        tmp = ft_atoi(args[i]);

        if (ft_duplicated(tmp, set))  // Comprobamos si ya está en el conjunto
            error_handle("Error");

        if (tmp < -2147483648 || tmp > 2147483647)  // Verificamos si el número está en el rango válido
            error_handle("Error");

        // Añadimos el número al conjunto
        ft_lstadd_back(&set, ft_lstnew(tmp));  // Pasamos el valor directamente como un 'int'

        i++;
    }

    if (ac == 2)
        ft_free(args);  // Liberar la memoria si es necesario

    // Liberar el conjunto sin el parámetro 'del'
    ft_lstclear(&set);
}

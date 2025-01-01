//Tenemos dos stacks llamados a y b

// Un stack (Estructura de datos, se basa en Last in, First out)

// El stack a tiene numeros positivos y negativos / stack b empty

//el objetivo es ordenar de manera ascendente con las operaciones que se indican

//sa sb pa pb ra rb rr rrb rrr rra rrb

//La idea es que el ordenamiento funciona de manera dinamica.

//Necesitamos manejar dos arrays, e ir moviendo los valores de un lado a otro. 
//Podríamos crear una estructura o usar listas que supuestamente es mejor

Vamos a utilizar el qsort o el turk algoritmo uno de estos dos cual entendamos mejor
Por lo que podemos comprender
Necesitamos primero recrear el funcionamiento de las indicaciones
sa() sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.

sb() swap b: Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.

ss() swap a y swap b a la vez.

pa() push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.

pb() push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.

ra() rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.

rb()rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.

rr() ra y rb al mismo tiempo.

rra() reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

rrb() reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.

rrr() rra y rrb al mismo tiempo.


pseudo code:

Declara los punteros a dos datos structura/links list uno para stack a y otro para b
//set both pointer to NUll to avoid undefined behaviour and indicate were starting
con empty stacks
Handle input count errors, argument count must be 2 o more, and the second input must not be empty
Desarrolla los comandos como funciones y añade un printf al usarlas
//prueba el algoritmo de ordenacion qsort con numeros pequeños
// 
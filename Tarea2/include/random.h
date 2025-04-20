#include <stdlib.h>
#include <time.h>

/**     
 * @brief Inicializa el generador de números aleatorios utilizando la hora actual como semilla.
 * @return Nada (tipo void)
 * @note  Esta función debe ser llamada una vez antes de usar la función generate_random_between() para asegurar que los números aleatorios generados sean diferentes en cada ejecución del programa.
 * 
 */
void initialize_random() {
        srand(time(NULL));
}
/**     
 * @brief Intercambia los valores de dos enteros utilizando punteros en una función clasica de intercambio Swap.
 * @param a Puntero al primer entero.
 * @param b Puntero al segundo entero.
 * @return Nada (tipo void)
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


/**
 *  
 * @brief  Genera un número aleatorio entre min y max, asegurando que esté dentro del rango especificado.
 * @param min Valor mínimo del rango (inclusivo).
 * @param max Valor máximo del rango (inclusivo).
 * @return Un número entero aleatorio entre min y max, ambos incluidos. (tipo int)
 * @note   Esta función utiliza la función rand() de la biblioteca estándar de C para generar números aleatorios. La función srand() se utiliza para inicializar el generador de números aleatorios con una semilla basada en el tiempo actual, lo que garantiza que los números generados sean diferentes en cada ejecución del programa.
 */
int generate_random_between(int min, int max) {
        //realiza un swap si el min es mayor que el max con punteros
        if (min > max) {
            swap(&min, &max);
        }
        int rd_num = rand() % (max - min + 1) + min;
        if (rd_num < min || rd_num > max) {
            rd_num = (rd_num < min) ? min : max;
        }
        return rd_num;
}
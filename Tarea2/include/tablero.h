#ifndef TABLERO_H
#define TABLERO_H
//-----------------OBLIGATORIO -------------------------

/**
 * @brief Estructura del tablero del juego.
 * @param celdas Matriz 2D de elementos (puntero triple).
 * @param filas Número de filas del tablero.
 * @param columnas Número de columnas del tablero.
 */
typedef struct {
     void *** celdas; // Matriz 2D de elementos (puntero triple)
int filas;
int columnas;
} Tablero;

/**
 * @brief Inicializa el tablero con las estaciones y sus posiciones aleatorias. Sin el jugador.
 * @param tablero Puntero al tablero a inicializar.
 * @param filas Número de filas del tablero.
 * @param columnas Número de columnas del tablero.
 * @return Nada (tipo void)
 */
void inicializarTablero(Tablero* tablero , int filas , int columnas);

/**
 * @brief Muestra el tablero en la consola.
 * @param tablero Puntero al tablero a mostrar.
 * @return Nada (tipo void).
 */
void mostrarTablero(Tablero* tablero);

void actualizarCelda(Tablero* tablero , int x, int y, void* elemento);

/**
 * @brief Libera la memoria del tablero.
 * @param tablero Puntero al tablero a liberar.
 * @return Nada (tipo void).
 */
//-----------------OBLIGATORIO -------------------------

//-----------------EXTRA -------------------------
void liberarTablero(Tablero* tablero);
//-----------------EXTRA -------------------------
#endif // TABLERO_H
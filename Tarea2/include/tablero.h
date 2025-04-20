#ifndef TABLERO_H
#define TABLERO_H

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
void mostrarTablero(Tablero* tablero);
void actualizarCelda(Tablero* tablero , int x, int y, void* elemento);


void liberarTablero(Tablero* tablero);

#endif // TABLERO_H
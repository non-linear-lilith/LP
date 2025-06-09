#ifndef MAIN_H
#define MAIN_H

#include <tablero.h>
#include <inventario.h>
#include <acciones.h>
#include <random.h>
//-----------------OBLIGATORIO -------------------------

/**  
 * @brief Estructura principal del juego.
 * @param tablero Puntero al tablero del juego.
 * @param inventario Puntero a la lista de ingredientes del jugador.
 * @param pedidos Puntero a la lista de pedidos del juego.
 * @param turnos_restantes Turnos restantes para completar el juego.
 * @param dificultad Dificultad del juego (1, 2 o 3).
*/
typedef struct {
    Tablero* tablero; // Puntero al struct Tablero
    Ingrediente ** inventario; // Puntero a la lista de ingredientes
    Pedido* pedidos; // Puntero a la lista de pedidos
    int turnos_restantes; // Turnos restantes para completar el juego
    int dificultad; // Dificultad del juego (1, 2 o 3)
} Juego;

/**
 * @brief Estructura del jugador.
 * @param x Posicion X en el tablero.
 * @param y Posicion Y en el tablero.
 * @param en_llamas 1 si el jugador esta en llamas (por atravesar estacion incendiada), 0 si no.
 */
typedef struct {
    int x; // Posicion X en el tablero
    int y; // Posicion Y en el tablero
    int en_llamas; // 1 si el jugador esta en llamas (por atravesar estacion incendiada)
} Jugador;
//-----------------OBLIGATORIO -------------------------



//-----------------EXTRA -------------------------

/**
 * @brief Inicializa a el jugador en una posicion aleatoria dentro del tablero que no este ocupada por una estacion.
 * @param jugador Puntero al Jugador.
 * @param juego Puntero al Juego.
 * @return Nada (tipo void).
 * */
void inicializarJugador(Jugador* jugador, Juego* juego);
void moverJugador(Juego* juego, Jugador* jugador); //distancia es el total la que se mueve y direccion es la direccion a la que se mueve (0,1,2,3) (N^,E<,Sv,O>)
void liberarJugador(Jugador* jugador);
void mostrarJuego(Juego* juego,Jugador* jugador);
void inicializarJuego(Juego* juego, int dificultad, int turnos_max);
//-----------------EXTRA -------------------------

#endif // MAIN_H
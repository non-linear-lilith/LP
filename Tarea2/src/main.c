#include <main.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    Tablero tablero;
    Juego juego;
    char dificultad;
    int matrix_size;
    char num_pedidos;
    int num_turnos_max;
    printf("Selecciona la dificultad del juego (solo 1,2,3):\n");
    printf("1. Facil\n");
    printf("2. Medio\n");
    printf("3. Dificil\n");

    scanf("%c", &dificultad); // Lee la dificultad
    char dificultad_valida = '0';
    while ((dificultad_valida!='1')) {
        switch(dificultad) {
            case '1':
                printf("Dificultad Facil seleccionada.\n");
                dificultad_valida = '1';
                matrix_size = 5;
                num_pedidos = '3';
                num_turnos_max = 60;
                break;
            case '2':
                printf("Dificultad Medio seleccionada.\n");
                dificultad_valida = '1';
                matrix_size = 8;
                num_pedidos = '4';
                num_turnos_max = 50;
                break;
            case '3':
                printf("Dificultad Dificil seleccionada.\n");
                dificultad_valida = '1';
                matrix_size = 10;
                num_pedidos = '5';
                num_turnos_max = 45;
                break;
            default:
                printf("Dificultad no valida. Seleccione 1, 2 o 3.\n");
                scanf("%c", &dificultad); // Lee la dificultad nuevamente
                break;
        }
    }
    juego.dificultad = dificultad - '0';
    juego.turnos_restantes = num_turnos_max;

    inicializarTablero(&tablero, matrix_size, matrix_size); // Inicializa un tablero de 5x5
    mostrarTablero(&tablero); // Muestra el tablero inicial
    liberarTablero(&tablero); // Libera la memoria del tablero
    mostrarTablero(&tablero); // Muestra el tablero después de liberar
    printf("Tablero liberado correctamente.\n");
    return 0;
}
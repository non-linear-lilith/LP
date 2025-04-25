#include <main.h>
#include <stdio.h>
#include <stdlib.h>


void inicializarJugador(Jugador* jugador, Juego* juego){
    initialize_random();
    char flag = '0';
    int posx = 0;
    int posy = 0;
    jugador->en_llamas = 0; // Inicializa el estado del jugador
    while(flag != '1') {
        posx = generate_random_between(0, juego->tablero->filas - 1);
        posy = generate_random_between(0, juego->tablero->columnas - 1);
        if (juego->tablero->celdas[posx][posy] == NULL) { // Verifica si la celda está vacía
            jugador->x = posx;
            jugador->y = posy;
            flag = '1';
        }
    }
}

void mostrarJuego(Juego* juego, Jugador* jugador) {
    printf("Turnos restantes: %d\n", juego->turnos_restantes);
    printf("Dificultad: %d\n", juego->dificultad);
    printf("Posicion del jugador: (%d, %d)\n", jugador->x, jugador->y);
    printf("Estado del jugador: %s\n", (jugador->en_llamas) ? "En llamas" : "No en llamas");
    printf("Estado del tablero:\n");
    for(int i = 0; i < juego->tablero->filas; i++) {
        for(int j = 0; j < juego->tablero->columnas; j++) {
            if (jugador->x == i && jugador->y == j) {
                if (juego->tablero->celdas[i][j] != NULL) {
                    printf("V ");
                } else {
                    printf("O ");
                }
            } else if (juego->tablero->celdas[i][j] != NULL) {
                printf("%c ", ((Estacion*)juego->tablero->celdas[i][j])->simbolo);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void inicializarJuego(Juego* juego, int dificultad, int turnos_max) {
    juego->dificultad = dificultad;
    juego->turnos_restantes = turnos_max;
    juego->inventario = NULL;
}

int main() {
    Tablero tablero;
    Juego juego;
    Jugador jugador;
    char dificultad;
    int matrix_size;
    char num_pedidos;
    int num_turnos_max;
    printf("Selecciona la dificultad del juego (solo 1,2,3) o cerrar el juego (4):\n");
    printf("1. Facil  5x5\n");
    printf("2. Medio  8x8\n");
    printf("3. Dificil 10x10\n");
    printf("4. Salir\n");
    char dificultad_valida = '0';
    while ((dificultad_valida!='1')){
        scanf(" %c", &dificultad);
        switch(dificultad){
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
            case '4':
                printf("Saliendo del juego...\n");
                return 0; // Salir del juego
            default:
                printf("Dificultad no valida. Seleccione 1, 2 o 3.\n");
                break;
        }
    }
    inicializarTablero(&tablero, matrix_size, matrix_size); 
    juego.tablero = &tablero; 

    juego.dificultad = dificultad - '0';
    juego.turnos_restantes = num_turnos_max;
    //busca un lugar aleatorio vacio para el jugador en el tablero
    crearInventario(); // Inicializa el inventario
    juego.inventario = obtenerInventario(); // Asigna el inventario al juego

    inicializarJugador(&jugador, &juego); // Inicializa el jugador en la posición (0, 0)
    mostrarTablero(juego.tablero); // Muestra el tablero inicial
    printf("Jugador inicializado en la posicion (%d, %d)\n", jugador.x, jugador.y);
    mostrarJuego(&juego, &jugador); // Muestra el estado del juego
    verInventario(); // Muestra el inventario
    agregarIngrediente(1); // Agrega un ingrediente al inventario
    agregarIngrediente(2); // Agrega un ingrediente al inventario
    verInventario(); // Muestra el inventario
    cortar(g_inventario);
    //liberar memoria
    liberarTablero(juego.tablero); // Libera la memoria del tablero
    liberarInventario(); // Libera la memoria del inventario
    printf("Tablero liberado correctamente.\n");
    printf("Inventario liberado correctamente.\n");
    printf("Juego terminado.\n");

    return 0;
}
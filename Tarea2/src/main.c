#include <main.h>
#include <stdio.h>
#include <stdlib.h>

void moverJugador(Juego* juego, Jugador* jugador) {
    int distancia;
    char direccion;
    printf("ingrese la direccion a mover (w: Norte, d: Este, s: Sur, a: Oeste): ");
    scanf(" %c", &direccion);
    printf("Ingrese la distancia a mover: ");
    scanf("%d", &distancia);
    // Validar la dirección y la distancia
    if (direccion != 'w' && direccion != 'd' && direccion != 's' && direccion != 'a') {
        printf("Direccion no valida. Debe ser w, d, s o a.\n");
        return;
    }
    //gastar turnos
    juego->turnos_restantes= juego->turnos_restantes-1;
    // 0: Norte, 1: Este, 2: Sur, 3: Oeste
    int nueva_x = jugador->x;
    int nueva_y = jugador->y;

    switch (direccion) {
        case 'w': // Norte
            nueva_x -= distancia;
            break;
        case 'd': // Este
            nueva_y += distancia;
            break;
        case 's': // Sur
            nueva_x += distancia;
            break;
        case 'a': // Oeste
            nueva_y -= distancia;
            break;
        default:
            printf("Distancia no valida.\n");
            return;
    }

    if (nueva_x >= 0 && nueva_x < juego->tablero->filas && nueva_y >= 0 && nueva_y < juego->tablero->columnas) {
        jugador->x = nueva_x;
        jugador->y = nueva_y;
    } else {
        printf("Movimiento fuera de los limites del tablero.\n");
    }
}

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
/**
 * @brief Initializes a new game based on user-selected difficulty
 * @param tablero Pointer to the game board
 * @param juego Pointer to the game state
 * @param jugador Pointer to the player
 * @return 1 if successful, 0 if user chose to exit
 */
int iniciarJuego(Tablero* tablero, Juego* juego, Jugador* jugador) {
    char dificultad;
    int matrix_size;
    int num_pedidos;
    int num_turnos_max;
    
    printf("Selecciona la dificultad del juego (solo 1,2,3) o cerrar el juego (4):\n");
    printf("1. Facil  5x5\n");
    printf("2. Medio  8x8\n");
    printf("3. Dificil 10x10\n");
    printf("4. Salir\n");
    
    char dificultad_valida = '0';
    while ((dificultad_valida != '1')) {
        scanf(" %c", &dificultad);
        switch(dificultad) {
            case '1':
                printf("Dificultad Facil seleccionada.\n");
                dificultad_valida = '1';
                matrix_size = 5;
                num_pedidos = 3;
                num_turnos_max = 60;
                break;
            case '2':
                printf("Dificultad Medio seleccionada.\n");
                dificultad_valida = '1';
                matrix_size = 8;
                num_pedidos = 4;
                num_turnos_max = 50;
                break;
            case '3':
                printf("Dificultad Dificil seleccionada.\n");
                dificultad_valida = '1';
                matrix_size = 10;
                num_pedidos = 5;
                num_turnos_max = 45;
                break;
            case '4':
                printf("Saliendo del juego...\n");
                return 0; // Exit game
            default:
                printf("Dificultad no valida. Seleccione 1, 2 o 3.\n");
                break;
        }
        
    }
    
    inicializarTablero(tablero, matrix_size, matrix_size); 
    juego->tablero = tablero;
    juego->dificultad = dificultad - '0';
    juego->turnos_restantes = num_turnos_max;
    
    crearInventario();
    juego->inventario = obtenerInventario();
    
    inicializarJugador(jugador, juego);
    
    mostrarTablero(juego->tablero);
    printf("Jugador inicializado en la posicion (%d, %d)\n", jugador->x, jugador->y);
    mostrarJuego(juego, jugador);
    
    while (juego->turnos_restantes > 0) {
        mostrarJuego(juego, jugador);
        printf("Turnos restantes: %d\n", juego->turnos_restantes);
        printf("Selecciona una accion:\n");
        printf("1. Mover jugador\n");
        printf("2. Ver inventario\n");
        printf("3. Ejecutar acción de la estación\n");
        printf("4. Salir del juego\n");
        
        char accion;
        scanf(" %c", &accion);
        
        switch(accion) {
            case '1':
                moverJugador(juego, jugador);
                break;
            case '2':
                verInventario();
                break;
            case '3':
                //ejecutar accion del tablero de haber
                if(juego->tablero->celdas[jugador->x][jugador->y] != NULL) {
                    printf("accion: %c\n", ((Estacion*)juego->tablero->celdas[jugador->x][jugador->y])->simbolo);
                    ((Estacion*)juego->tablero->celdas[jugador->x][jugador->y])->accion(juego, jugador);
                } else {
                    printf("No hay estacion en la posicion actual.\n");
                }
                break;
            case '4':
                printf("Saliendo del juego...\n");
                return 0; 
            default:
                printf("Accion no valida.\n");
                break;
        }
        
        juego->turnos_restantes--;
    }

    
    
    printf("¡Se acabaron los turnos! Juego terminado.\n");
    return 1;
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
    
    // Start the game
    iniciarJuego(&tablero, &juego, &jugador);
    
    // Game loop would go here
    verInventario();
    agregarIngrediente(1);
    agregarIngrediente(2);
    verInventario();
    
    //cortar(&juego, &jugador);
    
    // Cleanup
    liberarTablero(juego.tablero);
    liberarInventario();
    printf("Tablero liberado correctamente.\n");
    printf("Inventario liberado correctamente.\n");
    printf("Juego terminado.\n");
    
    return 0;
}
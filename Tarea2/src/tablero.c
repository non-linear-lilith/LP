#include <tablero.h>
#include <stdio.h>

#include <random.h>
#include <acciones.h>
void actualizarCelda(Tablero* tablero , int x, int y, void* estacion){
    if (x >= 0 && x < tablero->filas && y >= 0 && y < tablero->columnas) {
        tablero->celdas[x][y] = estacion; // Actualizar la celda con el nuevo elemento
    } else {
        printf("Coordenadas fuera de rango.\n");
    }
}
void inicializarTablero(Tablero* tablero , int filas , int columnas){
    // Inicializar el tablero
    tablero->celdas = NULL; // Inicializar a NULL para evitar liberar memoria no asignada
    tablero->filas = 0;
    tablero->columnas = 0;
    // Reservar memoria para el tablero
    tablero->celdas = malloc(sizeof(Tablero));
    tablero->filas = filas;
    tablero->columnas = columnas;

    // Reservar memoria para las filas
    tablero->celdas = malloc(filas * sizeof(void*));
    if (tablero->celdas == NULL) {
        printf("Error al reservar memoria para el tablero.\n");
        return;
    }
    for (int i = 0; i < filas; i++) {
        // Reservar memoria para las columnas
        tablero->celdas[i] = malloc(columnas * sizeof(void*));
        for (int j = 0; j < columnas; j++) {
            tablero->celdas[i][j] = NULL; // Inicializar cada celda a NULL
        }
    }
    // Inicializar el generador de números aleatorios
    initialize_random();
    
    // Inicializar estaciones en el tablero
    // 1. Tabla de cortar
    int posx= generate_random_between(0, filas-1);
    int posy= generate_random_between(0, columnas-1);
    tablero->celdas[posx][posy] = malloc(sizeof(Estacion));
    ((Estacion*)tablero->celdas[posx][posy])->simbolo = 'T';
    //((Estacion*)tablero->celdas[posx][posy])->accion = cortar;
    ((Estacion*)tablero->celdas[posx][posy])->en_llamas = 0;
    ((Estacion*)tablero->celdas[posx][posy])->turnos_inhabilitada = 0;

    // 2. Almacen
    char flag= '0';
    while (flag=='0'){
        posx= generate_random_between(0, filas-1);
        posy= generate_random_between(0, columnas-1);
        if (tablero->celdas[posx][posy] == NULL) {
            tablero->celdas[posx][posy] = malloc(sizeof(Estacion));
            ((Estacion*)tablero->celdas[posx][posy])->simbolo = 'A';
            //((Estacion*)tablero->celdas[posx][posy])->accion = buscar_ingrediente;
            ((Estacion*)tablero->celdas[posx][posy])->en_llamas = 0;
            ((Estacion*)tablero->celdas[posx][posy])->turnos_inhabilitada = 0;
            flag='1';
        }
    }

    // 3. Cocina
    flag= '0';
    while (flag=='0'){
        posx= generate_random_between(0, filas-1);
        posy= generate_random_between(0, columnas-1);
        if (tablero->celdas[posx][posy] == NULL) {
            tablero->celdas[posx][posy] = malloc(sizeof(Estacion));
            ((Estacion*)tablero->celdas[posx][posy])->simbolo = 'C';
            //((Estacion*)tablero->celdas[posx][posy])->accion = cocinar;
            ((Estacion*)tablero->celdas[posx][posy])->en_llamas = 0;
            ((Estacion*)tablero->celdas[posx][posy])->turnos_inhabilitada = 0;
            flag='1';
        }
    }

    // 4. Extintor
    flag= '0';
    while (flag=='0'){
        posx= generate_random_between(0, filas-1);
        posy= generate_random_between(0, columnas-1);
        if (tablero->celdas[posx][posy] == NULL) {
            tablero->celdas[posx][posy] = malloc(sizeof(Estacion));
            ((Estacion*)tablero->celdas[posx][posy])->simbolo = 'E';
            //((Estacion*)tablero->celdas[posx][posy])->accion = apagar_incendio;
            ((Estacion*)tablero->celdas[posx][posy])->en_llamas = 0;
            ((Estacion*)tablero->celdas[posx][posy])->turnos_inhabilitada = 0;
            flag='1';
        }
    }
}

void mostrarTablero(Tablero* tablero){
    for (int i = 0; i < tablero->filas; i++) {
        for (int j = 0; j < tablero->columnas; j++) {
            if (tablero->celdas[i][j] != NULL) {
                // Mostrar el símbolo de la estación
                printf("%c ", ((Estacion*)tablero->celdas[i][j])->simbolo);
            } else {
                printf(". "); // Indica que la celda está vacía
            }
        }
        printf("\n");
    }
    
}

void liberarTablero(Tablero* tablero) {
    if (tablero == NULL || tablero->celdas == NULL) {
        return; // Nothing to free
    }
    
    // Liberar cada fila
    for (int i = 0; i < tablero->filas; i++) {
        if (tablero->celdas[i] != NULL) {
            // Liberar cada celda
            for (int j = 0; j < tablero->columnas; j++) {
                if (tablero->celdas[i][j] != NULL) {
                    free(tablero->celdas[i][j]); // Liberar la estación
                }
            }
            free(tablero->celdas[i]); // Liberar la fila
        }
    }
    free(tablero->celdas); // Liberar el puntero a filas
    tablero->celdas = NULL; // Evitar puntero colgante
    tablero->filas = 0; // Reiniciar filas
    tablero->columnas = 0; // Reiniciar columnas

    // Liberar el tablero en sí
    free(tablero); // Liberar el tablero
    tablero = NULL; // Evitar puntero colgante
}
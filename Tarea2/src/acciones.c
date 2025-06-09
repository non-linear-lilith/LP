#include <acciones.h>
#include <main.h>

void cortar(void* contexto_juego,void* contexto_jugador){
    Juego* juego = (Juego*) contexto_juego;
    Jugador* jugador = (Jugador*) contexto_jugador;
    int x =jugador->x;
    int y = jugador->y;
    Estacion* estacion = (Estacion*) juego->tablero->celdas[x][y];
    if (estacion->accion == cortar) {
        printf("Que ingredientes quieres cortar?\n");
        verInventario();
        int ingrediente_a_cortar;
        printf("Ingrese el numero del ingrediente a cortar: ");
        scanf("%d", &ingrediente_a_cortar);
        if (ingrediente_a_cortar >= 0 && ingrediente_a_cortar < MAX_INGREDIENTES) {
            if (juego->inventario[ingrediente_a_cortar] != NULL) {
                printf("Cortando %s...\n", juego->inventario[ingrediente_a_cortar]->nombre);
                printf("Al ingrediente %s le quedan %d turnos de corte.\n", juego->inventario[ingrediente_a_cortar]->nombre, juego->inventario[ingrediente_a_cortar]->turnos_corte);
                printf("Cuantos turnos quieres usar para cortar el ingrediente?\n"); 
                int turnos_a_usar;
                printf("Ingrese el numero de turnos a usar: ");
                scanf("%d", &turnos_a_usar);
                if (turnos_a_usar > 0 && turnos_a_usar <= juego->inventario[ingrediente_a_cortar]->turnos_corte) {
                    printf("Cortando %s durante %d turnos...\n", juego->inventario[ingrediente_a_cortar]->nombre, turnos_a_usar);
                    if(turnos_a_usar == 0){
                        printf("El Ingrediente Fue cortado exitosamente!\n");
                        juego->inventario[ingrediente_a_cortar]->estado = 1; // Cambia el estado del ingrediente a cortado
                    }

                } else {
                    printf("Número de turnos inválido.\n");
                }
            } else {
                printf("Ingrediente no encontrado en el inventario.\n");
            }
        } else {
            printf("Número de ingrediente inválido.\n");
        }

    } else {
        printf("No puedes cortar en esta estacion.\n");
    }
}

void buscar_ingrediente(void* contexto_juego,void* contexto_jugador){
    Juego* juego = (Juego*) contexto_juego;
    printf("Buscando ingredientes en el almacen y gastado un turno\n");
    juego->turnos_restantes--;
    printf("Se ha encontrado un ingrediente!\n");
    int num = generate_random_between(0, 8);
    printf("El ingrediente encontrado es: %s\n", obtenerNombreIngrediente(num));
    printf("¿Deseas agregarlo al inventario? (1: Si, 0: No)\n");
    int respuesta;
    scanf("%d", &respuesta);
    if (respuesta == 1) {
        agregarIngrediente(num);
        printf("Ingrediente agregado al inventario.\n");
    } else {
        printf("Ingrediente no agregado al inventario.\n");
    }
}


void cocinar(void* contexto_juego,void* contexto_jugador){
    Juego* juego = (Juego*) contexto_juego;
    Jugador* jugador = (Jugador*) contexto_jugador;
    int x =jugador->x;
    int y = jugador->y;
    Estacion* estacion = (Estacion*) juego->tablero->celdas[x][y];
    if (estacion->accion == cocinar) {
        printf("Cocinando...\n");
        printf("Al ingrediente le quedan %d turnos de coccion.\n", juego->inventario[0]->turnos_cocina_o_freir);
        printf("Cuantos turnos quieres usar para cocinar el ingrediente?\n"); 
        int turnos_a_usar;
        printf("Ingrese el numero de turnos a usar: ");
        scanf("%d", &turnos_a_usar);
        if (turnos_a_usar > 0 && turnos_a_usar <= juego->inventario[0]->turnos_cocina_o_freir) {
            printf("Cocinando durante %d turnos...\n", turnos_a_usar);
            // Actualizar el estado del ingrediente en el inventario
            juego->inventario[0]->turnos_cocina_o_freir -= turnos_a_usar;
            if (juego->inventario[0]->turnos_cocina_o_freir == 0) {
                printf("El ingrediente ha sido cocinado!\n");
                if()
            }
        } else {
            printf("Número de turnos inválido.\n");
        }
    } else {
        printf("No puedes cocinar en esta estacion.\n");
    }
}
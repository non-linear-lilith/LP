#include <inventario.h>

const int MAX_INGREDIENTES = 5;    // Maximo de ingredientes en el inventario pedido en el enunciado (5).
Ingrediente** g_inventario = NULL; // Inventario global que se inicializa en NULL.
char* obtenerNombreIngrediente(int cod_item) {
    switch (cod_item) {
        case 1: return "Papa";
        case 2: return "Pollo";
        case 3: return "Hamburguesa";
        case 4: return "Arroz";
        case 5: return "Pasta";
        case 6: return "Tomate";
        case 7: return "Lechuga";
        case 8: return "Pan";
        case 9: return "Extintor";
        default: return NULL;
    }
}
char* obtenerestadoIngrediente(int cod_estado) {
    switch (cod_estado) {
        case 0: return "Crudo";
        case 1: return "Cocido o Frito";
        case 2: return "Cortado";
        case 3: return "Cocido y Cortado";
        default: return NULL;
    }
}
void crearInventario() {
    // Si el inventario ya existe, se libera la memoria anteriormente asignada
    if (g_inventario != NULL) {
        for (int i = 0; i < MAX_INGREDIENTES; i++) {
            free(g_inventario[i]);
        }
        free(g_inventario);
    }
    // Se asigna memoria para el inventario
    g_inventario = (Ingrediente**)malloc(sizeof(Ingrediente*) * MAX_INGREDIENTES);
    if (g_inventario == NULL) {
        printf("Error: No se pudo asignar memoria para el inventario\n");
        return;
    }
    // Se inicializa el inventario
    for (int i = 0; i < MAX_INGREDIENTES; i++) {
        g_inventario[i] = NULL;
    }
}

Ingrediente** obtenerInventario() {
    return g_inventario;
}

void liberarInventario() {
    // Solo si el inventario existe, se libera la memoria asignada, sino no se hace nada
    if (g_inventario != NULL) {
        for (int i = 0; i < MAX_INGREDIENTES; i++) {
            free(g_inventario[i]);
        }
        free(g_inventario);
        g_inventario = NULL;
    }
}
void verInventario (){
    if (g_inventario == NULL) {
        printf("El inventario no ha sido creado.\n");
        return;
    }
    printf("-------------------------------------------------\n");
    printf("Inventario:\n");
    if(g_inventario[0] == NULL) {
        printf("El inventario está vacío.\n");
        printf("-------------------------------------------------\n");
    }
    else{
        if(g_inventario[0]->es_extintor == 1) {
            printf("El inventario tiene un extintor.\n");
            printf("-------------------------------------------------\n");
        }
        else{
            for (int i = 0; i < MAX_INGREDIENTES; i++) {
                if (g_inventario[i] != NULL) {
                    printf("Item %d:\n", i + 1);
                    printf("%s\n", g_inventario[i]->nombre);
                    printf("Estado: %s\n", obtenerestadoIngrediente(g_inventario[i]->estado));
                    printf("Turnos de corte: %d\n", g_inventario[i]->turnos_corte);
                    printf("Turnos de cocina o freir: %d\n", g_inventario[i]->turnos_cocina_o_freir);
                    printf("Probabilidad de incendio: %d\n", g_inventario[i]->prob_incendio);
                    printf("-------------------------------------------------\n");
                }
            }   
        }
    }
}
void agregarIngrediente (int cod_item) {
    if (g_inventario == NULL) {
        printf("El inventario no ha sido creado.\n");
        return;
    }
    if(g_inventario[4] != NULL) {
        printf("El inventario está lleno. No se puede agregar más ingredientes. \n");
        return;
    }
    for (int i = 0; i < MAX_INGREDIENTES; i++) {
        if (g_inventario[i] == NULL) {
            g_inventario[i] = (Ingrediente*)malloc(sizeof(Ingrediente));
            //si no se pudo asignar memoria porque  la asignacion de memoria devuelve NULL, entonces se imprime un mensaje de error
            if (g_inventario[i] == NULL) {
                printf("Error: No se pudo asignar memoria para el ingrediente\n");
                return;
            }
            switch (cod_item) {
                case 1:
                    strcpy(g_inventario[i]->nombre, "Papa");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=0;
                    g_inventario[i]->turnos_corte = 1;
                    g_inventario[i]->turnos_cocina_o_freir = 4;
                    g_inventario[i]->prob_incendio = 2;
                    break;
                case 2:
                    strcpy(g_inventario[i]->nombre, "Pollo");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=0;
                    g_inventario[i]->turnos_corte = 0;
                    g_inventario[i]->turnos_cocina_o_freir = 5;
                    g_inventario[i]->prob_incendio = 5;
                    break;
                case 3:
                    strcpy(g_inventario[i]->nombre, "Hamburguesa");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=0;
                    g_inventario[i]->turnos_corte = 0;
                    g_inventario[i]->turnos_cocina_o_freir = 3;
                    g_inventario[i]->prob_incendio = 3;
                    break;
                case 4:
                    strcpy(g_inventario[i]->nombre, "Arroz");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=0;
                    g_inventario[i]->turnos_corte = 0;
                    g_inventario[i]->turnos_cocina_o_freir = 2;
                    g_inventario[i]->prob_incendio = 1;
                    break;
                case 5:
                    strcpy(g_inventario[i]->nombre, "Pasta");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=0;
                    g_inventario[i]->turnos_corte = 0;
                    g_inventario[i]->turnos_cocina_o_freir = 2;
                    g_inventario[i]->prob_incendio = 1;
                    break;
                case 6:
                    strcpy(g_inventario[i]->nombre, "Tomate");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=0;
                    g_inventario[i]->turnos_corte = 1;
                    g_inventario[i]->turnos_cocina_o_freir = 0;
                    g_inventario[i]->prob_incendio = 0;
                    break;
                case 7:
                    strcpy(g_inventario[i]->nombre, "Lechuga");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=0;
                    g_inventario[i]->turnos_corte = 1;
                    g_inventario[i]->turnos_cocina_o_freir = 0;
                    g_inventario[i]->prob_incendio = 0;
                    break;
                case 8:
                    strcpy(g_inventario[i]->nombre, "Pan");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=0;
                    g_inventario[i]->turnos_corte = 0;
                    g_inventario[i]->turnos_cocina_o_freir = 0;
                    g_inventario[i]->prob_incendio = 0;
                    break;
                case 9:
                    liberarInventario();
                    crearInventario();
                    g_inventario[0] = (Ingrediente*)malloc(sizeof(Ingrediente));
                    if (g_inventario[0] == NULL) {
                        printf("Error: No se pudo asignar memoria para el extintor\n");
                        return;
                    }
                    strcpy(g_inventario[i]->nombre, "Extintor");
                    g_inventario[i]->estado=0;
                    g_inventario[i]->es_extintor=1;
                    g_inventario[i]->turnos_corte = 0;
                    g_inventario[i]->turnos_cocina_o_freir = 0;
                    g_inventario[i]->prob_incendio = 0;
                    break;
                default:
                    printf("ERROR!! Codigo de ingrediente invalido.\n");
                    free(g_inventario[i]);
                    g_inventario[i] = NULL;
                    return;
            }
            printf("Ingrediente %s agregado al inventario.\n", g_inventario[i]->nombre);
            return;
        }
    }
    printf("El inventario está lleno. No se puede agregar más ingredientes.\n");
}

void eliminarIngrediente(int cod_item){
    if (g_inventario == NULL) {
        printf("El inventario no ha sido creado.\n");
        return;
    }
    printf("Eliminando ingrediente %s del inventario...\n", obtenerNombreIngrediente(cod_item));
    for(int i =0;i<MAX_INGREDIENTES;i++){
        if(strcmp(g_inventario[i]->nombre, obtenerNombreIngrediente(cod_item)) == 0){
            free(g_inventario[i]);
            g_inventario[i] = NULL;
            printf("Ingrediente %s eliminado del inventario.\n", obtenerNombreIngrediente(cod_item));
            for(int j=i;j<MAX_INGREDIENTES-1;j++){
                g_inventario[j]=g_inventario[j+1];
            }
            return;
        }
    }
    printf("El ingrediente %s no se encuentra en el inventario.\n", obtenerNombreIngrediente(cod_item));
}
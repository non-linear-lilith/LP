#ifndef ACCIONES_H
#define ACCIONES_H
#include <inventario.h>
//-----------------OBLIGATORIO -------------------------
/**
 * @brief Estructura de una estación del juego.
 * @param simbolo Caracter que representa la estación ('T' para tabla, 'C' para cocina, 'A' para almacén, 'E' para extintor).
 * @param accion Puntero a la función que representa la acción de la estación (ej: cocinar, cortar).
 * @param en_llamas 1 si hay incendio, 0 si no.
 * @param turnos_inhabilitada Turnos que la estación estará inhabilitada (por ejemplo, si se apaga con un extintor).
 */
typedef struct {
    char simbolo; //’T’ (Tabla), ’C’ (Cocina), ’A’ (Almacen), ’E’ (Extintor)
    void (* accion)(void*, void*); // Puntero a funcion (ej:cocinar , cortar)
    int en_llamas; // 1 si hay incendio , 0 si no
    int turnos_inhabilitada; // Para estaciones apagadas con extintor
} Estacion;

/**
 * @brief Estructura de un pedido del juego.
 * @param nombre_plato Nombre del plato (ej: "McCharly").
 * @param ingredientes_requeridos Lista de ingredientes necesarios para el pedido.
 * @param completado 1 si el pedido fue entregado, 0 si está pendiente.
 */
typedef struct {
    char nombre_plato [50]; //Ej: McCharly
    Ingrediente ** ingredientes_requeridos; // Lista deingredientes necesarios
    int completado; // 1 si entregado , 0 si pendiente
} Pedido;


void cortar(void* contexto_juego,void* contexto_jugador); // Tabla de cortar         (SUPUESTO III)
void cocinar(void* contexto_juego,void* contexto_jugador); // Cocina                 (SUPUESTO III)
void buscar_ingrediente(void* contexto_juego,void* contexto_jugador); // Almacen     (SUPUESTO III)
void apagar_incendio(void* contexto_juego,void* contexto_jugador); // Extintor       (SUPUESTO III)
void entregar_pedido(void* contexto_juego,void* contexto_jugador);
//-----------------OBLIGATORIO -------------------------

#endif // ACCIONES_H
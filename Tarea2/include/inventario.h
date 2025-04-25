#ifndef INVENTARIO_H
#define INVENTARIO_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern const int MAX_INGREDIENTES; 

//-----------------OBLIGATORIO -------------------------

/**
 * @brief Estructura de un ingrediente.
 * @param nombre Nombre del ingrediente (ej: "pan", "pollo").
 * @param estado Estado del ingrediente (ej: "0 = crudo", "1 = cortado", etc.).
 * @param es_extintor 1 si es extintor, 0 si es ingrediente.
 * @param turnos_elaboracion Turnos que tarda en prepararse.
 * @param prob_incendio Probabilidad de causar incendio.
 */
typedef struct {
    char nombre [30]; // Ej: "pan", "pollo"
    int estado; // Ej: "0 = crudo", "1 = cortado", etc.
    int es_extintor; // 1 si es extintor , 0 si es ingrediente.
    //int turnos_elaboracion; // Turnos que tarda en prepararse.                        (SUPUESTO I, README)
    int turnos_corte; // Turnos que tarda en cortarse.                                  (SUPUESTO I, README)
    int turnos_cocina_o_freir; // Turnos que tarda en cocinarse o freirse.              (SUPUESTO I, README)
    int prob_incendio; // Probabilidad de causar incendio.
} Ingrediente;
void crearInventario (); // Puntero doble void**, que apunta a una lista estática de ingredientes y, eventualmente, el extintor.
void agregarIngrediente (int cod_item); // Agrega un ingrediente al inventario          (SUPUESTO II, README)
void eliminarIngrediente (int cod_item); // Elimina un ingrediente del inventario       (SUPUESTO II, README)
void verInventario ();
//-----------------OBLIGATORIO -------------------------


//-----------------EXTRA -------------------------

extern Ingrediente** g_inventario;
/**
 * @brief Devuelve el puntero al inventario global, que es un puntero doble que fue inicializado en NULL en el archivo inventario.c.
 * 
 * @return Ingrediente** 
 */
Ingrediente** obtenerInventario(); // Devuelve el puntero al inventario global
/**
 * @brief Libera la memoria del inventario global (g_inventario).
 * 
 * @return Nada (Tipo void)
 */
void liberarInventario(); // Libera la memoria del inventario
//-----------------EXTRA -------------------------
#endif // INVENTARIO_H

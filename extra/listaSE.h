#ifndef LISTASE_H_INCLUDED
#define LISTASE_H_INCLUDED

#include "funciones.h"

LineaPiezas *crearLista();
void insertarBodega(LineaPiezas *lista, Pieza dato);
int listaVacia(LineaPiezas lista);
void listarBodega(LineaPiezas lista, char texto[]);
Pieza *borrarBodega(LineaPiezas *lista);
Pieza *borrarBuscando(LineaPiezas *lista, Id dato);
void inicializarLista(LineaPiezas *lista);

#endif // LISTASE_H_INCLUDED

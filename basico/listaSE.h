#ifndef LISTASE_H
#define LISTASE_H

#include "funciones.h"

LineaPiezas *crearLista();
void insertarBodega(LineaPiezas *lista, Pieza dato);
int listaVacia(LineaPiezas lista);
void listarBodega(LineaPiezas lista);

#endif
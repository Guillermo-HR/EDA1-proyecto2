#ifndef LISTADE_H_INCLUDED
#define LISTADE_H_INCLUDED

#include "funciones.h"

// FUNCIONES
void insertarAlPrincipio(LineaPintado *lista, Pieza dato);
void listarPintado(LineaPintado lista);
void listarInversa(LineaPintado lista);
void listarPintadoPieza(LineaPintado lineaPintado, NodoDoble *i);
Pieza *borrarPintado(LineaPintado *lista);

// FUNCIONES AUXILIARES
LineaPintado *crearListaDoble();
NodoDoble *crearNodoDoble(Pieza dato, NodoDoble *sig, NodoDoble *ant);
int listaVaciaPintado(LineaPintado lista);
void inicializarListaPintado(LineaPintado *lista);

#endif // LISTADE_H_INCLUDED
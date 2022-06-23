#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

#include "funciones.h"
// FUNCIONES
void insertar(LineaPiezas *cola, Pieza dato);
Pieza *borrar(LineaPiezas *cola);
// FUNCIONES AUXILIARES
LineaPiezas *crearCola();
int colaVacia(LineaPiezas cola);
void inicializarCola(LineaPiezas *cola);
void listar(LineaPiezas cola);

#endif // COLADINAMICA_H_INCLUDED
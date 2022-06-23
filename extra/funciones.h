#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// Include
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHAR 15
#define MAX_STR 30

typedef struct
{
    char letra;
    int numero;
} Id;

typedef struct
{
    Id id;
    char color[MAX_CHAR];
    char descripcion[MAX_CHAR];
} Pieza;

typedef struct
{
    char id_final[6];
    Pieza arreglo[4];
} Automovil;

typedef struct nodoSimple
{
    Pieza info;
    struct nodoSimple *sig; // APUNTADOR AL SIG NODO DE LA lista
} NodoSimple;

typedef struct
{
    NodoSimple *h, *t;
} LineaPiezas;
// Linea de pintado DE
typedef struct nodoDoble
{
    Pieza info;
    struct nodoDoble *sig, *ant; // APUNTADOR AL SIG NODO DE LA lista
} NodoDoble;

typedef struct
{
    NodoDoble *h, *t;
} LineaPintado;

void generarPiezas(int n, LineaPiezas *linea, int control[]);
void pintarPiezas(LineaPiezas *linea, LineaPintado *lineaPintado);
void bodegaDeEnsamble(LineaPiezas *bodega, LineaPintado *lineaPintado);
void ensambleFinal(LineaPiezas *bodega, LineaPiezas *lineaFinal, int *arreglo, int n, Automovil *bodegaAutos, int maximo, int *autos);
void imprimirArreglo(Automovil autos[], int n, int m);

#endif // FUNCIONES_H_INCLUDED
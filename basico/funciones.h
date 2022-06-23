#ifndef estructuras_h
#define estructuras_h

// Include
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_CHAR 15

// Estructuras
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
    Pieza arreglo[4];
    int numero;
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

// Funciones
void generarPiezas(int n, LineaPiezas *linea, int control[]);
void pintarPiezas(LineaPiezas *linea, LineaPintado *lineaPintado);
void bodegaDeEnsamble(LineaPiezas *bodega, LineaPintado *lineaPintado);

#endif
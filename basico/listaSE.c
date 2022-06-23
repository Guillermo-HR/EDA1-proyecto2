#include "listaSE.h"

LineaPiezas *crearLista()
{
    LineaPiezas *nuevaLista;
    // CREACI�N DIN�MICA DE LA ESTRUCTURA COLA
    nuevaLista = (LineaPiezas *)malloc(sizeof(NodoSimple));
    if (nuevaLista == NULL)
    {
        printf("Error: Espacio insuficiente...");
        return NULL;
    }
    // INICIALIZANDO h y t
    nuevaLista->h = NULL;
    nuevaLista->t = NULL;
    return nuevaLista;
}

void insertarBodega(LineaPiezas *lista, Pieza dato) // IGUAL QUE LA COLA
{
    NodoSimple *nuevoNodo;
    // CREA EL NODO
    nuevoNodo = (NodoSimple *)malloc(sizeof(NodoSimple));
    if (nuevoNodo == NULL)
    {
        printf("Error: memoria insuficiente...");
        exit(-1);
    }
    // ASIGNA VALORES AL NODO
    nuevoNodo->info = dato;
    nuevoNodo->sig = NULL;

    // INSERTA EL NODO EN LA COLA
    if (lista->h == NULL)
    {
        lista->h = nuevoNodo;
        lista->t = nuevoNodo;
    }
    else
    {
        lista->t->sig = nuevoNodo;
        lista->t = nuevoNodo;
    }
}

int listaVacia(LineaPiezas lista)
{
    return lista.h == NULL;
}

void listarBodega(LineaPiezas lista)
{
    NodoSimple *q; // inicializar q

    if (listaVacia(lista))
        printf("\nbodega vacia\n");
    else
    {
        printf("\nBodega: ");
        for (q = lista.h; q != NULL; q = q->sig)
        {
            printf("\n\n\tid: %c%i", q->info.id.letra, q->info.id.numero);
            printf("\n\tcolor: %s", q->info.color);
            printf("\n\tdescripcion: %s", q->info.descripcion);
        }
    }
}

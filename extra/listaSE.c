#include "listaSE.h"
#include "coladinamica.h"
#include "listaDE.h"

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

void listarBodega(LineaPiezas lista, char texto[])
{
    NodoSimple *q; // inicializar q

    if (listaVacia(lista))
        printf("\n\n%s vacia\n", texto);
    else
    {
        printf("\n%s: ", texto);
        for (q = lista.h; q != NULL; q = q->sig)
        {
            printf("\n\n\tid: %c%i", q->info.id.letra, q->info.id.numero);
            printf("\n\tcolor: %s", q->info.color);
            printf("\n\tdescripcion: %s", q->info.descripcion);
        }
    }
}

Pieza *borrarBodega(LineaPiezas *lista)
{
    Pieza *dato;
    dato = malloc(sizeof(Pieza));
    NodoSimple *q = lista->h;
    if (!listaVacia(*lista))
    {
        if (lista->h == lista->t)
            lista->h = lista->t = NULL;
        else
            lista->h = lista->h->sig;
        *dato = q->info;
        free(q);
    }
    else
        printf("No hay datos registrados");
    return dato;
}

Pieza *borrarBuscando(LineaPiezas *lista, Id dato)
{

    Pieza *pieza;
    pieza = malloc(sizeof(Pieza));
    NodoSimple *p, *q = lista->h;
    if (listaVacia(*lista))
        return NULL;
    if (lista->h->info.id.letra == dato.letra && lista->h->info.id.numero == dato.numero)
    {
        if (lista->h == lista->t)
            lista->h = lista->t = NULL;
        else
            lista->h = lista->h->sig;

        q->sig = NULL;
        *pieza = q->info;
        return pieza;
    }
    while (q != lista->t)
    {

        if ((q->sig->info.id.letra == dato.letra) && (q->sig->info.id.numero == dato.numero))
        {
            p = q->sig; // nodo a borrar
            q->sig = p->sig;
            p->sig = NULL;
            if (p == lista->t) // borrar el último
                lista->t = q;
            *pieza = p->info;
            return pieza;
        }
        q = q->sig;
    }
    printf("\nNo existe el dato en la lista...\n");
    return NULL;
}

void inicializarLista(LineaPiezas *lista)
{
    NodoSimple *q;
    // LIBERA MEMORIA
    if (!listaVacia(*lista))
    {
        q = lista->h;
        while (q != NULL)
        {
            lista->h = lista->h->sig;
            free(q);
            q = lista->h;
        }
    }
    // INICIALIZA APUNTADORES COLA
    lista->h = lista->t = NULL;
}

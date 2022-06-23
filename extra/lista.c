#include "listaDE.h"
#include "coladinamica.h"
#include "listaSE.h"

LineaPintado *crearListaDoble()
{
    LineaPintado *nuevaLista;
    // CREACI�N DIN�MICA DE LA ESTRUCTURA COLA
    nuevaLista = (LineaPintado *)malloc(sizeof(LineaPintado));
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

NodoDoble *crearNodoDoble(Pieza dato, NodoDoble *sig, NodoDoble *ant)
{
    NodoDoble *nuevoNodo;
    // CREA EL NODO
    nuevoNodo = (NodoDoble *)malloc(sizeof(NodoDoble));
    if (nuevoNodo == NULL)
    {
        printf("Error: memoria insuficiente...");
        exit(0);
    }
    // ASIGNA VALORES AL NODO
    nuevoNodo->info.id = dato.id;
    strcpy(nuevoNodo->info.descripcion, dato.descripcion);
    strcpy(nuevoNodo->info.color, dato.color);
    nuevoNodo->sig = sig;
    nuevoNodo->ant = ant;
    return nuevoNodo;
}

int listaVaciaPintado(LineaPintado lista)
{
    return lista.h == NULL;
}

void listarPintado(LineaPintado lista)
{
    NodoDoble *q; // inicializar q

    if (listaVaciaPintado(lista))
        printf("\n\nLinea de pintado vacia\n");
    else
    {
        q = lista.h;
        printf("\nLinea de pintado: ");
        while (q != NULL)
        {
            // printf("\nPieza");
            printf("\n\n\tid: %c%i", q->info.id.letra, q->info.id.numero);
            printf("\n\tcolor: %s", q->info.color);
            printf("\n\tdescripcion: %s\n", q->info.descripcion);
            q = q->sig;
        }
    }
}

void listarInversa(LineaPintado lista)
{
    NodoDoble *q; // inicializar q

    if (listaVaciaPintado(lista))
        printf("\n\nLinea de pintado vacia\n");
    else
    {
        q = lista.t;
        printf("\nLinea de pintado: ");
        while (q != NULL)
        {
            // printf("\nPieza");
            printf("\n\n\tid: %c%i", q->info.id.letra, q->info.id.numero);
            printf("\n\tcolor: %s", q->info.color);
            printf("\n\tdescripcion: %s\n", q->info.descripcion);
            q = q->ant;
        }
    }
}

void inicializarListaPintado(LineaPintado *lista)
{
    NodoDoble *q;
    // LIBERA MEMORIA
    if (!listaVaciaPintado(*lista))
    {
        q = lista->h;
        while (q != NULL)
        {
            lista->h = lista->h->sig;
            free(q);
            q = lista->h;
        }
    }
    // INICIALIZA APUNTADORES
    lista->h = lista->t = NULL;
}

void insertarAlPrincipio(LineaPintado *lista, Pieza dato)
{
    NodoDoble *nuevoNodo;
    // CREA EL NODO
    nuevoNodo = crearNodoDoble(dato, lista->h, NULL);

    // INSERTA EL NODO EN LA lista
    if (lista->h == NULL)
    {
        lista->h = nuevoNodo;
        lista->t = nuevoNodo;
    }
    else
    {
        lista->h->ant = nuevoNodo;
        lista->h = nuevoNodo;
    }
}

Pieza *borrarPintado(LineaPintado *lista)
{
    Pieza *dato;
    dato = malloc(sizeof(Pieza));
    NodoDoble *q = lista->h;
    // BORRA EL DATO
    if (!listaVaciaPintado(*lista))
    {
        if (lista->h == lista->t)
            lista->h = lista->t = NULL;
        else
        {
            lista->h = lista->h->sig;
            lista->h->ant = NULL;
        }
        *dato = q->info; // EXTRAE LA INFORMACI�N
        free(q);         // LIBERA LA MEMORIA
    }
    else
        printf("\nNo hay datos registrados...");
    return dato;
}

void listarPintadoPieza(LineaPintado lista, NodoDoble *i)
{
    NodoDoble *q;
    if (listaVaciaPintado(lista))
        printf("\n\nLinea de pintado vacia\n");
    else
    {
        q = i;
        while (q)
        {
            printf("\n\tPintando la pieza %c%i de color %s", q->info.id.letra, q->info.id.numero, q->info.color);
            if (i == lista.h)
                q = q->sig;
            else
                q = q->ant;
        }
    }
}

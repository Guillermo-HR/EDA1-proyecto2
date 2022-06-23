#include "coladinamica.h"
#include "listaDE.h"
#include "listaSE.h"

LineaPiezas *crearCola()
{
    LineaPiezas *nuevaCola;
    // CREACI�N DIN�MICA DE LA ESTRUCTURA COLA
    nuevaCola = (LineaPiezas *)malloc(sizeof(Pieza));
    if (nuevaCola == NULL)
    {
        printf("Error: Espacio insuficiente...");
        exit(0);
    }
    // INICIALIZANDO h y t
    nuevaCola->h = NULL;
    nuevaCola->t = NULL;
    return nuevaCola;
}

void insertar(LineaPiezas *cola, Pieza dato)
{
    NodoSimple *nuevoNodo;
    // CREA EL NODO
    nuevoNodo = (NodoSimple *)malloc(sizeof(NodoSimple));
    if (nuevoNodo == NULL)
    {
        printf("Error: memoria insuficiente...");
        exit(0);
    }
    // 1.ASIGNA VALORES AL NODO
    nuevoNodo->info.id = dato.id;
    strcpy(nuevoNodo->info.descripcion, dato.descripcion);
    strcpy(nuevoNodo->info.color, dato.color);
    nuevoNodo->sig = NULL;
    // 2.INSERTA EL NODO EN LA COLA
    if (colaVacia(*cola))
        cola->h = cola->t = nuevoNodo;
    else
    {
        cola->t->sig = nuevoNodo;
        cola->t = nuevoNodo;
    }
}

void listar(LineaPiezas cola)
{
    NodoSimple *q;
    // printf("\n");
    if (colaVacia(cola))
        printf("\n\nLinea de piezas vacia\n");
    else
    {
        printf("\nLinea de piezas: ");
        for (q = cola.h; q != NULL; q = q->sig)
        {
            printf("\n\n\tid: %c%i", q->info.id.letra, q->info.id.numero);
            printf("\n\tcolor: %s", q->info.color);
            printf("\n\tdescripcion: %s", q->info.descripcion);
        }
    }
}

int colaVacia(LineaPiezas cola)
{
    return cola.h == NULL;
}

Pieza *borrar(LineaPiezas *cola)
{

    Pieza *dato;
    dato = malloc(sizeof(Pieza));
    NodoSimple *q = cola->h;
    // BORRA EL DATO
    if (!colaVacia(*cola))
    {
        if (cola->h == cola->t)
            cola->h = cola->t = NULL;
        else
            cola->h = cola->h->sig;

        *dato = q->info; // EXTRAE LA INFORMACI�N
        free(q);         // LIBERA LA MEMORIA
    }
    else
        printf("\nNo hay datos registrados...");
    return dato;
}

void inicializarCola(LineaPiezas *cola)
{
    NodoSimple *q = cola->h;
    if (!colaVacia(*cola))
    {
        // LIBERA MEMORIA
        while (q != NULL)
        {
            cola->h = cola->h->sig;
            free(q); // LIBERA LA MEMORIA
            q = cola->h;
        }
        // INICIALIZA APUNTADORES COLA
        cola->h = cola->t = NULL;
    }
}

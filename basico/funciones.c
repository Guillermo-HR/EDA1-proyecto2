#include "funciones.h"
#include "colaDinamica.h"
#include "listaDE.h"
#include "listaSE.h"

void generarPiezas(int n_piezas, LineaPiezas *linea, int control[])
{
    int i, aux;
    char letra, *colores[] = {"blanco", "negro", "azul"}, descripciones[][MAX_CHAR] = {"ejes", "puerta", "ventana", "cofre"};
    Pieza *pieza, dato;

    pieza = &dato;
    printf("\nRobots generadores\n");
    for (i = 0; i < n_piezas; i++)
    {
        if (rand() % 100 + 1 > 50)
        {
            pieza->id.letra=65+i;
            pieza->id.numero=control[i];
            control[i] = control[i] + 1;
            strcpy(pieza->color, colores[rand() % (sizeof(colores) / sizeof(colores[0]))]);
            strcpy(pieza->descripcion, descripciones[i]);
            insertar(linea, *pieza);
            printf("\nEl robot %c termino la pieza: %c%i", 65 + i, pieza->id.letra, pieza->id.numero);
        }
    }
    printf("\n\n---------------------------------\n");
    listar(*linea);
}

void pintarPiezas(LineaPiezas *linea, LineaPintado *lineaPintado)
{
    if (!colaVacia(*linea))
    {
        Pieza *aux;
        printf("\n\n---------------------------------\n");
        printf("\nBrazo robotico\n");
        while (!colaVacia(*linea))
        {
            aux = borrar(linea);
            insertarAlPrincipio(lineaPintado, *aux);
            printf("\nLa pieza %c%i se envia a la seccion de pintado", aux->id.letra, aux->id.numero);
            listar(*linea);
            listarInversa(*lineaPintado);
        }
        printf("\n---------------------------------\n");
        printf("\nRobot pintor");
        printf("\n\nPrimera pasada\n");
        listarPintadoPieza(*lineaPintado, lineaPintado->h, lineaPintado->t);
        printf("\n\nSegunda pasada\n");
        listarPintadoPieza(*lineaPintado, lineaPintado->t, lineaPintado->h);
    }
    printf("\n\n---------------------------------\n");
}

void bodegaDeEnsamble(LineaPiezas *bodega, LineaPintado *lineaPintado)
{
    if (listaVaciaPintado(*lineaPintado))
        printf("\nLinea de pintado vacia\n");
    else
    {
        Pieza aux;
        printf("\nBrazo robotico\n");
        while (!listaVaciaPintado(*lineaPintado))
        {
            aux = borrarPintado(lineaPintado);
            insertarBodega(bodega, aux);
            printf("\nLa pieza %c%i se envia a la bodega", aux.id.letra, aux.id.numero);
            listarInversa(*lineaPintado);
            listarBodega(*bodega);
        }
    }
    printf("\n\n---------------------------------\n");
}
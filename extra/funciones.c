#include "funciones.h"
#include "coladinamica.h"
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
            pieza->id.letra = 65 + i;
            pieza->id.numero = control[i];
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
            printf("\n>>La pieza %c%i se envia a la seccion de pintado", aux->id.letra, aux->id.numero);
            listar(*linea);
            listarInversa(*lineaPintado);
        }
        printf("\n---------------------------------\n");
        printf("\nRobot pintor");
        printf("\n\nPrimera pasada\n");
        listarPintadoPieza(*lineaPintado, lineaPintado->t);
        printf("\n\nSegunda pasada\n");
        listarPintadoPieza(*lineaPintado, lineaPintado->h);
    }
    printf("\n\n---------------------------------\n");
}

void bodegaDeEnsamble(LineaPiezas *bodega, LineaPintado *lineaPintado)
{
    Pieza *aux;
    if (listaVaciaPintado(*lineaPintado))
        printf("\nLinea de pintado vacia\n");
    else
    {
        printf("\nBrazo robotico\n");
        while (!listaVaciaPintado(*lineaPintado))
        {
            aux = borrarPintado(lineaPintado);
            insertarBodega(bodega, *aux);
            printf("\n>>La pieza %c%i se envia a la bodega", aux->id.letra, aux->id.numero);
            listarInversa(*lineaPintado);
            listarBodega(*bodega, "Bodega");
        }
    }
    printf("\n\n---------------------------------\n");
}

void ensambleFinal(LineaPiezas *bodega, LineaPiezas *lineaFinal, int *arreglo, int n, Automovil *bodegaAutos, int maximo, int *autos)
{
    Pieza *aux;
    Id id;
    int i, j, k;
    if (listaVacia(*bodega))
        printf("\nBodega de ensable vacia\n");
    else
    {
        printf("\nComenzando ensamblaje\n\n");
        while (!listaVacia(*bodega))
        {
            aux = borrarBodega(bodega);
            for (i = 0; i <= n; i++)
            {
                if (aux->id.numero == i)
                {
                    arreglo[i]++;
                }
            }

            insertarBodega(lineaFinal, *aux);
            printf("\n>>La pieza %c%i se envia a la línea de ensamble final", aux->id.letra, aux->id.numero);
            listarBodega(*bodega, "Bodega");
            listarBodega(*lineaFinal, "Línea de ensamble final");

            for (i = 0; i <= n; i++)
            {
                if (arreglo[i] == maximo)
                {
                    id.numero = i;
                    k = sprintf(bodegaAutos[i].id_final, "AU%i", i);
                    printf("\n\n---------------------------------\n");
                    printf("\nEl robot de ensamble está ensamblando el producto %s\n", bodegaAutos[i].id_final);
                    for (j = 0; j < maximo; j++)
                    {
                        id.letra = 65 + j;
                        aux = borrarBuscando(lineaFinal, id);
                        bodegaAutos[i].arreglo[j] = *aux;
                        printf("\n>>Se extrae la pieza %c%i de la lista de ensamble final para ensamble", aux->id.letra, aux->id.numero);
                        listarBodega(*lineaFinal, "Línea de ensamble final");
                    }
                    printf("\n\nEl auto %i esta terminado\n\n", i);
                    printf("---------------------------------\n\n");
                    arreglo[i] = 0;
                    (*autos)++;
                }
            }
        }
    }
}

void imprimirArreglo(Automovil autos[], int n, int m)
{
    int i, j;
    for (i = 0; i <= n; i++)
    {
        if (strlen(autos[i].id_final) != 0)
        {
            printf("\n\n\nAuto terminado: %s", autos[i].id_final);
            printf("\nPiezas: ");
            for (j = 0; j < m; j++)
            {
                printf("\n\tID: %c%i", autos[i].arreglo[j].id.letra, autos[i].arreglo[j].id.numero);
                printf("\tColor: %s", autos[i].arreglo[j].color);
                printf("\tDescripcion: %s", autos[i].arreglo[j].descripcion);
            }
        }
    }
}

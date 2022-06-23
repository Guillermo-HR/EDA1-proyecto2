#include <time.h>
#include "funciones.h"
#include "coladinamica.h"
#include "listaDE.h"
#include "listaSE.h"

int main()
{
    // Variables iniciales
    int n_piezas, i, j, cap_bodega, ciclo = 0, Autos = 0;
    LineaPiezas *linea, *bodega, *lineaFinal;
    LineaPintado *lineaPintado;
    // Crear apuntadores
    linea = crearCola();
    bodega = crearLista();
    lineaFinal = crearLista();
    lineaPintado = crearListaDoble();

    // Parametros de la simulacion
    do
    {
        printf("Numero de piezas max: 4\nn_piezas: ");
        scanf("%i", &n_piezas);
    } while (n_piezas > 4 || n_piezas < 1);
    do
    {
        printf("Capacidad de la bodega: ");
        scanf("%i", &cap_bodega);
    } while (cap_bodega < 1 && cap_bodega > 10);

    Automovil *autos;
    autos = calloc(cap_bodega, sizeof(Automovil));

    int arreglo[cap_bodega];

    for (i = 0; i <= cap_bodega; i++)
    {
        arreglo[i] = 0;
    }

    // Inicializar programa
    int control[n_piezas];
    for (i = 0; i < n_piezas; i++)
        control[i] = 1;
    srand(time(NULL));
    do
    {
        generarPiezas(n_piezas, linea, control);
        pintarPiezas(linea, lineaPintado);
        bodegaDeEnsamble(bodega, lineaPintado);
        ensambleFinal(bodega, lineaFinal, arreglo, cap_bodega, autos, n_piezas, &Autos);
        ciclo++;
        printf("\n\nFin del ciclo %i\n\n", ciclo);
        printf("---------------------------------\n");
    } while (Autos != cap_bodega);
    printf("\n>>Fin de la simulacion<<\n\n");
    printf("\t\t\tResumen\n");
    printf("\nPiezas sin usar:");
    listarBodega(*lineaFinal, "Línea de ensamble final");
    printf("\n---------------------------------\n");
    printf("\nAutos terminados: %i", Autos);
    imprimirArreglo(autos, cap_bodega, n_piezas);

    inicializarCola(linea);
    inicializarListaPintado(lineaPintado);
    inicializarLista(bodega);
    inicializarLista(lineaFinal);
    free(linea);
    free(lineaPintado);
    free(bodega);
    free(lineaFinal);


    return 0;
}

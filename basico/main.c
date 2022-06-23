#include "funciones.h"
#include "colaDinamica.h"
#include "listaDE.h"
#include "listaSE.h"

int main()
{
    // Variables iniciales
    int n_piezas, i, cap_bodega, ciclo = 0;
    LineaPiezas *linea, *bodega;
    LineaPintado *lineaPintado;
    Pieza pieza;
    // Crear apuntadores
    linea = crearCola();
    bodega = crearLista();
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
    } while (cap_bodega < 1);
    // Inicializar programa
    int control[n_piezas];
    for (i = 0; i < n_piezas; i++)
        control[i] = 1;
    srand(time(NULL));
    system("clear");
    while (ciclo < cap_bodega)
    {
        generarPiezas(n_piezas, linea, control);
        pintarPiezas(linea, lineaPintado);
        bodegaDeEnsamble(bodega, lineaPintado);
        ciclo++;
    }

    return 0;
}
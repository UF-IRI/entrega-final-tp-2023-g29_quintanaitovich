#include "cliente.h"
#include "clasess.h"
#include <iostream>

using namespace std;

int buscar_idcliente(sClientes *cliente, string nombre, string apellido)
{
    int i=0;
    sClientes* Actual = cliente;
    sClientes* Ultimo = cliente + 249;
    while(Actual != Ultimo)
    {
        if(Actual->nombre==nombre && Actual->apellido==apellido)
        {
            return Actual->id;
        }
    }
    return -1;
    //cuando llamo a la funcion aclarar que -1 es error.
}

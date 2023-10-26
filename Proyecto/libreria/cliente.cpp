#include "cliente.h"
#include "clases.h"
#include <iostream>

using namespace std;

int buscar_idcliente(sClientes *cliente, string nombre, string apellido)
{
    int i=0;
    sClientes* actual = cliente;
    sClientes* Ultimo = cliente + 249;
    while(actual != Ultimo)
    {
        if(actual->nombre==nombre && actual->apellido==apellido)
        {
            return actual->id;
        }
    }
    return -1;
    //cuando llamo a la funcion aclarar que -1 es error.
}

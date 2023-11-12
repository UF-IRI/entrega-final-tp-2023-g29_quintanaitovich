#include "cliente.h"
#include "clasess.h"
#include <iostream>
#include "archivos.h"

using namespace std;

int buscar_idcliente(sClientes *cliente, unsigned int cant, string nombre, string apellido)
{
    int i=0;
    sClientes* Actual = cliente;
    sClientes* Ultimo = cliente + cant;
    while(Actual != Ultimo)
    {
        if(Actual->nombre==nombre && Actual->apellido==apellido)
        {
            if(Actual->estado<0) //tiene una deuda.
                return -1;
            return Actual->id;
        }
        Actual++;
    }
    return -1;
    //cuando llamo a la funcion aclarar que -1 es error.
}


#include <iostream>
#include "cliente.h"
#include "archivos.h"

using namespace std;

int buscar_idcliente (sClientes *cliente, unsigned int tamT, string nombre, string apellido)
{
    sClientes* actual = cliente;
    sClientes* Ultimo = cliente + tamT;
    while(actual != Ultimo)
    {
        if(actual->nombre==nombre && actual->apellido==apellido)//agrego el mail??
        {
            if(actual->estado<0){
                return -1;
            }

            return actual->id;
        }
        actual++;
    }
    return -1;
    //cuando llamo a la funcion aclarar que -1 es error.
}

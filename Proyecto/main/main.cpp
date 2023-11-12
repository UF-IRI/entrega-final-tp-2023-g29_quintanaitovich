#include <iostream>
#include "archivos.h"
#include "clasess.h"
#include "cliente.h"
#include "archivos.cpp"

int main()
{
    //leo archivo clases
    ifstream archivoClases;
    archivoClases.open("iriClasesGYM");
    unsigned int tamT=0;
    sClases*ClasesGYM= new sClases[tamT];
    int result1=leerArchivoClases(archivoClases, ClasesGYM, tamT);
    if(result1<0)
        cout<<"No se pudo abrir el archivo"<<endl;
    archivoClases.close();

    ifstream archivoClientes;
    archivoClientes.open ("iriClientesGYM");
    unsigned int cant=0;
    sClientes*ClientesGYM= new sClientes[cant];
    int result2=leerArchivoClientes(archivoClientes, ClientesGYM, cant);
    if(result2<0)
        cout<<"No se puede abrir el archivo"<<endl;
    archivoClientes.close();




    return 0;
}

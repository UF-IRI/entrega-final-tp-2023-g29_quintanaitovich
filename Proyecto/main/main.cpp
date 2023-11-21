#include <iostream>
#include "archivos.h"
#include "clases.h"
#include "cliente.h"
#include "archivos.cpp"
#include "clases.cpp"
#include <ctime>

int main()
{
    //leo archivo clases
    ifstream archivoClases;
    archivoClases.open("iriClasesGYM.csv");
    unsigned int tamT=0;
    sClases*ClasesGYM= nullptr;
    int result1=leerArchivoClases(archivoClases, ClasesGYM, tamT);
    if(result1<0)
        cout<<"No se pudo leer el archivo de Clases"<<endl;
    archivoClases.close();

    ifstream archivoClientes;
    archivoClientes.open ("iriClientesGYM.csv");
    unsigned int cant=0;
    sClientes*ClientesGYM= new sClientes[cant];
    int result2=leerArchivoClientes(archivoClientes, ClientesGYM, cant);
    if(result2<0)
        cout<<"No se pudo leer el archivo de Clientes"<<endl;
    archivoClientes.close();

    //leo archivo de asistencias de ayer
    ifstream archivoAsistenciasAyer;
    archivoAsistenciasAyer.open("asistencias_1697673600000.dat", ios::binary);
    unsigned int tam=0;
    sAsistencias*asistenciasAyer = new sAsistencias[tam];
    int result3=leerArchivoAsistencias(archivoAsistenciasAyer, asistenciasAyer, tam);
    if(result3<0)
        cout<<"Ocurrio un error leyendo mis clases para hoy";
    archivoAsistenciasAyer.close();

    int CantidadClientesMañana= rand()%(cant);
    sAsistencias*asistenciasMañana= new sAsistencias[CantidadClientesMañana];
    for(unsigned int k=0; k < CantidadClientesMañana; k++)
    {
        asistenciasMañana[k].idCliente=0;
        asistenciasMañana[k].cantInscriptos=0;
    }

    //asistenciasMañana llega con & y se cambia.
    FuncionMain(ClasesGYM, cant, ClientesGYM, tamT, asistenciasMañana,CantidadClientesMañana);

    ofstream archivoMañana;
    archivoMañana.open("AsistenciaManiana.bin",ios::binary);
    int result4 = escribirArchivoMañana(archivoMañana,asistenciasMañana,CantidadClientesMañana);
    if(result4<0)
        cout<<"No se pudo escribir el archivo de mañana";
    archivoMañana.close();

    //borro todas las memorias dinamicas
    delete[]ClasesGYM;
    delete[]ClientesGYM;
    delete[]asistenciasAyer;
    delete[]asistenciasMañana;

    return 0;
}

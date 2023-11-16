#include <iostream>
#include "archivos.h"
#include "clases.h"
#include "cliente.h"
#include "archivos.cpp"
#include "clases.cpp"

int main()
{
    //leo archivo clases
    ifstream archivoClases;
    archivoClases.open("iriClasesGYM.csv");
    unsigned int tamT=0;
    sClases*ClasesGYM= new sClases[tamT];
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
    sAsistencias*asistenciasAyer=new sAsistencias[tam];
    int result3=leerArchivoAsistencias(archivoAsistenciasAyer, asistenciasAyer, tam);
    if(result3<0)
        cout<<"Ocurrio un error leyendo mis clases para hoy";
    archivoAsistenciasAyer.close();

    //hago el random de mi lista de clientes [una posicion]
    //hago un random que me diga la cantidad de clientes que se van a anotar hoy
    int CantidadClientesHoy= rand()%(cant);
    string nombrecito=" ", apellidito=" ", emailcito=" ", actividadd=" ";
    float horarioo=0.0;
    sAsistencias*asistenciasMañana= new sAsistencias[CantidadClientesHoy];
    int Reserva=0;
    unsigned int i=0;

    while(i<CantidadClientesHoy)
    {
        unsigned int j=0;
        clienteRandom (ClientesGYM, ClasesGYM, nombrecito, apellidito, emailcito, actividadd, horarioo);
        Reserva = reservar_clase (ClientesGYM, cant, ClasesGYM, tamT, asistenciasMañana, tam, actividadd, horarioo, nombrecito, apellidito ,emailcito);
        int idclaseR= buscar_idclases(ClasesGYM,tamT,actividadd,horarioo);
        int idclienteR=buscar_idcliente(ClientesGYM,cant,nombrecito,apellidito,emailcito);

        if(Reserva>0)
        {
            while(j<i) //recorro la cantidad de asistencias que tengo por ahora
            {
                if(asistenciasMañana[j].idCliente== idclienteR)
                {
                    //resize de las inscripciones del cliente para sumarle un lugar y poder agregarle la clase
                    //crearme un vector dinamico de tipo inscripcion con 0 lugares
                    int cantidad= (asistenciasMañana[j].cantInscriptos)++;
                    //asistenciasMañana[j].cantInscriptos= cantidad;
                    asistenciasMañana[j].Inscripcion[cantidad] = {idclaseR, time(NULL)};

                }
                else
                {
                    asistenciasMañana[j].Inscripcion[0]={idclaseR,timezone};
                    asistenciasMañana[j].cantInscriptos+=1;
                }
                j++;
            }
        }
        i++;
    }

    ofstream archivoMañana;
    archivoMañana.open("AsistenciasMañana.bin",ios::binary);
    int result4 = escribirArchivoMañana(archivoMañana,asistenciasMañana,CantidadClientesHoy);
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

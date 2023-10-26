#include "cliente.h"
#include "clases.h"
#include <iostream>

using namespace std;

eReserva reservar_clase(sClientes* cliente, sClases* clases,sAsistencia*asistencia, string actividad, int horario, string nombre, string apellido)
{
    int i=0;
    sClases clase_reserva;
    //busco el id de la persona que quiere reservar
    int id=buscar_idcliente(cliente,nombre,apellido);
    sClases*ultimo=clases[60];
    for(i=0;i<60;i++) //se puede poner directamente 60?
    {
        //encuentro la clase que me pasaron en el archivo
        if(clases[i].actividad==actividad && clases[i].horario==horario)
        {
            clase_reserva=clases[i]; //guardo en la variable la clase a reservar
            break;
        }
        if(ultimo->id > clases[i].id) //no se encontro el horario
            return eReserva::ErrorReserva;
    }
    //preguntar que actividad es para ver cuantos cupos?
    for(int j=0;j<40;j++)
    {
        asistencia[j].idCliente=id;

    }

}

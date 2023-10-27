#include "cliente.h"
#include "clases.h"
#include <iostream>

using namespace std;

eReserva reservar_clase(sClientes* cliente, sClases* clases, sAsistencia*asistencia, string actividad, int horario, string nombre, string apellido)
{
    int i=0;
    sClases clase_reserva;
    //busco el id de la persona que quiere reservar
    int id=buscar_idcliente(cliente,nombre,apellido);
    sClases *ultimo = clases + 59;
    while(true) //se puede poner directamente 60?
    {
        //encuentro la clase que me pasaron en el archivo
        if(clases[i].actividad==actividad && clases[i].horario==horario)
        {
            clase_reserva= clases[i]; //guardo en la variable la clase a reserva
            break;
        }
        if(i==ultimo -> id) //no se encontro el horario
            return eReserva::ErrorReserva;
    }
    //ver que si ya estoy inscripto --> si estoy inscripto me borro
        // si me encontro una sola vez--> return exito reserva
        //si me encontro dos veces--> borro la segunda (funcion borrar)
        //si me encontro dos o mas--> borro odos menos el primero
    //ver si hay espacio (funcion hay espacio)--> si hay y no estoy ya anotado me inscribo en el primer lugar libre
    //si no hay lugar --> error reserva
}

bool HayEspacio (sClases*clases, sAsistencia*asistencia, sInscripcion*inscripcion, int idClase)
{
    int i;
    int j;
    int cont=0;
    for(i=0;i<250;i++)
    {
        for(j=0;j<60;j++)
        {
            if(asistencia[i].Inscripcion[j].idClase==idClase)
                cont++;
        }
    }

    if(idClase>1 && idClase <6) //estas en spinning
        {
        if(cont<=45)
            return true;
        else
            return false;
        }
    if(idClase>5 && idClase <12) //estas en yoga
        {
        if(cont<=25)
            return true;
        else
            return false;
        }
    if(idClase>11 && idClase <19) //estas en pilates
        {
        if(cont<=15)
            return true;
        else
            return false;
        }
    if(idClase>18 && idClase <24) // streching
        {
            if(cont<=40)
                return true;
            else
                return false;
        }
    if(idClase>23 && idClase <30) //zumba
        {
            if(cont<=50)
                return true;
            else
                return false;
        }
    if(idClase>29 && idClase <34) // boxeo
        {
            if(cont<=30)
                return true;
            else
                return false;
        }
    if(idClase>33 && idClase <61) // musculacion
        {
            if(cont<=30)
                return true;
            else
                return false;
        }
}
eTieneReserva TieneReserva(sAsistencia*asistencia, sInscripcion*inscripcion,int idClase)
{
        sAsistencia*ultimo = asistencia+59;
        int i;
        int j;
        int r;
        for(i=0;i<250;i++) //recorro mis estructuras de asistencias
        {
            for(j=0;j<60;j++) //recorro todas las inscripciones de cada liente
            {
                if(asistencia[i].Inscripcion[j].idClase==idClase) //encuentro la primera que coincide con el id
                {
                    for(r=j;r<60;r++) //vuelvo a recorrer las inscripciones desde la primera que encontre
                    {
                        if(asistencia[i].Inscripcion[r].idClase==idClase) //si coincide con el id, lo elimino
                            *(asistencia[i].Inscripcion[r]) = InscripcionNula;
                    }
                    return eTieneReserva::YaTieneLugar; //ya estaba en la clase
                    break; //se corta el primer for?
                }
                if(asistencia[i].Inscripcion[j] == ultimo->Inscripcion) //si recorri toda la lista de asistencias y el id
                    return eTieneReserva::PuedeReservar; //no esta en la clase
            }
        }
}

#include "cliente.h"
#include "clientes.cpp"
#include "clasess.h"
#include "archivos.h"
#include <iostream>

using namespace std;

eReserva reservar_clase(sClientes* cliente, unsigned int cant, sClases* clases, unsigned int tamT,sAsistencias*asistencia,
                        unsigned int tamMañana, string actividad, float horario, string nombre, string apellido)
{
    int poscliente=0;
    int IdClase = buscar_idclases(clases,tamT,actividad,horario);
    unsigned int aux_cantins=0;
    unsigned int n=0;
    int*grupitos=nullptr;
    int idCliente = buscar_idcliente(cliente, cant,nombre,apellido);
    if(idCliente == -1)
        return eReserva::ErrorReserva;

    for(unsigned int i=0; i< tamMañana; i++)
    {
        if(asistencia[i].idCliente==0)
        {
            aux_cantins=0;
        }
        else
        if(asistencia[i].idCliente==idCliente) //el cliente ya vino
            {
                aux_cantins=asistencia[i].cantInscriptos;
                poscliente=i;
            }
        }
        for(unsigned int i=0; i<aux_cantins; i++)
        {
            AgruparPorHorarios(clases,tamT,grupitos,n,horario);
            for(unsigned int j=0; j<n; j++)
            {
                if(asistencia[poscliente].Inscripcion[i].idClase==grupitos[j])
                  return eReserva::ErrorReserva; //ya tiene una reserva en ese horario
            }
        }

    delete[]grupitos;
    //una vez que hacemos la funcion de grupitos, tambien estamos viendo que el cliente no este dos veces en la misma clase

    if(HayEspacio(asistencia,IdClase,tamMañana)==true)
    {
        return eReserva::ExitoReserva;
    }else
        return eReserva::ErrorReserva;
}

bool HayEspacio (sAsistencias*asistencia, unsigned int idClase, int tam)
{
    int i;
    int j;
    int cont=0;
    for(i=0;i<tam;i++)
    {
        for(j=0; j<asistencia[i].cantInscriptos; j++) //asistencia[i].cantInscriptos
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
    return false;
}

int buscar_idclases(sClases *clases, unsigned int tamT, string actividad, float horario)
{
    sClases* Actual = clases;
    sClases* Ultimo = clases + tamT;
    while(Actual != Ultimo)
    {
        if(Actual->actividad==actividad && Actual->horario==horario)
        {
            return Actual->id;
        }
        Actual++;
    }
    return -1;
    //cuando llamo a la funcion aclarar que -1 es error.
}

void AgruparPorHorarios(sClases*clases, int tamT, int*& grupitos, unsigned int &n, float horario)
{
    //recorrer las clases y buscar todas las que coincida el horario con horario
    for(int i=0; i<tamT; i++)
    {
        if(clases[i].horario==horario)
        {
            ResizeGrupitos(grupitos,n);
            grupitos[n-1]=clases[i].id;
        }
    }
    return;
}

void ResizeGrupitos(int*& grupitos, unsigned int &N)
{
    if(grupitos==nullptr)
    {
        if(N<=0)
        {
            grupitos= new int[++N];
        }
        return;
    }
    int*aux=new int[++N];
    for(unsigned int i=0; i<N-1 ;i++)
    {
        aux[i]=grupitos[i];
    }
    delete[]grupitos;
    grupitos=aux;
}

void clienteRandom (sClientes*clientes, sClases*clases, string &nombrecito, string &apellidito,
                   string &actividadd, float &horarioo)
{
    int num_cliente=rand()%(sizeof(clientes));
    nombrecito=clientes[num_cliente].nombre;
    apellidito=clientes[num_cliente].apellido;
    //emailcito=clientes[num_cliente].nombre;

    int num_clase=rand()%(sizeof(clases));
    actividadd=clases[num_clase].actividad;
    horarioo=clases[num_clase].horario;

    return;
}

void ResizeInscripciones(sInscripcion*&inscripciones,int &num_clases)
{
    if(inscripciones==nullptr)
    {
        if(num_clases<0)
        {
            inscripciones=new sInscripcion[++num_clases];
        }
    }
    sInscripcion*aux=new sInscripcion[++num_clases];
    for(unsigned int i=0;i<num_clases-1;i++)
    {
        aux[i]=inscripciones[i];
    }
    delete[]inscripciones;
    inscripciones=aux;
}


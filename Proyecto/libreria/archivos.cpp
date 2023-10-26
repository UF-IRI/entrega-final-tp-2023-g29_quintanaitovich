#include "cliente.h"
#include "clases.h"
#include "archivos.h"
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

eArchivos leerArchivoClientes(std::fstream *archivo, sClientes *clientes)
{
    unsigned int auxId;
    std::string auxNombre;
    std::string auxApellido;
    std::string auxEmail;
    std::string auxTelefono;
    sFecha auxFecha;
    int auxEstado;
    char coma;
    int i=0;

    archivo->open("iriClientesGYM");
    if(!archivo->is_open())
        return eArchivos::ErrorApertura;

    while(*archivo>>auxId>>coma>>auxNombre>>coma>>auxApellido>>coma>>auxEmail>>coma>>
           auxTelefono>>coma>>auxFecha.dia>>coma>>auxFecha.mes>>coma>>auxFecha.anyo>>coma>>auxEstado)
    {
        (clientes+i)->id=auxId;
        (clientes+i)->nombre=auxNombre;
        (clientes+i)->apellido=auxApellido;
        (clientes+i)->email=auxEmail;
        (clientes+i)->telefono=auxTelefono;
        (clientes+i)->fecha=auxFecha;
        (clientes+i)->estado=auxEstado;
        i++;
    }
    return eArchivos::ExitoOperacion;
}

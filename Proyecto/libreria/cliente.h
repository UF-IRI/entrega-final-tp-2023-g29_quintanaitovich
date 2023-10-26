#ifndef CLIENTE_H
#define CLIENTE_H

#include <string.h>
#include <iostream>
#include "clases.h"

using namespace std;

struct fecha
{
    int dia,mes,anyo;
};
typedef struct fecha sFecha;

struct cliente
{
    int id;
    std::string nombre;
    std::string apellido;
    std::string email;
    std::string telefono;
    sFecha fecha;
    int estado;
};
typedef struct cliente sClientes;

//guarda todas las clases que tiene un cliente
struct inscripcion
{
    int idClase;
    int fechaInscripcion; //como se declara si es un timestamp
};
typedef struct inscripcion sInscripcion;

//va guardando los clientes que se anotan en cada clase
struct asistencia
{
    int idCliente;
    int cantInscriptos;
    sInscripcion Inscripcion;
};
typedef struct asistencia sAsistencia;

int buscar_idcliente(sClientes *cliente, string nombre, string apellido);

#endif // CLIENTE_H

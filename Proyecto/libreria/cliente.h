#ifndef CLIENTE_H
#define CLIENTE_H

#include <string.h>
#include <iostream>


using namespace std;

struct cliente
{
    int id;
    std::string nombre;
    std::string apellido;
    std::string email;
    std::string telefono;
    std::string fecha;
    int estado;
};
typedef struct cliente sClientes;

//guarda todas las clases que tiene un cliente
struct inscripcion
{
    int idClase;
    time_t fechaInscripcion;
};
typedef struct inscripcion sInscripcion;

//va guardando los clientes que se anotan en cada clase
struct asistencia
{
    int idCliente;
    int cantInscriptos;
    sInscripcion *Inscripcion=new sInscripcion[cantInscriptos];
};
typedef struct asistencia sAsistencias;

const sInscripcion InscripcionNula = { 0 , 0 };

int buscar_idcliente (sClientes *cliente,unsigned int tamT, string nombre, string apellido);

#endif // CLIENTE_H

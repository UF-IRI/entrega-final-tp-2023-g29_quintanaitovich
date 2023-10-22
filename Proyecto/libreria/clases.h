#ifndef CLASES_H
#define CLASES_H
#include <iostream>
#include "cliente.h"
using namespace std;

struct clases
{
    int id;
    std:: string nombre;
    int horario;
};
typedef struct clases sClases;

enum Reserva {ErrorReserva=-1, ExitoReserva=1};
typedef enum Reserva eReserva;

eReserva reservar_clase(sCliente*cliente, sClases*clases,int id,string actividad,int horario, string nombre, string apellido);

#endif // CLASES_H

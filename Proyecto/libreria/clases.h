#ifndef CLASES_H
#define CLASES_H

#include "cliente.h"
#include <iostream>
#include <string.h>

using namespace std;

struct clases
{
    int id;
    std:: string actividad;
    int horario;
};
typedef struct clases sClases;

enum Reserva {ErrorReserva=-1, ExitoReserva=1};
typedef enum Reserva eReserva;

#endif // CLASES_H

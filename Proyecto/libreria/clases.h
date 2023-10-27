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

bool HayEspacio (sClases*clases, string actividad, int id_clase);

enum Reserva {ErrorReserva=-1, ExitoReserva=1};
typedef enum Reserva eReserva;

enum eTieneReserva { PuedeReservar = 1, YaTieneLugar = -1 };
typedef enum eTieneReserva eTieneReserva;

#endif // CLASES_H

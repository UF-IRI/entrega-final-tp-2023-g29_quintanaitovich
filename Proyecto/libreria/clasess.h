#ifndef CLASESS_H
#define CLASESS_H

#include <iostream>
#include <string>
#include "cliente.h"

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

eReserva reservar_clase(sClientes*cliente, sClases*clases,int id,std::string actividad,int horario, string nombre,
                        string apellido, int tamT, int cant);
bool HayEspacio (sAsistencias*asistencia, unsigned int idClase, int tam);
int buscar_idclases(sClases *clases, unsigned int tamT, string actividad, int horario);
void AgruparPorHorarios(sClases*clases, int tamT, int*&grupitos, unsigned int &n, int unsigned horario);
void ResizeGrupitos(int *& grupitos, unsigned int &N, unsigned int nuevaN);

enum eTieneReserva { PuedeReservar = 1, YaTieneLugar = -1, ErrId=-2 };
typedef enum eTieneReserva eTieneReserva;

eTieneReserva TieneReserva(sAsistencias*asistencia,int idClase, int idCliente);

#endif // CLASESS_H

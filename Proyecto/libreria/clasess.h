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
    float horario;
};
typedef struct clases sClases;

enum Reserva {ErrorReserva=-1, ExitoReserva=1, PrimerReserva=-2};
typedef enum Reserva eReserva;

eReserva reservar_clase(sClientes* cliente, unsigned int cant, sClases* clases, unsigned int tamT,sAsistencias*asistencia,
          unsigned int tamMañana, string actividad, float horario, string nombre, string apellido);
bool HayEspacio (sAsistencias*asistencia, unsigned int idClase, int tam);
int buscar_idclases(sClases *clases, unsigned int tamT, string actividad, float horario);
void AgruparPorHorarios(sClases*clases, int tamT, int*&grupitos, unsigned int &n, float horario);
void ResizeGrupitos(int *& grupitos, unsigned int &N);
void clienteRandom (sClientes*clientes, sClases* clase, string &nombrecito, string &apellidito, string &actividadd, float &horarioo);
void ResizeInscripciones(sInscripcion*&inscripciones,int &num_clases);

#endif // CLASESS_H

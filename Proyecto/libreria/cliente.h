#ifndef CLIENTE_H
#define CLIENTE_H
#include <string.h>
#include <iostream>

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
typedef struct cliente sCliente;

struct gym
{
    sCliente* Clientes;
    int CantClientes;
};

typedef struct gym sGym;

int buscar_id(sCliente *cliente, string nombre, string apellido);

#endif // CLIENTE_H

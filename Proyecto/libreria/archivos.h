#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "cliente.h"
#include "clasess.h"
#include <string.h>
#include <fstream>

enum Archivos { ErrorApertura = -1,  ExitoOperacion = 1, ErrorEscritura= -2 };

typedef enum Archivos eArchivos;

eArchivos leerArchivoAsistencias (std::ifstream &archivo, sAsistencias *&asistencias, unsigned int &tam);
eArchivos leerArchivoClientes (std::ifstream &archivo, sClientes *&clientes, unsigned int &cant);
eArchivos leerArchivoClases (std::ifstream &archivo, sClases*& clases, unsigned int &tamT);
eArchivos escribirArchivoMañana(std::ofstream&archivo,sAsistencias*cliente_mañana, unsigned int cant_mañana);
void resizeClases(sClases*&clases, unsigned int &tamanio);
void resizeAsistencia (sAsistencias *& asistencia, unsigned int &tam);
void resizeClientes (sClientes *& clientes, unsigned int &tamC);
void resizeClienteMañana(sAsistencias*&asistencia_mañana, unsigned int&tamm, unsigned int nuevoTamm);

#endif // ARCHIVOS_H

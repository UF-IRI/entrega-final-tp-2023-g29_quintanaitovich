#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "cliente.h"
#include "clases.h"
#include <string.h>
#include <fstream>

enum Archivos { ErrorApertura = -1,  ExitoOperacion = 1, ErrorEscritura= -2 };

typedef enum Archivos eArchivos;

eArchivos leerArchivoClientes (std::fstream *archivo, sClientes *clientes);
eArchivos escribirArchivoClientes (std::fstream *archivo, sClientes *clientes);
eArchivos leerArchivoClases (std::fstream *archivo, sClases *clases);
eArchivos escribirArchivoGrupos (std::fstream* archivo, sClases* clases, int cantidad_clases);

#endif // ARCHIVOS_H

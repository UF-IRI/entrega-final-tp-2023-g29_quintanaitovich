#include "cliente.h"
#include "clasess.h"
#include "archivos.h"

#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


eArchivos leerArchivoAsistencias(std::ifstream &archivo, sAsistencias *&asistencias, unsigned int &tam) //tam es igual en la funcion que afuera
{
    unsigned int id_aux;
    unsigned int cant_ins_aux;
    sAsistencias*asistencia = new sAsistencias[tam]; //tam tiene que ser minimo 1

    while(archivo.good())
    {
        archivo.read((char*)&id_aux,sizeof(unsigned int));
        archivo.read((char*)&cant_ins_aux,sizeof(unsigned int));
        sInscripcion*inscripcion_aux = new sInscripcion [cant_ins_aux];

        for(int i=0; i<cant_ins_aux; i++)
        {
            //levanto directamente la estructura de inscripcion
            archivo.read((char*)&inscripcion_aux[i],sizeof(inscripcion));
        }

        //ver que esta persona no este en el archivo
        bool personaExistente = false; //declaro como que no existe
        int i=0;
        while(i<tam-1){
            if (asistencias[i].idCliente == id_aux){
                personaExistente = true;
                break;
            }
            i++;
        }
        //veo que los cupos de las clases se respeten

    if (!personaExistente)//si no esta, la copio en mi nuevo array sin los repetidos
        {
            // La persona no existe en el archivo, por lo que podemos agregarla al array y actualizar el tamaño
            asistencia[tam-1].idCliente=id_aux;
            asistencia[tam-1].cantInscriptos=cant_ins_aux;
            asistencia[tam-1].Inscripcion=inscripcion_aux;
            resizeAsistencia(asistencia, tam); //agrego memoria a medida que agrego clientes
        }
        else
        {
            // La persona ya existe en el archivo, por lo que no la agregamos y liberamos la memoria de inscripcion_aux
            delete[] inscripcion_aux;
        }
    }
    delete[] asistencia; // Liberar la memoria original
    asistencias=asistencia; //copia la lista sin repetidos
    return eArchivos::ExitoOperacion;
}

eArchivos leerArchivoClientes (std::ifstream &archivo, sClientes *&clientes, unsigned int &cant)
{
    if (!archivo.is_open())
    {
        return eArchivos::ErrorApertura;
    }

    char delimitador = ',';
    string linea;
    stringstream ss(linea);
    string auxid, auxnombre, auxapellido, auxemail, auxtelefono,auxFechaNac, auxestado;
    unsigned int cant_actual=cant;

    getline(archivo, linea); //descarto la linea del encabezado

    while (!archivo.eof() && getline(archivo, linea))
    {
        ss.clear(); //limpio el buffer de stringstream
        ss<<linea;
        getline(ss,auxid,delimitador);
        getline(ss,auxnombre,delimitador);
        getline(ss,auxapellido,delimitador);
        getline(ss,auxemail,delimitador);
        getline(ss,auxtelefono,delimitador);
        getline(ss,auxFechaNac,delimitador);
        getline(ss,auxestado,delimitador);

        if(cant_actual >= cant) //lo hago asi para no hacer tantos resize
            resizeClientes(clientes, cant);

        clientes[cant_actual-1].id= stoi (auxid);
        clientes[cant_actual-1].nombre=auxnombre;
        clientes[cant_actual-1].apellido=auxapellido;
        clientes[cant_actual-1].email=auxemail;
        clientes[cant_actual-1].telefono=auxtelefono;
        //como hago para leerlo si es time_t?
        clientes[cant_actual-1].fecha= auxFechaNac;
        clientes[cant_actual-1].estado= stoi (auxestado);

        cant_actual++;
    }
    cant=cant_actual;
    return eArchivos::ExitoOperacion;
}

eArchivos leerArchivoClases (std::ifstream &archivo, sClases *& clases, unsigned int &tamT)
{
    //no abro el archivo porque ya lo paso como ifstream
    if (!archivo.is_open()) {
        return ErrorApertura;
    }

    char delimiter = ',';
    string linea;
    stringstream s; //revisar si es asi el nombre
    string snombre, shorario, sidclase;
    //int sidclase, shorario;
    unsigned int tamactual= tamT;

    getline(archivo,linea);

    while (!archivo.eof() && getline(archivo,linea))//infile.good())
    {
        s.clear();
        s<<linea;

        getline(s,sidclase,delimiter);
        getline (s,snombre,delimiter);
        getline(s,shorario,delimiter);

        if (tamactual >=tamT)

        resizeClases(clases,tamT);

        //ver la conversion de string a int
        clases[tamactual-1].id=  std::stoi(sidclase);
        clases[tamactual-1].actividad=snombre;
        clases[tamactual-1].horario= std::stoi(shorario);
        tamactual++;
    }

    tamT=tamactual;
    return ExitoOperacion;
}

eArchivos escribirArchivoMañana(std::ofstream&archivo,sAsistencias*cliente_mañana, unsigned int cant_mañana)
{
    //
    if(archivo.is_open())
        return eArchivos::ErrorApertura;

    for(unsigned int i =0; i<cant_mañana; i++) //recorro el vector
    {
        archivo.write((char*)&cliente_mañana[i].idCliente,sizeof(int));
        archivo.write((char*)&cliente_mañana[i].cantInscriptos,sizeof(unsigned int));

        for(unsigned int j = 0; j < cliente_mañana[i].cantInscriptos; j++)
        {
            archivo.write((char*)&cliente_mañana[i].Inscripcion[j], sizeof(sInscripcion));
        }
    }
    return eArchivos::ExitoOperacion;
}
void resizeClases(sClases*&clases, unsigned int &tamanio)
{
    if(clases==nullptr)
    {
        if(tamanio<=0)
            clases=new sClases [tamanio++];
        return;
    }
    sClases* aux= new sClases[tamanio++]; // mi aux donde copio las clases lo hago del nuevo tamanio

    for(unsigned int i=0; i<tamanio;i++)
    {
        aux[i]= clases[i]; // copio las clases en mi vector auxiliar
    }

    delete[]clases; //borro asi libero memoria
    clases=aux; //copio mi axiliar en clases
}
void resizeAsistencia (sAsistencias *& asistencia, unsigned int &tam)
{
    if(asistencia==nullptr)
    {
        if(tam<=0)
            asistencia= new sAsistencias[tam++];
    return;
    }
    sAsistencias*aux=new sAsistencias[tam++];
    for(int i=0; i< tam; i++)
    {
        aux[i]= asistencia[i];
    }
    delete[]asistencia;
    asistencia=aux; //sAsistencias apunta al nuevo array
}

void resizeClientes (sClientes *& clientes, unsigned int &tamC)
{
    if(clientes ==nullptr) //la lista de clientes no apunta a nada --> nada para redimensionar
    {
        if(tamC<=0)
        {
            clientes= new cliente[tamC++]; //si no tenia espacio --> le agrego espacio directamente a clientes
        }
        return;
    }
    sClientes*aux= new sClientes[tamC++]; //si no es la primera vez, creo nuevo vector

    for(unsigned int i=0; i< tamC; i++)
    {
        aux[i]= clientes[i]; //copio dato pot dato (struct por struct)
    }

    delete[]clientes; //libero la memoria que estaba asignada a clientes
    clientes= aux; //clientes apunta al nuevo array
}

void resizeClienteMañana(sAsistencias*& asistencia_mañana, unsigned int &tamm)
{
    if(asistencia_mañana==nullptr)
    {
        if(tamm<=0)
            asistencia_mañana=new sAsistencias[tamm++];
        return;
    }
    sAsistencias*aux=new sAsistencias[tamm++];

    for(unsigned int i=0; i<tamm; i++)
    {
        aux[i]=asistencia_mañana[i];
    }
    delete[]asistencia_mañana;
    asistencia_mañana=aux;
}

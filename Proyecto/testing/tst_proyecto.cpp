#include <catch2/catch.hpp>
#include "clasess.h"
#include "cliente.h"
#include "clases.cpp"
#include "archivos.h"
#include "archivos.cpp"

int buscar_idcliente_test(sClientes* misClientes, unsigned int tamT, string nombre, string apellido){
    return buscar_idcliente(misClientes, tamT, nombre, apellido);
}
sClientes Clientes[3]={
    {1,"Agusti­n","Guerra","Agusti­nGuerra@bolandia.iri","462-185-1730","10-12-1966",0},
        {11,"Celeste","Ortega","CelesteOrtega@bolandia.iri","414-820-0908","12-08-1992",-2480},
        {26,"Daniela","Cortez","DanielaCortez@bolandia.iri","995-806-6312","27-02-1965",423}
    };
sClases Clases[5]={
    {5,"Spinning",18},{6,"Yoga",9},{26,"Zumba",12},{3,"Spinning",12},
    {16,"Pilates",18} };

TEST_CASE("buscar_id", "[fancy]")
{
    unsigned int tamT_test=3;
    sClientes * micliente= Clientes;
    REQUIRE(micliente != nullptr);

    int idnuevo=buscar_idcliente(micliente,tamT_test,"Celeste", "Ortega");
    REQUIRE(idnuevo == -1);

    int idnuevo1=buscar_idcliente(micliente, tamT_test,"Agusti­n","Guerra");
    REQUIRE(idnuevo1 == 1);
}

TEST_CASE("buscar idClase")
{
    unsigned int tamClases=5;
    sClases*misClases = Clases;
    REQUIRE(misClases!= nullptr);
    int idc1 = buscar_idclases(misClases,tamClases,"Yoga", 9);
    REQUIRE(idc1 == 6);

    int idc2=buscar_idclases(misClases,tamClases, "Stretching", 13);
    REQUIRE (idc2==-1);
}
TEST_CASE ("AgruparPorHorarios")
{
    //grupitos es un vector que tiene ids adentro
    sClases*misClases=Clases;
    REQUIRE(misClases != nullptr);
    unsigned int n=0;
    float horario=12;
    int*grupitos=nullptr;
    AgruparPorHorarios(misClases, 5 , grupitos, n, horario );
    //hacer test para el resize grupitos !!!
    REQUIRE (grupitos[0]== 26);
    REQUIRE(grupitos[1]== 3);

    delete[]grupitos;
}
TEST_CASE("Archivos")
{
    ifstream archivoClientes;
    archivoClientes.open("iriClientesGYM.csv");
    ifstream archivoClases;
    archivoClases.open("iriClasesGYM.csv");

    SECTION("LeerArchivoClientes")
    {
        sClientes*clientes=nullptr;
        unsigned int cantClientes=0;
        int result = leerArchivoClientes(archivoClientes,clientes,cantClientes);
        REQUIRE(result == eArchivos::ExitoOperacion);
        REQUIRE(cantClientes==250);
        REQUIRE(clientes[156].id==157);
        REQUIRE(clientes[156].nombre=="María");
        REQUIRE(clientes[156].apellido=="Díaz");
        //REQUIRE(clientes[156].email=="MarÃ­aDÃ­az@bolandia.iri");
        REQUIRE(clientes[156].telefono=="490-735-0987");
        REQUIRE(clientes[156].fecha=="18-01-1983");
        REQUIRE(clientes[156].estado==-8413);

        delete[]clientes;
    }
    SECTION("LeerArchivoClases")
    {
        sClases*clases=nullptr;
        unsigned int cantClases=0;
        int result = leerArchivoClases(archivoClases,clases,cantClases);
        REQUIRE(result == eArchivos::ExitoOperacion);
        REQUIRE(cantClases==60);
        REQUIRE(clases[32].id==33);
        REQUIRE(clases[32].actividad=="Boxeo");
        REQUIRE(clases[32].horario==19);

        delete[]clases;
    }
    SECTION("LeerArchivoAyer")
    {

    }
}

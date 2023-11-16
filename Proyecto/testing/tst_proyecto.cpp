#include <catch2/catch.hpp>
#include "clasess.h"
#include "cliente.h"
#include "clases.cpp"
#include "archivos.h"
#include "archivos.cpp"

int buscar_idcliente_test(sClientes* misClientes, unsigned int tamT, string nombre, string apellido, string email) {
    return buscar_idcliente(misClientes, tamT, nombre, apellido, email);
}
sClientes Clientes[3]={
    {1,"Agusti­n","Guerra","Agusti­nGuerra@bolandia.iri","462-185-1730","10-12-1966",0},
        {11,"Celeste","Ortega","CelesteOrtega@bolandia.iri","414-820-0908","12-08-1992",-2480},
        {26,"Daniela","Cortez","DanielaCortez@bolandia.iri","995-806-6312","27-02-1965",423}
    };
sClases Clases[5]={
    {5,"Spinning",18},{6,"Yoga",9},{26,"Zumba",12},{3,"Spinning",12},
    {16,"Pilates",18} };

TEST_CASE("buscar idCiente")
{
    unsigned int tam_test=3;
    sClientes*misClientes= Clientes; //apunta a la primera pos (agustin guerra)
    REQUIRE(misClientes != nullptr);
    int idNuevo1= buscar_idcliente_test(misClientes,tam_test,"Celeste","Ortega","CelesteOrtega@bolandia.iri");
    REQUIRE(idNuevo1==-1); //porque tiene estado negativo

    int idNuevo2= buscar_idcliente(misClientes,tam_test,"Agustin","Guerra","AgustinGuerra@bolandia.iri");
    REQUIRE(idNuevo2==1); //me devuelve el id
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
    unsigned int n=2;
    float horario=12;
    int*grupitos=nullptr;
    AgruparPorHorarios(misClases, 5 , grupitos, n, horario );
    //hacer test para el resize grupitos !!!
    int num=26,num2=3;
    REQUIRE (grupitos[0]== num);
    REQUIRE(grupitos[1]== num2);

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
        REQUIRE(clientes[156].email=="MarÃ­aDÃ­az@bolandia.iri");
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
}

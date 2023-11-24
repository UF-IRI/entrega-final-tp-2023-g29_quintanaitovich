#include <catch2/catch.hpp>
#include "clasess.h"
#include "cliente.h"
#include "clases.cpp"
#include "archivos.h"
#include "archivos.cpp"
#include <ctime>

int buscar_idcliente_test(sClientes* misClientes, unsigned int tamT, string nombre, string apellido){
    return buscar_idcliente(misClientes, tamT, nombre, apellido);
}
sClientes Clientes[4]={
    {1,"Agusti­n","Guerra","Agusti­nGuerra@bolandia.iri","462-185-1730","10-12-1966",0},
        {11,"Celeste","Ortega","CelesteOrtega@bolandia.iri","414-820-0908","12-08-1992",-2480},
        {26,"Daniela","Cortez","DanielaCortez@bolandia.iri","995-806-6312","27-02-1965",423},
        {10,"Gonzalo","Espinosa","GonzaloEspinosa@bolandia.iri","216-995-2329","29-12-1993",0}
    };

sClases Clases[5]={
    {5,"Spinning",18},{6,"Yoga",9},{26,"Zumba",12},{3,"Spinning",12},
    {16,"Pilates",18} };

time_t obtenerFechaHoraActual()
{
    return std::time(nullptr);
}


TEST_CASE("buscar_id", "[fancy]")
{
    unsigned int tamT_test=4;
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
    ifstream archivoAyer;
    archivoAyer.open("asistencias_1697673600000.dat", ios::binary);
    ofstream archivoMañana;
        archivoMañana.open("AsistenciaManiana.bin",ios::binary);

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

    }
    SECTION("LeerArchivoAyer")
    {
        sAsistencias*asistencias=nullptr;
        unsigned int i=0;
        int result=leerArchivoAsistencias(archivoAyer,asistencias,i);
        REQUIRE(result==eArchivos::ExitoOperacion);
    }
    SECTION("EscribirArchivoMañana")
    {
        sAsistencias asistencias[4]=
            {
                //agustin guerra
                {1,3,new sInscripcion[3]{{5,obtenerFechaHoraActual()},{26,obtenerFechaHoraActual()},{16,obtenerFechaHoraActual()}}}, //tiene dos clases en el mismo horario--> error
                //celeste ortega
                {11,2,new sInscripcion[2]{{14,obtenerFechaHoraActual()},{19,obtenerFechaHoraActual()}}},
                //daniela cortez
                {26,4,new sInscripcion[4]{{1,obtenerFechaHoraActual()},{18,obtenerFechaHoraActual()},
                                            {14,obtenerFechaHoraActual()},{3,obtenerFechaHoraActual()}}}, // 1 y 18 son al mismo horario.
                {10,2,new sInscripcion[2]{{1,obtenerFechaHoraActual()},{18,obtenerFechaHoraActual()}}}
            };
        int result2= escribirArchivoMañana(archivoMañana,asistencias,4);
        REQUIRE(result2==eArchivos::ExitoOperacion);
    }

}
TEST_CASE("Reservar clase")
{
    sClientes * micliente= Clientes; //tengo 4 declarados
    sClases*misClases=Clases; //tengo 5 declaradas
    sAsistencias asistencias[4]=
    {
        //agustin guerra
        {1,3,new sInscripcion[3]{{5,obtenerFechaHoraActual()},{26,obtenerFechaHoraActual()},{16,obtenerFechaHoraActual()}}}, //tiene dos clases en el mismo horario--> error
        //celeste ortega
        {11,2,new sInscripcion[2]{{14,obtenerFechaHoraActual()},{19,obtenerFechaHoraActual()}}},
        //daniela cortez
        {26,4,new sInscripcion[4]{{1,obtenerFechaHoraActual()},{18,obtenerFechaHoraActual()},
                 {14,obtenerFechaHoraActual()},{3,obtenerFechaHoraActual()}}}, // 1 y 18 son al mismo horario.
        {10,2,new sInscripcion[2]{{1,obtenerFechaHoraActual()},{18,obtenerFechaHoraActual()}}}
    };
    //BoolHayEspacio (adentro de reservar clase) siempre va a dar true en estos casos
    int result= reservar_clase(Clientes,4, Clases, 5, asistencias, 3, "Yoga", 9, "Agustin", "Guerra");
    REQUIRE(result == eReserva::ErrorReserva); //dos clases el mismo horario

    int result2= reservar_clase(Clientes,4, Clases, 5, asistencias,3, "Zumba", 12, "Daniela", "Cortez");
    REQUIRE(result2 == eReserva::ErrorReserva); //dos clases el mismo horario

    int result3= reservar_clase(Clientes,4, Clases, 5, asistencias,3, "Zumba", 12, "Celeste", "Ortega");
    REQUIRE(result3 == eReserva::ErrorReserva);//tiene estado negativo

    int result4= reservar_clase (Clientes,4,Clases,5,asistencias,3,"Yoga",9,"Gonzalo","Espinosa");
    REQUIRE(result4== eReserva::ExitoReserva);
}
TEST_CASE("Resizes")
{
    SECTION ("Resize clientes")
    {
        sClientes* clientes1 = nullptr;
        unsigned int tamC1 = 0;
        resizeClientes(clientes1, tamC1);
        REQUIRE(clientes1 != nullptr);
        REQUIRE(tamC1 == 1);

        // clientes no es nullptr y tamC es 3
        sClientes* clientes2 = new sClientes[3];
        unsigned int tamC2 = 3;

        resizeClientes(clientes2, tamC2);
        REQUIRE(tamC2 == 4);  // tamC se tiene que haber incrementado en 1
    }
}




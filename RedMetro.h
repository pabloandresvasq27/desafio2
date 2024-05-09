#ifndef REDMETRO_H
#define REDMETRO_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_LINEAS = 3;
const int MAX_ESTACIONES = 10;

class Estacion {
private:
    string nombreEstacion;
    string tipoEstacion;
    string idLineaTransferencia;
    Estacion* siguiente;
    Estacion* anterior;

public:
    Estacion(string nombre, string tipo, string idLinea);
    ~Estacion();
    string getNombreEstacion();
    string getTipoEstacion();
    string getIdLineaTransferencia();
    Estacion* getSiguiente();
    Estacion* getAnterior();
    void setSiguiente(Estacion* est);
    void setAnterior(Estacion* est);
};

class Linea {
private:
    string idLinea;
    int numeroEstaciones;
    Estacion** estaciones;

public:
    Linea(string id);
    ~Linea();
    string getIdLinea();
    int getNumeroEstaciones();
    Estacion** getEstaciones();
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string nombreEstacion);
};

class RedMetro {
private:
    string nombreRed;
    int numeroLineas;
    Linea** lineas;

public:
    RedMetro(string nombre);
    ~RedMetro();
    string getNombreRed();
    int getNumeroLineas();
    Linea** getLineas();
    void agregarLinea(Linea* linea);
    void eliminarLinea(string idLinea);
    void eliminarEstacion(string nombreEstacion);
    void mostrarRedesLineasEstaciones();
};

#endif





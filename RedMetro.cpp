#include "RedMetro.h"

// Implementación de los métodos de la clase Estacion
Estacion::Estacion(string nombre, string tipo, string idLinea) {
    this->nombreEstacion = nombre;
    this->tipoEstacion = tipo;
    this->idLineaTransferencia = idLinea;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Estacion::~Estacion() {}

string Estacion::getNombreEstacion() {
    return nombreEstacion;
}

string Estacion::getTipoEstacion() {
    return tipoEstacion;
}

string Estacion::getIdLineaTransferencia() {
    return idLineaTransferencia;
}

Estacion* Estacion::getSiguiente() {
    return siguiente;
}

Estacion* Estacion::getAnterior() {
    return anterior;
}

void Estacion::setSiguiente(Estacion* est) {
    siguiente = est;
}

void Estacion::setAnterior(Estacion* est) {
    anterior = est;
}

// Implementación de los métodos de la clase Linea
Linea::Linea(string id) {
    this->idLinea = id;
    this->numeroEstaciones = 0;
    this->estaciones = new Estacion*[MAX_ESTACIONES];
}

Linea::~Linea() {
    for (int i = 0; i < numeroEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;
}

string Linea::getIdLinea() {
    return idLinea;
}

int Linea::getNumeroEstaciones() {
    return numeroEstaciones;
}

Estacion** Linea::getEstaciones() {
    return estaciones;
}

void Linea::agregarEstacion(Estacion* estacion) {
    if (numeroEstaciones < MAX_ESTACIONES) {
        estaciones[numeroEstaciones++] = estacion;
    } else {
        cout << "No se pueden agregar más estaciones a esta línea." << endl;
    }
}

void Linea::eliminarEstacion(string nombreEstacion) {
    for (int i = 0; i < numeroEstaciones; ++i) {
        if (estaciones[i]->getNombreEstacion() == nombreEstacion) {
            delete estaciones[i];
            for (int j = i; j < numeroEstaciones - 1; ++j) {
                estaciones[j] = estaciones[j + 1];
            }
            estaciones[numeroEstaciones - 1] = nullptr;
            numeroEstaciones--;
            cout << "Estación eliminada exitosamente." << endl;
            return;
        }
    }
    cout << "La estación no se encuentra en esta línea." << endl;
}

// Implementación de los métodos de la clase RedMetro
RedMetro::RedMetro(string nombre) {
    this->nombreRed = nombre;
    this->numeroLineas = 0;
    this->lineas = new Linea*[MAX_LINEAS];
}

RedMetro::~RedMetro() {
    for (int i = 0; i < numeroLineas; ++i) {
        delete lineas[i];
    }
    delete[] lineas;
}

string RedMetro::getNombreRed() {
    return nombreRed;
}

int RedMetro::getNumeroLineas() {
    return numeroLineas;
}

Linea** RedMetro::getLineas() {
    return lineas;
}

void RedMetro::agregarLinea(Linea* linea) {
    if (numeroLineas < MAX_LINEAS) {
        lineas[numeroLineas++] = linea;
    } else {
        cout << "No se pueden agregar más líneas a esta red." << endl;
    }
}

void RedMetro::eliminarLinea(string idLinea) {
    for (int i = 0; i < numeroLineas; ++i) {
        if (lineas[i]->getIdLinea() == idLinea) {
            delete lineas[i];
            for (int j = i; j < numeroLineas - 1; ++j) {
                lineas[j] = lineas[j + 1];
            }
            lineas[numeroLineas - 1] = nullptr;
            numeroLineas--;
            cout << "Línea eliminada exitosamente." << endl;
            return;
        }
    }
    cout << "La línea no se encuentra en esta red." << endl;
}

void RedMetro::eliminarEstacion(string nombreEstacion) {
    for (int i = 0; i < numeroLineas; ++i) {
        lineas[i]->eliminarEstacion(nombreEstacion);
    }
    cout << "Estación eliminada exitosamente de todas las líneas." << endl;
}

void RedMetro::mostrarRedesLineasEstaciones() {
    cout << "Redes Metro:" << endl;
    cout << "------------" << endl;
    for (int i = 0; i < numeroLineas; ++i) {
        cout << "Nombre de la red: " << nombreRed << endl;
        cout << "Numero de lineas: " << numeroLineas << endl;
        cout << "Lineas:" << endl;
        cout << "-------" << endl;
        for (int j = 0; j < lineas[i]->getNumeroEstaciones(); ++j) {
            cout << "Id de linea: " << lineas[i]->getIdLinea() << endl;
            cout << "Numero de estaciones: " << lineas[i]->getNumeroEstaciones() << endl;
            cout << "Estaciones:" << endl;
            cout << "-----------" << endl;
            Estacion** estaciones = lineas[i]->getEstaciones();
            for (int k = 0; k < lineas[i]->getNumeroEstaciones(); ++k) {
                cout << "Nombre de la estacion: " << estaciones[k]->getNombreEstacion() << endl;
                cout << "Tipo de estacion: " << estaciones[k]->getTipoEstacion() << endl;
                cout << "Id de linea de transferencia: " << estaciones[k]->getIdLineaTransferencia() << endl;
                cout << endl;
            }
        }
    }
}


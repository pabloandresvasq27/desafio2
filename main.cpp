#include <iostream>
#include "RedMetro.h"

using namespace std;

void mostrarMenu() {
    cout << "MENU:" << endl;
    cout << "1. Agregar Red Metro" << endl;
    cout << "2. Agregar Linea a Red Metro" << endl;
    cout << "3. Agregar Estacion a Linea" << endl;
    cout << "4. Eliminar Estacion" << endl;
    cout << "5. Eliminar Linea" << endl;
    cout << "6. Mostrar Redes, Lineas y Estaciones" << endl;
    cout << "7. Salir" << endl;
    cout << "Ingrese su opcion: ";
}

int main() {
    RedMetro* redMetro = nullptr;
    bool salir = false;

    while (!salir) {
        mostrarMenu();
        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string nombreRed;
            cout << "Ingrese el nombre de la Red Metro: ";
            cin >> nombreRed;
            redMetro = new RedMetro(nombreRed);
            cout << "Red Metro agregada correctamente." << endl;
            break;
        }
        case 2: {
            if (redMetro != nullptr) {
                string idLinea;
                cout << "Ingrese el ID de la Linea: ";
                cin >> idLinea;
                Linea* linea = new Linea(idLinea);
                redMetro->agregarLinea(linea);
                cout << "Linea agregada correctamente a la Red Metro." << endl;
            } else {
                cout << "No existe una Red Metro." << endl;
            }
            break;
        }
        case 3: {
            if (redMetro != nullptr) {
                string idLinea;
                cout << "Ingrese el ID de la Linea a la que desea agregar la estacion: ";
                cin >> idLinea;

                // Buscar la linea en la red metro
                Linea* linea = nullptr;
                Linea** lineas = redMetro->getLineas();
                for (int i = 0; i < redMetro->getNumeroLineas(); ++i) {
                    if (lineas[i]->getIdLinea() == idLinea) {
                        linea = lineas[i];
                        break;
                    }
                }

                if (linea != nullptr) {
                    string nombreEstacion, tipoEstacion, idLineaTransferencia;
                    cout << "Ingrese el nombre de la estacion: ";
                    cin >> nombreEstacion;
                    cout << "Ingrese el tipo de la estacion (Transito/Transferencia): ";
                    cin >> tipoEstacion;

                    if (tipoEstacion == "Transferencia") {
                        cout << "Ingrese el ID de la Linea de Transferencia: ";
                        cin >> idLineaTransferencia;
                    } else {
                        idLineaTransferencia = "";
                    }

                    Estacion* estacion = new Estacion(nombreEstacion, tipoEstacion, idLineaTransferencia);
                    linea->agregarEstacion(estacion);
                    cout << "Estacion agregada correctamente a la Linea." << endl;
                } else {
                    cout << "No se encontró la Linea con el ID especificado." << endl;
                }
            } else {
                cout << "No existe una Red Metro." << endl;
            }
            break;
        }
        case 4: {
            if (redMetro != nullptr) {
                string nombreEstacion;
                cout << "Ingrese el nombre de la Estacion que desea eliminar: ";
                cin >> nombreEstacion;

                // Iterar sobre las lineas para encontrar la estacion y eliminarla
                Linea** lineas = redMetro->getLineas();
                for (int i = 0; i < redMetro->getNumeroLineas(); ++i) {
                    lineas[i]->eliminarEstacion(nombreEstacion);
                }
                cout << "Estacion eliminada correctamente." << endl;
            } else {
                cout << "No existe una Red Metro." << endl;
            }
            break;
        }
        case 5: {
            if (redMetro != nullptr) {
                string idLinea;
                cout << "Ingrese el ID de la Linea que desea eliminar: ";
                cin >> idLinea;
                redMetro->eliminarLinea(idLinea);
                cout << "Linea eliminada correctamente de la Red Metro." << endl;
            } else {
                cout << "No existe una Red Metro." << endl;
            }
            break;
        }

        case 6: {
            if (redMetro != nullptr) {
                redMetro->mostrarRedesLineasEstaciones();
            } else {
                cout << "No existe una Red Metro." << endl;
            }
            break;
        }
        case 7: {
            salir = true;
            break;
        }
        default: {
            cout << "Opcion no valida. Por favor ingrese una opcion valida." << endl;
        }
        }
    }

    delete redMetro;

    return 0;
}

#include "Seguridad.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;
// Muestra el menú principal del sistema de bitácora
void Seguridad::menu()
{
    int choice;
    do {
        system("cls"); // Limpia la pantalla

        // Menú de opciones
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t |   SISTEMA GESTIÓN BITACORA  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Despliegue Bitacora" << endl;
        cout << "\t\t\t 2. Agregar Registro" << endl;
        cout << "\t\t\t 3. Salir" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpción a escoger:[1/2/3]: ";

        cin >> choice;

        // Manejo de errores si la entrada no es un número válido
        if (cin.fail()) {
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            cout << "\n\t\t\tEntrada invalida. Intente de nuevo...";
            cin.get(); // Pausa
            continue;
        }

        cin.ignore(); // Limpia el salto de línea antes de usar getline

        switch (choice) {
            case 1:
                desplegar(); // Mostrar los registros
                break;
            case 2: {
                // Solicita los datos al usuario
                string nombre, accion;
                int aplicacion;
                cout << "\t\t\tIngrese accion realizada: ";
                getline(cin, accion);
                insertar(nombre, aplicacion, accion); // Agrega el registro
                break;
            }
            case 3:
                break; // Salir del programa
            default:
                cout << "\n\t\t\t Opción invalida...Por favor prueba otra vez..";
                cin.get();
        }
    } while (choice != 3); // Repite hasta que el usuario elija salir
}

// Agrega un nuevo registro al archivo bitacora.txt
void Seguridad::insertar(string nombre, int aplicacion, string accion)
{
    this->FechaLogger = chrono::system_clock::now();
    system("cls"); // Limpia la pantalla
    ofstream file("bitacora.bin", ios::binary | ios::app | ios::out); // Abre archivo para agregar contenido
    // Guarda los datos en el archivo con comillas para evitar errores con espacios
    file << std::quoted(nombre) << ","
        << std::quoted(std::to_string(aplicacion)) << ","
        << std::quoted(accion) << ","
        <<generarHora() << "\n";

    file.close(); // Cierra el archivo

    cout << "\n\t\t\tRegistro agregado exitosamente.\n";
    system("pause"); // Pausa para que el usuario vea el mensaje
}
string Seguridad::generarHora() const
{
    //se guarda en variable local el dato de fechalogger
    time_t tiempo = chrono::system_clock::to_time_t(FechaLogger);
    //el dato se convierte a formato local
    tm*tm_ptr = localtime(&tiempo);
    std::ostringstream registrotiempo;
    registrotiempo << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S");  // Formato personalizado
    return registrotiempo.str();
}
// Muestra los registros almacenados en bitacora
void Seguridad::desplegar()
{
    system("cls"); // Limpia pantalla
    fstream file("bitacora.bin", ios::binary | ios::in); // Abre el archivo para lectura
    int total = 0;
    string nombre, aplicacion, accion, timestamp;

    cout << "\n--------------------- Tabla de Detalles de Bitacora ---------------------" << endl;

    if (!file) {
        cout << "\n\t\t\tNo hay información disponible."; // Si el archivo no existe
    } else {
        // Lee cada línea del archivo usando std::quoted para manejar campos con espacios
        while (file >> std::quoted(nombre)) {
            file.ignore(); // Ignora coma
            file >> std::quoted(aplicacion);
            file.ignore();
            file >> std::quoted(accion);
            file.ignore();
            getline(file, timestamp); // El timestamp va sin comillas

            total++;
            // Muestra los datos del registro
            cout << "\n\t\t\tNombre Usuario     : " << nombre << endl;
            cout << "\t\t\tAplicación         : " << aplicacion << endl;
            cout << "\t\t\tAcción realizada   : " << accion << endl;
            cout << "\t\t\tFecha y Hora       : " << timestamp << endl;
            cout << "\t\t\t---------------------------------------------";
        }

        if (total == 0) {
            cout << "\n\t\t\tNo hay registros aún.";
        }
    }

    file.close(); // Cierra el archivo
    cout << "\n\n";
    system("pause"); // Pausa para que el usuario vea los resultados
}

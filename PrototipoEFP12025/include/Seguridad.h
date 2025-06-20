#ifndef SEGURIDAD_H
#define SEGURIDAD_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <filesystem>
using namespace std;

// Clase que maneja el sistema de bit�cora
class Seguridad {//
private:
    // Variables para almacenar informaci�n de cada registro
    string nombre, accion;
    int aplicacion;
    //Se llama a chrono para crear una variable en el tiempo actual
    chrono::system_clock::time_point FechaLogger;
public:
    //Sobrecargamos el constructor para inicializar el dato y hora actual
    Seguridad() : FechaLogger(chrono::system_clock::now()){}
    // Muestra el men� principal al usuario
    void menu();

    // Inserta un nuevo registro en la bit�cora
    void insertar(string nombre, int aplicacion, string accion);

    // Muestra todos los registros almacenados
    void desplegar();

     //Obsoleto pero util para futuros proyectos
     //string generarCodigoAplicacion();

     //String para Guardar la hora en un formato
     string generarHora() const;

};
#endif // SEGURIDAD_H

#include "Opciones.h"
#include<iostream>
#include "Seguridad.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "usuarios.h"
using namespace std;
Seguridad Bitacora;
//codigo realizado por HERSON GIRON

void Opciones::menu(string usuario)//Metodo de despliegue del menu
{
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout<<"\n\n\t      Menu General"<<endl;
        cout<<"\t ----------------------"<<endl;
        cout<<"\t | 1. Catalogos:      |"<<endl;
        cout<<"\t | 2. Informes:       |"<<endl;
        cout<<"\t | 3. Seguridad:       |"<<endl;
        cout<<"\t | 4. Regresar:       |"<<endl;
        cout<<"\t |                    |"<<endl;
        cout<<"\t | 5. Salir sistema:  |"<<endl;
        cout<<"\t ----------------------"<<endl<<endl;
        cout<<"   Ingrese opcion: ";
        cin>>opciones;
        switch (opciones)
        {
        case 1:
            {

            }
            break;
        case 2:
            {

            }
            break;
        case 3:
            {
            Bitacora.menu(); //Se llama al metodo menu de la clase bitacora para mostrar el menu de la bitacora
            }
            break;
        case 4:
            {
            repetir=false; //Al momento de ingresar el 4 no retorna al menu anterior
            }
            break;
        case 5:
            {
            repetir=false; //Si se ingresa 5 se cierra el programa por completo
            exit(0); //Finaliza el programa de forma inmediata (el 0 signifca que el programa termino correctamente sin errores)
            }
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(repetir);
}

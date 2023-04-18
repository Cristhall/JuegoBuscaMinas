//Librerias
#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"
#include "Usuario.h"

using namespace std;
//xonstantes para los parametros del tablero
const int FILASTABLERO = 5;
const int COLUMNASTABLERO = 5;
const int MINASENTABLERO = 3;
const bool MODODESARROLLADOR = true; //si es true se pueden ver todos los valores del tablero, si es false no.
int main()
{
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR); //creacion de objeto de la clase config y se manda los valores para poder modificar
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero()); //creacion de objeto de la clase juego con parametros que llaman a las funciones de config donde se da la modificacion del tablero.
    Usuario ingresoUsuario; //Creacion de objeto para utilizar funciones de la clase usuario
    juego.dibujarPortada("portada.txt"); //con el objeto se llama a la funcion juego para imprimir la portada.
    int opcion; //variables opcion para el menu principal
	do //inicio de ciclo do while para trabajar con el menu
    {
	system("cls");
	//impresion de formato con las opciones
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |      INGRESO DE SESION     |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Iniciar Sesion"<<endl;
	cout<<"\t\t\t 2. Crear cuenta"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion; //se almacena la respuesta

    switch(opcion) //inicio para saber que hacer segun la respuesta ingresada.
    {
	case 1:
		ingresoUsuario.iniciarSesion(); //si es 1 se llama con el objeto de la clase usuario a la funcion de iniciar sesion.
		break;
	case 2:
		ingresoUsuario.insertar(); //si es 2 se llama con el objeto de la clase usuario a la funcion de insertar o crear un usuario.
		break;
	case 3:
		exit(0); //se termina el programa
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez.."; //indica que la opcion ingresada es invalida
	}
	getch(); //pausa
    }while(opcion!=3); //fin del ciclo do while
    system("cls");
    juego.dibujarPortada("creditos.txt"); //cuando se termina el programa, con el objeto se llama a la funcion juego para imprimir la portada creditos.
    return 0;
}

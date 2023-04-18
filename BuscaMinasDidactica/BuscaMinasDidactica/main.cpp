#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"
#include "Usuario.h"

using namespace std;
const int FILASTABLERO = 5;
const int COLUMNASTABLERO = 5;
const int MINASENTABLERO = 3;
const bool MODODESARROLLADOR = true;
int main()
{
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR);
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    Usuario ingresoUsuario;
    juego.dibujarPortada("portada.txt");
    int opcion;
	do
    {
	system("cls");
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
    cin>>opcion;

    switch(opcion)
    {
	case 1:
		ingresoUsuario.iniciarSesion();
		break;
	case 2:
		ingresoUsuario.insertar();
		break;
	case 3:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(opcion!=3);
    system("cls");
    juego.dibujarPortada("creditos.txt");
    return 0;
}

#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class Usuario
{
	private:
		string nombre, contrasena; //atributos de la clase usuario
		int score; //atributo score para la clase usuario
		int valScore; //variable para poder llamar al score
	public:
		void iniciarSesion(); //funcion para iniciar sesion
		void menuSecundario(); //funcion de menu secudario para modificaciones
		void insertar(); // funcion para insertar o crear un usuario
		void modificar(); //funcion para modificar al usuario
		void borrar(); //funcion para eliminar al usuario
		void cambioScore (int valScore); //funcion que permitira guardar el score

};


#endif // USUARIO_H

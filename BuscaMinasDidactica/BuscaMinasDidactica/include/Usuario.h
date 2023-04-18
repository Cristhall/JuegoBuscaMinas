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
		string nombre, contrasena;
		int score;
		int valScore;
	public:
		void iniciarSesion();
		void menuSecundario();
		void insertar();
		void modificar();
		void borrar();
		void cambioScore (int valScore);

};


#endif // USUARIO_H

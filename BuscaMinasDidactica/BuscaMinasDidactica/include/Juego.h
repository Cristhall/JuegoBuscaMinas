#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego //Creación de la clase juego
{
private:
	int VIDASTABLERO = 3; //Variable fija para las vidas del jugador
	Tablero tablero; //Creación del objeto tablero
	int cantidadMinas; //Atributo de las cantidad de minas que se colocaran en el tablero.

	int aleatorio_en_rango(int minimo, int maximo); //Atributo que permite colocar aleatoriamente ciertos valores
	int filaAleatoria(); //atributo que indica la cantidad de filas que tendrá el tablero.
	int columnaAleatoria(); //Atributo que indica la cantidad de columnas que tendrá el tablero
public:
    Juego(Tablero tablero, int cantidadMinas); //función que llama a la clase tablero y a las minas que se ingresaran
	void colocarMinasAleatoriamente(); //Función que permite colocar las minas aleatoriamente en el tablero
	//funciones que guardan los parámetros en que se jugará
	int solicitarFilaUsuario();
	int solicitarColumnaUsuario();
	bool jugadorGana(); //Funcion que indica si el jugador pierde o gana
	void iniciar(); //Funcion que indica el inicio del juego
	void dibujarPortada(string nombreArchivo); //Dibujo hecho a base de símbolos que se muestra antes de todo
};

#endif // JUEGO_H

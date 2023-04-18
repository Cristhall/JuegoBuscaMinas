#include "Juego.h"
#include <fstream>
#include <unistd.h>
#include "Usuario.h"

int Juego::aleatorio_en_rango(int minimo, int maximo)
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}

	int Juego::filaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

	int Juego::columnaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}

	Juego::Juego(Tablero tablero, int cantidadMinas)
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->colocarMinasAleatoriamente();
	}

	void Juego::colocarMinasAleatoriamente()
	{
		int x, y, minasColocadas = 0;

		while (minasColocadas < this->cantidadMinas)
		{
			x = this->columnaAleatoria();
			y = this->filaAleatoria();
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++;
			}
		}
	}

	int Juego::solicitarFilaUsuario()
	{
		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar: ";
		cin >> fila;
		return fila - 1;
	}

	int Juego::solicitarColumnaUsuario()
	{
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar: ";
		cin >> columna;
		return columna - 1;
	}

	bool Juego::jugadorGana()
	{
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Juego::iniciar()
	{
		int fila, columna;
		int puntos = 0;
		Usuario agregarScore;
		while (true)
		{
			system ("cls");
			cout << "\n\tvidas: " << VIDASTABLERO << endl;
			cout << "\tPuntos: " << puntos << endl << endl;
			this->tablero.imprimir();
			fila = this->solicitarFilaUsuario();
			columna = this->solicitarColumnaUsuario();
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
			this -> VIDASTABLERO = VIDASTABLERO;
			if (!respuestaAUsuario)
			{
				VIDASTABLERO--;
				puntos = puntos - 5;
			}
			if (VIDASTABLERO == 0)
            {
				system("cls");
				cout << "\n\tPerdiste el Juego\n";
				puntos = puntos + 5;
				cout<<"\tObtuviste: "<<puntos<<" puntos "<<endl;
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				system("pause");
				agregarScore.cambioScore(puntos);
				break;
			}

			if (this->jugadorGana())
			{
				system("cls");
				puntos = puntos + 5;
				cout << "\n\tGanaste el Juego\n";
				cout<<"\tObtuviste: "<<puntos<<" puntos "<<endl;
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				system("pause");
				agregarScore.cambioScore(puntos);
				break;

			}
			puntos+=5;
		}
	}

	void Juego::dibujarPortada(string nombreArchivo)
	{
        string line;
        //char userInput = ' ';
        ifstream myFile(nombreArchivo);
        if(myFile.is_open())
        {
            //Se obtiene la portada del juego
            while( getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
            system("pause");
        }
        else
        {
            cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
            system("pause");
        }
	}

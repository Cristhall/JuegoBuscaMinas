#include "Juego.h" //liberia donde se encuentra la clase, sus atributos y funciones
#include <fstream> //libreria para trabajar con archivos
#include <unistd.h>
#include "Usuario.h"

int Juego::aleatorio_en_rango(int minimo, int maximo) //funcion que permitira agregar valores de manera aletaria
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1); //operacion que permite el ingreso de numeros aleatorios
	}

	int Juego::filaAleatoria() //Llamada al atributo de filas
	{
		//Retorna el valor de cantidad de filas a la altura del tablero.
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

	int Juego::columnaAleatoria()  //Llamada al atributo de columnas
	{
		//Retorna el valor de cantidad de columnas al ancho del tablero.
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}

	Juego::Juego(Tablero tablero, int cantidadMinas) //Funcion que llama a la clase mina y la cantidad de minas que se indicaron
	{
		this->tablero = tablero; //permite trabajar con la clase tablero y asi transferirle valores
		this->cantidadMinas = cantidadMinas; //establece la cantidad de minas, basado en la cantidad de minas
		this->colocarMinasAleatoriamente(); //llamado a la funcion de colocar minas de forma aleatoria
	}

	void Juego::colocarMinasAleatoriamente() //Llama a la funcion para poder colocar las minas en el tablero
	{
		int x, y, minasColocadas = 0; //varibles que guardan la posicion de la mina y un contador que lleva la cantidad de minas colocadas

		while (minasColocadas < this->cantidadMinas) //ciclo que se repetira hasta que se coloquen las minas indicadas en la configuracion
		{
			//se coloca una mina en un parametro aleatorio dentro del tablero
			x = this->columnaAleatoria();
			y = this->filaAleatoria();
			//condicional que permitira el conteo de minas colocadas, asi no habran errores de colocar diferente cantidad de minas a las indicadas.
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++; //contador de las minas colocadas
			}
		}
	}

	int Juego::solicitarFilaUsuario() //Funcion que permite ingresar la fila en que se jugara
	{
		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar: ";
		cin >> fila;
		return fila - 1; //Retorna - 1 debido a que tiene que quitar los encabezados
	}

	int Juego::solicitarColumnaUsuario() //Funcion que permite ingresar la columna en que se jugara
	{
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar: ";
		cin >> columna;
		return columna - 1; //Retorna - 1 debido a que tiene que quitar los encabezados
	}

	bool Juego::jugadorGana()
	{
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir(); //permite guardar contar las celdas que han sido encontradas y que no tienen mina
		if (conteo == 0)
		{
			return true; //El juego continua
		}
		else
		{
			return false; //Si la celda descubierta tiene una mina el juego termina
		}
	}

	void Juego::iniciar()
	{
		int fila, columna; //variables donde se guarda la fila y columna ingresada
		int puntos = 0; //contador para puntaje
		Usuario agregarScore; //crador de objeto para usar una funcion de la clase usuario
		while (true)
		{
			system ("cls");
			cout << "\n\tvidas: " << VIDASTABLERO << endl; //se imprime la cantidad de vidas que se tienen
			cout << "\tPuntos: " << puntos << endl << endl; //se imprime la cantidad de puntos acumulados
			this->tablero.imprimir(); //llamado al tablero y la funcion imprimir
			fila = this->solicitarFilaUsuario(); //llamada a la fila que se ingreso
			columna = this->solicitarColumnaUsuario(); //llamada a la columna que se ingreso
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila); //llamada al tablero para descubrir lo que tiene la celda
			this -> VIDASTABLERO = VIDASTABLERO; //se llaman la vidas
			if (!respuestaAUsuario) //si al descubir celda hay una vida se hace lo siguiente
			{
				VIDASTABLERO--; //se resta una vida
				puntos = puntos - 5; //los puntos se basan de movimientos, para que no coloque la mina encontrada con puntaje se le resta el punto de esa celda para continuar con el puntaje normal
			}
			if (VIDASTABLERO == 0) //al llegar a vidas 0
            {
				system("cls");
				cout << "\n\tPerdiste el Juego\n";
				puntos = puntos + 5; //debido a los movimientos, se restara 5 porque se perdio la vida, entoces para recuperar los puntos, se le suma 5
				cout<<"\tObtuviste: "<<puntos<<" puntos "<<endl; //se imprimen los puntos acumulados
				this->tablero.setModoDesarrollador(true); //se cambia a true el modo desarrollador para ver con respuestas el tablero
				this->tablero.imprimir(); //Se imprime nuevamente el tablero para que el jugador ve en donde estaba las otras minas y las zonas seguras
				system("pause");
				agregarScore.cambioScore(puntos); //se llama la funcion del usuario para almacenar el puntaje, se manda el score
				break;
			}

			if (this->jugadorGana())
			{
				system("cls");
				puntos = puntos + 5; //debido a los movimientos, se restara 5 porque se perdio la vida, entoces para recuperar los puntos, se le suma 5
				cout << "\n\tGanaste el Juego\n";
				cout<<"\tObtuviste: "<<puntos<<" puntos "<<endl; //se imprime los puntos acumulados
				this->tablero.setModoDesarrollador(true); //se cambia a true el modo desarrollador para ver con respuestas el tablero
				this->tablero.imprimir(); //se imprime nuevamente el tablero para mostrarle al jugador donde estaban las minas
				system("pause");
				agregarScore.cambioScore(puntos);  //se llama la funcion del usuario para almacenar el puntaje, se manda el score
				break;

			}
			puntos+=5; //sumatoria de 5 puntos por cada respuesta correcta
		}
	}
	void Juego::dibujarPortada(string nombreArchivo) //Se llama a la función de portada
	{
        string line;
        //char userInput = ' ';
        ifstream myFile(nombreArchivo); //Archivo que contiene la portada
        if(myFile.is_open()) //Condicional que permite abrir o no la portada
        {
            //Se obtiene la portada del juego
            //Se va imprimiendo linea por linea del archivo hasta completar el juego
            while( getline(myFile, line))
            {
                cout << line << endl; //impresion de cada linea del archivo
            }
            myFile.close(); //cierre del archivo al terminar de imprimirlo
            system("pause");
        }
        else
        {
            //Mensaje que aparece si la portada no se pudo abrir
            cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
            system("pause");
        }
	}

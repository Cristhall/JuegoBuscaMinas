#include "Tablero.h"
#include <sstream>
#include <iostream>

using namespace std;

Tablero::Tablero() //se invoca libreria tablero para adjuntar funcion
{
}
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador) //se agrega valor a la matriz con int en su construccion y un valor de falso y verdadero para su ejecucion
{
    this->alturaTablero = alturaTablero; //se implementa this para señalar al objeto que se llama la funcion
    this->anchoTablero = anchoTablero;
    this->modoDesarrollador = modoDesarrollador;
    int x, y;
    for (y=0; y < this->alturaTablero; y++)   //se genera un ciclo para crear las filas de la matriz hasta que sea igual al valor de la altura del tableto
    {
        vector<Celda> fila; //vector ayuda a establecer la plantilla de clase para contenedores de secuencia como cicloos en matriz
        for (x=0; x < this->anchoTablero; x++) //se genera un ciclo dentro del ciclo anterior para generar el numero de columnas
        {
            fila.push_back((Celda(x, y, false)));
        }
        this->contenidoTablero.push_back(fila);  //usamos la funcion pushback para añadir de la collecion un dato
    }
}
int Tablero::getAlturaTablero() //se establecen las funciones que daran valor a los dato que llamaremos con this
{
    return this->alturaTablero;
}
int Tablero::setAlturaTablero(int alturaTablero)
{
    this->alturaTablero = alturaTablero;
}
int Tablero::getAnchoTablero()
{
    return this->anchoTablero;
}
int Tablero::setAnchoTablero(int anchoTablero)
{
    this->anchoTablero = anchoTablero;
}
bool Tablero::getModoDesarrollador()
{
    return this->modoDesarrollador;
}
bool Tablero::setModoDesarrollador(bool modoDesarrollador)
{
    this->modoDesarrollador = modoDesarrollador;
}
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY) //se establece la matriz con los valores obtenido con la funcion get
{
    Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX);//establecemos las posiciones de los valores de retorno
    if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)
    {
        if (celdaTemporal.getMina())//si es sellecionada la celda como una mina
        {
            return "*";   //retornamos el valor en signo porque usamos string
        }
        else
        {
            int cantidadCelda=this->minasCercanas(coordenadaY,coordenadaX); //llamamos el valor minascernacasa a la funcion
            string cantidadCeldaString = " ";
            stringstream ss;   //realizamos un llamado como valor string
            ss << cantidadCelda;
            ss >> cantidadCeldaString;
            return cantidadCeldaString; //enviamos el valor del resultado final de la funcion que no fue una mina
        }
    }
    else     // se usa una opcion para posibilidad en donde se genera un dato string
    {
        return "?";
        //return ".";
    }
}
int Tablero::minasCercanas(int filaTablero, int columnaTablero)//se genera nuevamente una matriz con los valores establecido con las filas y columnas
{
        int contadorTablero = 0; //se iguala a cero para no alterar los valores numericos
        int filaInicioTablero, filaFinTablero, columnaInicioTablero, columnaFinTablero; //establecemos las variables a usar
        if (filaTablero <= 0)    //definimos un ciclo para establecer los valores cercanos a las celdas donde se obtendra el valor string *
		{
			filaInicioTablero = 0; //se establece la posicion de mina
		}
		else
		{
			filaInicioTablero = filaTablero - 1;
		}

		if (filaTablero + 1 >= this->alturaTablero)//se adjuntan las posiciones en el valor de celda
		{
			filaFinTablero = this->alturaTablero - 1; //se resta al valor asignado para intentar generar un cero como mina
		}
		else
		{
			filaFinTablero = filaTablero + 1; //se crean lo valores sumando al valor asignado a la celda y se repite el ciclo
		}

		if (columnaTablero <= 0)
		{
			columnaInicioTablero = 0;
		}
		else
		{
			columnaInicioTablero = columnaTablero - 1;
		}
		if (columnaTablero + 1 >= this->anchoTablero)
		{
			columnaFinTablero = this->anchoTablero - 1;
		}
		else
		{
			columnaFinTablero = columnaTablero + 1;
		}
		int m;
		for (m = filaInicioTablero; m <= filaFinTablero; m++)
		{
			int l;
			for (l = columnaInicioTablero; l <= columnaFinTablero; l++)
			{
				if (this->contenidoTablero.at(m).at(l).getMina())//establecemos un punto de interrupcion
				{
					contadorTablero++;
				}
			}
		}
		return contadorTablero;
}
void Tablero::imprimirSeparadorEncabezado() //generamos un cliclo con un valor string para que lo repita segun el ancho de la matriz
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			cout << "----";
			if (m + 2 == this->anchoTablero)
			{
				cout << "-";
			}
		}
		cout << "\n"; //se imprime el resultado del ciclo dejando un espacio para el valor asignado como columnas
	}

	void Tablero::imprimirSeparadorFilas()//generamos un cliclo con un valor string para que lo repita segun el largo de la matriz
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			if (m <= 1)
			{
				cout << "|---";
			}
			else
			{
				cout << "+---";
			}
			if (m == this->anchoTablero)
			{
				cout << "+";
			}
		}
		cout << "\n";//se imprime el resultado del ciclo dejando un espacio para el valor asignado como columnas
	}

	void Tablero::imprimirEncabezado()//generamos un cliclo con un valor string para que lo repita segun el ancho de la matriz
	{
		this->imprimirSeparadorEncabezado();
		cout << "|   ";
		int l;
		for (l = 0; l < this->anchoTablero; l++)
		{
			cout << "| " << l + 1 << " ";
			if (l + 1 == this->anchoTablero)
			{
				cout << "|";
			}
		}
		cout << "\n";//se imprime el resultado del ciclo dejando un espacio para el valor asignado en lo ancho de matriz
	}

	void Tablero::imprimir()
	{
		this->imprimirEncabezado();//usamos el puntero this para invocar la funcion de una clase
		this->imprimirSeparadorEncabezado();//usamos el puntero this para invocar la funcion
		int x, y;
		for (y = 0; y < this->alturaTablero; y++)//creamos un ciclo que imprima el valor string con un maximo del valor ingresado a lo ancho de la matriz
		{
			cout << "| " << y + 1 << " ";
			for (x = 0; x < this->anchoTablero; x++)//creamos un ciclo que imprima el valor string con un maximo del valor ingresado a lo largo de la matri
			{
				cout << "| " << this->getRepresentacionMina(x, y) << " ";//separamos la lineas de impresion
				if (x + 1 == this->anchoTablero)
				{
					cout << "|";
				}
			}
			cout << "\n";//tabulamos con salto de linea para determinar el espacio para agregar el valor a la celda
			this->imprimirSeparadorFilas();
		}
	}
    bool Tablero::colocarMina(int x, int y)//usamos la funcion para establecer si existe o no el valor cero correspondiente a la mina
	{
		return this->contenidoTablero.at(y).at(x).setMina(true);//usamos los valores x,y para establecer en posiciones de la matriz la mina
	}
    bool Tablero::descubrirMina(int x, int y)//incorporamos funcion para relacionar los valores correspondiente a la mina
	{
		this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);//si el valor corresponde a cero, se establece una mina
		Celda celda = this->contenidoTablero.at(y).at(x);
		if (celda.getMina())
		{
			return false; //si no fuese el valor de mina, se establecer valor normal
		}
		return true;
	}
	int Tablero::contarCeldasSinMinasYSinDescubrir()
	{
		int x, y, contador = 0;
		for (y = 0; y < this->alturaTablero; y++)//se crea ciclo para realizar el contador total de los valores obtenido a lo largo de matriz
		{
			for (x = 0; x < this->anchoTablero; x++)//se crea ciclo para realizar el contador total de los valores obtenido a lo ancho de matriz
			{
				Celda celdaTemporal = this->contenidoTablero.at(y).at(x);//se llama los valores asgnados a las posiciones de la matriz
				if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())
				{
					contador++;//se suma a la variable el valor de la operacion de suma
				}
			}
		}
		return contador; //la funcion retorna el total de la sumatoria de los valores en la matriz cuando su valor no es cero y no es mina
	}

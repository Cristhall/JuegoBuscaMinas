#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
#include "Celda.h"

using namespace std;


class Tablero
{
    public:
        Tablero();
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);//establece las dimenciones del tablero
        int getAlturaTablero();//trae las funciones que permiten obtener las filas de la altura
        int setAlturaTablero(int alturaTablero);//ivoca la funcion y poscicion de altura del tablero
        int getAnchoTablero();//trae funcones que permiten obtener las columnas de la altura
        int setAnchoTablero(int anchoTablero);//invoca la funcion y poscicion de ancho del tablero
        bool getModoDesarrollador();//permite obtener la funcion que manejara la interfaz del tablero de juego
        bool setModoDesarrollador(bool modoDesarrollador);//lamamos a la funcion que permite cambiar los valores establecidos en la matriz del tablero
        void imprimirSeparadorEncabezado();//trae valores string que se usaron con una tabulacion y respectivo ciclo para colocarse en la posicion del encabezado
        void imprimirSeparadorFilas();//trae al llamado las lineas que a travez de un codigo for se crean con al ancho del tablreo de juego
        void imprimirEncabezado();//invoca el enunacado establecido en la funcion imprimirencabezado
        void imprimir();//adjunta y llama los valores utilizados en la funcion que permite crear la matriz con sus respectivos datos
        bool colocarMina(int x, int y);//a travez de la matriz, establecemos el valor * que
        bool descubrirMina(int x, int y);//si la funcion es verdadera entonces se deplegariael valor string que correpnde a la mina
        int contarCeldasSinMinasYSinDescubrir();//se establece el valor totla de las celdas que no corresponden a las minas y estas se suman para que haya un punteo de juego

    protected:

    private:
        int alturaTablero, anchoTablero;//utilizamos la declaracion de las variables a utilizar
        bool modoDesarrollador;//es la funcion que cambia la interfaz del tablero
        vector<vector<Celda> > contenidoTablero;//permite almacenar una sellecion de objetos y presentarlos en la matriz

        string getRepresentacionMina(int x, int y);//invoca la funcion que trae el valor * el cual representa la mina en el juego
        int minasCercanas(int fila, int columna);//es la funcion que nos permite conocer segun el valor de los numeros al rededor de las casillas de la matriz si una mina esta cerca
};

#endif // TABLERO_H

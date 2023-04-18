#include "Celda.h"
#include <iostream>
using namespace std;
Celda::Celda() //Iniciamos el constructor
{
}
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina) //Enviamos lo que son los parametros en dirección al contructor. Las coordenadas aunque se llamen casi igual, no son lo mismo
{
    this->coordenadaX = coordenadaX; // this sirve para referenciar la clase que se esta trabajando en ese momento
    this->coordenadaY = coordenadaY; // -> apunta a una clase
    this->mina = estadoMina; //Guardamos el contenido de la variable
    this->minaDescubierta = false;
}
int Celda::setCoordenadaX(int coordenadaX) //Con set almacenamos los datos
{
    this->coordenadaX = coordenadaX;
} //Con estos gets y sets accedemos y cambiamos los valores internos de la clase
int Celda::getCoordenadaX() //Se llama al valor de la coordenada X con get
{
    return this->coordenadaX; //Con esta instrucción retornamos el valor de la cordenada X
}
int Celda::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY; //Se guardan los datos en memoria
}
int Celda::getCoordenadaY()
{
    return this->coordenadaY;
}
bool Celda::setMina(bool estadoMina)
{
    if (this->getMina()) //Se hace un comparativo
    {
        return false;
    }
    else{
        this->mina = estadoMina; //Pasamos el valor si es verdadero o falso
        return true;
    }
}
bool Celda::getMina()
{
    return this->mina;
}
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    this->minaDescubierta = minaDescubierta;
}
bool Celda::getMinaDescubierta()
{
    return this->minaDescubierta;
}
void Celda::imprimirCelda()
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << "con mina? " << this->mina << "\n"; //Se imprime en pantalla el mensaje con una pregunta
}


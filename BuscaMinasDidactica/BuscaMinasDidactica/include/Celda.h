#ifndef CELDA_H
#define CELDA_H
//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
//definicion generica de la clase
//estructura de cada celda dentro del tablero

class Celda
{
    public:
        Celda();
        Celda(int coordenadaX, int coordenadaY, bool estadoMina); //Este es un contructor con datos.
        int setCoordenadaX(int coordenadaX); //Set y Get. Nos permite acceder a todos los atributos privados
        int getCoordenadaX();
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();
        bool setMina(bool estadoMina); //bool estadoMina nos dice si se ve que hay una mina o no hay
        bool getMina(); //Devuelve true o false si hay una mina o no lo hay
        bool setMinaDescubierta(bool minaDescubierta);
        bool getMinaDescubierta();
        void imprimirCelda(); //Se utiliza para mostrar la cerlda en la coordanada adecuada
    protected:

    private: //Se definen los atributos privados
        int coordenadaX, coordenadaY;
        bool mina, minaDescubierta; //Estos son los dos atributos y son booleanos
};

#endif // CELDA_H

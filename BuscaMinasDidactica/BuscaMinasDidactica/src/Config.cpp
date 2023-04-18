#include <iostream>
#include <unistd.h>
#include "Config.h"
using namespace std;

Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero)
{
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
}
void Config::menuConfiguracion()
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero()<< " (DIFICIL= 5+ / INTERMEDIO= 2-4 / FACIL= 1) "  << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero()<<endl;
        cout << "\t\t5. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        if (opciones!=5)
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        switch (opciones)
        {
        case 1:
            {
                this->setfilasTablero(valorIngresado);
                cout << "Filas del Tablero actualizadas" << endl;
                break;
            }
        case 2:
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "Columnas del Tablero actualizadas" << endl;
                break;
            }
        case 3:
            {
                this->setminasTablero(valorIngresado);
                cout << "Minas del Tablero actualizadas" << endl;
                break;
            }
        case 4:
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Juego actualizado" << endl;
                break;
            }
        case 5: repetir = false;
                break;
        }
        system("pause");
    } while (repetir);
}
int Config::getfilasTablero()
{
    return this->filasTablero;
}
int Config::setfilasTablero(int filasTablero)
{
    this->filasTablero=filasTablero;
}
int Config::getcolumnasTablero()
{
    return this->columnasTablero;
}
int Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero=columnasTablero;
}
int Config::getminasTablero()
{
    return this->minasTablero;
}
int Config::setminasTablero(int minasTablero)
{
    this->minasTablero=minasTablero;
}
bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero;
}
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero;
}

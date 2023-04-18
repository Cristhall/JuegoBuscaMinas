#ifndef CONFIG_H
#define CONFIG_H


class Config
{
    // public indica que los atributos de esta clase son accesibles desde cualquier parte del programa.
    public:
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero); // Se utiliza para inicializar los Atributos de un objeto de la clase.
        int getfilasTablero(); // Es una función que devuelve el valor del atibuto filasTablero.
        int setfilasTablero(int filasTablero);//es una función  que establece el valor del atributo filasTablero y devuelve el nuevo valor.
        int getcolumnasTablero(); // Es una función que devuelve el valor del atibuto columnastablero.
        int setcolumnasTablero(int columnasTablero); //es una función  que establece el valor del atributo columnasTablero y devuelve el nuevo valor.
        int getminasTablero(); // Es una función que devuelve el valor del atibuto minastablero.
        int setminasTablero(int minasTablero); //es una función  que establece el valor del atributo minasTablero y devuelve el nuevo valor.
        bool getmodoDesarrolladorTablero(); // Es una función que devuelve el valor del atibuto mododesarrolladroTablero.
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero); //es una función  que establece el valor del atributo mododesarrolladorTablero y devuelve el nuevo valor.
        void menuConfiguracion();
    protected: //ndica que los miembros de datos y funciones miembro de esta clase son accesibles desde la propia clase y sus clases derivadas.

   //private indica que los miembros de datos y funciones miembro de esta clase sólo son accesibles desde la propia clase y no son accesibles desde ninguna otra parte del programa.
    private:
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
};

#endif // CONFIG_H

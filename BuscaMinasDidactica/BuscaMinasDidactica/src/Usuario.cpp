#include "Usuario.h"
#include "Juego.h"
#include "Config.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
//variables para poder configurar el juego, si no se modifican se mantienen de forma estándar
const int FILASTABLERO = 5;
const int COLUMNASTABLERO = 5;
const int MINASENTABLERO = 3;
const bool MODODESARROLLADOR = true;
string nameUsuario, codigo; //variables que guardan el usuario y contraseña del login
void Usuario::insertar() //funcion para crear usuario
{
	system("cls");
	fstream file; //libreria para trabajar con un archivo
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Agregar Nuevo Usuario -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre de Usuario: "; //se solicita el usuario
	cin>>nombre;
	cout<<"\t\t\tIngresa la contraseña: "; //se solicita la contraseña
	cin>>contrasena;
	score = 0; //el score al inicio es declarado como 0
	file.open("nombresUsuarios.txt", ios::app | ios::out); //se abre o crea el archivo
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score << "\n"; //se guarda informacion en el archivo
	file.close(); //se cierra el archivo
}
void Usuario::iniciarSesion() //funcion para iniciar sesion
{
    system("cls"); //limpia la pantalla
	fstream file; //libreria para trabajar con un archivo
	int found=0, opcion; //contador y varible opcion para respuesta
	file.open("nombresUsuarios.txt",ios::in); //se abre el archivo
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..."; //si no hay usuarios desplega la siguiente opcion
	}
	else
	{
		cout<<"\n----------------------------------------------------------------------------------------------------------------";
        cout<<"\n--------------------------------------------------- Iniciar Sesion ---------------------------------------------"<<endl;
		cout<<"\n\t\tUsuario: "; //solicita usuario
		cin>>nameUsuario;
		cout << "\t\tContraseña: "; //solicita contraseña
		cin >> codigo;
		file >> nombre >> contrasena >> score; //indica el orden del archivo
		while(!file.eof()) //ciclo que permite buscar al usuario
		{
			if(nameUsuario==nombre && codigo == contrasena) //condicional que dice que el usuario y la contraseña deben ser el mismo
			{
                Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR); //creacion de objeto de clase cofig para modificar parámetros
                Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero()); //creacion de objeto de la clase juego con los parámetros establecidos
                do{
                Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero()); //creacion de un segundo objeto de la clase juego para poder jugar
                system("cls"); //se limpia la pantalla
                cout<<"\n------------------------------------------------------------------------------------------------------------------------";
                cout<<"\n---------------------------------------------- BIENVENIDO AL JUEGO BUSCAMINAS ------------------------------------------"<<endl;
                cout << "\n\n\t\tUsuario: " << nombre << endl << endl; //imprime el nombre dle usuario que esta jugando
                //opciones para realizar determinada accion
                cout << "\n\t\t1. Iniciar juego" << endl;
                cout << "\t\t2. Configuracion del juego" << endl;
                cout << "\t\t3. Modificar usuario" << endl;
                cout << "\t\t4. Regresar a menú principal" << endl;
                cout<<"\t\t\t-------------------------------"<<endl;
                cout << "\t\tIngrese una opción: "; //se solicita la opcion
                cin >> opcion; //se guarda la opcion
                    switch(opcion) //inicio de cilo swith para las acciones a tomar dependiendo de la opcion ingresada
                    {
                        case 1:
                            file.close(); //se cierra el archivo
                            system("cls"); //se limpia la pantalla
                            juegoTemporal.iniciar(); //inicio de juego
                            system("pause"); //pausa para mostrar resultados
                            break;
                        case 2:
                            file.close(); //se cierra el acrhivo
                            configuracionJuego.menuConfiguracion(); //se traslada a la funcion menu configuracion para modificaciones de parámetros del juego
                            break;
                        case 3:
                            file.close(); //se cierra el archivo
                            menuSecundario(); //llama a la funcion del menu secundario
                            break;
                        case 4:
                            return; //regresa al menu principal
                        default:
                            cout << "\n\t\tOpcion inválida" << endl; //mensaje si la opcion ingresada no se encuentra
                            system("pause");
                            break;
                    }
                }while(opcion!=4); //fin del ciclo hasta que seleccione la opcion de salir
				found++; //si el nombre o usuario no son correctos el contador aumenta
			}
			file >> nombre >> contrasena >> score; //se ordena el archivo
		}
		if(found==0) //si el contador es mayor a 0 es porque no se encuentra el usuario
		{
			cout<<"\n\t\t\t El usuario o contraseña sin incorrectos...";
		}
		file.close(); //se cierra el archivo
	}
}
void Usuario::menuSecundario() //funcion menu secudario - opciones de modificacion de usuario
{
    int opcion; //variable que guarda la opcion del menu
	do //inicio ciclo do while
    {
	system("cls"); //se limpia la pantalla
	//aparece el menu con sus opciones
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------- Modificacion de Usuario ----------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Cambiar usuario o contraseña"<<endl;
	cout<<"\t\t\t 2. Borrar cuenta"<<endl;
	cout<<"\t\t\t 3. Regresar"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\tIngresa tu Opcion: "; //se indica ingresar una opcion
    cin>>opcion;
        switch(opcion) //inicio de swith para las opciones
        {
        case 1:
            modificar(); //se llama a la funcion modificar
            break;
        case 2:
            borrar(); //se llama a la funcion borrar
            break;
        case 3:
            return; //se regresa al menu secundario
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez.."; //mensaje de error si la opcion es incorrecta
            system ("pause");
            break;
        }
    }while(opcion!=3); //fin de ciclo hasta que se seleccione la opcion 3
}
void Usuario::modificar() //funcion de modificacion de usuario
{
	system("cls"); //se limpia la panatalla
	fstream file,file1; //se trabajara con dos archivos, siendo file1 el auxiliar o nuevo
	string name, c2; //variables para verificacion de usuario
	int found=0, opcion; //contador y variable para guardar la opcion del menu
	cout<<"\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
	//solicitud de usuario y contraseña para verificar que se esta seguro de modificar
	cout<<"\n Ingrese su nombre de usuario: ";
    cin>>name;
    cout<<" Ingrese la contraseña: ";
    cin>>c2;
    file1.open("Record.txt",ios::app | ios::out); //se abre o crea el archivo nuevo para guardar modificaciones
    file >> nombre >> contrasena >> score; //se llama al usuario que se encuentra en el primer file
    while(!file.eof()) //ciclo para encontrar al usuario
    {
        if(name!=nombre && c2!=contrasena){ //si el usuario o contraseña no son los mismos, se queda igual y continua
         file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score << "\n";
        }
        else{ //en caso contrario
            cout << "\n\tQue desea modificar?" << endl; //se pregunta que desea modificar
            cout << "\t1. Usuario" << endl;
            cout << "\t2. Contraseña" << endl;
            cout << "\tIngrese una opcion" << endl; //se solicita ingresar una opcion
            cin >> opcion;
            if (opcion == 1){
                cout<<"\n Ingrese su nombre de usuario: "; //se ingresa el nuevo nombre de usuario
                cin>>nombre; //se cambia el nombre
                file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score<< "\n"; //se guarda en el archivo nuevo o auxiliar
                nameUsuario = nombre; //el nuevo nameUsuario es el nombre que se cambio para evitar problemas con el usuario que se esta trabajando
                found++; //contador aumenta para indicar que si se encontro al usuario y se modifico
            }
            else{
                if (opcion == 2){
                    cout<<" Ingrese la contraseña: "; //solicita la nueva contraseña
                    cin>>contrasena; //guarda y reemplaza la nueva contraseña
                    codigo = contrasena; //se cambia la constraseña que se ingreso en el login para evitar errores del usuario con el que se esta trabajando
                }
            file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score << "\n"; //se guarda en el archivo nuevo o auxiliar
            found++; //contador aumenta para indicar que si se encontro al usuario y se modifico
            }
        }
        file >> nombre >> contrasena >> score; //se ordena el archivo
    }
    if(found==0) //si el contador no se aumento es porque el usuario no es el correcto
    {
        cout<<"\n\t\t\t Usuario no encontrado...";
    }
    file1.close(); //se cierra el archivo auxiliar
    file.close(); //cierre del archivo original
    remove("nombresUsuarios.txt"); //se elimina el archivo original
    rename("Record.txt","nombresUsuarios.txt"); //ya se que se traslado la informacion nueva, se le cambia el nombre al archivo auxiliar para evitar errores
}
void Usuario::borrar() //funcion para eliminar al usuario
{
	system("cls"); //se limpia la pantalla
	fstream file,file1; //se trabajara con dos archivos, siendo file1 el auxiliar o nuevo
	string name, c2; //variables para verificacion de usuario
	int found=0; //contador para ver si existe el usuario
	cout<<"\n------------------------- Borrar Cuenta -------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in); //se abre el archivo
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..."; //si esta vacio no deja eliminar, aunque si el usuario ingreso es porque si existen usuarios, solo es una precaucion
		file.close(); //se cierra el archivo
	}
	else //si hay informacion
	{
		//se solicita el usuario y contraseña para verificacion de que si es la persona
		cout<<"\n Ingrese el usuario para borrar: ";
		cin>>name;
		cout<<" Ingrese la contraseña: ";
		cin>>c2;
		file1.open("Record.txt",ios::app | ios::out); //se abre o crea el archivo auxiliar
		file >> nombre >> contrasena >> score; //se llama al usuario que esta en el primer file
		while(!file.eof()) //ciclo que busca al usuario a borrar
		{
			if(name!= nombre && c2 != contrasena) //si el usuario o contraseña son incorrectos se sigue y no hace cambios
			{
				file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score<< "\n";
			}
			else //de lo contrario
			{
				found++; //el contador aumenta
				cout << "\n\t\t\tBorrado de Usuario exitoso"; //se elimina el archivo
			}
			file >> nombre >> contrasena >> score; //se ordena la nueva informacion
		}
		if(found==0) //si el contador no aumento, es cuando hubo error, es porque el usuario no se encontro
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file1.close(); //se cierra el archivo auxiliar
		file.close(); //cierre del archivo original
		remove("nombresUsuarios.txt"); //se elimina el archivo original
		rename("Record.txt","nombresUsuarios.txt"); //ya se que se traslado la informacion nueva, se le cambia el nombre al archivo auxiliar para evitar errores
		exit(0);
	}
}
void Usuario::cambioScore(int valScore) //funcion para llamar, agregar o modificar el score
{
	//no se imprime nada en esta funcion, solo se hacen cambios en el archivo
	system("cls");
	fstream file,file1; //se trabaja con dos archivos
	string name; //creacion de variable para almacenar el usuario con que se esta trabajando
	file.open("nombresUsuarios.txt",ios::in); //se abre el archivo de usuarios
	if(!file) //solo como precaucion, si no existe ningun usuario indica que no hay informacion
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close(); //se cierra el archivo
	}
	else //si existe infromacion
	{
		name = nameUsuario; //el name sera el nameUsuario ingresado en el login
		file1.open("Record.txt",ios::app | ios::out); //se crea o abre el archivo nuevo
		file >> nombre >> contrasena >> score; //se basa de los usuarios en el primer file
		while(!file.eof()) //ciclo que busca al usuario con el que se esta trabajando
		{
			if(name!= nombre) //como precaucion, si el name no se encuentra, el usuario se mantiene igual y no hay cambios
			{
				file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score<< "\n";
			}
			else //de lo contrario
			{
				if(valScore > score) //el score se inicializo en cero, entonces si el puntaje es mayor a este se hace lo siguiente
                {
                    score = valScore; //el nuevo score es el valscore que es el valor de puntaje que se llamo
                    file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score << "\n"; //se guarda la nueva informacion en el archivo nuevo o auxiliar
                }
                else{
                    if(valScore <= score){ //si el valScore, puntaje, es menor o igual al score actual no se modifica, la idea es guardar el puntaje más alto que ha obtenido el usuario
                       valScore = score; //entonces el valScore sigue siendo el score actual
                       score = score; //se indica que score siempre es score
                       file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<<std::left<<std::setw(15)<< score << "\n"; //se guarda la nueva informacion en el archivo nuevo o auxiliar
                    }
                }
			}
			file >> nombre >> contrasena >> score; //se ordena la nueva informacion
		}
		file1.close(); //se cierra el archivo auxiliar
		file.close(); //cierre del archivo original
		remove("nombresUsuarios.txt"); //se elimina el archivo original
		rename("Record.txt","nombresUsuarios.txt"); //ya se que se traslado la informacion nueva, se le cambia el nombre al archivo auxiliar para evitar errores
	}
	cout << "\n\n\t\t\tFIN DEL JUEGO!!!\n\n\n";
}


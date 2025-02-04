//TRABAJO FINAL ESTRUCTURAS DE DATOS
//PADR�N VEHICULAR
//JUAN CARLOS SOL�RZANO CASTANEDO
//TDA: LDEA
#include <iostream>
#include <locale.h>
#include <stdexcept>
#include <limits>
using namespace std;

struct vehiculo { //Estructura del vehiculo
    int ID;
    char modelo[20];
    int anio;
    int noPuertas;
    char color[20];
    char placas[8];
    char propietario[20];
    float tenencia;
    int infracciones;
    vehiculo* siguiente;
    vehiculo* atras;
} *primero, *ultimo;// Fin Estructura

void ignorarInput() { //Funcion usada en insertarVehiculo para ignorar datos no validos
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void nombreLogo(){ //Funcion para mostrar el nombre y logo del programa
 cout<<"                                                        _________________________   \n";
 cout<<"                   /\\      _____          _____       |   |     |     |    | |  \   \n";
 cout<<"    ,-----,       /  \\____/__|__\_    ___/__|__\___   |___|_____|_____|____|_|___\ \n";
 cout<<" ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \ \n";
 cout<<"==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--' \n";
 cout<<"`````````````````````````````````````````````````````````````````````````````````````\n";
 cout<<"          P   A   D   R   O   N            V   E   H   I   C   U   L   A   R   ";
}; //Fin Funcion

void menu(){ //Funci�n que despliega el men�
    cout<<"\n\nMenu de opciones: \n\n";
    cout<<"1. Dar de alta un nuevo vehiculo\n";
    cout<<"2. Dar de baja un vehiculo existente\n";
    cout<<"3. Consultar la lista\n";
    cout<<"4. Filtrar por a�o, numero de puertas, tenencia o infracciones\n";
    cout<<"5. Buscar un vehiculo por placas\n";
    cout<<"0. Salir del programa\n";

} //Fin funci�n menu

void pickDato(void){ //MENU PARA ELEGIR FILTRO DE DATO NUMERICO
    cout<<"\nSelecciona el tipo de dato numerico que quieres buscar: \n";
    cout<<"1. ID\n";
    cout<<"2. A�o\n";
    cout<<"3. Numero de puertas\n";
    cout<<"4. Tenencia\n";
    cout<<"5. Numero de infracciones\n";
}

void insertarVehiculo(){ //Funci�n para insertar un nuevo elemento al inicio de la lista

vehiculo* nuevo = new vehiculo(); //Reserva memoria para un nuevo vehiculo
system("cls"); //Limpia la pantalla

do{ //INGRESAR ID
    cout<<"Ingresa el ID del vehiculo: ";
    cin.ignore();
    cin>>nuevo->ID;
    if (0 > nuevo->ID || !cin){
        ignorarInput();
        cout<<"\nIntroduce un ID numerico mayor a 0\n\n";
    }
}
while(0 > nuevo->ID); //FIN INGRESO ID
//////////////////////////////////////////////////////////////////////////////////
    cout<<"Ingresa el modelo del vehiculo: "; //INGRESA MODELO DEL VEHICULO
    cin.ignore();
    cin.getline(nuevo->modelo,20,'\n'); //FIN INGRESO MODELO
//////////////////////////////////////////////////////////////////////////////////
do{ //A�O VEHICULO
    cout<<"Ingresa el a�o del vehiculo: ";
    cin>>nuevo->anio;
    if (nuevo->anio < 1886){
        ignorarInput();
        cout<<"\nEl automovil se invent� en 1886, intentalo de nuevo.\n";
    }
}
while(nuevo->anio < 1886); //FIN A�O VEHICULO
//////////////////////////////////////////////////////////////////////////////////
do{
    cout<<"Ingresa el numero de puertas del vehiculo: ";
    cin>>nuevo->noPuertas;
    if (nuevo->noPuertas < 1){
        ignorarInput();
        cout<<"\nUn vehiculo necesita por lo menos 1 puerta.\n";
    }
}
while(nuevo->noPuertas < 0);
///////////////////////////////////////////////////////////////////////////////////
    cout<<"Ingresa el color del vehiculo: "; //INGRESA COLOR VEHICULO
    cin>>nuevo->color;
    cin.ignore(1,'\n');
///////////////////////////////////////////////////////////////////////////////////
    cout<<"Ingresa las placas del vehiculo: "; //INGRESA PLACAS VEHICULO
    cin>>nuevo->placas;
    cin.ignore(1,'\n');
///////////////////////////////////////////////////////////////////////////////////
    cout<<"Ingresa el nombre del propietario del vehiculo: "; //INGRESIA PROPIETARIO
    cin.ignore(0,'\n');
    cin.getline(nuevo->propietario,20,'\n');
///////////////////////////////////////////////////////////////////////////////////
do{ //TENENCIA
    cout<<"Ingresa la cantidad de tenencia del vehiculo: ";
    cin>> nuevo->tenencia;
    if ( 0 > nuevo->tenencia){
        ignorarInput();
        cout<<"\nNo se puede tener tenencia negativa.\n";
    }
}
while(0 > nuevo->tenencia); //FIN TENENCIA
//////////////////////////////////////////////////////////////////////////////////
do{ //INFRACCIONES
    cout<<"Ingresa la cantidad de infracciones que tiene el vehiculo: ";
    cin>> nuevo->infracciones;
    if (nuevo->infracciones < 0){
        ignorarInput();
        cout<<"\nNo se puede tener una cantidad negativa de infracciones.\n";
    }
}
while (nuevo->infracciones < 0);//FIN INFRACCIONES
////////////////////////////////////////////////////////////////////////////////// FIN DE INSERCIONES
if (primero == NULL){ //If
    primero = nuevo;
    primero->siguiente = NULL;
    primero->atras = NULL;
    ultimo = primero;
} //Fin de If
else { //Else
    ultimo->siguiente = nuevo;
    nuevo->siguiente = NULL;
    nuevo->atras = ultimo;
    ultimo = nuevo;
} //Fin de Else
cout<<"\nVehiculo registrado\n\n";
return;
} //Fin funci�n InsertarVehiculo

void eliminarVehiculo(){ //Funci�n para eliminar un vehiculo buscandolo por su ID. AQUI HAY ERROR AYUDA PORFAVOR
vehiculo* actual = new vehiculo(); //Liberando espacio para vehiculo actual
actual = primero; //Vehiculo actual comienza siendo el primero
vehiculo* anterior = new vehiculo(); //Liberando espacio para vehiculo anterior
anterior = NULL; //Anterior es nulo

int vehiculoBuscado = 0;
bool encontrado = false;

system("cls");
cout<<"Ingresa el ID del Vehiculo a buscar para eliminar: ";
cin>>vehiculoBuscado;

if (primero != NULL){ //If primero != NULL
    while (actual != NULL && encontrado != true){ //While
        if (actual->ID == vehiculoBuscado){ //If ID == vehiculoBuscado
            cout<<"\nVehiculo con el ID "<<vehiculoBuscado<<" encontrado.\n";

            if (actual == primero && actual->siguiente == NULL){
                primero = NULL;
                actual = NULL;
                cout<<"Vehiculo eliminado.\n";
                return;
                break;
            }
            else {
                if (actual == primero){ //If actual == primero
                    primero = primero->siguiente;
                    primero->atras = NULL;
                }
                 //Fin If actual == primeros
                else if (actual == ultimo){ //Else if actual == ultimo
                    anterior->siguiente = NULL;
                    ultimo = anterior;
                } //Fin else if actual == ultimo
                else { //Else
                    anterior->siguiente = actual->siguiente;
                    actual->siguiente->atras = anterior;
                } //Fin else

                cout<<"\nVehiculo eliminado.\n";
                encontrado = true;
                return;

            }

    }//FIN If actual == vehiculo buscado

anterior = actual;
actual = actual->siguiente;
}//FIN WHILE
    if (!encontrado){ //If no encontrado
        cout<<"\nEl vehiculo no pudo ser encontrado.\n\n";
        return;
    //Fin if no encontrado
    }

} //If primero != NULL FIN
else {//Else lista vacia
    cout<<"\nLa lista esta vacia.\n\n";
    return;
    }//Fin else lista vacia
}

void consultarLista(){ //Funci�n para consultar toda la lista
    vehiculo* actual = new vehiculo(); //Liberaci�n de espacio
    actual = primero;
    system("cls");
    if (primero != NULL){
        while(actual != NULL){
            cout<<"\nID: "<<actual->ID;
            cout<<"\nModelo: "<<actual->modelo;
            cout<<"\nA�o: "<<actual->anio;
            cout<<"\nNo. de puertas: "<<actual->noPuertas;
            cout<<"\nColor: "<<actual->color;
            cout<<"\nPlacas: "<<actual->placas;
            cout<<"\nPropietario: "<<actual->propietario;
            cout<<"\nTenencia: "<<actual->tenencia;
            cout<<"\nInfracciones: "<<actual->infracciones;
            cout<<"\n----------------------------------------\n";
            actual = actual->siguiente;
        }
    }
    else {
        cout<<"\nLa lista esta vacia. Por favor agrega vehiculos\n";
    }
}

void filtrarPorNum(){ //Funcion que filtra por valor numerico

vehiculo *actual = new vehiculo();
bool encontrado = false;
int buscar = 0;

system("cls");
pickDato();
cout<<"Ingrese el tipo de dato que desea buscar: ";
cin>>buscar;
switch (buscar){ //SWITCH
case 1: //CASE 1 ID
    {actual = primero;
    int datoBuscado = 0;
    cout<<"Escribe el ID del vehiculo que quieres buscar: ";
    cin>>datoBuscado;

    if (primero != NULL){
        while (actual != NULL && encontrado != true){

            if (actual->ID != datoBuscado && actual->siguiente != NULL){
                actual = actual->siguiente;
            }

            if (actual->ID == datoBuscado){
                cout<<"\nEl vehiculo con el ID "<<datoBuscado<<" ha sido encontrado.\n";
                 encontrado = true;
                        cout<<"\nID: "<<actual->ID;
                        cout<<"\nModelo: "<<actual->modelo;
                        cout<<"\nA�o: "<<actual->anio;
                        cout<<"\nNo. de puertas: "<<actual->noPuertas;
                        cout<<"\nColor: "<<actual->color;
                        cout<<"\nPlacas: "<<actual->placas;
                        cout<<"\nPropietario: "<<actual->propietario;
                        cout<<"\nTenencia: "<<actual->tenencia;
                        cout<<"\nInfracciones: "<<actual->infracciones;
                        cout<<"\n----------------------------------------\n";
            }

            if (encontrado == false){
                cout<<"\nEl vehiculo no pudo ser encontrado.\n\n";
                break;
            }
        }
    }
    else{
        cout<<"\nLa lista esta vacia.\n";
    }
break;
}//FIN CASE 1 ID
/////////////////////////////////////////////////////////////////////////////////////////
case 2: //CASE 2 A�O
    {actual = primero;
    int datoBuscado = 0;
    cout<<"Escribe el a�o del vehiculo que quieres buscar: ";
    cin>>datoBuscado;

    if (primero != NULL){
        while (actual != NULL && encontrado != true){

            if (actual->anio != datoBuscado && actual->siguiente != NULL){
                    actual = actual->siguiente;
            }

            if (actual->anio == datoBuscado){
                cout<<"\nEl vehiculo con el a�o "<<datoBuscado<<" ha sido encontrado.\n";
                encontrado = true;
                        cout<<"\nID: "<<actual->ID;
                        cout<<"\nModelo: "<<actual->modelo;
                        cout<<"\nA�o: "<<actual->anio;
                        cout<<"\nNo. de puertas: "<<actual->noPuertas;
                        cout<<"\nColor: "<<actual->color;
                        cout<<"\nPlacas: "<<actual->placas;
                        cout<<"\nPropietario: "<<actual->propietario;
                        cout<<"\nTenencia: "<<actual->tenencia;
                        cout<<"\nInfracciones: "<<actual->infracciones;
                        cout<<"\n----------------------------------------\n";
            }

            if (encontrado == false){
                cout<<"\nEl vehiculo no pudo ser encontrado.\n\n";
                break;
            }
        }//while
    }//if primero!=null
    else{
        cout<<"\nLa lista esta vacia.\n";
    }
break; //FIN CASE 2 A�O
}

/////////////////////////////////////////////////////////////////////////////////////////
case 3://CASE 3 NUMERO DE PUERTAS
{actual = primero;
int datoBuscado = 0;
    cout<<"Escribe el numero de puertas del vehiculo que quieres buscar: ";
    cin>>datoBuscado;

    if (primero != NULL){
        while (actual != NULL && encontrado != true){

            if (actual->noPuertas != datoBuscado && actual->siguiente != NULL){
                    actual = actual->siguiente;
            }

            if (actual->noPuertas == datoBuscado){
                cout<<"\nEl vehiculo con "<<datoBuscado<<" puertas ha sido encontrado.\n";
                encontrado = true;
                        cout<<"\nID: "<<actual->ID;
                        cout<<"\nModelo: "<<actual->modelo;
                        cout<<"\nA�o: "<<actual->anio;
                        cout<<"\nNo. de puertas: "<<actual->noPuertas;
                        cout<<"\nColor: "<<actual->color;
                        cout<<"\nPlacas: "<<actual->placas;
                        cout<<"\nPropietario: "<<actual->propietario;
                        cout<<"\nTenencia: "<<actual->tenencia;
                        cout<<"\nInfracciones: "<<actual->infracciones;
                        cout<<"\n----------------------------------------\n";
            }

            if (encontrado == false){
                cout<<"\nEl vehiculo no pudo ser encontrado.\n\n";
                break;
            }
        }//while
    }//if primero!=null
    else{
        cout<<"\nLa lista esta vacia.\n";
    }
break;
} //FIN CASE 3 NO PUERTAS

case 4: //CASE 4
{actual = primero;
    int datoBuscado = 0;
    cout<<"Escribe la cantidad de tenencia del vehiculo que quieres buscar: ";
    cin>>datoBuscado;

    if (primero != NULL){
        while (actual != NULL && encontrado != true){

            if (actual->tenencia != datoBuscado && actual->siguiente != NULL){
                    actual = actual->siguiente;
            }

            if (actual->tenencia == datoBuscado){
                cout<<"\nEl vehiculo con la tenencia de "<<datoBuscado<<" ha sido encontrado.\n";
                encontrado = true;
                        cout<<"\nID: "<<actual->ID;
                        cout<<"\nModelo: "<<actual->modelo;
                        cout<<"\nA�o: "<<actual->anio;
                        cout<<"\nNo. de puertas: "<<actual->noPuertas;
                        cout<<"\nColor: "<<actual->color;
                        cout<<"\nPlacas: "<<actual->placas;
                        cout<<"\nPropietario: "<<actual->propietario;
                        cout<<"\nTenencia: "<<actual->tenencia;
                        cout<<"\nInfracciones: "<<actual->infracciones;
                        cout<<"\n----------------------------------------\n";
            }

            if (encontrado == false){
                cout<<"\nEl vehiculo no pudo ser encontrado.\n\n";
                break;
            }
        }//while
    }//if primero!=null
    else{
        cout<<"\nLa lista esta vacia.\n";
    }
break;
} //FIN CASE 4 TENENCIA
case 5: //CASE 5
{actual = primero;
    int datoBuscado = 0;
    cout<<"Escribe el numero de infracciones del vehiculo que quieres buscar: ";
    cin>>datoBuscado;

    if (primero != NULL){
        while (actual != NULL && encontrado != true){

            if (actual->infracciones != datoBuscado && actual->siguiente != NULL){
                    actual = actual->siguiente;
            }

            if (actual->infracciones == datoBuscado){
                cout<<"\nEl vehiculo con "<<datoBuscado<<" infracciones ha sido encontrado.\n";
                encontrado = true;
                        cout<<"\nID: "<<actual->ID;
                        cout<<"\nModelo: "<<actual->modelo;
                        cout<<"\nA�o: "<<actual->anio;
                        cout<<"\nNo. de puertas: "<<actual->noPuertas;
                        cout<<"\nColor: "<<actual->color;
                        cout<<"\nPlacas: "<<actual->placas;
                        cout<<"\nPropietario: "<<actual->propietario;
                        cout<<"\nTenencia: "<<actual->tenencia;
                        cout<<"\nInfracciones: "<<actual->infracciones;
                        cout<<"\n----------------------------------------\n";
            }

            if (encontrado == false){
                cout<<"\nEl vehiculo no pudo ser encontrado.\n\n";
                break;
            }
        }//while
    }//if primero!=null
    else{
        cout<<"\nLa lista esta vacia.\n";
    }
break;
}//FIN CASE 5 INFRACCIONES

default:
    cout<<"\nOpcion no valida. Introduce una opcion valida.\n";
}//FIN SWITCH


}

void busquedaPorPlacas(){ //Funci�n que busca por placas de vehiculo
vehiculo *actual = new vehiculo();
bool encontrado = false;
actual = primero;
char placasBuscadas[8];
system("cls");

    cout<<"Escribe la placa del vehiculo que quieres buscar: ";
    cin>>placasBuscadas;

    if (primero != NULL){
        while (actual != NULL && encontrado != true){
            for (int i=0;i<8;i++){
                if (actual->placas[i] == placasBuscadas[i]){
                    encontrado = true;
                }
                else{
                    encontrado = false;
                    actual = actual->siguiente;
                    break;
                }
            }
            if (encontrado == true){
                cout<<"\nEl vehiculo con el numero de infracciones "<<placasBuscadas<<" ha sido encontrado.\n";

                vehiculo* actual = new vehiculo();
                actual = primero;

                if (primero != NULL){
                    while(actual != NULL){
                        cout<<"\nID: "<<actual->ID;
                        cout<<"\nModelo: "<<actual->modelo;
                        cout<<"\nA�o: "<<actual->anio;
                        cout<<"\nNo. de puertas: "<<actual->noPuertas;
                        cout<<"\nColor: "<<actual->color;
                        cout<<"\nPlacas: "<<actual->placas;
                        cout<<"\nPropietario: "<<actual->propietario;
                        cout<<"\nTenencia: "<<actual->tenencia;
                        cout<<"\nInfracciones: "<<actual->infracciones;
                        cout<<"\n----------------------------------------\n";
                        actual = actual->siguiente;
                    }
                }
                else {
                    cout<<"\nLa lista esta vacia. Por favor agrega vehiculos.";
                }
                encontrado = true;
            }
            actual = actual->siguiente;
        }
        if (!encontrado){
            cout<<"\nEl vehiculo no pudo ser encontrado.\n\n";
        }
    }
    else {
        cout<<"\nLa lista esta vacia.\n";
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(){ //Funci�n main
setlocale(LC_ALL, "");
int operacion;
	//Declarar Variables
    do {
        system("cls");
        nombreLogo();
    	menu();
    	cout<<"Selecciona la operacion a realizar --> ";
    	cin>>operacion;

    	switch(operacion){
    		case 1: insertarVehiculo(); break;
    		case 2: eliminarVehiculo(); break;
    		case 3: consultarLista(); break;
    		case 4: filtrarPorNum(); break;
    		case 5: busquedaPorPlacas(); break;
    		case 0: cout<<"Saliendo del Programa..."<<endl; break;
    		default: cout<<"Operacion NO Valida...."<<endl; break;
		}//Switch
		system("PAUSE");
	}while(operacion != 0);

return(0);

};  //Fin funcion main


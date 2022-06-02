//============================================================================
// Name        : 04Clase.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//hpp = hider plus plus

/*ESTRUCTURA*/
struct Fecha{
   int dia;
   int mes;
   int anio;
};


/*FUNCION DE INICIALIZACION*/
Fecha fecha (int d, int m, int a){
   return {d,m,a};
}

/*FUNCION DE CONVERSION A STRING
 * TIENE QUE DEVOLVER UNA CADENA QUE TENGA DIA MES Y ANIO
 ej "2/10/2022"*/

string fechaToString(Fecha f){
   return to_string(f.dia) + "/" + to_string(f.mes) + "/" + to_string(f.anio);
};
//C++ no puede concatenar enteros con cadenas, solo cadenas (en JAVA si se puede)
//por eso se usa to_string



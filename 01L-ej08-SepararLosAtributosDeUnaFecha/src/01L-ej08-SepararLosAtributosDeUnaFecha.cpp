//============================================================================
// Name        : 01L-ej08-SepararLosAtributosDeUnaFecha.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/* LECCION 1 EJERCICIO 8 - SEPARAR LOS ATRIBUTOS DE UNA FECHA
Dificultad: b�sica, Requerido: Indispensable.
Dado un n�mero de ocho d�gitos que representa una fecha con formato aaaammdd,
se pide mostrar por separado el d�a, el mes y el a�o de la fecha ingresada.
TIP: Usar operadores / (division) y % (modulo)*/

int main() {
	cout << "Ingrese una fecha con el formato anio, mes y dia de esta manera: aaaammdd:" << endl;
	cout << "Por ejemplo 20221016" << endl;
	int fecha;
	cin >> fecha;

	int dia = fecha % 100;
	//int mes = fecha / 100;
	int anio = fecha / 10000 ;


	//impresion x pantalla de resultados
	cout << "El dia es: " << dia << endl;
	//cout << "El mes es: " << mes << endl;
	cout << "El anio es: " << anio << endl;




	return 0;
}//FIN DEL PROGRAMA

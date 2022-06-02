//============================================================================
// Name        : 01L-ej03-DivisionEnteraYModulo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/* LECCION 1 EJERCICIO 3 - DIVISION ENTERA Y MODULO
Dificultad: básica, Requerido: Indispensable.

Se ingresa por teclado un valor numérico entero, informar:
1. La quinta parte de dicho valor.
2. El resto que surge al dividir el valor ingresado en cinco partes iguales.
3. La séptima parte de la quinta parte del valor ingresado. */


int main() {
	cout << "Ingrese un numero entero:" << endl;
	int num;
	cin >> num;

	//calculos pedidos y delcaracion de sus variables
	double quintaParte = num / 5;
	double restoQuintaParte = num % 5;
	double septimaParte = quintaParte / 7;

	//impresion de rtas x pantalla
	cout << "La quinta parte de " << num << " es: " << quintaParte << endl;
	cout << "El resto de la quinta parte de " << num << " es: " << restoQuintaParte << endl;
	cout << "La 7ma parte de la 5ta parte de " << num << " es: " << septimaParte << endl;

	return 0;
} //FIN PROGRAMA

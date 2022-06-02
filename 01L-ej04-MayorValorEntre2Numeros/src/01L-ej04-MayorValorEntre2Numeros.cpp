//============================================================================
// Name        : 01L-ej04-MayorValorEntre2Numeros.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/* LECCION 1 EJERCICIO 4 - MAYOR VALOR ENTRE 2 NUMEROS
Dificultad: básica, Requerido: Indispensable.
Se ingresa por teclado dos valores numéricos enteros diferentes entre sí, informar
cuál es el mayor.*/


int main() {
	cout << "Ingrese un numero entero:" << endl;
	int num1;
	cin >> num1;
	cout << "Ingrese otro numero entero:" << endl;
	int num2;
	cin >> num2;

	//Condicional if para determinar cual es los 2 numeros es + grande
	if (num1 > num2) {
      cout << "El 1er numero ingresado (" << num1 << ") es mayor que el 2do (" << num2 <<")";
   } else {
      cout << "El 2do numero ingresado (" << num2 << ") es mayor que el 1ro (" << num1 <<")";
   }




	return 0;
} //FIN DEL PROGRAMA

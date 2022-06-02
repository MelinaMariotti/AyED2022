//============================================================================
// Name        : 01L-ej05-MayorYMenorValorEntre2Numeros.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/* LECCION 1 EJERCICIO 5 - MAYOR Y MENOR VALOR ENTRE 2 NUMEROS
Dificultad: básica, Requerido: Indispensable.
Se ingresa por teclado dos valores numéricos enteros, informar cuál es el mayor y
cuál el menor. Si son iguales, entonces, mostrar un mensaje con el siguiente texto:
“Los valores ingresados son iguales”.*/


int main() {
	cout << "Ingrese un numero entero:" << endl;
	int num1;
	cin >> num1;
	cout << "Ingrese otro numero entero:" << endl;
	int num2;
	cin >> num2;

	//Condicional IF pero determinar el mayor, el menor o si son iguales
	if (num1 > num2) {
	   cout << "El 1er numero ingresado (" << num1 << ") es mayor que el 2do (" << num2 << ")" << endl;
   } else if (num2 > num1){
      cout << "El 2do numero ingresado (" << num2 << ") es mayor que el 1ero (" << num1 << ")" << endl;
   } else if ( num1 == num2) {
      cout << "Los valores ingresados son iguales";
   }



	return 0;
} // FIN DEL PROGRAMA

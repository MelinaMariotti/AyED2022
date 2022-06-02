//============================================================================
// Name        : 01L-ej02-CocienteEntre2Numeros.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/*LECCION 1 EJERCICIO 2 - COCIENTE ENTRE 2 NUMEROS
Dificultad: básica, Requerido: Indispensable.

Se ingresan por teclado dos valores numéricos enteros: a y b, se pide calcular e
informar el cociente a/b, validando que b sea distinto de cero. En tal caso, mostrar
un mensaje de error en la consola. */


int main() {

	cout << "Ingrese un numero entero:" << endl;
	int a;
	cin >> a;
	cout << "Ingrese otro numero entero:" << endl;
	int b;
	cin >> b;

	//decl de variable y formula del cociente
	int cociente = a / b;

	//condicion para validacion b!=0
	if (b != 0) {
      cout << "El cociente entre " << a << " y " << b << " es: " << cociente;
   } else {
      cout << "ERROR! El segundo numero es 0 por lo no es posible realizar el cociente.";
   }




	return 0;
} //FIN PROGRAMA

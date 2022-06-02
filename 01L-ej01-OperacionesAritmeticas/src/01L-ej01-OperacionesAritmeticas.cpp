//============================================================================
// Name        : 01L-ej01-OperacionesAritmeticas.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/*LECCION 1 - EJ 01 - OPERACIONES ARITMETICAS
Se ingresan por teclado dos valores numéricos enteros, a y b, se pide calcular e in-
formar por consola el resultado de las siguientes operaciones:
1. La suma: a+b.
2. La diferencia: a-b.
3. El producto: a*b.
4. El cociente: a/b, aceptando que b es distinto de 0 (cero). */

int main() {

	cout << "Ingrese un numero entero:";
	int a;
	cin >> a;
	cout << "Ingrese otro numero entero:";
	int b;
	cin >> b;

	//declaracion de variables para los calculos
	int suma = a+ b;
	int diferencia = a - b;
	int producto = a * b;
	int cociente = a / b;

	cout << "La suma entre " << a << " y " << b << " es: " << suma << endl;
	cout << "La diferencia entre " << a << " y " << b << " es: " << diferencia << endl;
	cout << "El producto entre " << a << " y " << b << " es: " << producto << endl;
	//condicion para validar que b != 0
	if (b != 0) {
	   cout << "El cociente entre " << a << " y " << b << " es: " << cociente << endl;
   } else {
      cout << "No se puede realizar el cociente porque b es 0";
   } //FIN IF, validacion b!=0




	return 0;
} //FIN PROGRAMA

//============================================================================
// Name        : 01L-ej29-ConjuntoDivididoPorValoresCero.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/* LECCION 1 EJERCICIO 29
Dificultad: moderada, Requerido: Indispensable.
Se dispone de un conjunto de valores enteros positivos cuyo ingreso finaliza con la
llegada de un número negativo.
El conjunto está dividido en subconjuntos, separados entre sí mediante valores
0 (cero). Se pide informar:
1. Por cada subconjunto:
   a. Promedio de sus valores.
   b. Valor mínimo.
2. Para el conjunto completo:
   a. Cantidad de subconjuntos.
   b. Sumatoria de sus valores.
   c. Número del subconjunto en el que se ingresó el mayor valor (será
   único), indicando también cuál fue ese valor y en qué posición
   relativa se encontró.*/

//lo hizo con while
/*p.e
 Si ingresamos 44400
 SE CONTEMPLAN CONJUNTOS VACIOS*/


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int n;
	cin >> n;

	while (n>=0) //xq cuando ingresa un negativo sale del bucle, itera mientas sea positivo
	{
	   while (n > 0) // o (n != 0)
	   {
	      cin >> n; //aca vas leyendo el siguiente numero ingresado
	   }
	   //cuando ingresa 0ya salio del while anterior
	   //vuelve a leer xq el "n" es 0
	   cin >> 0;
	}

	return 0;
}

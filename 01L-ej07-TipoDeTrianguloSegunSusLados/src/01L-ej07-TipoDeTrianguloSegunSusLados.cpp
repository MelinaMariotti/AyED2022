//============================================================================
// Name        : 01L-ej07-TipoDeTrianguloSegunSusLados.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/* LECCION 1 EJRCICIO 7 - TIPO DE TRIANGULO SEGUN SUS LADOS
Dificultad: básica, Requerido: Indispensable.
Se ingresan tres valores que representan las longitudes de los lados de un triángulo,
informar cuál es el tipo del triángulo ingresado (isósceles, equilátero o escaleno).*/

int main() {

   cout << "Ingrese valor de un lado del triangulo:" << endl;
   int lado1;
   cin >> lado1;
   cout << "Ingrese el valor del 2do lado del triangulo:" << endl;
   int lado2;
   cin >> lado2;
   cout << "Ingrese el valor del 3er lado del triangulo:" << endl;
   int lado3;
   cin >> lado3;

   //Condicional if para determinar que tipo de triangulo es
   //Triangulo equilatero
   if (lado1 == lado2 && lado2 == lado3){
      cout << "El triangulo es equilatero porque sus 3 lados miden lo mismo" << endl;
   } else if (
         ((lado1 == lado2) && (lado3 !=lado1 && lado3 != lado2)) ||
         ((lado1 == lado3) && (lado2 !=lado1 && lado2 != lado3)) ||
         ((lado2 == lado3) && (lado1 !=lado2 && lado1 != lado3))
         ) {
      cout << "El triangulo es isosceles porque 2 de sus lados son iguales y 1 distinto." << endl;

   } else if ((lado1 != lado2) && (lado2 != lado3)) {
      cout << "El triangulo es escaleno porque todos sus lados son distintos" << endl;
   }



   return 0;
}//FIN DEL PROGRAMA

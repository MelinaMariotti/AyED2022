//============================================================================
// Name        : 01L-ej06-MayorMedioYMenorValorEntre3Numeros.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/* LECCION 1 EJERCICIO 6 - MAYOR, MEDIO Y MENOR VALOR ENTRE 3 NUMEROS
 Se ingresan tres valores numéricos enteros, diferentes entre sí, informar cuál es el
 menor, cuál está en el medio y cuál es el mayor.*/

int main()
{
   cout<<"Ingrese un numero entero:"<<endl;
   int num1;
   cin>>num1;
   cout<<"Ingrese un 2do numero entero:"<<endl;
   int num2;
   cin>>num2;
   cout<<"Ingrese 3er un numero entero:"<<endl;
   int num3;
   cin>>num3;

   //Condicional if para c/caso para saber cual es el mayor, intermedio y menor de todos
   //1ER CASO
   //Si el 1ero es mayor al 2do Y al 3ero es xq es el + grande de los 3
   if( num1>num2&&num1>num3 )
   {
      cout<<"El mayor numero de los 3 es: "<<num1<<endl;

      //Si el 2do es mayor que el 3ero, el 2do es el del medio y el 3ero el menor valor
      if( num2>num3 )
      {
         cout<<"El numero intermedio de los 3 es: "<<num2<<endl;
         cout<<"Y el menor numero de los 3 es: "<<num3<<endl;

         //Sino caso contrario, el 2do es el menor y el 3ero el intermedio
      }
      else
      {
         cout<<"El numero intermedio de los 3 es: "<<num3<<endl;
         cout<<"Y el menor numero de los 3 es: "<<num2<<endl;
      }
   } //FIN 1ER CASO

   //2DO CASO
   //Si el 2do es mayor al 1ero Y al 3ero es xq es el + grande de los 3
   if( num2>num1&&num2>num3 )
   {
      cout<<"El mayor numero de los 3 es: "<<num2<<endl;

      //Si el 1ero es mayor que el 3ero, el 1ero es el del medio y el 3ero el menor valor
      if( num1>num3 )
      {
         cout<<"El numero intermedio de los 3 es: "<<num1<<endl;
         cout<<"Y el menor numero de los 3 es: "<<num3<<endl;

         //Sino caso contrario, el 1ero es el menor y el 3ero el intermedio
      }
      else
      {
         cout<<"El numero intermedio de los 3 es: "<<num3<<endl;
         cout<<"Y el menor numero de los 3 es: "<<num1<<endl;
      }
   }   //FIN 2DO CASO

   //3ER CASO
   //Si el 3ero es mayor al 1ero Y al 2do es xq es el + grande de los 3
   if( num3>num1&&num3>num2 )
   {
      cout<<"El mayor numero de los 3 es: "<<num3<<endl;

      //Si el 1ero es mayor que el 2do, el 1ero es el del medio y el 2do el menor valor
      if( num1>num2 )
      {
         cout<<"El numero intermedio de los 3 es: "<<num1<<endl;
         cout<<"Y el menor numero de los 3 es: "<<num2<<endl;

         //Sino caso contrario, el 1ero es el menor y el 2do el intermedio
      }
      else
      {
         cout<<"El numero intermedio de los 3 es: "<<num2<<endl;
         cout<<"Y el menor numero de los 3 es: "<<num1<<endl;
      }

   } //FIN 3ER CASO

   return 0;
} //FIN DEL PROGRAMA

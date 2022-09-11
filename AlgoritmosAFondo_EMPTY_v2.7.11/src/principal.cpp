
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

//para funcion find
struct Persona
{
   int dni;
   string nom;
};

//funcion inicializacion
Persona persona(int dni, string nom)
{
   return {dni, nom};
}

int cmpPersonaDni(Persona p, int dni)
{
   return p.dni-dni;
}

//para la funcion orderedInsert
int cmpInt(int a, int b)
{
   return a-b;
}

int cmpIntDes(int a, int b)
{
   return b-a;
}

//int _redimensionar(int* arr, int cap)
//{
////creo un nuevo array el doble de grande que el anterior
//   int* nuevo = new int[cap*2];
//   return cap*2;
//}
//

template <typename T>
void bubbleSortMEJORADO(T arr[], int len){
   //arranca con que NO esta ordenado
   bool ordenado = false;

   while( !ordenado ){ //mientras que NO ESTE ordenado itera para justamente ordenarlo

      ordenado = true;
      for(int i=0; i<len-1; i++){
         if(arr[i] > arr[i+1]){
            //guardamos el 1er de los 2 elementos, para no pisarlo
            int aux = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = arr[i];

            //si entro en este if es porque se tenia que permutar
            //ponemos que sigue desordenado para que el while siga analizando el programa
            ordenado = false;
         }
         //si no entro al if es porque esta ordenado
      }
   }
}

int main()
{
//   //FUNCION ORDEREDINSERT
//   int a[10]= {4,3,2,1};
//   int len = 4;
//
//   cout << "---Before insert---" << endl;
//   for(int i=0; i<len; i++)
//   {
//      cout << a[i] << "  ";
//   }
//   int e = 5;
//   int pos = orderedInsert<int>(a,len,e, cmpIntDes);
//   cout << "\n" << "El: " << e << ", insertado en pos: " << pos << endl;
//
//   cout << "---POST insert---" << endl;
//   for(int i=0; i<len; i++)
//      {
//         cout << a[i] << "  ";
//      }


   //funcion sort
   int a[5] = {4,1,5,3,2};
   int len = 5;

   cout << "Before sorting:" << endl;
   for(int i=0; i<len; i++)
   {
      cout << a[i] << '|';
   }

   sort<int>(a,len,cmpInt);

   cout << "\n" << "AFTER sorting:" << endl;
   for(int i=0; i<len; i++)
   {
      cout << a[i] << '|';
   }


//   short a = 123;
//   short* p = &a;
//
//   cout << p << endl; //cualquier verdura
//   cout << *p << endl; // 123
//
//   *p = 456;
//
//   cout << *p << endl; // 456



   return 0;
} //END MAIN

#endif

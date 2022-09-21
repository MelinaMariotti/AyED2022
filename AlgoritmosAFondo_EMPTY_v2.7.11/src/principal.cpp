
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

struct Persona
{
   string nombre;
   int dni;
};

string personaToString(Persona x)
{
   char sep = 1;
   string sNombre=x.nombre;
   string sDni=to_string(x.dni);
   return sNombre+sep+sDni;
}

Persona personaFromString(string s)
{
   char sep = 1;
   Persona x;
   string t0 = getTokenAt(s,sep,0);
   x.nombre=t0;
   string t1 = getTokenAt(s,sep,1);
   x.dni=stoi(t1);
   return x;
}

Persona persona(string nombre,int dni)
{
   Persona a;
   a.nombre = nombre;
   a.dni = dni;
   return a;
}

//funcion para arrayFind
int cmpPersonaDni(Persona p, int dni){
   return p.dni-dni;
}

int cmpInt(int a, int b){
   return a-b;
}

int cmpIntDes(int a, int b){
   return b-a;
}

int main()
{
   Array<int> arr = array<int>();
   arrayAdd<int>(arr, 5);
   arrayAdd<int>(arr, 96);
   arrayAdd<int>(arr, 18);
   arrayAdd<int>(arr, 1);
   arrayAdd<int>(arr, 60);

   cout << "Array before sorting:" << endl;
   for (int i=0; i<arraySize<int>(arr); i++){
      int* p = arrayGet<int>(arr, i);
      cout << *p << endl;
   }

   arraySort<int>(arr, cmpInt);

   cout<< "\n" << "Array sorted: " << endl;
   for(int i=0; i<arraySize<int>(arr); i++){
      int* p = arrayGet<int>(arr, i);
      cout << *p << endl;
   }


   return 0;
} //END MAIN

#endif

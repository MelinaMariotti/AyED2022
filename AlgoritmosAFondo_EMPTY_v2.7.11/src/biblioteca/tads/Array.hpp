#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
void redimensionar(T*& arr, int& cap){
   //creo un nuevo array el doble de grande que el anterior
   T* newArr = new T[cap*2];

   //lo hacemos hasta cap xq total el size del nuevo arr contendra el doble de cap
   for(int i=0; i<cap; i++)
   {
      //pasamos los elementos de arr a -> newArr
      newArr[i] = arr[i];
   }

   //una vez que pasamos los datos al newArr, le "devolvemos" la memoria del arr al S.O
   //liberamos arr
   delete arr;

   //hacemos que arr apunte a newArr
   arr = newArr;

   cap*=2;
}

//Que vamos a encapsular? Que es lo que quiero guardar? Un Array generico
template<typename T>
struct Array
{
   T* arr; //lo manejo como un puntero
   int len;
   int cap;
};

//funcion de inicializacion -> creamos un array vacio
template<typename T>
Array<T> array() //retorna una instancia/struct de array
{
   Array<T> ret;
   //como indica la API, "len comenzara en 0 e ++ a medida que se agregen elemetos"
   ret.len = 0;
   ret.cap = 100; //lo tenemos que harcodear
   ret.arr = new T[ret.cap]; //checkear esto, como es que funcion?
   return ret;
}

//add "t" at the end of the array
template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   if(a.len >= a.cap){ //no es (a.len + 1), porque add incrementa el len
      redimensionar(a.arr, a.cap);
   }
   return add<T>(a.arr, a.len, t); //la propia funcion add<> ya tiene integrada la pos que debe retornar
}

//Retorna la direcci�n del elemento de a ubicado en la posici�n p
template<typename T>
T* arrayGet(Array<T> a,int p)
{
   return &a.arr[p]; //RETORNA UN PUNTERO, que contiene la direccion/abicacion de memoria
}

//Asigna el elemento t en la posici�n p del array a
template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   //create a pointer
   T* ptr = arrayGet<T>(a, p);
   //use the (* operator + the ptr) to access to the content
   //and set the content of 't'
   *ptr = t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   if(a.len >= a.cap){
      redimensionar(a.arr, a.cap);
   }
   insert<T>(a.arr, a.len, t, p);
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   return remove(a.arr, a.len, p);
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
  //es tan simple como invocar a array(); ?
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find<T, K>(a.arr, a.len, k, cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   if(a.len >= a.cap){
      redimensionar(a.arr, a.cap);
   }
   return orderedInsert<T>(a.arr, a.len, t, cmpTT);
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr, a.len, cmpTT);
}

#endif

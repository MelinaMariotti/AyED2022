
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

//No pueden haber 2 values para una unica key

template<typename K,typename V>
struct Map
{
   Array<K> keys; //vino x defecto, el tipo de dato generico <K> siempre debe ser primitivo, no una struc p.e
   Array<V> values; //vino x defecto
   int pos; //para la iteracion sobre el map
};

//Initialize the map
//think that the var1.var2 -> sets a value
template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   //initialize the array of keys with the TAD ARRAY function
   m.keys = array<K>();
   //initialize the array of values with the TAD ARRAY function
   m.values = array<V>();
   m.pos = 0;
   return m;
}

template<typename K,typename V>
bool mapContainsKey(Map<K,V> m,K k) //OK
{
   for(int i=0; i<arraySize<K>(m.keys); i++)
   {
      if (m.keys.arr[i] == k){
         return true;
      }
   }
   return false;
}

//return the & of the value associated with the parameter key -> (K k)
template<typename K,typename V>
V* mapGetValue(Map<K,V> m,K k) //OK
{
   if( mapContainsKey<K,V>(m,k) )
   {
      for(int i=0; i<arraySize<K>(m.keys); i++)
      {
         if(m.keys.arr[i] == k)
         {
            return arrayGet<V>(m.values, i);
         }
      }
   }
   return NULL;
}

//Add  to the map
template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v) //OK
{
   V* valuePtr = mapGetValue<K,V>(m,k);

   //if it already contained and associated value, we replace it
   if((mapContainsKey<K,V>(m,k)) && (valuePtr != NULL))
   {
      *valuePtr = v; //assign the new value to the key
      return valuePtr; //return pointer
   }

   //else, we add the pair at the end of the map to continue respecting the order of the map
   arrayAdd<K>(m.keys, k);
   int pos = arrayAdd<V>(m.values, v); //add the value and keep the pos
   return &m.values.arr[pos];
}

template<typename K,typename V>
int findKey(Map<K,V> m,K k){ //added by me, this function is NOT in the API
   int pos;
   for(int i=0; i<arraySize<K>(m.keys); i++)
   {
      if(m.keys.arr[i] == k)
      {
         pos = i;
      }
   }
   return pos;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k) //IS IT OK?
{
   int pos = findKey(m, k);
   V value = *mapGetValue<K,V>(m, k);

   arrayRemove<K>(m.keys, pos);
   arrayRemove<V>(m.values,pos);
   return value;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
}

//you add and remove by pairs so the size is the same in keys or values
template<typename K,typename V>
int mapSize(Map<K,V> m) //OK
{
   return arraySize<K>(m.keys);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m) //OK
{
   //mientras que la pos no exceda el size del map
   return m.pos < mapSize<K,V>(m); //es lo mismo poner el m.pos++ aca o en cada funcion particualar?
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m) //ok?
{
   K key = *arrayGet<K>(m.keys, m.pos);
   m.pos++;
   return key;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m) //ok?
{
   V* valuePtr = arrayGet<V>(m.values, m.pos);
   m.pos++;
   return valuePtr;
}

template<typename K,typename V>
void mapReset(Map<K,V>& m) //ok?
{
   m.pos = 0;
}

//copy paste del bubble sort mejorado de Array.hpp
template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
   //arranca con que NO esta ordenado
   bool ordenado = false;

   while( !ordenado ){ //mientras que NO ESTE ordenado itera para justamente ordenarlo

      ordenado = true;
      for(int i=0; i < mapSize<K,V>(m); i++){
         if(cmpKK(m.keys.arr[i], m.keys.arr[i+1]) > 0){
            //guardamos el 1er de los 2 elementos, para no pisarlo
            //ordenamos/permutamos las KEYS
            K auxKey = m.keys.arr[i];
            m.keys.arr[i] = m.keys.arr[i+1];
            m.keys.arr[i+1] = auxKey;

            //ordenamos/permutamos los VALUES concidiendo con el [i]
            V auxValue = m.values.arr[i];
            m.values.arr[i] = m.values.arr[i+1];
            m.values.arr[i+1] = auxValue;

            //si entro en este if es porque se tenia que permutar
            //ponemos que sigue desordenado para que el while siga analizando el programa
            ordenado = false; // esto es == a !ordenado
         }
         //si no entro al if es porque esta ordenado
      }
   }
} //end function

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
   //arranca con que NO esta ordenado
   bool ordenado = false;

   while( !ordenado ){ //mientras que NO ESTE ordenado itera para justamente ordenarlo

      ordenado = true;
      for(int i=0; i < mapSize<K,V>(m); i++){
         if(cmpVV(m.values.arr[i], m.values.arr[i+1]) > 0){
            //guardamos el 1er de los 2 elementos, para no pisarlo
            //ordenamos/permutamos los VALUES
            V auxValue = m.values.arr[i];
            m.values.arr[i] = m.values.arr[i+1];
            m.values.arr[i+1] = auxValue;


            //ordenamos/permutamos las KEYS concidiendo con el [i]
            K auxKey = m.keys.arr[i];
            m.keys.arr[i] = m.keys.arr[i+1];
            m.keys.arr[i+1] = auxKey;

            //si entro en este if es porque se tenia que permutar
            //ponemos que sigue desordenado para que el while siga analizando el programa
            ordenado = false; // esto es == a !ordenado
         }
         //si no entro al if es porque esta ordenado
      }
   }
}

#endif

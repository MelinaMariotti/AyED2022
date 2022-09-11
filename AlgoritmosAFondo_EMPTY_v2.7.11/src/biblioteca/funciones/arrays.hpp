#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

//remember that every time we declare an array we initialize it's length to 0
//    array[n];
//--> len =0;
//that means that the len is equal to starting index of the array, arr[0] == len == arr[len]

//add 'e' at the end of the array
template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len] = e;
   len++; //para la prox vez que se invoque la funcion, se agregue en la siguente pos (xq &len)
   return len -1; //-1 xq en la linea anterior incrementamos
}

//insert 'e' at pos/index 'p'
template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   for(int i=len; i>p; i--) //arranco en la pos del ult valor ingresado
   {
      arr[i] = arr[i-1]; //en esa pos le asigno el valor anterior
      //Ej 0 1 2, en a[3]
   }
   //ahora que la pos 'p' quedo libre, le asigno el valor 'e'
   arr[p] = e;
   //como corri los valores que estaban definidos anteriormente (a la derecha)
   //y sume un nuevo valor, incremento la length del array
   len++;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret = arr[p];

   //arranco en la pos que quiero eliminar el valor
   for(int i=p; i<len; i++)
   {
      arr[i] = arr[i+1]; //voy desplazando los elementos a la izquierda
   }

   len--; //porque removi 1 elemento del array

   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   for(int i=0; i<len; i++)
   {
      if(cmpTK(arr[i], k) == 0) //signfica que SI lo encontro
      {
         return i;
      }
   }
   return -1;
}

//order the array according to cmp precedence criteria (criterio)
//es requisio que el array YA VENGA ordenado
template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int ret;
   for(int i=0; i<len; i++)
   {
      if(cmpTT(arr[i], e) >= 0)
      {
         insert<T>(arr, len, e, i);
         ret = i;
         break;
      }
   }
   //si recorre todo el array con el for y no inserto, es porque debe ir a lo ultimo
   if(cmpTT(arr[len], e) < 0)
   {
      ret = add<T>(arr, len, e);
   }
   //no ponemos len++ porque eso ya lo tienen incorporado las funciones insert/add
   return ret; //retornamos la pos en la que insertamos 'e'
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   for(int j=0; j<len; j++) //hace las len (cant) pasadas si o si
   {
      for(int i=0; i<len-1; i++) // len - 1 hace referencia al anteultimo elemento del array
      {
         if(cmpTT(arr[i], arr[i+1]) > 0)
         {
            T aux = arr[i]; //guardamos el valor de arr[i] en un aux porque sino estuviera esta linea pisariamos su valor
            arr[i] = arr[i+1];
            arr[i+1] = aux;
         }
      }
   }
}

#endif

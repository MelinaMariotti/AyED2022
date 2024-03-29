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
   for(int i=0; i<len; i++)
   {
      //if arr[i] is greater than 'e', insert 'e' at pos 'i'
      //p.e cmpTT{3-2}, insert 2 in a[i] and put i in a[i+1]
      if(cmpTT(arr[i], e) >= 0)
      {
         insert<T>(arr, len, e, i);
         return i;
         // break; es necesario?
      }
   }
   //si recorre todo el array con el for y no inserto, es porque 'e' debe ir a lo ultimo
   //no ponemos len++ porque eso ya lo tienen incorporado las funciones insert/add
   return add<T>(arr, len, e); //retornamos la pos en la que insertamos 'e'
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T)) //Bubble sort mejorado
{
   //arranca con que NO esta ordenado
   bool ordenado = false;

   while( !ordenado ){ //mientras que NO ESTE ordenado itera para justamente ordenarlo

      ordenado = true;
      for(int i=0; i<len-1; i++){
         if(cmpTT(arr[i], arr[i+1]) > 0){
            //guardamos el 1er de los 2 elementos, para no pisarlo
            T aux = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = aux;

            //si entro en este if es porque se tenia que permutar
            //ponemos que sigue desordenado para que el while siga analizando el programa
            ordenado = false; // esto es == a !ordenado
         }
         //si no entro al if es porque esta ordenado
      }
   }
}

#endif

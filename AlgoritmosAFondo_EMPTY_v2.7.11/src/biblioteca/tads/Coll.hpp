#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

/*1.3.2.1*/
template<typename T>
struct Coll //OK
{
   //cadena tokenizada
   string token;
   char sep;
   int pos; //es necesario para collHasNext, next, etc
};

/*1.3.2.2*/
template<typename T>
Coll<T> coll(char sep) //OK
{
   Coll<T> c;
   c.token;
   c.sep = sep;
   c.pos = 0;
   return c;
}
/*1.3.2.3 Initialization function, creating a Coll struct*/
template<typename T>
Coll<T> coll() //OK
{
   Coll<T> c;
   c.token = "";
   c.sep = '|';
   c.pos = 0; //es realmente necesario?
   return c;
}

/*1.3.2.4*/
template<typename T>
int collSize(Coll<T> c) //OK
{
   return tokenCount(c.token, c.sep);
}

/*1.3.2.5*/
template<typename T>
void collRemoveAll(Coll<T>& c) //OK
{
   c.token = ""; //empty coll
}

/*1.3.2.6*/
//remove especific token in the coll
template<typename T>
void collRemoveAt(Coll<T>& c, int p) //OK
{
   removeTokenAt(c.token, c.sep, p);
}
/*1.3.2.7*/
//add elements at the end of the coll
template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T)) //OK
{
   addToken(c.token, c.sep, tToString(t));
   return tokenCount(c.token, c.sep)-1; //-1 xq arranca de s[0]
}

/*1.3.2.8*/
//replace in position from "p" to "t"
template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T)) //OK
{
   //the coll is in the parameter only to access the fields
   setTokenAt(c.token, c.sep, tToString(t), p);
}

/*1.3.2.9*/
template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string)) //OK
{
   T t = tFromString(getTokenAt(c.token, c.sep, p));
   return t;
}

/*1.3.2.10*/
template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string)) //OK
{
   for (int i=0; i < collSize<T>(c); i++)
   {
      T t = collGetAt<T>(c, i, tFromString);
      if (cmpTK(t,k) == 0)
      {
         return i;
      }
   }
   return -1;
}

/*1.3.2.11 advance insertion*/
template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T)) //OK
{
   for(int i=0; i < collSize<T>(c) - 1; i++)
   {
      //j beggins in the next token
      for (int j= i + 1; j < collSize<T>(c); j++)
      {
         //1rst the 1rst index
         T a = collGetAt<T>(c, i, tFromString);
         //next token
         T b = collGetAt<T>(c, j, tFromString);

         if (cmpTT (a,b) > 0) //a is grater than b
         {
            //intercambian posiciones
            collSetAt<T>(c, a, j, tToString);
            collSetAt<T>(c, b, i, tToString);
         }
      }
   }
}

template<typename T>
bool collHasNext(Coll<T> c) //OK
{
   return c.pos<collSize(c); //begins in 0 and increments in collNext
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string)) //OK
{
   T getToken = collGetAt(c, c.pos, tFromString);
   c.pos++; //
   return getToken;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string)) //NO
{
   endOfColl = !collHasNext<T>(c);
   if( endOfColl )
   {
      return {};
   }
   else
   {
      return collGetAt<T>(c, c.pos++, tFromString);
   }
}

template<typename T>
void collReset(Coll<T>& c) //OK
{
   c.pos = 0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.token;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.token=substring(s,1);
   return c;
}

#endif

#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
   //cadena tokenizada
   string token;
   char sep;
   int pos;
};

template<typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
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
   c.pos = 0;
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
   c = removeTokenAt(c.token, c.sep, p);
}
/*1.3.2.7*/
//add elements at the end of the coll
template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
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
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t;
   t = tFromString(getTokenAt(c.token, c.sep, p));
   return t;
}

/*1.3.2.10*/
template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   cmpTK(t, k)>0?
   return 0;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   return true;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t;
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
}

#endif

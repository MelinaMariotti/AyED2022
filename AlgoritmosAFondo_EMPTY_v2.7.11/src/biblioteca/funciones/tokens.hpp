#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

/*1.2.1.1*/
int tokenCount(string s,char sep) //OK
{
   //si esta vacio retorna 0, si cuanta cuantos sep hay, sumandole 1 da la cant de tokens
   //xq aunq el ult [i] sea el sep, se cuenta como token de cadena vacia
   return isEmpty(s)?0:charCount(s, sep)+1;
}

/*1.2.1.2*/
//add "t" at the end of "s"
void addToken(string& s,char sep,string t) //OK
{
   s = isEmpty(s)?t:s+sep+t; //se concatenan con el 'sep'
}

/*1.2.1.3*/
string getTokenAt(string s,char sep, int i) //OK
{
   int firstIndexSep = indexOfN(s, sep, i) + 1; //we dont want the sep
   int nextIndexSep = indexOfN(s, sep, i+1); // the next sep

   //el 1er token
   if (i == 0){
      return substring(s, i, indexOfN(s, sep, 1)); //el index del 1er sep
   }
   //el ult token
   else if (i == charCount(s, sep))
   {
      return substring(s, firstIndexSep);
   }
   else {
      return substring(s, firstIndexSep, nextIndexSep);
   }
}

/*1.2.1.4*/
void removeTokenAt(string& s,char sep, int i) //OK
{
   int firstIndex = indexOfN(s, sep, i) + 1; //1rst index after sep
   int nextIndex =  indexOfN(s, sep, i+1) ; //substring NO iclusive

   //1rst token
   if ( i == 0 )
   {
      s = substring(s, indexOfN(s, sep, 1) + 1); //1rst char after 'sep'
   }
   //last token
   else if( i == charCount(s, sep))
   {
      s = substring(s, 0, firstIndex - 1);
   }
   else {
      s = substring(s, 0, firstIndex) + substring(s,nextIndex + 1);
   }
}

/*1.2.1.5*/
void setTokenAt(string& s,char sep, string t,int i) //OK
{
   int firstIndex = indexOfN(s, sep, i) + 1; //1rst index agter 'sep'
   int nextIndex = indexOfN(s, sep, i+1);

   //1rst token
   if (i == 0)
   {
      removeTokenAt(s, sep, i);
      s = t + sep + s;
   }
   //last token
   else if (i == charCount(s, sep))
   {
      removeTokenAt(s, sep, i);
      s += sep + t;
   }
   else {
      s = substring(s, 0, firstIndex) + t + substring(s, nextIndex);
   }
}

/*1.2.1.6*/
int findToken(string s,char sep, string t) //PROCESS
{
   int ret = -1;
   for (int j = 0; j < tokenCount(s, sep); j++)
   {
      string token = getTokenAt(s, sep, j);
      if (token == t)
      {
         ret = j;
      }
   }
   return ret;
}

#endif

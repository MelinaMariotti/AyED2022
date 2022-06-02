#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

/*1.1.1.1*/
int length(string s) //OK
{
   int i=0;
   while ( s[i] != '\0') //mientras que en la posicion [i] no haya un \0 seguir contando los char
   {
      i++;
   }
   return i;
}

/*1.1.1.2*/
int charCount(string s,char c) //ok
{
   int index, cont = 0;

   while(s[index] != '\0')
   {
      if(s[index] == c)
      {
         cont++;
      }
      index++;
   }
   return cont;
}

/*1.1.1.3*/
string substring(string s,int d,int h) //OK
{
   /*FAIL
int index = 0;
   string sub; //parte/fragmento que queremos acotar de la string original

   while (index < h) //es menor xq h no es inclusivo y para que recorra de izq a derecha
   {
      sub[index] =  s[d + index];
      index++; //incrementa en 1 hasta que sea menor que h (h = endIndex)
   }
   sub [h] = '\0';*/

   string sub;

   for (int index = d ; index < h; index++) //d menos 1 xq los indices empiezan en 0
   {
      sub += s[index]; //el index de la string original (s) se va a ir cuardando en "sub"
   }
   return sub;
}

/*1.1.1.4 SOBRECARGA*/
string substring(string s,int d) //OK
{
   string sub;
   for (int index = d; index < length(s); index++) {
      sub += s[index];
   }
   return sub;
}

/*1.1.1.5 index de la 1era ocurrencia de 'c' en 's'*/
int indexOf(string s,char c) //OK
{
   int index;
   for (int i = 0; i < length(s); ++i)
   {
      if (s[i] == c)
      {
         index = i;
         break; //si le sacamos el break va a contar hasta el ultimo index donde esta la letra
      }
      else //por si no encuentra el caracter a buscar
      {
         index = -1;
      } //si no ponemos el else nos da un numero ...?

   }
   return index;
}

/*1.1.1.6*/
int indexOf(string s,char c,int offSet) //OK
{
   int index;

   for (int i = offSet; i < length(s); ++i)
   {
      if (s[i] == c) {
         index = i;
         break;
      }
      else
      {
         index = -1;
      }
   }

   /*
    * int p = -1;
    * int cont = 0;
    * int j = 0;
    *
    * for (int i = offSet; i<length(s) && j<length(toSearch); i++)
    * {
    *    if( s[i] == toSearch[j])
    *    {
    *       j++; //incrementas a j
    *    }
    *    else
    *    {
    *       j = 0; //vuelve a 0
    *    }
    *
    * }//end for
    *
    * return p;
    * */

   return index;
}

/*1.1.1.7
devuelve el 1er indice de la cadena pedida en "toSearch" dentro de "s"*/
int indexOf(string s,string toSearch) //OK
{
   int indexString = 0;
   int indexToSearch = 0;
   int indexReturn;

   while(indexString < length(s) && indexToSearch < length(toSearch))
   {
      if (s[indexString] == toSearch[indexToSearch]) {
         indexToSearch++;
      } else {
         indexToSearch = 0; //vuelve a empezar (con index 0)
      } //END IF

      indexString++; //Sigue recorriendo la cadena hasta su fin
   }//END WHILE

   if (indexToSearch == length(toSearch))
   {
      indexReturn = indexString - indexToSearch; //cuenta para saber el index de la 1era ocurrencia de "toSearch"

   }
   else
   {
      indexReturn = -1;
   }

   return indexReturn;
}

/*1.1.1.8*/
int indexOf(string s,string toSearch,int offset) //OK
{
   int indexToSearch = 0;
   int indexReturn;

   while(offset < length(s) && indexToSearch < length(toSearch))
   {
      if (s[offset] == toSearch[indexToSearch])
      {
         indexToSearch++;
      }
      else
      {
         indexToSearch =0;
      }//END IF

      offset++; //incrementa hasta terminar la cadena
   }//END WHILE

   if ( indexToSearch == length(toSearch))
   {
      indexReturn = offset - indexToSearch; //cuenta para saber el index de la 1era ocurrencia de "toSearch"

   }
   else
   {
      indexReturn = -1;
   }

   return indexReturn;
}

/*1.1.1.9*/
int lastIndexOf(string s,char c) //OK
{
   int index = 0;
   int indexReturn;

   while(index < length(s))
   {
      if (s[index] == c) {
         indexReturn = index;
      }
      index++;
   }//END WHILE

   return indexReturn;
}

/*1.1.1.10*/
int indexOfN(string s,char c,int n) //OK
{
   int indexReturn;
   int cont = 0;

   for (int i = 0; s[i] != '\0'; ++i)
   {
      if (s[i] == c)
      {
         cont ++; //cuenta cuantas veces aparece 'c' en "s"

         if (cont == n)
         {
            indexReturn = i;
            break;
         } //END 2DO IF, si el cont es igual a la ocurrencia que termine el programa
      }//END 1ER IF
   }//END FOR

   if ( n > cont) {
      indexReturn = 0;
   }
   else if ( n == 0)
   {
      indexReturn = -1;
   } //END IF

   return indexReturn;
}

/*1.1.1.11*/
//explicado en OneNote
int charToInt(char c) //OK
{
   int cuentaAscii;
   //'0'=48 , '1'=49 , '2'=50 ... hasta '9'=57
   // 'a/A'=10 , 'b/B'=11 , 'c/C'=12

   if ( c >= '0' && c <= '9')
   {
      cuentaAscii = c - '0'; //cuenta para los numeros
   }
   else
   {
      if ( c >= 'A' && c <= 'Z')
      {
         cuentaAscii = c - 'A' + 10;
      }
   }
   return cuentaAscii;
}

/*1.1.1.12*/
char intToChar(int i) //NO FUNCIONA
{
   char cuenta;

   if ( i>=0 && i<=9)
   {
      cuenta = '0'+i;
   }
   else
   {
      if ( i>='A' && i<='F')
      {
         cuenta = 'A'+i-10;
      }
   }

   return cuenta;
}

/**1.1.1.13*/
int getDigit(int n,int i) //OK
{
   /*FAIL, NO ENTENDI ESTA RESOLUCION
   int resto;
   int potenciaBase10 = 10;

   for (int i = 0; i < 10; ++i) {

   }
   resto = n % (i+1);*/

   int resto;

   while(i > 0)
   {
      n /= 10; //al numero lo dividis x 10 en cada vuelva
      i--; // i = index con el cual buscamos el numero que esta en la posicion "i", decrementa
   }

   resto = n % 10;
   return resto;
}

/*1.1.1.14*/
int digitCount(int n) //OK
{
   int cantDigitos = 0;

   while (n > 0)
   {
      n /= 10;
      cantDigitos ++;
   }

   return cantDigitos;
}

/*1.1.1.15*/
string intToString(int i) //NO TERMINADO
{
   string conversion = "";
   int contExtra = 0;
   int cantDivisiones = 1; //porque sino en la division x 10 queda en 0
   int cantDigitos = digitCount(i);


   while( contExtra == digitCount(i) )
   {

      while(cantDivisiones < cantDigitos)
      {
         i /= 10;
         cantDivisiones ++;
      } //END 2do while
      i = i % 10;
      conversion += i;
      cantDigitos --;
      contExtra++;
   } //END 1er while



   return conversion;
}

int stringToInt(string s,int b) // NO TERMINADO
{
   for (int i = 0; i < length(s); ++i) {
      //s[i] =
   }

   return 0;
}

int stringToInt(string s) // ok
{
   return 0;
}

string charToString(char c)
{
   return "";
}

char stringToChar(string s)
{
   return 'X';
}

string stringToString(string s)
{
   return "";
}

string doubleToString(double d)
{
   return "";
}

double stringToDouble(string s)
{
   return 1.1;
}

/*1.1.1.23*/
bool isEmpty(string s) //OK
{
   bool isEmpty;

   if (length(s) == 0)
   {
      isEmpty = true;
   }
   else if (length(s) > 0)
   {
      isEmpty = false;
   }

   return isEmpty;
}

/*1.1.1.24*/
bool startsWith(string s,string x) //OK
{
   bool start;
   int index = 0;

   while(x[index] != '\0')
   {
      if (s[index] == x[index])
      {
         index++;
      }
      else
      {
         break;
      }//END IF

   }//END WHILE

   if (index == length(x)) //index se usa como contador ademas de que incrementa el index de x
   {
      start = true;
   } //END IF

   return start;
}

/*1.1.1.25*/
bool endsWith(string s,string x) //PROCESS NO FUNCIONA
{
   bool end = true;
   int indexX = length(x) - 1;
   int indexS = length(s) - 1;
   int contador = 0;

   while(x[indexX] != 0 && indexX > 0)
   {
      if (s[indexS] == x[indexX])
      {
         indexX--;
         indexS--;
         contador ++;
      }
      else
      {
         break;
      }//END IF

   }//END WHILE

   if (contador == length(x))
   {
      end = true;
   }
   else
   {
      end = false;
   }//END IF


   return end;
}

/*1.1.1.26*/
bool contains(string s,char c) //OK
{
   int contador = 0;
   bool loContiene;

   for (int i = 0; i < length(s); ++i)
   {
      if (s[i] == c)
      {
         contador ++;
      } //end if
   } //end for

   if (contador > 0)
   {
      loContiene = true;
   } //end if

   return loContiene;
}

/*1.1.1.27*/
string replace(string s,char oldChar,char newChar) //OK
{
   for (int i = 0; i < length(s); ++i)
   {
      if (s[i] == oldChar) {
         s[i] = newChar;
      }
   } //END FOR

   return s;
}

/*1.1.1.28*/
string insertAt(string s,int pos,char c) //OK
{
   string stringWithCharAdded = "";

   //en esta funcion subtring el ultimo parameteo no esta includo
   stringWithCharAdded = substring(s, 0, pos) + c + substring(s, pos, length(s));

   return stringWithCharAdded;
}

/*1.1.1.29*/
string removeAt(string s,int pos) //PROCESS
{
   string stringWithoutChar = "";

      //en esta funcion subtring el ultimo parameteo no esta includo
   //stringWithoutChar = substring(s, 0, pos) - c + substring(s, pos, length(s));

      return stringWithoutChar;
}

string ltrim(string s)
{
   return "";
}

string rtrim(string s)
{
   return "";
}

string trim(string s)
{
   return "";
}

string replicate(char c,int n)
{
   return "";
}

string spaces(int n)
{
   return "";
}

string lpad(string s,int n,char c)
{
   return "";
}

string rpad(string s,int n,char c)
{
   return "";
}

string cpad(string s,int n,char c)
{
   return "";
}

bool isDigit(char c)
{
   return true;
}

bool isLetter(char c)
{
   return true;
}

bool isUpperCase(char c)
{
   return true;
}

bool isLowerCase(char c)
{
   return true;
}

char toUpperCase(char c)
{
   return 'X';
}

char toLowerCase(char c)
{
   return 'X';
}

string toUpperCase(string s)
{
   return "";
}

string toLowerCase(string s)
{
   return "";
}

int cmpString(string a,string b)
{
   return 0;
}

int cmpDouble(double a,double b)
{
   return 0;
}

#endif

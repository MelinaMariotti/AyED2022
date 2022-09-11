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
int charCount(string s,char c) //OK
{
   int index = 0;
   int cont = 0;

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
   string sub = "";

   for (int index = d ; index < h; index++) //d menos 1 xq los indices empiezan en 0
   {
      sub += s[index]; //el index de la string original (s) se va a ir cuardando en "sub"
   }
   return sub;
}

/*1.1.1.4 SOBRECARGA*/
string substring(string s,int d) //OK
{
   string sub = "";
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
      } //end if
   } //end for

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
         cuentaAscii = c - 'A' + 10; //cuenta para las letras
      }
   }
   return cuentaAscii;
}

/*1.1.1.12*/
char intToChar(int i) //OK
{
   char a;
   //hacemos como la asignacion de un char a un int con el "="
   a=i;
   //le sumamos 48 por '0'
   a+=48;

   if (a>57) a+=7; //un numero
   if (a>90) a+=6; //mayuscula
   if (a<123) return a; //minuscula
   else return 0;
}

/**1.1.1.13*/
int getDigit(int n,int i) //OK
{
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
string intToString(int i) //OK
{
   string convertido = "";
   //conversion = i;

   int length = digitCount(i) - 1;

   for(int j=length; j>=0 ;j--) //decrementa xq getDigit lee de derecha a izq
   {
      convertido += intToChar(getDigit(i, j));
   }

   return convertido;
}

/*1.1.1.16*/
int stringToInt(string s,int b) //OK
{
   int convertido = 0;
   int exp = length(s) - 1;

   if (b == 2 || b == 8 || b == 10 || b == 16)
   {
      for (int i=0; i<length(s); i++)
      {
         convertido += charToInt((char)s[i])*pow(b, exp);
         exp--;
      } //END FOR
   } //END IF

   return convertido;
}

/*1.1.1.17*/
int stringToInt(string s) //OK
{
   int convertido = 0;

   for(int i=0; i < length(s); i++)
   {
      convertido = convertido * 10 + (int(s[i] - 48));
   } //END FOR
   return convertido;
}

/*1.1.1.18*/
string charToString(char c) //OK
{
   string convertido = "";

   convertido += c;

   return convertido;
}

/*1.1.1.19*/
char stringToChar(string s) //OK
{
   char convertido;

   convertido = s[0];

   return convertido;
}

/*1.1.1.20*/
string stringToString(string s) //OK
{
   return s;
}

/*1.1.1.21*/
string doubleToString(double d) //OK
{
   char buffer[100];
   sprintf(buffer, "%lf", d);
   string ret = buffer;
   return ret;
}

/*1.1.1.22*/
double stringToDouble(string s)
{
   double before = 0;
   double after = 0.0;
   bool hasDot = false;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] == '.')
      {
         hasDot = true;
         continue;
      }
      if (hasDot)
      {
         // Parte decimal
         after += (double)charToInt((char)s[i]) / 10;
         hasDot = false;
      }
      else
      {
         // Parte entera
         before = before * 10 + (double)charToInt((char)s[i]);
      }
   }
   return before + after;
}

/*1.1.1.23*/
bool isEmpty(string s) //OK
{
   bool isEmpty = false;

   if (length(s) == 0)
   {
      isEmpty = true;
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
bool endsWith(string s,string x) //PONELE Q SI
{
   //1er char de "x", para buscar su ult ocurrencia en "s"
   char busqEnIndex = x[0];
   //para usarlo en IndexOf y que busque "x" correctamente
   int offSet = lastIndexOf(s, busqEnIndex);
   return indexOf(s,x, offSet-1)!=-1;
}

/*
bool endsWith(string s, string x)
{
   int indexOfWord = indexOf(s, x);
   if (indexOfWord < 0)
      // Esta contenida
      return false;
   else if (indexOfWord == 0)
      // No esta al inicio
      return false;
   else if (length(s) - indexOfWord == length(x))
      return true;
   return false;
}*/

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

   //en esta funcion subtring el ultimo parametro no esta includo
   stringWithCharAdded = substring(s, 0, pos) + c + substring(s, pos, length(s));

   return stringWithCharAdded;
}

/*1.1.1.29*/
string removeAt(string s,int pos) //OK
{
   string stringWithoutChar = "";

   //en esta funcion subtring el ultimo parametro no esta includo
   stringWithoutChar = substring(s, 0, pos) + substring(s, pos + 1, length(s));

   return stringWithoutChar;
}

/*1.1.1.30 lefttrim*/
string ltrim(string s) //OK
{
   int index;
   string trimString;

   for (int i = 0; i < length(s); ++i)
   {
      if (s[i] != 32) //32 es el caracter del espacio en ASCII
      {
         index = i;
         break;
      }//END IF

   }//END FOR

   trimString = substring(s, index, length(s));
   return trimString;
}

/*1.1.1.31*/
string rtrim(string s) //OK
{
   int index;
   string trimString;

   if (s[length(s) - 1] == 32)
   {
      for (int i = length(s) - 1; i > 0 ; --i)
      {
         if (s[i] != 32)
         {
            index = i;
            break;
         } //END IF
      } //END FOR

      trimString = substring(s, 0, index+1);
   }
   else
   {
      trimString = s;
   }//END 1ER IF

   return trimString;
}

/*1.1.1.32*/
string trim(string s) //OK
{
   return rtrim(ltrim(s));
}

/*1.1.1.33*/
string replicate(char c,int n) //OK
{
   string cadena = "";

   for (int i = 0; i < n; ++i) {
      cadena += c;
   }

   return cadena;
}

/*1.1.1.34*/
string spaces(int n) //OK
{
   string cadena = "";

   for (int i = 1; i < n; ++i)
   {
      cadena += " ";
   }//END FOR

   return cadena;
}

/*1.1.1.35*/
string lpad(string s,int n,char c) //OK
{
   string strleftpad = "";

   if (length(s) == n)
   {
      strleftpad = s;
   }
   else if (length(s) < n)
   {
      strleftpad = replicate(c , n - length(s)) + s;
   }

   return strleftpad;
}

/*1.1.1.36*/
string rpad(string s,int n,char c) //OK
{
   string strrigthpad = "";

   if (length(s) == n)
   {
      strrigthpad = s;
   }
   else if (length (s) < n)
   {
      strrigthpad = s + replicate(c , n - length(s));
   }//END IF

   return strrigthpad;
}

/*1.1.1.37*/
string cpad(string s,int n,char c) //OK
{
   string strLpad, strRpad;
   int charFaltantes = n - length(s);

   if (n > length(s))
   {
      strLpad = lpad(s,length(s) + (charFaltantes/2), c);
      strRpad = rpad(strLpad,n, c);
   }
   else
   {
      strRpad = s;
   }

   return strRpad;
}

/*1.1.1.38*/
bool isDigit(char c) //OK
{
   bool esDigito;

   if ( c>=48 && c<=57 )
   {
      esDigito = true;
   }

   return esDigito;
}

/*1.1.1.39*/
bool isLetter(char c) //OK
{
   bool esLetra;

   //Si c esta entre 65 y 90 (A - Z) o entre 97 y 122 (a - z)
   if ( (c>=65 && c<=90) || (c>=97 && c<=122) )
   {
      esLetra = true;
   }

   return esLetra;
}

/*1.1.1.40*/
bool isUpperCase(char c) //OK
{
   bool upperCase;

   if ( c>=65 && c<=90 )
   {
      upperCase = true;
   }

   return upperCase;
}

/*1.1.1.41*/
bool isLowerCase(char c) //OK
{
   bool lowerCase;

   if ( c>=97 && c<=122 )
   {
      lowerCase = true;
   }

   return lowerCase;
}

/*1.1.1.42*/
char toUpperCase(char c) //OK
{

   char charToUpper;

   if ( c>=97 && c<=122 ) {
      charToUpper = c - 32;
   }
   else
   {
      charToUpper = c;
   }

   return charToUpper;
}

/*1.1.1.43*/
char toLowerCase(char c) //OK
{
   char charToLower;

   if ( c>=65 && c<=90 ) {
      charToLower = c + 32;
   }
   else
   {
      charToLower = c;
   }

   return charToLower;
}

/*1.1.1.44*/
string toUpperCase(string s) //OK
{
   string stringToUpper;

   for (int i = 0; i < length(s); ++i)
   {
      if (s[i]>=97 && s[i]<=122)
      {
         stringToUpper += s[i] - 32;
      }
      else
      {
         stringToUpper += s[i];
      }
   }

   return stringToUpper;
}

/*1.1.1.45*/
string toLowerCase(string s) //OK
{
   string stringToLower;

   for (int i = 0; i < length(s); ++i)
   {
      if (s[i]>=65 && s[i]<=90)
      {
         stringToLower += s[i] + 32;
      } else
      {
         stringToLower += s[i];
      } //END IF
   } //END FOR
   return stringToLower;
}

/*1.1.1.46*/
int cmpString(string a,string b) //OK
{
   return a<b?-1:a>b?1:0;
}

/*1.1.1.47*/
int cmpDouble(double a,double b) //OK
{
   return a<b?-1:a>b?1:0;
}

#endif

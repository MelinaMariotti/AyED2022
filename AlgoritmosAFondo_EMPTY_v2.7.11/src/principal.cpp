
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

int main()
{
   //create coll
   Coll<string> c = coll<string>();

   //add elements
   collAdd<string>(c, "Meli", stringToString);
   collAdd<string> (c, "Valen", stringToString);

   int pos = 0;
   string r =collGetAt<string>(c, pos, stringToString);
   cout << stringToString(r) << endl;

   pos = 1;
   string nuevo = "Ali";
   collSetAt<string>(c, nuevo, pos, stringToString);
   string res = collGetAt<string>(c, pos, stringToString);
   cout << res << endl;


   return 0;

} //END MAIN

#endif

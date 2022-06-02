//============================================================================
// Name        : 04Clase.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Fecha.hpp"
using namespace std;


int main() {

   int d,m,a;

   cin >> d >> m >> a;

   Fecha f = fecha(d,m,a);

	cout << fechaToString << endl; //el cout sabe compliar una estructura? NOOOO
	return 0;
}

//============================================================================
// Name        : Demo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//El usuario ingreas un valor que indiica cuantos numeros primos quiere ver,
// y el progama le mostrara x pantlla esa cant de numeros primos
// ej: n=5 -> {2,3,5,7,11}

int main() {

   //el usuario ingresa cuantos primos quiere ver
	cout << "Cuantos numeros primos queres ver?" << endl;
	int n;

	cin >> n;

	int cont = 0;
	int nroAEvaluar = 1;

	while (cont<n){

	   //inicializas primo en = true
	   bool primo = true;

	   //contador
	   int i = 2;

	   while( i < nroAEvaluar and primo == true){
	      if (nroAEvaluar % i == 0){
	         primo = false;
	      }

	      //incrementacion contador
	      i += 1;
	   }


	   if ( primo == true){
	      cout << nroAEvaluar << endl;
	      cont += 1;

	   }

	   //para pasar a evaluar el siguiente numero hasta que sea menor
	   //que la cant de num que quiere ver.

	   nroAEvaluar +=1;

	} //end while



	return 0;

} //FIN PROGRAMA

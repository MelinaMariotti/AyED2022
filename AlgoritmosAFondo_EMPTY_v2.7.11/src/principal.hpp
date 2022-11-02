#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Fecha{
   int d;
   int m;
   int a;
};

struct Socio
{
   int idSocio;
   char nombre[50];
   int idSocioRef; // socio referente
   Fecha fechaIngreso;
   double totalVentasAcumuladas;
   double liquidacionAnterior;
   double liquidacionesAcumuladas;
};

struct RSocio{
   Socio socio;
   double acumComision;
   double acumPrecioVentas;
};

struct Venta
{
   int idSocio;
   int idProducto;
   char observ[100];
   Fecha fecha;
   double importe;
};

#endif

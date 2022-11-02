
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
#include "principal.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

// -----EJERCICIO DE LA EMPRESA PIRAMIDAL ---------

Map<int,RSocio> subirSociosAMemoria()
      {
   return {};
      }


/*
                     $1.000       -  precio total de la venta
                        |
                        | 30% comision
                        |
                      $300
                  /            \
70% de comision  /              \   30% de comision
                /                \
              $210              $90
                |                 |
          para el socio     para el referido
 */

//proceso de a 1 socio

bool esJefeMaximo(int idReferente){
   return idReferente == -1;
}

void procesarVenta(Venta venta, Map<int,RSocio>& mapSocios){

   //RSocio es == a wRappSocio, !significa -> registroSocio
   //obtengo al socio para el obj 1 y 2:
   RSocio* registroSocio = mapGetValue(mapSocios,venta.idSocio);

   //1er objetivo - liquidarle el 30% del 70% de comision del total $venta almacenada en <Venta venta>
   double comisionBruta_30 = venta.importe*0.30;
   registroSocio->acumComision += (comisionBruta_30)*0.70;

   //2do obj acum haciendo una sumatoria del $valor de c/venta
   registroSocio->acumPrecioVentas += venta.importe;


   //OBTENGO AL REFERENTE del socio obtenido de la linea 50
   int idJefe = registroSocio->socio.idSocioRef;
   //comision del 30% del bruto(30%) del $venta que le corresponde al referente
   double comDelReferente = (comisionBruta_30)*0.30;

   while( idJefe >= 0){
      //OBTENGO a el jefe del jefe obtenido en linea 61
      RSocio* idJefeDelJefe = mapGetValue<int,RSocio>(mapSocios,idJefe);

      //si es el jefe MAXIMO se queda con toda la comision calculada en linea 63
      if( esJefeMaximo(idReferente) ){
         idJefeDelJefe->acumComision += comDelReferente;
      }
      else{ //sino, se queda con el con el 70%
         idJefeDelJefe->acumPrecioVentas+= comDelReferente*0.70;
      }

      //para liquidarle al proximo
      comDelReferente *= 0.30;
      //obtenemos al jefe de la linea 67
      idJefe = idJefeDelJefe->socio.idSocioRef;
   }
}

int main()
{

   Map<int,RSocio> mapSocios = subirSociosAMemoria();

   FILE* f = fopen("VENTAS.dat","r+b");

   Venta venta = read<Venta>(f);

   while( !feof(f) ){
      procesarVenta(venta,mapSocios);
      venta = read<Venta>(f);
   }




   fclose(f);

   return 0;
} //END MAIN

#endif

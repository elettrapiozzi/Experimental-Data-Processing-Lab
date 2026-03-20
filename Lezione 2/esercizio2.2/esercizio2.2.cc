#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "Vettore.h"
#include "funzioni.h"

using namespace std;

int main ( int argc , char** argv) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }

  int ntot = atoi(argv[1]);
  char * filename = argv[2];

  // uso una funzione per leggere gli elementi da un file

  Vettore v = ReadDataFromFile ( ntot, filename ) ;

  Print(v);

  // uso una funzione per calcolare la media, varianza e mediana
 
  cout << "Media = " << CalcolaMedia(v) << endl;

  cout << "Varianza = " << CalcolaVarianza(v) << endl;

  cout << "Mediana = " << CalcolaMediana(v) << endl;

  // Scrivo i dati riordinati su file
  selection_sort(v); 
  Print("data_out.txt", v);

  Print(v);

  return 0;

}
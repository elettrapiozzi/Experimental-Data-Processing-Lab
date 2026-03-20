#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "funzioni.h"

using namespace std;

int main ( int argc , char** argv) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }

  int ndata = atoi(argv[1]);
  char * filename = argv[2];

  // uso una funzione per leggere gli elementi da un file

  double * data = ReadDataFromFile ( filename, ndata ) ;

  for (int k = 0; k < ndata; k++) cout << data[k] << endl; 

  // uso una funzione per calcolare la media e la varianza

  cout << "Media = " << CalcolaMedia( data , ndata ) << endl;

  cout << "Varianza = " << CalcolaVarianza( data , ndata ) << endl;

  // uso una funzione per calcolare la mediana

  cout << "Mediana = " << CalcolaMediana(data, ndata) << endl;

  // Scrivo i dati riordinati su file
  selection_sort(data, ndata); 
  Print( "fileout.txt", data, ndata ) ;
  Print(data, ndata);

  return 0;

}






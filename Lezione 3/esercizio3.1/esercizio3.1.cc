#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "funzioni.h"

using namespace std;

int main( int argc , char** argv ) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl << endl;
    return -1 ;
  }  

  vector<double> v = read <double> (atoi(argv[1]) , argv[2]);   // atoi = da stringa di "parole" a int
  cout << "Elementi dell'array: " << endl;
  print(v) ;
  cout << endl;

  cout << "-- Media    = " << media <double> (v) << endl;
  cout << "-- Varianza = " << varianza <double> (v) << endl;
  cout << "-- Deviazione Standard = " << dev_std <double> (v) << endl;
  cout << "-- Mediana  = " << mediana <double> (v) << endl << endl;

  sort(v.begin(),v.end());
  //se voglio ordinarli in ordine decrescente uso: sort(v.begin(), v.end(), greater<T>());

  cout << "Elementi dell'array riordinati: " << endl;
  print(v); 

  print("output.txt", v);

  return 0;

}


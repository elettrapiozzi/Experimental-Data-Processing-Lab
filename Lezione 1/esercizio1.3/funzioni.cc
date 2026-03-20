#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "funzioni.h"


// LEGGE I DATI DAL FILE E LI CONVERTE IN NUMERI
double * ReadDataFromFile ( const char* Filename , int size  ) {

    double * data = new double[size];
    ifstream fin(Filename); 

    if (!fin) { //controlla se il file non si è aperto
        cout << "Errore apertura del file " << Filename << endl;
        exit(33);
    } else {

        for (int i = 0; i < size; i++) {
            fin >> data[i]; //prendo dal file e inserisco nell'i-esima casella dell'array
            if (fin.eof()) {
                cout << "Fine del file" << endl;
                exit(33); //ovvero se sono alla fine del file stampa che ho finito
            }
        }
    }

    return data;
}


// CREA UN FILE CONTENENTE I DATI SELEZIONATI
// ATTENZIONE! Print non stampa i dati in ordine, c'è prima selection_sort nel main
void Print ( const char* Filename, double * data, int size ) {

    ofstream fout(Filename);

    if (!fout) {
        cout << "Errore: impossibile aprire il file " << Filename << " per scrivere" << endl;
        exit(33);
    }
    
    for (int i = 0; i < size; i++) {
        fout << data[i]<< endl;
    }

    fout.close();

}


// STAMPA A SCHERMO ELEMENTI DI UN ARRAY
void Print ( double* data, int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << endl;
    }
}



// CALCOLO DELLA MEDIA
double CalcolaMedia( double * data , int size ) {

    double somma = 0.0; 

    for (int i = 0; i < size; i++) {
        somma += data[i];
    }
    double media = somma / size;

  return media ;

}


// CALCOLO DELLA VARIANZA

double CalcolaVarianza( double * data , int size ) {

    double sommaquad = 0.0;
    double media = CalcolaMedia(data, size);

    for (int i = 0; i < size; i++) {
        sommaquad += pow(data[i] - media,2);
    }

    double varianza = sommaquad / size;

  return varianza;

}


// FUNZIONI PER SCAMBIARE DI POSTO DUE ELEMENTI, UTILI PER IL RIORDINAMENTO

void scambiaByValue(double a, double b) {
  double c=a;
  a=b;
  b=c;
}

void scambiaByRef(double &a, double &b) {
  double c=a;
  a=b;
  b=c;
}

void scambiaByPointer(double *a, double *b) {
  double c=*a;
  *a=*b;
  *b=c;
}


// RIORDINAMENTO DI UN ARRAY 

void selection_sort( double * vec, int size) {

  for (int j=0; j<size-1; j++) {     
    int imin = j;
    double min=vec[imin];

    for (int i=j+1; i<size; i++) { 
      if ( vec[i]<min ) {                 
        min  = vec[i];
        imin = i;
      }
    }                                       
    scambiaByRef(vec[j],vec[imin]);     
  }                                          
}


// CALCOLO DELLA MEDIANA

double CalcolaMediana ( double vec[] , int size ) {

  double * vcopy = new double [size];
  for ( int i = 0 ; i < size ; i++ ) vcopy[i] = vec[i]; 

  selection_sort( vcopy , size );

  double mediana = 0;

  if ( size %2 == 0 ) {    
    mediana = ( vcopy[ size /2 -1 ] + vcopy[ size/2 ]  ) /2.;    
  } else {
    mediana = vcopy[size /2];    
  }

  delete [] vcopy;

  return mediana;
} 


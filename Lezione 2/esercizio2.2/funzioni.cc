#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "funzioni.h"
#include "Vettore.h"


// LEGGE I DATI DAL FILE E LI CONVERTE IN NUMERI
Vettore ReadDataFromFile (int ntot, const char* filename ) {
    
  Vettore v(ntot);
    fstream infile;
    infile.open(filename,ios::in);
    if(!infile.good()) {
        throw runtime_error("ERROR, failed to open file...");

    infile.clear(); infile.seekg(0);
    }else {
        for(int i = 0; i < ntot; i++){

            double vector = 0;
            infile >> vector;
            v.SetComponent(i, vector);
            if(infile.eof()){
                break;
            }
        }
    }

    infile.close();
    return v;

}


// CREA UN FILE CONTENENTE I DATI SELEZIONATI
// ATTENZIONE! Print non stampa i dati in ordine, c'è prima selection_sort nel main
void Print ( const char* filename, Vettore& v) {
  selection_sort(v);
  fstream outfile(filename, ios::out);
  outfile << "Array riordinato: " << endl;
  for(int i=0; i<v.GetN(); i++) {
      outfile << "Elemento " << i+1 << ": " << v.GetComponent(i) << endl;
  }
  outfile.close();
}


// STAMPA A SCHERMO ELEMENTI DI UN ARRAY
void Print (const Vettore& v) {
    for (int i = 0; i < v.GetN() ; i++) {
        cout << "Elemento " << i+1 << ": " << v[i] << endl;
    }
}



// CALCOLO DELLA MEDIA
double CalcolaMedia( const Vettore& v) {

    double somma = 0.0; 

    for (int i = 0; i < v.GetN(); i++) {
        somma += v.GetComponent(i);
    }
    double media = somma / v.GetN();

  return media ;

}


// CALCOLO DELLA VARIANZA

double CalcolaVarianza( const Vettore& v) {

    double sommaquad = 0.0;
    double media = CalcolaMedia(v);

    for (int i = 0; i < v.GetN(); i++) {
        sommaquad += pow(v[i] - media,2);
    }

    double varianza = sommaquad / (v.GetN());

  return varianza;

}

double dev_std(Vettore v) {

  return sqrt(CalcolaVarianza(v));

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

void selection_sort( Vettore& v ) {
  double dep;              
  for (int i = 0; i < v.GetN() - 1; i++){
      for (int j = i + 1; j < v.GetN(); j++){
          if (v.GetComponent(i) > v.GetComponent(j)){
              v.Scambia(i,j);
          }
      }   
  }

} 


// CALCOLO DELLA MEDIANA

double CalcolaMediana ( Vettore& v) {
  selection_sort(v);
    double mediana;
        if(v.GetN()%2==0) {
            mediana = (v[(v.GetN()-1)/2] + v[v.GetN()/2])/2;
        } else {
            mediana = v[v.GetN()/2];
        }
    return mediana;
} 


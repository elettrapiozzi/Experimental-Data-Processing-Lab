#include <iostream>
#include <cstdlib>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include <vector>

#include "funzioni.h"

using namespace std;

int main( int argc , char** argv ) {

    if ( argc < 3 ) {
      cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
      return -1 ;
    }  
  
  // creo un processo "app" che lascia il programma attivo ( app.Run() ) in modo
  // da permettermi di vedere gli outputs grafici

  TApplication app("app",0,0);

  // leggo dati da file

  vector<double> v = read<double>( atoi(argv[1]) , argv[2]);

  //Creazione ISTOGRAMMA root 

  //TH1F : per dire che è un istogramma (come scrivere int per dire che è intero)
  //le cose tra parentesi in ordine sono: nome interno con cui se lo salva root, titolo che appare sul grafico,
  //numero di bin (caselle) lungo l'asse x, valore minimo dell'asse X (bordo inferiore), valore max asse X 

  TH1F histo ("histo","Istogramma", 100, -10, 100);
  
  // con .StateOverflows(kTRUE) sto dicendo "quando calcoli la media tramite operazioni di root, tieni conto anche dei "
  // valore di overflow (> xmax) e di underflow (<xmin)

  histo.StatOverflows(kTRUE);   

  for (int i = 0 ; i < v.size() ; i++) histo.Fill(v[i]);
  
  cout << "Media dei valori caricati = " << histo.GetMean() << endl;

  // TCanvas è per creare il disegno
  TCanvas mycanvas ("Histo","Histo");   // primo termine nome interno, secondo termine titolo 
  histo.Draw();
  histo.GetXaxis()->SetTitle("Measurement");
  histo.GetYaxis()->SetTitle("N");

  app.Run();

return 0;

}
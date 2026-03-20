#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "EquazioniDifferenziali.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"


using namespace std;

int main (int argc, char** argv ) {


  if ( argc!=2 ) {
    std::cerr << "Usage: " << argv[0] << " <stepsize>" << std::endl;   // da terminale devo inserire ./esercizio h nstep
    return -1;
  }  

  TApplication myApp("myApp",0,0); 

  RungeKutta myRungeKutta;

  double l = 1;
  Pendolo p (l);

  double h = atof(argv[1]);

  

  TGraph myGraph1;

  TCanvas c;
  c.cd();  

  for (int step = 0; step < 30; step++) {

    double A= 0.1*(step + 1);    //è un angolo 
    double t= 0.0;
    double w = 0; 
    vector<double> x {-A, w};

    while (x[1] >= 0) {  //finchè la derivata è positiva (velocità) faccio evolvere il sistema 
      w = x[1];
      x = myRungeKutta.Passo(t,x,h,p);
      t = t + h;

    }

    double T = t-w*h/(x[1]-w)*2;   //Periodo

    cout << "Ampiezza: " << A << ", Periodo: " << T << endl; 
    
    myGraph1.SetPoint(step, A, T);    //salvo il punto (A,T) nel grafico

  }

  myGraph1.SetTitle("Periodo in funzione dell'ampiezza (Eulero)");
  myGraph1.GetXaxis()->SetTitle("Ampiezza [rad]");
  myGraph1.GetYaxis()->SetTitle("Periodo [s]");
  myGraph1.SetLineColor(2);
  myGraph1.SetMarkerStyle(20); //quello che fa i puntini
  
  myGraph1.Draw("ALP");


  myApp.Run();


  return 0;

}
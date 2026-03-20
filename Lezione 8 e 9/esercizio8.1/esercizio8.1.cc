#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "EquazioniDifferenziali.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"

std::string convert ( double h ) ;  //convert è implementata a fine codice fuori dal main!!!

int main (int argc, char** argv ) {

  if ( argc!=2 ) {
    std::cerr << "Usage: " << argv[0] << " <stepsize>" << std::endl;   // da terminale devo inserire ./esercizio h 
    return -1;
  }  

  TApplication myApp("myApp",0,0); 

  Eulero myEuler;

  OscillatoreArmonico osc(1.0);   // oscillatore con omega0 = 1 

  double tmax = 70.0;             //tempo massimo fino a cui integrare: 70 sec
  double h = atof(argv[1]);       //converto il passo di integrazione h da string a double
  vector<double> x {0.0,1.0} ;    //vettore con condizioni iniziali ----> posizione = 0, velocità = 1
  double t = 0.;                  //condizione iniziale temporale t=0 

  TGraph myGraph ;
  
  int nstep = int(tmax/h+0.5);    
  /*Relativo a nstep: calcolo il numero di passi necessari: nel caso il rapporto sia un numero decimale si usa questo trick di sommare 0.5 
  al denominatore e poi a forzarlo a intero (metto int) ed vuol dire che lo sto approssimando al numero decimale più vicino*/
  

  
  // evoluzione del sistema fino a 70 s  

  for (int step=0; step<nstep; step++) {   
    myGraph.SetPoint(step,t,x[0]);
    x = myEuler.Passo(t,x,h,osc);
    t = t+h;
  }

  // grafici  

  TCanvas c ;
  c.cd();
  string title = "Oscillatore armonico (Eulero h = " + convert(h) + ")" ;
  myGraph.SetTitle(title.c_str());
  myGraph.GetXaxis()->SetTitle("Tempo [s]");
  myGraph.GetYaxis()->SetTitle("Posizione x [m]");
  myGraph.Draw("AL");

  myApp.Run();

  return 0;
  
}

// funzione convert per convertire h in string così lo possiamo mettere nel titolo del grafico
std::string convert ( double h ) {

  int cifre_significative = -log10(h);
  std::ostringstream streamObj3;
  streamObj3 << std::fixed;
  streamObj3 << std::setprecision(cifre_significative);
  streamObj3 << h;
  std::string strObj3 = streamObj3.str();
  return strObj3;

} ;

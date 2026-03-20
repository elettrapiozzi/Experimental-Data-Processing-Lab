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
  RungeKutta myRungeKutta;

  OscillatoreArmonico osc(1.0);   // oscillatore con omega0 = 1 

  double tmax = 70.0;             //tempo massimo fino a cui integrare: 70 sec
  double h = atof(argv[1]);       //converto il passo di integrazione h da string a double
  vector<double> x {0.0,1.0} ;    //vettore con condizioni iniziali ----> posizione = 0, velocità = 1 per runge kutta
  vector<double> y {0.0,1.0} ;    // """""""" per  eulero
  double t = 0.;                  //condizione iniziale temporale t=0 

  TGraph myGraph1;
  TGraph myGraph2;
  
  int nstep = int(tmax/h+0.5);    
  /*Relativo a nstep: calcolo il numero di passi necessari: nel caso il rapporto sia un numero decimale si usa questo trick di sommare 0.5 
  al denominatore e poi a forzarlo a intero (metto int) ed vuol dire che lo sto approssimando al numero decimale più vicino*/
  

  // grafici  

  TCanvas c ;
  c.Divide(1,2);

  //primo grafico: quello dell'andamento

  c.cd(1);

  // evoluzione del sistema fino a 70 s  

  for (int step=0; step<nstep; step++) {   

    myGraph1.SetPoint(step,t,x[0]);
    x = myRungeKutta.Passo(t,x,h,osc);
    y = myEuler.Passo(t,y,h,osc); 
    t = t+h;

  }

  string title = "Oscillatore armonico  " + convert(h) + ")" ;
  gPad->SetGrid();
  myGraph1.SetTitle(title.c_str());
  myGraph1.GetXaxis()->SetTitle("Tempo [s]");
  myGraph1.GetYaxis()->SetTitle("Posizione x [m]");

  myGraph1.SetLineColor(2);
  myGraph1.SetMarkerStyle(1);

  myGraph1.Draw("ALP");


  // secondo grafico: quello degli errori per comparare l'efficienza dei due metodi
 
  c.cd(2);

  for(double i=0; i<10; i++) {
    
    double h = 0.1*pow(0.5,i);
    vector <double> x {0.0, 1.0};
    vector <double> y {0.0, 1.0};
    double t = 0; 

    int nstep = int(tmax/h+0.5);

        for (int step = 0; step < nstep; step++) {
            
            x = myRungeKutta.Passo(t,x,h,osc);
            y = myEuler.Passo(t,y,h,osc);
            t = t+h;

        }

    myGraph2.SetPoint(i,h,fabs(x[0] - sin(t)));
    
    cout << "Errore Runge Kutta: " << x[0] << endl << "Errore Eulero: " << y[0] << endl;

  }
  gPad->SetLogx();
  gPad->SetLogy();
  gPad->SetGrid();
  
  myGraph2.SetTitle("Andamento errore");
  myGraph2.GetXaxis()->SetTitle("Passo [m]");
  myGraph2.GetYaxis()->SetTitle("Errore");

  myGraph2.SetLineColor(2);
  myGraph2.SetMarkerStyle(20);

  myGraph2.Draw("ALP");

  
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

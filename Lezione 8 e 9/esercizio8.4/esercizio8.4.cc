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

  if ( argc!=3 ) {
    std::cerr << "Usage: " << argv[0] << " <stepsize> <omegaforzante>" << std::endl;   // da terminale devo inserire ./esercizio h nstep
    return -1;
  }  

  TApplication myApp("myApp",0,0); 

  RungeKutta myRungeKutta;

  double omega0 = 10;
  double alpha = 1.0/30.0;
  double omega = atof(argv[2]);

  OscillatoreSmorzatoForzato osc (omega0, alpha, omega);

  double h = atof(argv[1]);

  TGraph myGraph1;
  TGraph myGraph2;

  TCanvas c;
  c.Divide(1,2);
  
  double tmax = 25;
  double A = 0;
  double t = 0;

  vector<double> x {A, 0.0};

  c.cd(1);
 
  while (t<=tmax) {

    x = myRungeKutta.Passo(t,x,h,osc);

    myGraph1.AddPoint(t, x[0]);

    t = t + h;

  }

  myGraph1.SetTitle("Oscillatore armonico smorzato con forzante");
  myGraph1.GetXaxis()->SetTitle("tempo [s]");
  myGraph1.GetYaxis()->SetTitle("x [rad]");
  
  myGraph1.SetLineColor(1);
  myGraph1.SetMarkerStyle(1);   

  myGraph1.Draw("ALP"); 

  c.cd(2);

  tmax = 10 * (1./alpha);

  int nstep = 40;

  for(int i = 0; i<nstep; i++) {

    omega = 0.9*omega0+(0.2*omega0/nstep)*(i+1); //aumento la forzante

    t = 0.;

    x[0] = 0;

    x[1] = 0;

  OscillatoreSmorzatoForzato osc (omega0, alpha, omega);

  double tmp = 0;

  while (t<=tmax) {

    if(x[0]>tmp) {
      tmp = x[0];
    }

    x = myRungeKutta.Passo(t,x,h,osc);

    double omega2 = pow(omega0, 2)- pow(omega, 2);

    A = tmp;

    t = t + h;

   }

  myGraph2.SetPoint(i, omega, fabs(A));

  }

  myGraph2.SetTitle("Lorentziana (ampiezza in funzione della forzante)");
  myGraph2.GetXaxis()->SetTitle("Pulsazione [rad/s]");
  myGraph2.GetYaxis()->SetTitle("Ampiezza [rad]");
  
  myGraph2.SetLineColor(1);
  myGraph2.SetMarkerStyle(20);   

  myGraph2.Draw("ALP");
  
  myApp.Run();

  return 0;
}
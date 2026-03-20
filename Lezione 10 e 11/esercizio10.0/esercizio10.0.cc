#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"

#include <iostream>
#include "FunzioneBase.h"
#include "RandomGen.h" 

int main() {

  TApplication myApp("app",0,0);

  RandomGen myGen(1);    //seed iniziale = 1

  int nmax = 10000;      //numero totale di campioni da generare per l'istogramma


  // Istogramma per Unif

  TH1F unif("Uniforme","Uniforme",70,0.0,0.0) ;

  for ( int k = 0 ; k < nmax ; k++ ) {
    unif.Fill( myGen.Unif(5,10)  ) ;  
  }


  // Istogramma per Exp 

  TH1F exp("Esponenziale","Esponenziale",70,0,10) ;

  for ( int k = 0 ; k < nmax ; k++ ) {
    exp.Fill( myGen.Exp(1.0)  ) ;  
  }


  // Istogramma Gauss Box MUller 

  TH1F gaus_bm("Guassiana con metodi di Box Muller","Gaussiana con metodo di Box Muller",70,-4,6) ;

  for ( int k = 0 ; k < nmax ; k++ ) {
    gaus_bm.Fill( myGen.Gaus(1.0,1.0)) ;  
  }
  
  // Istogramma Guass Accept Reject 

  double mu = 1.0;
  double sigma = 1.0;
  Gaussiana gauss(sigma, mu);

  // intervallo di campionamento per gauss AR
  double a = mu - 5 * sigma; 
  double b = mu + 5 * sigma; 
  double max = gauss.Eval(mu);

  TH1F gaus_ar("Gaussiana","Gaussiana con metodo di Accept Reject",70,-4,6) ;

  for ( int k = 0 ; k < nmax ; k++ ) {
    gaus_ar.Fill( myGen.GausAR(a,b,max,gauss));  
  }


  // Apro canvas
  TCanvas *can = new TCanvas("myCanvas", "Distribuzioni Monte Carlo", 1000, 800);
  can->Divide(2, 2);

  // Primo Isto
  can->cd(1); // 
  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.Draw();

  // Secondo isto
  can->cd(2); // 
  exp.GetXaxis()->SetTitle("x [AU]");
  exp.GetYaxis()->SetTitle("N");
  exp.Draw();

  // Terzo isto
  can->cd(3); 
  gaus_bm.GetXaxis()->SetTitle("x [AU]");
  gaus_bm.GetYaxis()->SetTitle("N");
  gaus_bm.Draw();

  // Quarto isto
  can->cd(4); 
  gaus_ar.GetXaxis()->SetTitle("x [AU]");
  gaus_ar.GetYaxis()->SetTitle("N");
  gaus_ar.Draw();

  myApp.Run(); 
 
  return 0;

}
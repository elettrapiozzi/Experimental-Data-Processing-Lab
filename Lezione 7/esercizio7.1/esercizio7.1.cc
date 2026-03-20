#include <iostream> 
#include <iomanip>
#include "FunzioneBase.h"
#include "Integral.h"
#include "Simpson.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"

using namespace std;

int main (int argc, char** argv ) {

    if ( argc!=2 ) {
      cout << "Usage: " << argv[0] << " <nstep>" << endl;
      return -1;
    }
  
    unsigned int nstep = atoi(argv[1]);
    double a = 0.0;
    double b = M_PI / 2.; 
    xsinx fz;
  
    Simpson integrale(a,b) ;
  
    double I = integrale.Integra(nstep, fz); 
    cout << " Passi= " << setw(20) << nstep << endl;
    cout << " I=     " << setw(20) << I << endl;
    cout << "----------------------------" << endl;

    //grafico errore rispetto a sol analitica = 1 

    TApplication app("app",0,0); 

    nstep = 4;

    TGraph graph;
    TCanvas canvas;
    double h = 0.; 

    for (unsigned int i = 0; i < 20; i++) {
        h = (M_PI/2.-0.)/nstep;
        double err = fabs(integrale.Integra(nstep,fz) - 1.0);
        graph.SetPoint(i, h, err);
        nstep = nstep * 2;
      }
    
    canvas.SetLogy();
    canvas.SetLogx();

    graph.SetTitle("Andamento dell'errore tramite lunghezza del passo");
    graph.GetXaxis()->SetTitle("Passo");
    graph.GetYaxis()->SetTitle("Scarto valore noto e integrale nel punto");
    
    graph.SetLineColor(2);
    graph.SetMarkerStyle(20);   

    graph.Draw("ALP"); 
    
    app.Run();
    


    return 0;

}
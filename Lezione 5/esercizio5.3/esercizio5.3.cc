#include "CampoVettoriale.h"
#include "PuntoMateriale.h"
#include "Posizione.h"
#include "Particella.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLine.h"

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    TApplication app("app", 0, 0);

    TGraph graph;

  if ( argc!= 4) {
    cerr << "Usage: " << argv[0] << " <x> <y> <z>" << endl;
    exit(33); 
  }
  
  // coordinate del vettore posizione inserite da terminale

  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double z = atof(argv[3]);

  Posizione p(x, y, z);

  const double e =1.60217653E-19 ;
  const double me= 9.1093826E-31;
  const double mp= 1.6726219E-27;  
  const double d =1.E-10;

  PuntoMateriale elettrone(me, -e ,0.0 ,0.0 ,d/2.);
  PuntoMateriale protone(mp, e,0.0 ,0.0 ,-d/2.);

  // sommo i campi delle due particelle per trovare il campo del dipolo elettrico

  CampoVettoriale E = elettrone.campoelettrico(p) + protone.campoelettrico(p) ;

  // stampo il vettore E = (Ex, Ey, Ez)
  cout << "E = (" << E.getFx() << "," << E.getFy() << "," << E.getFz() << ")" << endl;

  double E1;
  double E2;

  for(int i =100; i <1001; i++) {
    Posizione p(0, 0, d*i); 

    PuntoMateriale elettrone(me, -e,0.,0.,d/2.);
    PuntoMateriale protone(mp, e,0.,0.,-d/2.);

    CampoVettoriale E = elettrone.campoelettrico(p) + protone.campoelettrico(p) ;
    
    // .SetPoint serve ovviamente per fare gli indici. I termini tra parentesi rispettivamente sono il "nome" dell'indice (in root partono
    // da zero quindi devo fare i-100), posizione del punto sull'asse x e poszione del punto sull'asse y

    graph.SetPoint(i-100, d*i, E.modulo());   

    if (i == 100) {
        E1 = E.modulo();   // servono per il calcolo di alpha questo è il primo caso
    }

    if (i == 1000) {      // questo è l'ultimo
        E2 =E.modulo();
    }
  }

  
double alpha = log(E1/E2)/log((d*100)/(d*1000));

  if(alpha == 0) {
    cout << "Il campo elettrico è costante" << endl; 
  } 

  if(-1.5<alpha && alpha<0) {
    cout << "Il campo elettrico decresce con il raggio" << endl;
  }

  if(alpha == 1) {
    cout << "Il campo elettrico cresce con il raggio " << endl;
  }

  if(-2.5<alpha && alpha<=-1.5) {
    cout << "Il campo elettrico decresce come r^(-2) " << endl;
  }
  
  if(-3.5<alpha && alpha<=-2.5) {
    cout << "Il campo elettrico decresce come r^(-3) " << endl;
  }

  if(alpha <= -3.5) {
    cout << "Il campo elettrico decresce più velocemente " << endl;
  }

  TCanvas c ("campo elettrico", "Campo Elettrico");
  

  c.SetLogy();
  c.SetGrid();
  c.SetFillColor(0);

  graph.SetLineWidth(1);
  graph.SetTitle("Campo Elettrico");
  graph.GetXaxis()->SetNdivisions(500);
  graph.GetYaxis()->SetNdivisions(500);
  graph.GetXaxis()->SetTitle("Distanza [m]");
  graph.GetYaxis()->SetTitle("Modulo campo [N/C]");
  graph.Draw("ALP");
  c.SaveAs("CampoElettrico.png");

  app.Run();

  return 0;

}

#include <iostream>
#include <string>
#include <cstdlib>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include <vector>

#include "funzioni.h"
using namespace std;

int main () {

    TApplication app("app", 0, 0);

    TGraphErrors trend;    // definisco TGraphErrors ( sempre come fosse int ), è di root
    int index = 0;         

    vector <double> dati_tot;

    //loop principale su tutti i files (anni) da analizzare
    // !!!! Solo per calcolo della media storica !!!!

    for(int i= 1941; i< 2024; i++) {

    string filename = "TemperatureMilano/" + to_string(i) + ".txt";

    vector<double> v = read<double>(filename.c_str()); //c_str converte string in char

        for (int j = 0; j < v.size(); j++) {
            dati_tot.push_back(v[j]);
        }
    }

    double media_storica = media(dati_tot);
    
    
    //loop vero per il calcolo della media giornaliera per ogni anno

    for(int i = 1941; i < 2024; i++) {
        string filename = "TemperatureMilano/" + to_string(i) + ".txt";
        vector<double> v = read<double>(filename.c_str());

        vector<double> delta_giornaliero;

        for (int j = 0; j < v.size(); j++) {
            delta_giornaliero.push_back(v[j] - media_storica);
        }

        double ave = media(delta_giornaliero);     
        double err = errore(delta_giornaliero);    

        cout << "  Anno " << i << "  delta medio = " << ave << " +/- " << err << endl;

        //per il grafico
        trend.SetPoint(index, i, ave);
        trend.SetPointError(index, 0, err);
        index++;
    }


    //grafica

    TCanvas c("Temperature trend","Temperature trend");
    c.cd();
    c.SetGridx();
    c.SetGridy();
  
    trend.SetMarkerSize(1.0);
    trend.SetMarkerStyle(20);
    trend.SetFillColor(5);
  
    trend.SetTitle("Temperature trend");
    trend.GetXaxis()->SetTitle("Anno");
    trend.GetYaxis()->SetTitle("#Delta (#circ C)");
    trend.Draw("apl3");
    trend.Draw("pX");
  
    c.SaveAs("trend.png");
  
    app.Run();
        
}




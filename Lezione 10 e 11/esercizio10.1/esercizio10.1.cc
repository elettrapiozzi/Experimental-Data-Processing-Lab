#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include "RandomGen.h"

using namespace std;

int main() {

    TApplication myApp("app",0,0);
  
    RandomGen myGen(1);    //seed iniziale = 1
  
    int nmax = 1000000;      //numero totale di campioni da generare per l'istogramma

    // Apro canvas
    TCanvas *can = new TCanvas("myCanvas", "Distribuzioni Monte Carlo", 1000, 800);
    can->Divide(3,4);

    // dichiaro un vettore di puntatori a TH1F, altrimenti l'istogramma si cancella ogni volta che riparte il ciclo for
    vector <TH1F*> istogramma;

    // dichiaro vettore di puntatori per salvare le varianze ai vari N
    vector <double> varianza;
    vector <double> N_val;
    vector <double> var_teorica;

    double var_teorica_01 = 1.0 / 12.0;


    // ciclo for per generare gli istogrammi

    for (int N = 1; N < 13; N++) {

        TH1F *current_sum = new TH1F(Form("somme_N%d", N),Form("Distribuzione delle somme (N%d)", N),
        100.0,0.0,(double)N+0.5);

        istogramma.push_back(current_sum);

        for ( int k = 0 ; k < nmax ; k++ ) {
            double somma = 0.0;

            for (int j = 0; j<N; j++) {
            somma += myGen.Unif(0.0,1.0);  
        }
         
        current_sum->Fill(somma);

        }

        // stampo media e dev standard
        double mean1 = current_sum->GetMean();
        double devstd = current_sum->GetRMS();
        double var = devstd*devstd;

        cout << "Per N = " << N << " : " << endl;
        cout << fixed << setprecision(6);
        cout << "- Media = " << mean1 << endl;
        cout << "- Varianza = " << var << endl;

        
        can->cd(N);
        current_sum->GetXaxis()->SetTitle("x [AU]");
        current_sum->GetYaxis()->SetTitle("n");
        current_sum->Draw();


        // memorizzo i valori di varianza per fare il grafico in fz di N
        N_val.push_back((double)N);    // N dev'essere double per fare il TGraph
        varianza.push_back(var);
        var_teorica.push_back(N*var_teorica_01);

    }

    // creo il grafico della varianza

    TCanvas *cc = new TCanvas("grafico_varianza", "Varianza delle Somme in funzione di N", 800, 600);
    cc->cd();

    TGraph *varianza_empirica = new TGraph(N_val.size(), N_val.data(), varianza.data());
    varianza_empirica->SetTitle("Varianza delle Somme in funzione di N");
    varianza_empirica->SetMarkerStyle(20); 
    varianza_empirica->SetLineColor(1);

    TGraph *varianza_teorica = new TGraph(N_val.size(), N_val.data(), var_teorica.data());; 
    varianza_teorica->SetLineColor(1);

    varianza_empirica->Draw("AP");
    varianza_teorica->Draw("SAME L");    // sullo stesso grafico


myApp.Run();

return 0; 

}

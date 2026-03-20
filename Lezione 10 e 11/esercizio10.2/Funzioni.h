#include"Integrale.h"
#include <fstream>
#include"TGraph.h"
#include"TApplication.h"
#include"TCanvas.h"
#include"TAxis.h"
#include"TLine.h"
#include"TH1F.h"

// trovare ymax per metodo hit or miss 

double find_ymax(double a, double b, const FunzioneBase &f){

    double ymax = numeric_limits<double>::lowest();   // inizializzo ymax col valore più piccolo
    double temp=0.;

    for(double i=a; i<b; i+=0.0001) {
        temp=f.eval(i);

        if(temp>ymax){
            ymax=temp;
        }
    }
    return ymax;
}

// per il primo set di risultati (N= 100)
double findmaxfirst(vector<double> &dati, int toth){

    double max=numeric_limits<double>::lowest();
    for(int i=0; i<static_cast<int>(dati.size()/toth); i++){
        if(dati[i]>max){
            max=dati[i];
        }
    }
    return max;
}
double findminfirst(vector<double> &dati, int toth){
    double min=numeric_limits<double>::max();
    for(int i=0; i<static_cast<int>(dati.size()/toth); i++){
        if(dati[i]<min){
            min=dati[i];
        }
    }
    return min;

}



vector<double> IntegraleMC(int n, const vector <int> & N_values, double a, double b, Integrale *m){

    double inizio=min(a, b);
    double fine=max(a, b);
    int sgn;
    if(a<b){
        sgn=1;
    }else{
        sgn=-1;
    }

    vector<double> dati;
    xsinx f;
    double ymax=find_ymax(inizio, fine, f);
    double tmpint;

    for(int i=0; i<N_values.size(); i++){
        int N_current = N_values[i]; 

        for(int j=0; j<n; j++){
            tmpint=m->Integra(N_current, inizio, fine, f, ymax, sgn);
            dati.push_back(tmpint);
        }
    }    
    return dati;
}



void printtofile(vector<double> &dati, string filename){
    ofstream data;
    data.open(filename, ios::out);
    for(int i=0; i<dati.size(); i++){
        data << dati[i];
        data << endl;
    }
    data.close();
}


vector<double> copiadati(string filename){
    ifstream data;
    vector<double> dati;
    data.open(filename, ios::in);
    double mom=0.;
    while(data >> mom){
        dati.push_back(mom);
    }
    data.close();
    return dati;
}




vector<TH1F*> istogrammi(int n, const vector <int> & N_values, vector<double> &dati){
    vector<TH1F*> histo;
    double max = numeric_limits <double> :: lowest();
    double min = numeric_limits <double> :: max();

    for (int i=0; i<N_values.size(); i++){
        histo.push_back(new TH1F(Form("Legenda %d", i+1), Form("Integrale (N: %d)", N_values[i]), 100, 0.8, 1.2));
        
    }
    for(int i=0; i<N_values.size(); i++){
        for(int j=n*i; j<n*(i+1); j++){
            histo[i]->Fill(dati[j]);
        }
    }
    return histo;
}



void grafici(int n, const vector <int> & N_values, vector<TH1F*> histo, vector<double> &dati, string method){
    
    TCanvas c("Integrale (xsin(x))", "Integrale (xsin(x))");
    
    c.cd();
    c.Divide(4, 2);

    for(int i=0; i<N_values.size(); i++){
        c.cd(i+1);
        histo[i]->GetYaxis()->SetTitleOffset(1);
        histo[i]->GetXaxis()->SetTitle("Integrale");
        histo[i]->GetYaxis()->SetTitle("N");
        histo[i]->Draw();                
    }

    TGraph err;
    c.cd(N_values.size()+1);
    gPad->SetLogy();
    gPad->SetLogx();
    gPad->SetGrid();

    
    for(int i=0; i<N_values.size(); i++){
        int N_current = N_values[i];

        double mean=0.0;
        double sum=0.0;

        for(int t=n*i; t<n*(i+1); t++){
            sum+=dati[t];
        }

        mean=sum/n;

        double totsum=0.;

        for(int t=n*i; t<n*(i+1); t++){
            totsum+=pow(dati[t]-mean, 2);
        }

        double stddev=sqrt(totsum/n);
        err.SetPoint(i, N_current, stddev);
    
    }
        

    err.GetYaxis()->SetTitleOffset(1);
    err.SetTitle("Errore su ogni Integrale");
    err.GetXaxis()->SetTitle("N");
    err.GetYaxis()->SetTitle("Errore");
    err.SetMarkerColor(1);
    err.SetMarkerSize(0.4);
    err.SetMarkerStyle(20);
    err.SetLineColor(2);
    err.SetLineWidth(1);
    err.Draw("APL");
    stringstream nomepng;
    nomepng << "Integrale_" << method << ".png";
    c.SaveAs(nomepng.str().c_str());

};
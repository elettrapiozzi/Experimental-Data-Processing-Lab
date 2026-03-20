#include<iostream>
#include<filesystem>
#include"Funzioni.h"
#include "FunzioneBase.h"
#include "Integrale.h"
#include "RandomGen.h"

using namespace std;

namespace fs=std::filesystem;


int main(int argc, char **argv){
    if(argc<2){
        cout << "Uso del programma: " << argv[0] << " <media/hitmiss>" << endl;
        return -1; 
    }

    string method=argv[1];


    vector<int> N_values = {500, 1000, 5000, 10000, 50000, 100000};
    int n=10000;

    double a=0.;
    double b=M_PI/2;
    string filename;
    Integrale *metodo;

    if(method=="media"){
        metodo=new media(0);
        filename="data_media.txt";

    }else if(method=="hitmiss"){
        metodo=new hitmiss(0);

        filename="data_hitmiss.txt";
    }else{
        cout << "Errore, metodo non integrato." << endl;
        return (33);
    }
    if(fs::exists(filename)){
        vector<double> dati=copiadati(filename);
        vector<TH1F*> histo=istogrammi(n, N_values, dati);
        grafici(n, N_values, histo, dati, method);
    }else{
        vector<double> dati=IntegraleMC(n, N_values, a, b, metodo);
        printtofile(dati, filename);
        vector<TH1F*> histo=istogrammi(n, N_values, dati);
        grafici(n, N_values, histo, dati, method);
    }


    return 0;


}
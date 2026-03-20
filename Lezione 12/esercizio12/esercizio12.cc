#include "TApplication.h"
#include "TCanvas.h" 
#include "TH1F.h"
#include "TH2F.h"
#include "TAxis.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include "RandomGen.h"
#include "EsperimentoPrisma.h"
#include "print.h"

using namespace std;

int main(){

    TApplication myApp("app",0,0);

    TCanvas c;
    c.Divide(3,4);

    int n = 10000;   // ripetiamo l'esperimento 1000 volte 

    EsperimentoPrisma p;

    // ISTOGRAMMA PER PARAMETRO A DI CAUCHY

    c.cd(1);

    TH1F istoA("A","A",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();     // simulo esperimento
        p.Analizza();   // prendo i dati e calcolo le variabili derivate
        istoA.Fill(p.getAmis());   // aggiungi all'istogramma il valore di A misurato - A input
    }

    istoA.StatOverflows(kTRUE);   // includi anche dati overflow/underflow per i calcoli di media, dev std, ecc

    istoA.SetTitle("A");
    istoA.GetXaxis()->SetTitle("valori di A");
    istoA.GetYaxis()->SetTitle("occorrenze");

    istoA.Draw();


    // ISTOGRAMMA PER PARAMETRO B DI CAUCHY

    c.cd(2);

    TH1F istoB("B","B",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        istoB.Fill(p.getBmis());
    }

    istoB.StatOverflows(kTRUE);

    istoB.SetTitle("B");
    istoB.GetXaxis()->SetTitle("valori di B");
    istoB.GetYaxis()->SetTitle("occorrenze");

    istoB.Draw();


    // ISTOGRAMMA THETA ZERO

    c.cd(3);

    TH1F istoth0("th0","th0",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        istoth0.Fill(p.getth0mis());
    }

    istoth0.StatOverflows(kTRUE);

    istoth0.SetTitle("theta 0");
    istoth0.GetXaxis()->SetTitle("valori di theta 0");
    istoth0.GetYaxis()->SetTitle("occorrenze");

    istoth0.Draw();


    // ISTOGRAMMA THETA 1

    c.cd(4);

    TH1F istoth1("th1","th1",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        istoth1.Fill(p.getth1mis());
    }

    istoth1.StatOverflows(kTRUE);

    istoth1.SetTitle("theta 1");
    istoth1.GetXaxis()->SetTitle("valori di theta 1");
    istoth1.GetYaxis()->SetTitle("occorrenze");

    istoth1.Draw();


    // ISTOGRAMMA THETA 2

    c.cd(5);

    TH1F istoth2("th2","th2",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        istoth2.Fill(p.getth2mis());
    }

    istoth2.StatOverflows(kTRUE);

    istoth2.SetTitle("theta 2");
    istoth2.GetXaxis()->SetTitle("valori di theta 2");
    istoth2.GetYaxis()->SetTitle("occorrenze");

    istoth2.Draw();


    // ISTOGRAMMA DELTA M (LANDA 1)

    c.cd(6);

    TH1F istod1m("d1m","d1m",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        istod1m.Fill(p.getdm1mis());
    }

    istod1m.StatOverflows(kTRUE);

    istod1m.SetTitle("delta minimo 1");
    istod1m.GetXaxis()->SetTitle("valori di delta min 1");
    istod1m.GetYaxis()->SetTitle("occorrenze");

    istod1m.Draw();


    // ISTOGRAMMA DELTA M (LANDA 2)

    c.cd(7);

    TH1F istod2m("dm2","dm2",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        istod2m.Fill(p.getdm2mis());
    }

    istod2m.StatOverflows(kTRUE);

    istod2m.SetTitle("delta minimo 2");
    istod2m.GetXaxis()->SetTitle("valori di delta min 2");
    istod2m.GetYaxis()->SetTitle("occorrenze");

    istod2m.Draw();


    // INDICE DI RIFRAZIONE LANDA 1

    c.cd(8);

    TH1F iston1("n1","n1",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        iston1.Fill(p.getn1mis());
    }

    iston1.StatOverflows(kTRUE);

    iston1.SetTitle("n1");
    iston1.GetXaxis()->SetTitle("valori di n1");
    iston1.GetYaxis()->SetTitle("occorrenze");

    iston1.Draw();

    // INDICE DI RIFRAZIONE LANDA 2

    c.cd(9);

    TH1F iston2("n2","n2",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        iston2.Fill(p.getn2mis());
    }

    iston2.StatOverflows(kTRUE);

    iston2.SetTitle("n2");
    iston2.GetXaxis()->SetTitle("valori di n2");
    iston2.GetYaxis()->SetTitle("occorrenze");

    iston2.Draw();

    // variabili per il calcolo dei coefficienti di correlazione

    double AB = 0.0;
    double A = 0.0;
    double B = 0.0;
    double N2 = 0.0;
    double N1 = 0.0;
    double D1 = 0.0; 
    double D2 = 0.0;
    double N1N2 = 0.0;
    double D1D2 = 0.0;

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();

        AB += p.getAmis()*p.getBmis();
        A += p.getAmis();
        B += p.getBmis();

        N1N2 += p.getn1mis()*p.getn2mis();
        N1 += p.getn1mis();
        N2 += p.getn2mis();

        D1D2 += p.getdm1mis()*p.getdm2mis();
        D1 += p.getdm1mis();
        D2 += p.getdm2mis();
        
    }

    // calcolo dei coefficienti di correlazione

    double corrAB = (((AB/n) - (A/n)*(B/n))/(istoA.GetStdDev()*istoB.GetStdDev()))*100;
    double corrN1N2 = (((N1N2/n) - (N1/n)*(N2/n))/(iston1.GetStdDev()*iston2.GetStdDev()))*100;
    double corrD1D2 = (((D1D2/n) - (D1/n)*(D2/n))/(istod1m.GetStdDev()*istod2m.GetStdDev()))*100;


    // ISTOGRAMMA CORRELAZIONE TRA A E B

    c.cd(10);

    // è una correlazione tra due cose quindi serve istogramma 2d

    TH2F istoAB("correlazione AB", "Correlazione AB", 100, 0, 0, 100, 0, 0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();

        istoAB.Fill(p.getAmis(), p.getBmis());

    }

    istoAB.StatOverflows(kTRUE);

    istoAB.GetXaxis()->SetTitle("valori di A");
    istoAB.GetYaxis()->SetTitle("valori di B");
    istoAB.Draw();


    // ISTOGRAMMA CORRELAZIONE TRA N1 E N2

    c.cd(11);

    TH2F istoAN("correlazione N1N2", "Correlazione N1N2", 100, 0, 0, 100, 0, 0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();

        istoAN.Fill(p.getn1mis(), p.getn2mis());

    }

    istoAN.StatOverflows(kTRUE);

    istoAN.GetXaxis()->SetTitle("valori di N1");
    istoAN.GetYaxis()->SetTitle("valori di N2");
    istoAN.Draw();


    // ISTOGRAMMA CORRELAZIONE TRA DELTA 1 E DELTA 2

    c.cd(12);

    TH2F istoAD("correlazione D1D2", "Correlazione D1D2", 100, 0, 0, 100, 0, 0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();

        istoAD.Fill(p.getdm1mis(), p.getdm2mis());

    }

    istoAD.StatOverflows(kTRUE);

    istoAD.GetXaxis()->SetTitle("valori di D1");
    istoAD.GetYaxis()->SetTitle("valori di D2");
    istoAD.Draw();

    print (p, istoA, istoB, iston1, iston2, istoth0, istoth1, istoth2, istod1m, istod2m, corrAB, corrN1N2, corrD1D2);

    myApp.Run();

    return 0;

}
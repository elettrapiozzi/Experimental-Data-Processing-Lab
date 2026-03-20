#include "EsperimentoPrisma.h"
#include "TH1F.h"
#include <iostream>
using namespace std;

void print (EsperimentoPrisma p, TH1F istoA, TH1F istoB, TH1F iston1, TH1F iston2,
           TH1F istoth0, TH1F istoth1, TH1F istoth2, TH1F istod1m, TH1F istod2m, double corrAB, double corrN1N2, double corrD1D2) {

    cout << "Valore di A: " << istoA.GetMean() << " +- " << istoA.GetStdDev() << endl;
    cout << "Valore di B: " << istoB.GetMean() << " +- "<< istoB.GetStdDev() << endl;
    cout << "Valore di theta 0: " << istoth0.GetMean() << " +- "<< istoth0.GetStdDev() << endl;
    cout << "Valore di theta 1: " << istoth1.GetMean() << " +- "<< istoth1.GetStdDev() << endl;
    cout << "Valore di theta 2: " << istoth2.GetMean() << " +- "<< istoth2.GetStdDev() << endl;
    cout << "Valore di delta minimo 1: " << istod1m.GetMean() << " +- "<< istod1m.GetStdDev() << endl;
    cout << "Valore di delta minimo 2: " << istod2m.GetMean() << " +- "<< istod2m.GetStdDev() << endl;
    cout << "Valore di n1: " << iston1.GetMean() << " +- "<< iston1.GetStdDev() << endl;
    cout << "Valore di n2: " << iston2.GetMean() << " +- "<< iston2.GetStdDev() << endl;
    cout << "Correlazione AB: " << corrAB << " %" << endl;
    cout << "Correlazione N1N2: " << corrN1N2 << " %" << endl;
    cout << "Correlazione D1D2: " << corrD1D2 << " %" << endl;
    cout << endl;
    cout << "Compatibilità tra valori noti e misurati: " << endl;
    cout << "A: " << (fabs(p.getAinput()-p.getAmis())/istoA.GetStdDev()) << endl;
    cout << "B: " << (fabs(p.getBinput()-p.getBmis())/istoB.GetStdDev())<< endl;
    cout << "theta 0: " << (fabs(p.getth0input()-p.getth0mis())/istoth0.GetStdDev()) << endl;
    cout << "theta 1: " << (fabs(p.getth1input()-p.getth1mis())/istoth1.GetStdDev()) << endl;
    cout << "theta 2: " << (fabs(p.getth2input()-p.getth2mis())/istoth2.GetStdDev()) << endl;
    cout << "delta minimo 1: " << (fabs(p.getdm1input()-p.getdm1mis())/istod1m.GetStdDev()) << endl;
    cout << "delta minimo 2: " << (fabs(p.getdm2input()-p.getdm2mis())/istod2m.GetStdDev()) << endl;
    cout << "n1: " << (fabs(p.getn1input()-p.getn1mis())/iston1.GetStdDev()) << endl;
    cout << "n2: " << (fabs(p.getn2input()-p.getn2mis())/iston2.GetStdDev()) << endl;
    
  };
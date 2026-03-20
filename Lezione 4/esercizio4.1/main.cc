#include <iostream>
#include <vector>
#include <fstream>

#include "TGraphErrors.h"
#include "TApplication.h"
#include "TF1.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TCanvas.h"  

#include <cmath>

using namespace std;

void ParseFile(string filename, vector<double> &myx, vector<double> &myy, vector<double> &myerry) {
    ifstream fin(filename.c_str());
    double x, y, err;

    if (!fin) {
        cout << "Cannot open file " << filename << endl;
        exit(11);
    }

    while (fin >> x >> y >> err) {
        myx.push_back(x);
        myy.push_back(y);
        myerry.push_back(err);
    }

    fin.close();
}

TGraphErrors DoPlot(vector<double> myx, vector<double> myy, vector<double> myerry) {
    TGraphErrors mygraph;
    for (int k = 0; k < myx.size(); k++) {
        mygraph.SetPoint(k, myx[k], myy[k]);
        mygraph.SetPointError(k, 0, myerry[k]);
    }
    return mygraph;
}

int main() {

    TApplication app("MyApp", 0, 0);

    vector<double> myx;
    vector<double> myy;
    vector<double> myerry;

    // leggi dati dal file
    ParseFile("data_eom.dat", myx, myy, myerry);

    // crea il TGraphErrors
    TGraphErrors mygraph = DoPlot(myx, myy, myerry);

    // fit lineare
    TF1 *myfun = new TF1("fitfun", "[0]*x+[1]", 0, 1000);
    mygraph.Fit(myfun);
    
    double slope = myfun->GetParameter(0);
    double slope_err = myfun->GetParError(0);

    // calcolo e/m e errore
    double em = 1.0 / slope;
    double em_err = slope_err / (slope * slope);

    cout << "Risultati del fit lineare:" << endl;
    cout << "- Chi quadro = " << myfun->GetChisquare() << endl;
    cout << "- Gradi di libertà = " << myfun->GetNDF() << endl;
    cout << "- Parametro slope (p0) = " << slope << " +/- " << slope_err << endl;
    cout << "- Parametro intercetta (p1) = " << myfun->GetParameter(1) << " +/- " << myfun->GetParError(1) << endl;
    cout << "- Valore stimato di e/m = " << em << " +/- " << em_err << endl;
    cout << "- Probabilità del fit (chi quadro) = " << myfun->GetProb() << endl;

    mygraph.SetMarkerStyle(20);
    mygraph.SetMarkerSize(1);
    mygraph.SetTitle("Misura e/m");
    mygraph.GetXaxis()->SetTitle("2#DeltaV (V)");
    mygraph.GetYaxis()->SetTitle("(B_{z}R)^{2} (T^{2}m^{2} )");

    TLegend leg(0.15, 0.7, 0.3, 0.85);
    leg.AddEntry(&mygraph, "Dati sperimentali", "p");
    leg.AddEntry(myfun, "Fit lineare", "l");

    TCanvas c("c", "Fit e/m");
    mygraph.Draw("AP");
    leg.Draw("same");

    c.SaveAs("fit_em.png");

    app.Run();

    return 0;
}

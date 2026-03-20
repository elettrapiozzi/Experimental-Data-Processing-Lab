#include <iostream>
#include <cmath>
#include <float.h>
#include <iomanip>
#include "Bisezione.h"
#include "Parabola.h"

using namespace std;

int main(int argc, char** argv) {

    Parabola miaparabola(3,5,-2);

    if(argc!=4) {
        cerr << "Utilizzo del programma: " << argv[0] << " <estremo a intervallo> <estremo b intervallo> <precisione>" << endl;
        exit(-1);
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double passo = 0.05;
    double prec = atof(argv[3]);

    int cifre_significative = -log10(prec);

    Bisezione bisezione;
    sign segno;

    double fa = miaparabola.Eval(a);
    double fb = miaparabola.Eval(b);

    cout << fixed << setprecision(cifre_significative);

        for (double x = a; x <= b; x += passo) {
            double fx = miaparabola.Eval(x);
            double fx_next = miaparabola.Eval(x + passo);
        
            if (segno.eval(fx) * segno.eval(fx_next) <= 0) {
                double zero = bisezione.CercaZero(miaparabola, x, x + passo, prec);
                cout << "Trovato zero in: " << zero << endl;
            }
        }
        


    return 0;
}
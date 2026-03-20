#include <iostream>
#include <cmath>
#include <float.h>
#include <iomanip>
#include "Bisezione.h"
#include "TanFunction.h"

using namespace std;

int main() {

    TanFunction funzione;
    Bisezione bisezione;
    double prec = 1e-6;

    int cifre_significative = - log10(prec);
    cout << fixed << setprecision(cifre_significative); 

    for (int i=1; i < 21; i++) {
        double a = i * M_PI;
        double b = a + M_PI / 2;

        double zero = bisezione.CercaZero(funzione, a, b, prec)
        ;
        cout << "n = " << i << ", zeri tra (" << a << ", " << b << ") : x = " << zero << endl;
    }
        


    return 0;
}
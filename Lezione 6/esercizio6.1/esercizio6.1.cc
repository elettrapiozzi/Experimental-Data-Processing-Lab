#include <iostream>
#include "FunzioneBase.h"
#include "Parabola.h"

using namespace std;

int main () {

    double a = 3; 
    double b = 5;
    double c = -2;

    Parabola miaparabola (a,b,c);
    double xv = - b /(2*a);

    double yv = miaparabola.Eval(xv); 

    cout << "Funzione valutata in x = " << xv << ": f(x) = " << yv << endl;
    
    return 0;
}
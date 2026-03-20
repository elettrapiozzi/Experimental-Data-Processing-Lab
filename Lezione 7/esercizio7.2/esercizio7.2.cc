#include <iostream> 
#include <iomanip>
#include "FunzioneBase.h"
#include "Integral.h"
#include "Trapezi.h"


using namespace std;

int main (int argc, char** argv ) {

    if ( argc!=2 ) {
      cout << "Usage: " << argv[0] << " <prec>" << endl;
      return -1;
    }
  
    double prec  = atof(argv[1]);
    double a = 0.0;
    double b = M_PI / 2; 
    xsinx fz;
  
    Trapezi integrale(a,b) ;   
  
    double I = integrale.Integra(prec, fz); 
    
    cout << " Hai richiesto una precisione = " << setw(20) << prec << endl;
    cout << setprecision(10) << " I=                             " << setw(20) << I << endl;
    cout << "-------------------------------------" << endl;
    
    return 0;

}
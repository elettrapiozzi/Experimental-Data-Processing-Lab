#include <vector>
#include <iostream>

#include "VectorOperations.h"

using namespace std;

int main() {

// provare la somma e prodotto per scalare, calcolare il versore della risultante v1+v2
   vector <double> v1 { 3.0,4.0,6.0} ;
   vector <double> v2 { 4.0,5.0,6.0} ;

   double para = 2.;

   vector <double> v_somma = v1 + v2;
   vector <double> prod_perscal1 = para*v1;
   vector <double> prof_perscal2 = para*v2;
   double prod_scal = v1*v2;

    cout << "Vettori iniziali: v1 = (3,4,6) e v2 = (4,5,6)" << endl;
    cout << "Somma: ";
    Print(v_somma);
    cout << endl << "Prodotto per scalare 2 di v2: ";
    Print(prof_perscal2);
    cout << endl << "Prodotto per scalare 2 di v1: ";
    Print(prod_perscal1);
    cout << endl << "Prodotto scalare: " << prod_scal << endl;

    return 0;

}
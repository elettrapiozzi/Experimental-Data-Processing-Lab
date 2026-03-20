#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Vettore.h"
#include "funzioni.h"

using namespace std;

int main (int argc, char** argv) {

    if (argc < 3) {
        cout << "Uso del programma: " << argv[0] << " <n_data> <filename>" << endl << endl;
        return -1;
    }

    unsigned int ndata = atoi(argv[1]);
    const char* filename = argv[2];

    Vettore<double> v = read<double>(ndata, filename);

    print (v);

    cout << "-- Media    = " << media<double>(v) << endl;
    cout << "-- Varianza = " << varianza<double>(v) << endl;
    cout << "-- Deviazione Standard = " <<dev_std<double>(v) << endl;
    cout << "-- Mediana  = " << mediana<double>(v) << endl << endl;
    
    sort_by(v);

    print(v); 

    print ("output.txt", v);
    
    return 0;
}

#include "Elettrone.h"

Elettrone::Elettrone() : Particella(9.1093826E-31,-1.60217653E-19) {
    //vuoto
}

Elettrone::~Elettrone() {
    //vuoto
}

void Elettrone::Print() const {
    cout << "Massa elettrone: " << m << endl;
    cout << "Carica elettrone: " << q << endl;
}
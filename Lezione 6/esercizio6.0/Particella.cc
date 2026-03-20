#include "Particella.h"

// costruttori 

Particella::Particella() {
    m = 0;
    q = 0;
}

Particella::Particella(double massa, double carica) {
    m = massa;
    q = carica;
}

//distruttore 

Particella::~Particella() {
    //vuoto
}


//metodi 

double Particella::getMassa() const {
    return m;
}


double Particella::getCarica() const {
    return q;
}


void Particella::Print() const {
    cout << "Massa particella: " << m << endl;
    cout << "Carica particella: " << q << endl;
}



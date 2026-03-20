#include "Posizione.h"
#include <cmath>

//costruttori 

Posizione::Posizione() {
    x_cart = 0;
    y_cart = 0;
    z_cart = 0;
}

Posizione::Posizione (double x, double y, double z) {
    x_cart = x;
    y_cart = y;
    z_cart = z;
}

//distruttore 

Posizione::~Posizione() {
    //vuoto (no dinamici)
}


//metodi per restituire coordinate CARTESIANE

double Posizione::getX() const {
    return x_cart;
}

double Posizione::getY() const {
    return y_cart;
}

double Posizione::getZ() const {
    return z_cart;
}


//metodi per restituire coordinate SFERICHE 

double Posizione::getR() const {
    double R = sqrt(x_cart*x_cart + y_cart*y_cart + z_cart*z_cart);

    return R;
}

double Posizione::getTheta() const {
    double Theta = acos(z_cart/getR());
    
    return Theta;
}

double Posizione::getPhi() const {
    double Phi = atan2(y_cart, x_cart); //cioe atan2(y/x)
    
    return Phi;
}


//metodi per restituire coordinate CILINDRICHE

double Posizione::getR_cilindrico() const {
    double R_cilindrico = sqrt(x_cart*x_cart + y_cart*y_cart);
    
    return R_cilindrico;
}

double Posizione::getTheta_cilindrico() const {
    double Theta_cilindrico = atan2(y_cart, x_cart);
    
    return Theta_cilindrico;
}


//calcolo distanza

double Posizione::distanza(const Posizione& p2) const {
    double distanza = sqrt( pow(getX()-p2.getX(), 2) + pow(getY() - p2.getY(), 2) + pow(getZ()-p2.getZ(), 2));

    return distanza;
}

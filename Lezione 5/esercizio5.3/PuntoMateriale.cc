#include "PuntoMateriale.h"
#include <iostream>
#include <cmath>

using namespace std;


// costruttori 

PuntoMateriale::PuntoMateriale() {
    //vuoto
}

PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione& posiz) : 
Posizione(posiz), Particella(massa, carica) {
    //vuoto
}

PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z) : 
Posizione(x, y, z), Particella(massa, carica) {
    //vuoto
}


// distruttore 

PuntoMateriale:: ~PuntoMateriale() {
        //vuoto
}


// metodi

double epsilon0 = 8.854187818E-12;
const double Ggrav = 6.67430E-11;

CampoVettoriale PuntoMateriale::campoelettrico(const Posizione& r) const {
    CampoVettoriale E(r);

    Posizione distanza(r.getX() - getX(), r.getY() - getY(), r.getZ() - getZ());

    double Ex = (getCarica()/(4*M_PI*epsilon0))*r.getX()*(1/(pow((distanza.getR()),3)));
    double Ey = (getCarica()/(4*M_PI*epsilon0))*r.getY()*(1/(pow((distanza.getR()),3)));
    double Ez = (getCarica()/(4*M_PI*epsilon0))*r.getZ()*(1/(pow((distanza.getR()),3)));
    
    E.setFx(Ex);
    E.setFy(Ey);
    E.setFz(Ez);

    return E;
}



CampoVettoriale PuntoMateriale::campogravitazionale(const Posizione& r) const {
    CampoVettoriale G(r);

    Posizione distanza(r.getX() - getX(), r.getY() - getY(), r.getZ() - getZ());

    double Gx = getMassa()*Ggrav*(1/(pow(distanza.getR(),3)));
    double Gy = getMassa()*Ggrav*(1/(pow(distanza.getR(),3)));
    double Gz = getMassa()*Ggrav*(1/(pow(distanza.getR(),3)));
    
    G.setFx(Gx);
    G.setFy(Gy);
    G.setFz(Gz);

    return G;

}

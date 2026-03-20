#include "CampoVettoriale.h"
#include <cmath>

using namespace std;

//costruttori

CampoVettoriale::CampoVettoriale(): Posizione(), m_Fx(0), m_Fy(0), m_Fz(0) {
// vuoto
}



CampoVettoriale::CampoVettoriale(const Posizione& posiz) : 
Posizione(posiz), m_Fx(0), m_Fy(0), m_Fz(0) {
    //vuoto
}


CampoVettoriale::CampoVettoriale(const Posizione& posiz, double Fx, double Fy, double Fz) : 
Posizione(posiz), m_Fx(Fx), m_Fy(Fy), m_Fz(Fz) {
    //vuoto
}


CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz) : 
Posizione(x, y, z), m_Fx(Fx), m_Fy(Fy), m_Fz(Fz) {
    //vuoto
}



//operazioni

CampoVettoriale& CampoVettoriale::operator += (const CampoVettoriale & altro_campo) {
    x_cart += altro_campo.x_cart;
    y_cart += altro_campo.y_cart;
    z_cart += altro_campo.z_cart;

    m_Fx += altro_campo.m_Fx;
    m_Fy += altro_campo.m_Fy;
    m_Fz += altro_campo.m_Fz;

    return *this;

}


CampoVettoriale CampoVettoriale::operator+( const CampoVettoriale & altro_campo) const {
    CampoVettoriale risultato = *this;
    risultato += altro_campo;

    return risultato;
}



//metodi 

double CampoVettoriale::modulo() const {
    double modulo = sqrt (m_Fx*m_Fx + m_Fy*m_Fy + m_Fz*m_Fz);
    
    return modulo;
}






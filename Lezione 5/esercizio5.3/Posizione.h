#ifndef __Posizione_h__
#define __Posizione_h__

#include <iostream>

using namespace std;


class Posizione {
    public: 

        Posizione(); 
        Posizione(double x, double y, double z); 

        ~Posizione();

        //metodi per restituire coordinate cartesiane
        double getX() const;
        double getY() const; 
        double getZ() const;

        //metodi per restituire coordinate sferiche 
        double getR() const;
        double getTheta() const;
        double getPhi() const;

        //metodi per restituire coordinate cilindriche
        double getR_cilindrico() const;
        double getTheta_cilindrico() const;

        //metodo per calcolare la distanza da un altro punto 
        double distanza(const Posizione&) const;


    protected: 

    double x_cart, y_cart, z_cart;


};


#endif
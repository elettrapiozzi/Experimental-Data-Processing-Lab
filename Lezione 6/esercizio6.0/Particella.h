#ifndef __Particella_h__
#define __Particella_h__

#include <iostream>

using namespace std;


class Particella {
    protected:

        double m;
        double q;

    public: 

        Particella(); 
        Particella(double massa, double carica);
         
        ~Particella();

        //metodi

        double getMassa() const;
        double getCarica() const;
        void Print() const;


};


#endif
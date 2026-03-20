#ifndef __Elettrone_h__
#define __Elettrone_h__

#include <iostream>
#include "Particella.h"

using namespace std;


class Elettrone : public Particella {

    public: 

        Elettrone();
        ~Elettrone();
        
        //metodi
        void Print() const;

};


#endif
#ifndef __FunzioneBase_h__
#define __FunzioneBase_h__

#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


class FunzioneBase {

    public:

    virtual double eval(double x) const=0;
    virtual ~FunzioneBase();

};




#endif
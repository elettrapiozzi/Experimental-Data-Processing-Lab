#ifndef __TanFunction_h__
#define __TanFunction_h__

#include <cmath>
#include "FunzioneBase.h"

class TanFunction : public FunzioneBase {
public:

    virtual double Eval(double x) const override {
        return sin(x) - x * cos(x);
        
    }
};

#endif

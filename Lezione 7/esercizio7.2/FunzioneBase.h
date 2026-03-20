#ifndef __FunzioneBase_h__
#define __FunzioneBase_h__

#include <cmath>

using namespace std;

class FunzioneBase {

    public:
    
      virtual double Eval(double x) const =0;
      virtual ~FunzioneBase() {;};
    
};

class sign {

    public:

    double Eval(double x) const { 
      
      if(x<0) 
        return -1;
      else
        return 1;

    }
};


class xsinx : public FunzioneBase {
    
  public:

  double Eval(double x) const {

      return x*sin(x);
  
    }
};

#endif

    
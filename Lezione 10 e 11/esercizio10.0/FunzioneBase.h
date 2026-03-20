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


class Gaussiana: public FunzioneBase {

  public:

  Gaussiana(double sigma, double mu) {
    m_mu = mu;
    m_sigma = sigma;
  }
  ~Gaussiana() {}

  double Eval (double x) const override {
    return (1/(sqrt(2*M_PI)*m_sigma))*pow(M_E,(-pow((x-m_mu),2)/(2*pow(m_sigma,2))));
  }

  private:
    double m_mu;
    double m_sigma;
};

#endif

    
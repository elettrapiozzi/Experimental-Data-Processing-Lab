#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__

#include "VectorOperations.h" 
#include <cmath>

using namespace std;

// ===========================================================================
// classe astratta, restituisce la derivata valutata nel punto x
// ===========================================================================

class FunzioneVettorialeBase {

    public:
        virtual vector<double> Eval(double t, const vector<double> & x) const = 0;
};

//=============================================================================
// caso fisico concreto, oscillatore armonico
//=============================================================================

class OscillatoreArmonico : public FunzioneVettorialeBase {
    public:
        OscillatoreArmonico(double omega0) {  m_omega0 = omega0;  } ;

        virtual vector<double> Eval(double t, const vector<double> & x) const override {
            vector <double> v {x[1], - pow(m_omega0, 2)*x[0]};

            return v;
        };

    private:
        double m_omega0;  
};

//============================================================================
// oscillatore armonico smorzato
//============================================================================

class OscillatoreSmorzatoForzato : public FunzioneVettorialeBase {
  public:

    OscillatoreSmorzatoForzato(double omega0, double alpha, double omega_forzante) {
      m_omega0 = omega0;
      m_alpha = alpha;
      m_omega_f = omega_forzante;

    }

    vector<double> Eval(double t, const vector<double> &x) const override {
        double pos = x[0];
        double vel = x[1];

        double accel = -pow(m_omega0, 2)*x[0]-m_alpha*x[1]+sin(m_omega_f*t);
        return vector<double> {vel, accel};
    }

private:
    double m_omega0;
    double m_alpha;
    double m_omega_f;

};


// ===========================================================================
// classe astratta per un integratore di equazioni differenziali
// ===========================================================================

class EquazioneDifferenzialeBase {

public:
  virtual vector<double> Passo(double t, const vector<double>& x, double h, 
  const FunzioneVettorialeBase &f) const =0;
};

//============================================================================
// integratore concreto, metodo di Eulero
//============================================================================

class Eulero : public EquazioneDifferenzialeBase {

 public:

  virtual vector <double> Passo(double t, const vector<double> & x, double h, 
  const FunzioneVettorialeBase &f) const override {

    return x+f.Eval(t,x)*h;

  };

};

// ===========================================================================
// integratore completo, metodo di Runge Kutta 
// ===========================================================================

class RungeKutta : public EquazioneDifferenzialeBase {

  public:
 
   virtual vector<double> Passo(double t, const vector<double> & x, double h, 
   const FunzioneVettorialeBase &f) const override {
 
    vector <double> k1 = f.Eval(t,x);
    vector <double> k2 = f.Eval(t + h/2.0, x + k1*(h/2.0));
    vector <double> k3 = f.Eval(t + h/2.0, x + k2*(h/2.0));
    vector <double> k4 = f.Eval(t + h, x + k3*h);
    
     return x+(k1+2.0*k2+2.0*k3+k4)*(h/6.0);
 
   };
 
 };

 //===========================================================================
 // codice fisico completo: pendolo
 //===========================================================================

 class Pendolo : public FunzioneVettorialeBase {

  public:
      Pendolo(double lunghezza) {m_lunghezza = lunghezza;} ;
  
      virtual vector<double> Eval(double t, const vector<double>& x) const override {
          // θ' = x[1], θ'' = - (g/l) * sin(θ)
          return { x[1], - (g / m_lunghezza) * sin(x[0]) };
      }
  
  private:
      double m_lunghezza;
      const double g = 9.806;  

  };
  




#endif


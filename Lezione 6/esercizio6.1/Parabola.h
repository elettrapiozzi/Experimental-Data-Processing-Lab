#ifndef __Parabola_h__
#define __Parabola_h__

#include "FunzioneBase.h"

class Parabola : public FunzioneBase {

    public:
    
      Parabola()  {
         m_a = 0.0; 
         m_b = 0.0; 
         m_c = 1.0; 
        }  

      Parabola(double a, double b, double c)  { 
        m_a = a;
        m_b = b; 
        m_c = c; 
      }

      ~Parabola() {;} ;

      virtual double Eval(double x) const override {
        return m_a*x*x + m_b*x + m_c;
      }
      
      void SetA(double a) { 
        m_a = a; 
      }

      double GetA() const {
        return m_a;
      } 

      void SetB(double b) { 
        m_b = b; 
      }

      double GetB() const {
        return m_b;
      }

      void SetC(double c) { 
        m_c = c; 
      }

      double GetC() const {
        return m_c;
      } 
    
      double GetVertice() const { 
        return -m_b / (2*m_a) ;} ;
    
    private:
    
      double m_a;
      double m_b;
      double m_c;
    
    };
    
    #endif
    
#ifndef __Trapezi_h__
#define __Trapezi_h__

#include "Integral.h"
#include "FunzioneBase.h"

class Trapezi : public Integral {

    public:
   
     Trapezi (double a, double b) : Integral (a, b){;};

     double Integra(unsigned int nstep, FunzioneBase& fz) override {

        std::cerr << "Errore: Trapezi usa la precisione, non il numero di step!" << std::endl;
        exit(33);
    }
    
   
     double Integra(double prec, FunzioneBase& fz) override {
   
       double fa = fz.Eval(m_a);
       double fb = fz.Eval(m_b);
       m_nstep = 2;

       double fk = 0.5*fa + 0.5*fb;
   
           do {
               m_h = (m_b - m_a) / m_nstep;
   
               for(int k=1; k<m_nstep; k+=2) { 
                    fk += fz.Eval(m_a + k*m_h);  
               } 
   
               m_sum = m_integral;
   
               m_integral = m_sign*fk*m_h;
   
               m_nstep = m_nstep*2;
       
   
           } while(prec < (4.0/3.0)*fabs(m_integral - m_sum));
   
           return m_integral;
    
   
       };
   
   };


#endif
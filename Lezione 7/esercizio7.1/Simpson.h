#ifndef __Simpson_h__
#define __Simpson_h__

#include "Integral.h"
#include "FunzioneBase.h"

class Simpson : public Integral {

    public:
   
     Simpson (double a, double b) : Integral (a,b) {;};

     double Integra(double prec, FunzioneBase& fz) override {

      std::cerr << "Errore: Simpson usa gli nstep, non la precisione!" << std::endl;
      exit(33);
   }
   
     double Integra(unsigned int nstep, FunzioneBase& fz) override {

       m_nstep = nstep;
       m_h = (m_b - m_a)/m_nstep;
       m_sum = 0;
   
       if(m_nstep % 2 !=0)  {
          std::cout << "Inserire n pari" << std::endl;
           exit(-1);
       }

       for (int k=1; k < m_nstep; k++) {
   
       double xk = m_a + k*m_h;
   
       double fz_xk = fz.Eval(xk);
   
       if(k%2==0) {
            m_sum += 2*fz_xk;
            } else {
            m_sum += 4*fz_xk;
       }
   
    }
   
     m_integral = m_sign*((m_h/3)*(fz.Eval(m_a) + m_sum + fz.Eval(m_b)));
   
     return m_integral;
   
   
   
     }
   
   };



#endif
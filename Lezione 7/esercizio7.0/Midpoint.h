#ifndef __Midpoint_h__
#define __MIdpoint_h__

#include <iostream>
#include "FunzioneBase.h"
#include "Integral.h"

class Midpoint : public Integral {

    public:
        
        Midpoint(double a, double b) : Integral(a, b) {;} ;

        double Integra(double prec, FunzioneBase& fz) override {

            std::cerr << "Errore: Midpoint usa gli nstep, non la precisione!" << std::endl;
            exit(33);
         }

        double Integra(unsigned int nstep, FunzioneBase& fz) override {
            m_nstep = nstep;
            m_h = (m_b - m_a) / m_nstep;
            m_sum = 0.0;

            for (unsigned int i = 0; i < m_nstep; ++i) {
            double x_mid = m_a + (i + 0.5) * m_h;
            m_sum += fz.Eval(x_mid);
            }

        m_integral = m_sum * m_h * m_sign;

        
        return m_integral;

        }
};



#endif


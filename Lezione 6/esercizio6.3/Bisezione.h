#ifndef __Bisezione_h__
#define __Bisezione_h__

#include <iostream>
#include "FunzioneBase.h"
#include "Solutore.h"

using namespace std;

class Bisezione : public Solutore {

    public:
   
     Bisezione() : Solutore() {;};
     Bisezione(double a, double b, double prec) : Solutore(a, b, prec) {;};
     virtual ~Bisezione() {;};
   
     virtual double CercaZero(const FunzioneBase & fz, double a, double b, double prec = 0.001, unsigned int nmax = 100) override {
        
        sign segno;

        m_precisione = prec;
        m_nmax = nmax;
        m_niterazioni = 0;

        if (a<b) {
            m_a = a;
            m_b = b;
        } else {
            m_a = b;
            m_b = a;
        }

        double fa = fz.Eval(m_a);
        double fb = fz.Eval(m_b);

        double xmedio = 0.5 * (m_b+m_a);
        double f_xmedio = fz.Eval(xmedio); 

        while(abs(m_b - m_a) > m_precisione && m_niterazioni < nmax) {
            
            m_niterazioni++;

            if (segno.eval(fa)*segno.eval(f_xmedio) < 0) {
                return CercaZero (fz, a, xmedio); //possibile da CAMBIAREEE

            } else if (segno.eval(f_xmedio)*segno.eval(fb) < 0) {
                return CercaZero (fz, xmedio, b); //ANCHE QYAAA
            }
        }

     return xmedio;

     }                                              
     

};
   

#endif



#ifndef __Solutore_h__
#define __Solutore_h__
#include "FunzioneBase.h"



class Solutore {

    public:

        Solutore () {;} ;

        Solutore(double a, double b, double prec) {
            
            m_a = a;
            m_b = b;
            m_precisione = prec;

        }

        virtual ~Solutore() {;} ;

        virtual double CercaZero(const FunzioneBase & fz, double a, double b, double prec = 0.001, unsigned int nmax =100) = 0;
        
        
      void SetPrecisione(double epsilon) { 
        m_precisione = epsilon; //quella da terminale
      }

      double GetPrecisione() { 
        return m_precisione;
      }

      void SetNMaxiterations(unsigned int n) { 
        m_nmax = n ; 
      }

      unsigned int GetNMaxiterations () { 
        return m_nmax ; 
      } 


      unsigned int GetNiterations () { 
        return m_niterazioni ;
     } 

    protected:
    double m_a, m_b;              // estremi intervallo di ricerca
    double m_precisione;                // precisione richiesta
    unsigned int m_nmax;          // massimo numero di iterazioni permesse
    unsigned int m_niterazioni;   // numero di iterazioni effettuate
    
};


#endif

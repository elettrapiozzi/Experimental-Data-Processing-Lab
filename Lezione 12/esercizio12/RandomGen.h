#ifndef __RandomGen_h__
#define __RandomGen_h__
#include <cmath>

#include "FunzioneBase.h"


class RandomGen {

    public:

    // costruttori
    // mettiamo il solito costruttore di default e poi un costruttore che accetta un seed specifico
    RandomGen() {;};
    RandomGen(unsigned int n) {
        n = m_seed;
        m_a = 1664525;
        m_m = pow(2,31);
        m_c = 1013904223;
    };

    // metodi 

    void SetA(unsigned int a) { m_a=a; } 
    void SetC(unsigned int c) { m_c=c; }
    void SetM(unsigned int m) { m_m=m; } 

    // Rand(): Genera un numero casuale uniforme tra 0 (incluso) e 1 (escluso)
    // è il generatore di base. Tutti gli altri metodi useranno questo.
    
    double Rand() {
       
        m_seed = (m_a*m_seed + m_c) % m_m;        // formula del generatore congruenziale lineare 
        double m_norm = (double)m_seed/m_m;       // normalizzo il risultato per farlo stare nell'intervallo [0, 1)
        
        return m_norm;
    }


    // Unif(min, max): genera un numero casuale uniforme n tra 'min' e 'max': n = seed / m

    double Unif(double min, double max) {
        // genero un numero U tra 0 e 1 usando Rand()
        double U = Rand();

        //formula di trasformazione
        return min + (max - min) * U;
    }


    // Exp(lambda) è la distribuzione esponenziale con costante lambda

    double Exp(double lambda) {
        // genero un numero U tra 0 e 1 usando Rand()
        double U = Rand();

        //formula di trasformazione
        return - (1/lambda)*log(1-U);
    }

    //Gaus: distribuzione Gaussiana Box-Muller

    double Gaus(double mean, double sigma) {
        // genero due numeri casuali tra 0 e 1         
        double s = Rand();
        double t = Rand();

        // formula di trasformazione
        double x=sqrt(-2.*log(1.-s))*cos(2.*M_PI*t);
        return mean+x*sigma; 
    }

    // distribuzione Gaussiana Accept Reject

    double GausAR (double a, double b, double max, FunzioneBase & fz) {
        double x;
        double y;

        do {
            double s = Rand();
            double t = Rand();

            x = a + (b-a)*s;;
            y = max*t;

        } while (y > fz.eval(x));
            
        
        return x;

    }
    
    private: 

    unsigned int m_a;
    unsigned int m_m;   
    unsigned int m_c;
    unsigned int m_seed;
};



// calcolatore di integrali Monte Carlo 

class IntegralMC {
    
    public:

    // Costruttore: inizializza l'oggetto RandomGen interno (m_myrand) con il seed fornito
    IntegralMC(unsigned int seed) : m_myrand(seed) {;};
    ~IntegralMC() {;} ;

    // ---------------------------------------------
    // Metodo HIT OR MISS dove bisogna inserire

    // xmin, xmax : estremi intervallo di integrazione
    // fmax : valore massimo della funzione nell'intervallo tra xmin e xmax (è l'altezza del rettangolo di campionamento)
    // punti : numero totale di punti casuali da generare all'interno del rettangolo

    double Integralehom(double xmin, double xmax, double fmax, FunzioneBase &f, int punti) {

        // m_punti = punti; GEMINI NON LO USA

        double nhit = 0;   // conta i punti hit, che stanno sotto la curva

        // LA ELE METTE a E b FUORI

        // loop per generare 'punti' campioni
        for(int i=0; i<punti; i++) {

            double x = m_myrand.Unif(xmin,xmax);

            double y = m_myrand.Unif(0,fmax);

            // "se il punto è sotto la curva è un hit"
            if(y<f.eval(x)) {

            nhit ++;

            }
        }

        // return : calcolo dell'integrale. letteralmente area del rettangolo per proporzione di hit
        
        return (xmax-xmin)*fmax*(nhit/(double)punti);

    };

    ///-------------------------------------------------------------------------
    // Metodo della MEDIA 
    // dove bisogna inserire:
    // xmin, xmax : estremi intervallo di integrazione
    // f : funzione da integrare 
    // numero di punti da campionare per calcolare la media  

    double IntegraleMedia(double xmin, double xmax, FunzioneBase &f, int punti) {

        double sum = 0;   

        // loop per campionare punti della funzione

        for(int i = 0; i<punti; i++) {
            
            double x = m_myrand.Unif(xmin,xmax);

            sum += f.eval(x);  // somma di tutte le f(x_i)

        }

        // return calcolo dell'integrale: ampiezza intervallo * media valori funzione

        return (xmax-xmin)*(sum/(double)punti);
    };

    private:

    RandomGen m_myrand;
};


#endif
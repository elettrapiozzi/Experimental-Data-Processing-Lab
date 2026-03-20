#ifndef __Integrale_h__
#define __Integrale_h__

#include"FunzioneBase.h"
#include"RandomGen.h"

//#################
//# DECLARATION #
//#################

class Integrale{

    public:
    virtual ~Integrale();

    // rispettivamente gli elementi tra parentesi sono numero di punti (iterazioni) da usare
    // per il calcolo, estremi inferiore e superiore dell'intervallo di integrazione, funzione da
    // integrare, ymax specifico per hit or miss (in media lo mettiamo = 0)), segno dell'integrale

    virtual double Integra(int n, double a, double b,
     const FunzioneBase &, double ymax, int sgn)=0;   
    
    protected:
    double m_a, m_b, m_sum, m_integrale, m_h, m_prec, m_err;
    int m_nstep;
};


// Integrale per il metodo MEDIA 

class media: public Integrale, public RandomGen{
    public:

    media(unsigned int seed) : RandomGen(seed){;};
    ~media();

    double Integra(int n, double a, double b,
            const FunzioneBase &, double ymax, int sgn) override;
    
    int getnstep() const {return m_nstep;}
    double geterr() const {return m_err;}
};


// integrale metodo HIT OR MISS 

class hitmiss: public Integrale, public RandomGen{
    public:
    hitmiss(unsigned int seed) : RandomGen(seed){;};
    ~hitmiss();
    double Integra(int n, double a, double b,
        const FunzioneBase &, double ymax, int sgn) override;
    
    int getnstep() const {return m_nstep;}
    double geterr() const {return m_err;}
};


// Implementazione dei metodi dichiarati


Integrale::~Integrale(){
}
double media::Integra(int n, double a, double b, const FunzioneBase &f, double ymax, int sgn){
    
    double sum=0.;

    for(int i=0; i<n; i++){
        sum+=f.eval(Unif(a, b));
    }
    m_integrale=(b-a)*(sum/n)*sgn;
    return m_integrale;
}
media::~media(){
}
double hitmiss::Integra(int n, double a, double b, const FunzioneBase &f, double ymax, int sgn){
    
    double ntot=0.;
    double nhit=0.;

    for(int i=0; i<n; i++){
        double x=Unif(a, b);
        double y=Unif(0, ymax);
        ntot++;
        if(y<=f.eval(x)){
            nhit++;
        }
    }
    m_integrale=(b-a)*ymax*(nhit/ntot)*sgn;
    return m_integrale;
}
hitmiss::~hitmiss(){
}

#endif
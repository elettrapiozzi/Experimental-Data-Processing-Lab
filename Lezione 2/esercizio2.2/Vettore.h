#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>

using namespace std;

class Vettore {

    public: //accessibili dall'esterno
        
        // costruttori 
        Vettore();         //Costruttore di default, inizializza a zero
        Vettore(unsigned int N);    //Costruttore con dimensione N, crea array di N elementi
        Vettore(const Vettore& ); //Copy constructor
        Vettore& operator= (const Vettore&);

        // Distruttori
        ~Vettore();

        // Metodi di accesso
        unsigned int GetN() const  {return m_N;}        // Restituisce numero elementi del vettore
        void SetComponent(unsigned int, double);        // Imposta un valore in una certa posizione
        double GetComponent(unsigned int) const;        // Restituisce il valore di una certa posizione
        double& operator[](unsigned int i);               // Permette di accedere alle componenti di un vettore
        double& operator[](unsigned int i) const;               // Permette di accedere alle componenti di un vettore solo in lettura 
        
        // metodi interni

        void Scambia(unsigned int primo ,unsigned int secondo);


    private:  //dati interni nascosti

    int m_N;          // dimensione del vettore
    double* m_v;      // puntatore al vettore dinamico
};

#endif  // __Vettore_h__

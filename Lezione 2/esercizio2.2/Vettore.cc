#include "Vettore.h"
#include <iostream> 

using namespace std;

// costruttore di default, inizializzato
Vettore::Vettore() {

    m_N = 0;      // dimensione del vettore = 0 (vuoto)
    m_v = NULL;   // puntatore all'array non punta a nessuna memoria

}


Vettore::Vettore(unsigned int N) {  // crea un vettore di dim N
    m_N = N;
    m_v = new double[N];
    
    for (int k = 0; k < N ; k++) m_v[k] = 0;
}

Vettore::~Vettore() {
    delete[] m_v;  // libero la memoria
}


// SetComponent serve a modificare o impostare un valore del vettore in una certa posizione
void Vettore::SetComponent(unsigned int i, double val) {
   
    if (i < m_N) {
        m_v[i] = val;
    } else {
        cout << "Errore: indice " << i << " fuori dal range" << endl;
        exit(33);
    }

}


// GetComponent serve a leggere un valore del vettore, in una certa posizione
double Vettore::GetComponent(unsigned int i) const {
    
    if (i < m_N) {
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << " fuori dal range" << endl;
        exit (33); 
    }

}

void Vettore::Scambia(unsigned int primo, unsigned int secondo) {
      
    double temp = GetComponent(primo);
        SetComponent(primo, GetComponent(secondo));
        SetComponent(secondo,temp);

}


// copy constructor (overloading perché si chiama Vettore)

Vettore::Vettore(const Vettore& V) {

    m_N = V.GetN();
    m_v = new double [m_N];
    for (int i=0; i < m_N; i++) m_v[i] = V.GetComponent(i);

}


// operatore di assegnazione: usato per eguagliare un vettore ad un altro
Vettore& Vettore::operator= (const Vettore& V) {
    m_N = V.GetN();
    if ( m_v ) delete[] m_v;
    m_v = new double[m_N];
    for (int i=0; i<m_N; i++) m_v[i]=V.GetComponent(i);
    return *this;
}

// operatore di accesso: per semplificare la codifica di accesso alle componenti di un vettore
double& Vettore::operator[] (unsigned int i)  {
    if ( i<m_N ) {
      return m_v[i];
    } else {
      cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
      exit(33); 
    }
  }
  

  double& Vettore::operator[] (unsigned int i) const {
    if ( i<m_N ) {
      return m_v[i];
    } else {
      cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
      exit(33); 
    }
  }
  



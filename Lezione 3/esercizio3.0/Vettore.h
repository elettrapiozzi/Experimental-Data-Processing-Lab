#ifndef __Vettore_h__
#define __Vettore_h__ 

#include <iostream>
#include <fstream>

using namespace std;

template <typename T> class Vettore {
 public:

    // COSTRUTTORI 

	Vettore() {
        m_N = 0;
        m_v = nullptr;
    }

	Vettore(unsigned int N) {
        m_N = N;
        m_v = new T[N];
        for (int j = 0; j < N; j++) m_v[j] = T(); //Per l'inizializzazione a zero
    }


    // DISTRUTTORI

	~Vettore() {
        delete[] m_v;
    }

    
    unsigned int GetN() const { return m_N; }  


    void SetComponent(unsigned int i, T a) {
        if (i < m_N) {
            m_v[i] = a;
        } else { 
            cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
            exit (33);
        }
    }


    T GetComponent(unsigned int i) const {
        if (i < m_N) {
            return m_v[i];
        } else {
            cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
            exit (33);
        }
    }


    T& operator[] (unsigned int i) const {
        if (i < m_N) {
            return m_v[i];
        } else {
            cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
            exit(33);
        }
    }


    void scambia(unsigned int primo, unsigned int secondo) {
        T tmp = GetComponent(primo);
        SetComponent(primo, GetComponent(secondo));
        SetComponent(secondo, tmp);
    }

    // COPY CONSTRUCTOR

    Vettore(const Vettore& V) {
        m_N = V.GetN();
        m_v = new T[m_N];
        for (int j = 0; j < m_N; j++) m_v[j]=V.GetComponent(j);
    }
    Vettore& operator=(const Vettore& V) {
        m_N = V.GetN();
        if (m_v) delete [] m_v;
        m_v = new T[m_N];
        for (int j = 0; j < m_N; j++) m_v[j]=V.GetComponent(j);
        return *this;
    }

 private:

	unsigned int m_N;
	T* m_v;

};

#endif 
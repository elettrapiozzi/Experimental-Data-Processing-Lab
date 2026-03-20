
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template <typename T> Vettore <T> read(unsigned int N, const char* filename) {
    Vettore <T> v(N);

    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file " << filename << endl;
        exit(33);
    } else {
        for (unsigned int i=0; i<N; i++) {
            T val;
            in >> val;       
            
            if (in.eof()) {
                cout << "End of file reached existing" << endl;
                exit(33);
                }
            
            v.SetComponent(i, val); 
        }
    }
    
    return v;

}

template <typename T> T media(const Vettore <T> &v) {
    T sum = 0;
    for (int i = 0; i < v.GetN(); i++){
        sum += v.GetComponent(i);
    }
    return sum/(v.GetN());
}
    

template <typename T> T varianza(const Vettore <T> &v){
    T mean = media(v);
    T scarti = 0;
    for(int i = 0; i < v.GetN(); i++){
        scarti += pow((v[i] - mean),2);
    }
    return (scarti/(v.GetN()-1));

}


template <typename T> T dev_std(Vettore<T> v) {
    return sqrt(varianza(v));

} 


template <typename T> void sort_by (Vettore <T> &v) {
    for(int i = 0; i<v.GetN() -1; i++) {
        for (int j=i+1; j<v.GetN(); j++) {
            if (v.GetComponent(i) > v.GetComponent(j)) {
                v.scambia(i,j);
            }
        }
    }
}


template <typename T> T mediana (Vettore<T> v) {
    sort_by(v);
    T mediana;

    if(v.GetN()%2==0) {
        mediana = (v[(v.GetN()-1)/2] + v[v.GetN()/2])/2;
    } else {
        mediana = v[v.GetN()/2];
    }

        return mediana;
}

template <typename T> void print(const char* filename,  Vettore<T> &v) {
    sort_by(v);
    fstream outfile(filename, ios::out);
    outfile << "Array riordinato: " << endl;
    for(int i=0; i<v.GetN(); i++){
        outfile << "Elemento " << i+1 << ": " << v.GetComponent(i) << endl;
    }
    outfile.close();
}


template <typename T> void print(Vettore<T> &v) {
    for(int i=0; i<v.GetN(); i++) {
        cout << "Elemento " << i+1 << ": " << v.GetComponent(i) << endl;
    }
}
#include <iostream>
#include <fstream>
#include <cmath> 

#include <vector>           //contenitore
#include <algorithm>        //funzioni


using namespace std;

template <typename T> vector<T> read(unsigned int N, const char* filename) {
    vector<T> v;

    ifstream in(filename);   // legge il file che si chiama "filename"

    if (!in) {
        cout << "Cannot open file " << filename << endl;
        exit(33);
    } else {
        for (unsigned int i=0; i<N; i++) {
            T val;
            in >> val;   // scrivi il primo valore del file dentro a val
            v.push_back(val);  //il vector diventa v = {val} e così via durante il ciclo for 
            
            if (in.eof()) { 
                cout << "End of file reached existing" << endl;
                exit(33);
            }
        }
    }
    
    return v;  // restituisco v riempito

}

template <typename T> T media(const vector <T> &v) {
    T sum = 0;
    for (int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum/(v.size());
}
    

template <typename T> T varianza(const vector <T> &v){
    T mean = media(v);
    T scarti = 0;
    for(int i = 0; i < v.size(); i++){
        scarti += pow((v[i] - mean),2);
    }
    return (scarti/(v.size()-1));

}


template <typename T> T dev_std(const vector <T> v) {
    return sqrt(varianza(v));

} 


template <typename T> T mediana (vector<T> v) {
    sort(v.begin(), v.end());
    T mediana;

    if(v.size()%2==0) {
        mediana = (v[(v.size()-1)/2] + v[v.size()/2])/2;
    } else {
        mediana = v[v.size()/2];
    }

        return mediana;
}


template <typename T> void print(const char* filename, const vector <T> &v) {
    fstream outfile(filename, ios::out);   // crea un file dove copiare i dati che trovo dal codice 

    outfile << "Array riordinato: " << endl;
    for(int i=0; i<v.size(); i++){
        outfile << "Elemento " << i+1 << ": " << v[i] << endl;
    } 
    outfile.close();
}


template <typename T> void print(const vector <T> &v) {
    for(int i=0; i<v.size(); i++) {
        cout << "Elemento " << i+1 << ": " << v[i] << endl;
    }
}
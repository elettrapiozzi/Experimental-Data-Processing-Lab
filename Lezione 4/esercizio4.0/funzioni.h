#include <iostream>
#include <fstream>
#include <cmath> 

#include <vector>           //contenitore
#include <algorithm>        //funzioni


using namespace std;

template <typename T> vector<T> read(const char* filename) {
    vector<T> v;

    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file " << filename << endl;
        exit(33);
    } else {
        T val;
        while (in >> val) {
            v.push_back(val);
        }
    }
    
    return v;

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
    return (scarti/(v.size()));

}


template <typename T> T dev_std(const vector <T> v) {
    return sqrt(varianza(v));

} 


template <typename T> T errore(const vector<T> &v) {
   
    vector<T> campioni_settimanali;

    for (int i = 0; i < v.size(); i++) {   // avevo messo i+= 7 ma l'errore è troppo grande
        campioni_settimanali.push_back(v[i]);
    }
    
    T dev_standard = dev_std(campioni_settimanali);
    return dev_standard / sqrt(campioni_settimanali.size());
}

#include <iostream>
#include <fstream>
#include <cmath> 

#include <vector>           //contenitore
#include <algorithm>        //funzioni


using namespace std;

template <typename T> vector<T> read(unsigned int N, const char* filename) {
    vector<T> v;

    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file " << filename << endl;
        exit(33);
    } else {
        for (unsigned int i=0; i<N; i++) {
            T val;
            in >> val;   
            v.push_back(val);    
            
            if (in.eof()) {
                cout << "End of file reached existing" << endl;
                exit(33);
            }
        }
    }
    
    return v;

}


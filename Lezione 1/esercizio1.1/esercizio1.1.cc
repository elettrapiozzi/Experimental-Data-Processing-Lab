#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;
// --- dichiarazione delle funzioni ---
// in ordine dice che tipo di valore restituiscono, come si chiamano, che tipo di valore accettano
double CalcolaMedia( double * , int ) ;
double CalcolaVarianza( double * , int );
double CalcolaMediana ( double [] , int ) ;
double * ReadDataFromFile ( const char*  , int ) ;
void Print ( const char* , double * , int ) ;
void scambiaByValue(double , double ) ;
void scambiaByRef(double &, double &) ;
void scambiaByPointer(double *, double *) ;
void selection_sort( double * , int );

int main ( int argc , char** argv) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }

  int ndata = atoi(argv[1]);
  char * filename = argv[2];

  // uso una funzione per leggere gli elementi da un file

  double * data = ReadDataFromFile ( filename, ndata ) ;

  for (int k = 0; k < ndata; k++) cout << data[k] << endl; 

  // uso una funzione per calcolare la media e la varianza

  cout << "Media = " << CalcolaMedia( data , ndata ) << endl;

  cout << "Varianza = " << CalcolaVarianza( data , ndata ) << endl;

  // uso una funzione per calcolare la mediana

  cout << "Mediana = " << CalcolaMediana(data, ndata) << endl;

  // Scrivo i dati riordinati su file
  selection_sort(data, ndata); 
  Print( "fileout.txt", data, ndata ) ;

  return 0;

}

// legge <size> elementi da <Filename> e restituisce un array

double * ReadDataFromFile ( const char* Filename , int size  ) {

    double * data = new double[size];
    ifstream fin(Filename); 

    if (!fin) { //controlla se il file non si è aperto
        cout << "Errore apertura del file " << Filename << endl;
        exit(33);
    } else {

        for (int i = 0; i < size; i++) {
            fin >> data[i]; //prendo dal file e inserisco nell'i-esima casella dell'array
            if (fin.eof()) {
                cout << "Fine del file" << endl;
                exit(33); //ovvero se sono alla fine del file stampa che ho finito
            }
        }
    }

    return data;
}

//ATTENZIONE! Print non stampa i dati in ordine, c'è prima selection_sort nel main
void Print ( const char* Filename, double * data, int size ) {

    ofstream fout(Filename);

    if (!fout) {
        cout << "Errore: impossibile aprire il file " << Filename << " per scrivere" << endl;
        exit(33);
    }
    
    for (int i = 0; i < size; i++) {
        fout << data[i]<< endl;
    }

    fout.close();

}

// calcola la media di <size> elementi dell'array <data>

double CalcolaMedia( double * data , int size ) {

    double somma = 0.0; 

    for (int i = 0; i < size; i++) {
        somma += data[i];
    }
    double media = somma / size;

  return media ;

}

// calcola la varianza di <size> elementi dell'array <data>

double CalcolaVarianza( double * data , int size ) {

    double sommaquad = 0.0;
    double media = CalcolaMedia(data, size);

    for (int i = 0; i < size; i++) {
        sommaquad += pow(data[i] - media,2);
    }

    double varianza = sommaquad / size;

  return varianza;

}

// funzioni per scambiare di posto due elementi, utile per il riordinamento

void scambiaByValue(double a, double b) {
  double c=a;
  a=b;
  b=c;
}

void scambiaByRef(double &a, double &b) {
  double c=a;
  a=b;
  b=c;
}

void scambiaByPointer(double *a, double *b) {
  double c=*a;
  *a=*b;
  *b=c;
}

// algoritmo di riordinamento di un array ( selection_sort ) 

void selection_sort( double * vec, int size) {

  for (int j=0; j<size-1; j++) {     
    int imin = j;
    double min=vec[imin];

    for (int i=j+1; i<size; i++) { 
      if ( vec[i]<min ) {                 
        min  = vec[i];
        imin = i;
      }
    }                                       
    scambiaByRef(vec[j],vec[imin]);     
  }                                          
}

// Calcolo della mediana di un array <vec> di dimensione <size>. Prima si crea
// una copia dell'array, lo riordina e calcola la mediana

double CalcolaMediana ( double vec[] , int size ) {

  double * vcopy = new double [size];
  for ( int i = 0 ; i < size ; i++ ) vcopy[i] = vec[i]; 

  selection_sort( vcopy , size );

  double mediana = 0;

  if ( size %2 == 0 ) {    
    mediana = ( vcopy[ size /2 -1 ] + vcopy[ size/2 ]  ) /2.;    
  } else {
    mediana = vcopy[size /2];    
  }

  delete [] vcopy;

  return mediana;
} 


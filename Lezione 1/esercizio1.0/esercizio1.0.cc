#include <iostream> //per usare cout e cin
#include <fstream> //per leggere e scrivere file
#include <cstdlib> //per usare la funzione atoi, che converte da stringa a intero
#include <cmath>
#include <algorithm> //per usare sort

using namespace std;

// Nel main:
// argc è il numero di argomenti passati da tastiera (compreso il nome del programma)
// argv è un array di stringhe (contiene i valori degli argomenti)

int main ( int argc, char** argv) {

    //il ciclo if controlla se ho inserito almeno tre argomenti (programma, numero di dati, nome file dati)
    if (argc < 3) {
        cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
        return -1;
    }


    //dichiarazione variabili 
    int ndata = atoi(argv[1]); //ndata: numero di dati da leggere. atoi converte stringa in intero
    double* data = new double[ndata]; // data: array dinamico dove metto i dati che leggo
    char* filename = argv[2]; //salvo il nome del file dei dati in una variabile 


    // ---- Aprire file di testo, leggere i primi ndata numeri e salvarli dentro l'array data ----
    ifstream fin(filename);   //apre il file
    
    if (!fin) { //controlla se il file non si è aperto
        cout << "Errore apertura del file " << filename << endl;
        exit(33);
    } else {

        for (int i = 0; i < ndata; i++) {
            fin >> data[i]; //prendo dal file e inserisco nell'i-esima casella dell'array
            if (fin.eof()) {
                cout << "Fine del file" << endl;
                exit(33); //ovvero se sono alla fine del file stampa che ho finito
            }
        }
    }

    for (int k = 0; k < ndata; k++) cout << data[k] << endl; //dopo averli caricati visualizzo

    // ---- calcolo la media e la varianza degli elementi caricati ----
    double media;
    double somma;
    double varianza;
    double sommaquad;
    double mediana;

    for (int i = 0; i < ndata; i++) {
        somma += data[i];
    }

    media = somma / ndata;

    for (int i = 0; i < ndata; i++) {
        sommaquad += pow(data[i] - media,2);
    }

    varianza = sommaquad / ndata;
    cout << "Media = " << media << endl << "Varianza = " << varianza << endl;

    //calcola la mediana: prima creo una copia del vettore di partenza, serve per riordinare i dati senza modificare l'originale
    double* vcopy = new double[ndata];   //crea una copia dell'array
    for (int k = 0; k < ndata; k++) vcopy[k] = data[k];  //copia tutti i dati 

    // ---- riordino gli elementi del vettore copia dal minore al maggiore ----
    sort(vcopy, vcopy + ndata);

    for (int k = 0; k < ndata; k++) cout << vcopy[k] << endl; //dopo averli ordinati visualizzo

    // ---- calcolo la mediana ----
    if (ndata%2 == 0)  {
        mediana = (vcopy[ndata/2 - 1] + vcopy[ndata/2]) /2; 
    } else {
        mediana = vcopy[ndata/2];
    }

    cout << "Mediana = " << mediana << endl;

    //Visualizzo l'array originale 

    for (int k =0; k < ndata; k++) cout << data[k] <<endl;

    // ---- scrivo i dati riordinati su un file ----
    ofstream fout("output_file.txt");
    
    for (int i = 0; i < ndata; i++) {
        fout << vcopy[i] << endl;
    }

    fout.close();

    delete [] vcopy;
    delete [] data;

    return 0;

}

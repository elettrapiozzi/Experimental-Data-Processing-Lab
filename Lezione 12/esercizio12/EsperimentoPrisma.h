#ifndef _EsperimentoPrisma_h_
#define _EsperimentoPrisma_h_

#include "RandomGen.h"

class EsperimentoPrisma {

 public :
    
   // costruttore e distruttore 

   EsperimentoPrisma() ;
  ~EsperimentoPrisma() {;} ;

  // METODI

  // Esegui simula l'esecuzione di una singola misura dell'esperimento
  // "Misure del goniometro"

  void Esegui() {

    // sto dicendo che l'angolo misurato è dato dal valore vero dell'angolo (input)
    // con un po' di rumore che segue una distrubzione gaussiana, dove la media è th_imput
    // e la sigma = 0.3 (m_sigmat)

    m_th0_misurato = randomgen.Gaus(m_th0_input, m_sigmat);
    m_th1_misurato = randomgen.Gaus(m_th1_input, m_sigmat);
    m_th2_misurato = randomgen.Gaus(m_th2_input, m_sigmat);

  } ;


  // analisi dei dati appena simulati 

  void Analizza() {

    // calcolo angoli di deviazione 

    m_dm1_misurato = m_th1_misurato - m_th0_misurato;
    m_dm2_misurato = m_th2_misurato - m_th0_misurato;

    // calcolo degli indici di rifrazione

    m_n1_misurato = (sin((m_dm1_misurato+m_alpha)/2))/(sin(m_alpha/2));
    m_n2_misurato = (sin((m_dm2_misurato+m_alpha)/2))/(sin(m_alpha/2));
    
    // calcolo dei parametri di Cauchy 

    m_A_misurato = ((m_lambda2*m_lambda2*m_n2_misurato*m_n2_misurato)-(m_lambda1*m_lambda1*m_n1_misurato*m_n1_misurato))/((m_lambda2*m_lambda2)-(m_lambda1*m_lambda1));
    m_B_misurato = ((m_n2_misurato*m_n2_misurato)-(m_n1_misurato*m_n1_misurato))/((1/(m_lambda2*m_lambda2))-(1/(m_lambda1*m_lambda1)));

  } ;


  // funzioni getter di tutte le variabili 

  double getAmis() { return m_A_misurato ; } ;
  double getBmis() { return m_B_misurato ; } ;
  double getn1mis() { return m_n1_misurato ; } ;
  double getn2mis() { return m_n2_misurato ; } ;
  double getdm1mis() { return m_dm1_misurato ; } ;
  double getdm2mis() { return m_dm2_misurato ; } ;
  double getth0mis() { return m_th0_misurato ; } ;
  double getth1mis() { return m_th1_misurato ; } ;
  double getth2mis() { return m_th2_misurato ; } ;

  double getAinput() { return m_A_input ; } ;
  double getBinput() { return m_B_input ; } ;
  double getn1input() { return m_n1_input ; } ;
  double getn2input() { return m_n2_input ; } ;
  double getdm1input() { return m_dm1_input ; } ;
  double getdm2input() { return m_dm2_input ; } ;
  double getth0input() { return m_th0_input ; } ;
  double getth1input() { return m_th1_input ; } ;
  double getth2input() { return m_th2_input ; } ;
                                                           
 private:

  // generatore di numeri casuali                                           

  RandomGen randomgen;

  // parametri dell'apparato sperimentale  

  double m_lambda1;    //lambda = 579.1 nm giallo
  double m_lambda2;    //lambda = 404.7 nm viola
  double m_alpha;      //angolo di apertura del prisma = Pigreco/3
  double m_sigmat;      //incertezza std = 0.3

  // valori delle quantita' misurabili :                                     
	// input    : valori assunti come ipotesi nella simulazione               
	// misurato : valore dopo la simulazione di misura  

  double m_A_input;    // parametro A vero di Cauchy (dalla formula di Cauchy)
  double m_A_misurato;     // parametro calcolato coi valori della sim
  double m_B_input;
  double m_B_misurato;
  double m_n1_input;     // indice di rifrazione vero giallo
  double m_n1_misurato;   // indice di rifrazione giallo calcolato dalla sim
  double m_n2_input;     // indice viola
  double m_n2_misurato;
  double m_dm1_input;    // angolo di deviazione minima per giallo
  double m_dm1_misurato;
  double m_dm2_input;    // angolo dev minimo per viola
  double m_dm2_misurato;
  double m_th0_input;    // angolo di riferimento 
  double m_th0_misurato;
  double m_th1_input;    // angolo posizione del raggio deviato giallo
  double m_th1_misurato;
  double m_th2_input;    // angolo posizione del raggio deviato viola
  double m_th2_misurato;

};

#endif
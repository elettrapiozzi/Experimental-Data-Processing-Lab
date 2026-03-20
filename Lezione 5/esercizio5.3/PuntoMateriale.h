#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"

class PuntoMateriale : public Particella, public Posizione {

public:

  // costruttori
    PuntoMateriale();
    PuntoMateriale(double massa, double carica, const Posizione&);
    PuntoMateriale(double massa, double carica, double x, double y, double z);

    // distruttore

    ~PuntoMateriale();

    // calcolo e restituisco il campo in una posizione
    CampoVettoriale campoelettrico(const Posizione&) const ;
    CampoVettoriale campogravitazionale(const Posizione&) const;

};

#endif 

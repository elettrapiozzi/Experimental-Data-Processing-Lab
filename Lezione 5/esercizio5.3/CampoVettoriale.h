#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__

#include "Posizione.h"

class CampoVettoriale : public Posizione {

public:
  CampoVettoriale ();
  CampoVettoriale(const Posizione&);
  CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
  CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);

  // il distruttore non c'e', uso quello di posizione

  // operazioni
  /*questa parte si fa perché così gli oggetti matematici + e += 
  funzionano normalmente anche coi miei oggetti campovettoriale. Di solito questi 
  simboli si usano per int, double, ecc. Quello che stiamo facendo si chiama overloading 
  di operatori e permette di dire al compilatore cosa vuol dire sommare
  2 oggetti campovettoriale*/

  CampoVettoriale & operator+=( const CampoVettoriale & ) ;
  CampoVettoriale operator+( const CampoVettoriale & ) const;

  // interfacce
  double getFx() const {return m_Fx;}
  double getFy() const {return m_Fy;}
  double getFz() const {return m_Fz;}

  void setFx(double Fx) { m_Fx=Fx;}
  void setFy(double Fy) { m_Fy=Fy;}
  void setFz(double Fz) { m_Fz=Fz;}

  double modulo() const ;

private:

  double m_Fx, m_Fy, m_Fz;

};

#endif 

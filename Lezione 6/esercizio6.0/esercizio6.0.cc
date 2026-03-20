#include "particella.h"
#include "elettrone.h"

int main() {

  particella *p = new particella(1.,2.);
  elettrone  *e = new elettrone();
  particella *b = new elettrone(); 

  p->Print(); // Metodo Print di Particella 
  e->Print(); // Metodo Print di Elettrone
  b->Print(); // Quale Print ???

  delete p;
  delete e;
  delete b;

  return 0;

}

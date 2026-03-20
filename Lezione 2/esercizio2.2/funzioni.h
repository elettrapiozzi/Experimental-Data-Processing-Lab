#include <iostream>
#include <fstream> 

#include "Vettore.h"

double CalcolaMedia( const Vettore& v) ;
double CalcolaVarianza( const Vettore& v);
double CalcolaDevStd (Vettore v);
double CalcolaMediana ( Vettore& v) ;

Vettore ReadDataFromFile (int ntot, const char* filename) ;

void Print ( const char* filneame, Vettore& v) ;
void Print (const Vettore& v);
void selection_sort( Vettore& v );

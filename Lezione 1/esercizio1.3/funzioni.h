#include <iostream>

using namespace std;


double CalcolaMedia( double * , int ) ;
double CalcolaVarianza( double * , int );
double CalcolaMediana ( double [] , int ) ;
double * ReadDataFromFile ( const char*  , int ) ;
void Print ( const char* , double * , int ) ;
void Print (double* , int );
void scambiaByValue(double , double ) ;
void scambiaByRef(double &, double &) ;
void scambiaByPointer(double *, double *) ;
void selection_sort( double * , int );
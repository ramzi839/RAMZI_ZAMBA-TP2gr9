#include "Gauge.h"

#ifndef VOL_MAX 
#define VOL_MAX 10

using namespace state ;

bool Gauge::isEmpty (){ if (this->volume == 0) return true; 
                        else return false;  }
bool Gauge::isFull (){if (this->volume == VOL_MAX) return true; 
                        else return false;  }
void Gauge::increase (int v){this->volume += v;}
void Gauge::decrease (int v){this->volume -= v;}

#endif
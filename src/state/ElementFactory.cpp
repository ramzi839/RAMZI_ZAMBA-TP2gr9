#include "ElementFactory.h"
#include "Player.h"
#include "Time.h"

using namespace state;


ElementFactory::ElementFactory (){}
ElementFactory::~ElementFactory (){}
Element* ElementFactory::newInstance (char* id){
    if(*id == 'P') return new Player("ken");
    else if (*id == 'T') return new Time();
    else throw "Invalid identifier";
}
void ElementFactory::registerType (char id){}
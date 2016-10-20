#include "ElementList.h"

using namespace state;

ElementList::ElementList (State& s) : state(s) {}
ElementList::~ElementList (){}
State&  ElementList::getState (){return this->state;}
int  ElementList::getSize (){return this->elements.size();}
Element*  ElementList::getElement (Element * e){
   /* for(std::vector<Element*>::iterator it=this->elements.begin(); it != this->elements.end(); ++it) {
        if(*it==*e) return it;
    }*/
                                                }

void ElementList::setElementFactory (ElementFactory* f){ this->factory =f; }
void ElementList::setElement (int i, Element* e){ this->elements.insert(this->elements.begin()+i,e);}
void ElementList::notifyObserver (int i ){}
#include "Observable.h"

using namespace state;

Observable::Observable (){}
Observable::~Observable (){}
void Observable::registerObserver (StateObserver* o){ this->observers.push_back(o);}
bool Observable::unregisteredObserver (StateObserver* o){}
bool Observable::notifyObservers (StateEventId EventId){
    for(std::vector<StateObserver*>::iterator it=observers.begin(); it!=observers.end();++it) {
//        it->stateChanged(EventId);
    
    }
}


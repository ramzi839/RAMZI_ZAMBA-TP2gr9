#include <iostream>
#include "Observable.h"
#include "PlayerStatus.h"

using namespace std;

namespace state {

    void Observable::addObserver(PlayerObserver* newObserver) {
        this->observers.push_back(newObserver);
    }
    void Observable::removeObserver(PlayerObserver* newObserver)  {
       
    }
   
    void Observable::notifyObservers (state::PlayerEvent) {
    }
}
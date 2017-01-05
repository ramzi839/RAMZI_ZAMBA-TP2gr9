#include <iostream>
#include "Hurt.h"
#include "state/State.h"

using namespace std;

namespace engine {

    Hurt::Hurt(int id): id(id) {}
    void    Hurt::apply(state::State* s) {
      
            s->players[id]->notifyObservers(state::HURTED);
       
    
    }

};
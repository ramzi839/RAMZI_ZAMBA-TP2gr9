#include <iostream>
#include "Punch.h"
#include "state/State.h"

using namespace std;

namespace engine {

    Punch::Punch(int id) : id(id){}
    void Punch::apply(state::State* s) {
         if ( id ==1) {
            s->players[1]->notifyObservers(state::ATTACK_PUNCH);
            
        }
        else  s->players[0]->notifyObservers(state::ATTACK_PUNCH);
    }
    
 }



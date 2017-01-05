#include <iostream>
#include "Kick.h"
#include "state/State.h"

using namespace std;

namespace engine {

    Kick::Kick(int id) : id(id){}
    void Kick::apply(state::State* s) {
        
            s->players[id]->notifyObservers(state::ATTACK_KICK);
        
    }


}
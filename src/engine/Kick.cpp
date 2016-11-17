#include <iostream>
#include "Kick.h"
#include "state/State.h"

using namespace std;

namespace engine {

    Kick::Kick(int id) : id(id){}
    void Kick::apply(state::State* s) {
        if ( id ==1) {
            s->players[1]->notifyObservers(state::ATTACK_KICK);
        }
        else  s->players[0]->notifyObservers(state::ATTACK_KICK);
    }


}
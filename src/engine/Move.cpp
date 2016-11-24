#include <iostream>
#include "Move.h"
#include "state/State.h"

using namespace std;

namespace engine {

    Move::Move(int id,state::Direction d) : id(id) , direction(d){}
    void Move::apply(state::State* s) {
        
        if (id==1){
            if(direction == state::EAST){
                
                s->players[1]->setPosition(5,0);
                //s->players[1]->decreaseHealth(5);
                
            }
            else  {
                
                s->players[1]->setPosition(-5,0);
                
            }
        }
        if (id==2) {
            if(direction == state::WEST)
            s->players[0]->setPosition(-5,0);
            else  s->players[0]->setPosition(5,0);
            
                    }
        
        if ((s->players[0]->getPosition().x - s->players[1]->getPosition().x)<7) {
            s->players[0]->setPosition(3,0);
            s->players[1]->setPosition(-3,0);
            }

    }
}

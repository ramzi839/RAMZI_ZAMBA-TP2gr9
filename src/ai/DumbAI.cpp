#include <iostream>
#include <random>
#include "DumbAI.h"
#include "state/Player.h"
#include "engine/Engine.h"
#include "engine/CommandSet.h"
#include "state/State.h"
namespace ai {

    DumbAI::DumbAI(state::State* s) :Ai(s) {}
    void DumbAI::run(state::State* s) {
        //std::default_random_engine generator;
        //std::uniform_int_distribution<int> distribution(0,9);
        
       // s->players[0]->setPosition(-distribution(generator),0);
         //   s->players[1]->setPosition(distribution(generator),0);
        
        /*if ((s->players[0]->getPosition().x - s->players[1]->getPosition().x)<7) {
            s->players[0]->setPosition(3,0);
            s->players[1]->setPosition(-3,0);
            }*/
        if(s->players[0]->getPosition().x>100){
            s->players[1]->setPosition(3,0);
            
            }
        
         if (s->players[0]->getPosition().x -10 == s->players[1]->getPosition().x ) {
            s->players[1]->notifyObservers(state::ATTACK_KICK);
         }
    }
        
        
            
    
    void DumbAI::run() {}
}

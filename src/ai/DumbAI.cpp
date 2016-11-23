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
        
        
        
        
        /*if(s->players[0]->getPosition().x>100){
            s->players[1]->setPosition(2,0);
         
           
            }*/
        
         if (s->players[0]->getPosition().x -70 == s->players[1]->getPosition().x ) {
                 
            //s->players[0]->decreaseHealth(120);
            s->players[0]->decreaseHealth(120);
            s->players[1]->notifyObservers(state::ATTACK_KICK);
              
            //s->players[0]->notifyObservers(state::HEALTH_CHANGED);
            
            
            
         }
         
         
         
       
        
    }
        
        
            
    
    void DumbAI::run() {}
}

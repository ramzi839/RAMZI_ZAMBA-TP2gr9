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
        s->players[0]->setPosition(-1,0); 
         if (s->players[0]->getPosition().x -20 < s->players[1]->getPosition().x ) {
               
            sf::sleep(sf::seconds(2.f));
            
            s->players[1]->decreaseHealth(120);
            s->players[0]->notifyObservers(state::ATTACK_KICK);
              
            
            
            
            
         }
         
         
         
       
        
    }
        
        
            
    
    void DumbAI::run() {}
}

#include <iostream>
#include "Engine.h"
#include "Kick.h"
#include "Punch.h"
#include "Move.h"
using namespace std;

namespace engine {

    Engine::Engine(state::State * s) : currentState(s){
   
        
    }
    
    void Engine::execute() {
    
        /*switch (command) {
            case engine::KEY_W : 
            actions[5]->apply(currentState);
            break;
            case engine::KEY_C:
            actions[4]->apply(currentState);
            break;
            case engine::KEY_RIGHT : 
            actions[6]->apply(currentState);
            break;
            case engine::KEY_LEFT:
            actions[7]->apply(currentState);
            break;
            case engine::KEY_KICK_P1:
            actions[0]->apply(currentState);    
            break;
            case engine::KEY_KICK_P2:
            actions[1]->apply(currentState);     
            break;
            case engine::KEY_PUNCH_P1:
            actions[2]->apply(currentState);    
            break;
            case engine::KEY_PUNCH_P2:
            actions[3]->apply(currentState);     
            break;
            default :
            
            break;        
        }*/
        
        for (auto a : actions ) 
           a->apply(currentState);    
        
        actions.clear();
        
    }

    void Engine::addCommand(engine::Action* action) {
        
        actions.push_back(action);
    
    }
    
    
}

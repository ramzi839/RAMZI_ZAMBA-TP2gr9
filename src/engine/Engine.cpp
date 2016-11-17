#include <iostream>
#include "Engine.h"
#include "Kick.h"
#include "Punch.h"
#include "Move.h"
using namespace std;

namespace engine {

    Engine::Engine(state::State * s) : currentState(s){
        Kick * kick = new Kick(1);
        actions.push_back(kick);
        Kick* kick2 = new Kick(2);
        actions.push_back(kick2);
        Punch* punch=new Punch(1);
        actions.push_back(punch);
        Punch* punch2 = new Punch(2);
        actions.push_back(punch2);
        
        Move * move_east = new Move(1,state::EAST);
        actions.push_back(move_east);
        Move * move_west = new Move(1,state::WEST);
        actions.push_back(move_west);
        Move* move2_east = new Move(2,state::EAST);
        actions.push_back(move2_east);
        Move* move2_west = new Move(2,state::WEST);
        actions.push_back(move2_west);
        
    }
    
    void Engine::execute(engine::CommandSet command) {
    
        switch (command) {
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
            default :
            
            break;
            
            
        
        
        
        }
    }


}

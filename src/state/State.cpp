/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace state{

    State::State(){
    
    
        
    
    }

    void State::update(engine::CommandTypeId order){
        if (order== engine::LEFT){
            scene.update(state::LEFT);
        
        }
    
        
        if (order== engine::RIGHT){
            scene.update(state::RIGHT);
        
        } 
        if (order== engine::NO_KEY){
            scene.update(state::NO_MOVE);
        
        }
        
       
    }


}
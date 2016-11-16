/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "State.h"
using namespace std;
namespace state{

    State::State(){
        Player ken("Ken"),ryu("Ryu");
        players.push_back(&ken);
        players.push_back(&ryu);
        cout<<"State Created..."<<endl;
    
    }
    State::State(Player* p1, Player* p2) {
        cout<<"Beginning..."<<endl;
        players.push_back(p1);
        players.push_back(p2);
        cout<<"State Created with " + players[0]->getName()+ " and " + players[1]->getName()<<endl; 
        
        
    
    }
    
    
/*void State::notifyObservers (int i){

    if (i==1){}

}*/
void State::update (engine::CommandTypeId order){

    if ((order==engine::LEFT) || (order==engine::RIGHT) || (order==engine::KICK) || (order==engine::JUMP)||(order==engine::SPELL) || (order==engine::COMBO)) 
        players[0]->notifyObservers((StateEvent)5,order);
    if ((order==engine::LEFT_IA) || (order==engine::RIGHT_IA) || (order==engine::KICK_IA) || (order==engine::JUMP_IA)||(order==engine::SPELL_IA) || (order==engine::COMBO_IA)) 
        players[1]->notifyObservers((StateEvent)5,order);
    


}
    
       
    


}
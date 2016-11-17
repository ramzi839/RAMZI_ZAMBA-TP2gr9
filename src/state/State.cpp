#include <iostream>
#include "State.h"
#include "PlayerObserver.h"

using namespace std;

namespace state {
   State::State(Player* p1,Player* p2) {
  
    this->players.push_back(p1);
    this->players.push_back(p2);   
    //players[0]->addObserver(new StateObserver(this->players[0]));
    //players[1]->addObserver(new StateObserver(this->players[1]));
    
       cout<<"State Created with players " + players[0]->getName() + " and  " + players[1]->getName()<<endl;
   } 

/*  State::State( state::Player* newPlayer1,  state::Player* newPlayer2)  {
       this->players.push_back(newPlayer1);
       this->players.push_back(newPlayer2);
       cout<<"State Created..."<<endl;
    }*/ 

   void State::notifyObservers() {
       cout<<"This is State Notification"<<endl;
   }
   void State::addObserver(PlayerObserver* newStateObserver) {
       this->observers.push_back(newStateObserver);
       cout<<"Observer added To State "<<endl;
   }

}
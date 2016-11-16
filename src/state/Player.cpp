#include <iostream>
#include "Player.h"
using namespace std;

namespace state {

Player::Player(std::string name) : name(name){
            cout<<"Player " + this->name + " Created..."<<endl;}
Player::~Player(){}
void Player::setStatus(PlayerStatus s){this->status=s;}
PlayerStatus Player::getStatus(){return this->status;}
void Player::setName(std::string s){this->name=s;}
std::string Player::getName(){return this->name;}
Side Player::getSide(){return this->side;}
void Player::setSide(Side side){this->side=side;}
sf::Vector2f Player::getPosition() {return this->position;}

void Player::registerObserver(StateObserver* o) {
     observers.push_back(o);
     cout<<"Observer Added To Player " + this->name<<endl;
                            }

void Player::notifyObservers (StateEvent e , engine::CommandTypeId c){

    for (auto o : this->observers) 
        o->stateChanged(e,c); 
                    }

}


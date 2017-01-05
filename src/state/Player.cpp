#include <iostream>
#include "Player.h"
#include "PlayerStatus.h"
#include "SIDE.h"

using namespace std;
namespace state {


Player::Player(std::string newName) : health(120) {
    this->name=newName;
    
    if(newName.compare("Ken")==0) {
        this->setPosition(690,350);
        this->side=state::RIGHT;
    }
    else if(newName.compare("Ryu")==0) {
         this->setPosition(10,350);
         this->side=state::LEFT;}

          std::cout<<"Player " +this->name+" Created... pos "<< this->getPosition().x<<std::endl;
}



void Player::notifyObservers(state::PlayerEvent e){
	for(auto o : this->observers) {
		o->update(e);
					}
}
PlayerStatus Player::getStatus() const{
        return this->status; 
                                    }
void Player::setStatus(PlayerStatus newPlayerStatus) {
        this->status=newPlayerStatus;
        notifyObservers(state::STATUS_CHANGED);
                        }
sf::Vector2f Player::getPosition() const {
        return this->position; 
                                     }
void Player::setPosition(float x, float y)  {
    if (this->position.x >= 0 )
    this->position.x += x;
    else this->position.x += 10;
    
    if (this->position.x <= 710)
    this->position.x += x;
    else this->position.x -= 10;
    
    if (x == 690)position.x = x;
    
    this->position.y += y;
   
    
    cout<<this->name + " Changed Position To  " << this->getPosition().x<< " " <<this->getPosition().x <<endl;
    notifyObservers((state::PlayerEvent)1);
                    }
void Player::addObserver(PlayerObserver* newPlayerObserver) {
        this->observers.push_back(newPlayerObserver);
        cout<<"Observer Added to Player " + this->name <<endl;
    }

std::string Player::getName() const {return this->name;}

float Player::getHealth() const { 
    
    return this->health;
                                }
void Player::decreaseHealth(float i) {
    notifyObservers(state::HEALTH_CHANGED);
    health -=i;}

void Player::setHealth(int health) {
    
    this->health = health;
}

state::SIDE Player::getSide() const { return this->side;}

void Player::setDirection(state::Direction d) { this->direction = d;}
state::Direction Player::getDirection() const { return this->direction;}

void Player::linkToState(state::State* state) {
        this->state=state;
        cout<<"Player "<< this->name<<" Linked To State... "<<endl;
                                       }


}

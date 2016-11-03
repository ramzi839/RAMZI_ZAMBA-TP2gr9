#include "Player.h"

using namespace state;

Player::Player(std::string name) { this->name = name;}
Player::~Player(){}
void Player::setStatus(PlayerStatus s){this->status=s;}
PlayerStatus Player::getStatus(){return this->status;}
void Player::setName(std::string s){this->name=s;}
std::string Player::getName(){return this->name;}
Side Player::getSide(){return this->side;}
void Player::setSide(Side side){this->side=side;}
sf::Vector2f Player::getPosition() {return this->position;}
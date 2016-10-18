#include "Player.h"

using namespace state;

Player::Player( std::string name ) {this->name = name;}
Player::~Player() {}
PlayerStatus state::Player::getStatus(){return this->status;}
void Player::setStatus(PlayerStatus s) {this->status = s;}
void Player::attack(std::string str) {}
void Player::defend() {} 
void Player::setName(std::string name) {this->name = name;}
std::string Player::getName() {return this->name;}
Side Player::getSide() {return this->side;}
void Player::setSide(Side side) {this->side = side;}


#include <iostream>
#include "Layer.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "state/State.h"

using namespace std;

namespace render {

    Layer::Layer(state::Player* observedPlayer ) : player(observedPlayer) {
        if (player->getName().compare("Ryu")==0) {
            this->setTexture();
            this->initSprite();
            this->setRectHealth();
            cout<<"Layer Linked to Player " + player->name << endl; 
         
        }
        if (player->getName().compare("Ken")==0) {
            this->setTexture();
            this->initSprite();
            this->setRectHealth();
            cout<<"Layer Linked to Player " + player->name << endl; 
       
        }
        
    }
    
    void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
            
    }
    
    void Layer::update(state::PlayerEvent e) {
         
        switch (e){
            case state::POSITION_CHANGED :
                
                 this->sprite.setPosition(this->player->getPosition());   
       cout<<"Position Of Sprite Changed " << player->getPosition().x<< " " << player->getPosition().y<<endl;
                 break;
            case state::STATUS_CHANGED :
               if ( player->side==state::LEFT){
                if (player->getStatus()==state::SUPER)
                this->texture.loadFromFile("../res/ryu_super.png");
                else if ( player->getStatus()==state::DEAD){
                     this->texture.loadFromFile("../res/ryu_dead.png");
                     this->sprite.rotate(-90);
                                                 }
                    else this->texture.loadFromFile("../res/ryu_normal.png");
                }
            case state::DEFEND : 
                this->texture.loadFromFile("../res/ryu_defend.png");
                    
                break;
            case state::HEALTH_CHANGED :
                if (player->getHealth()>=0)  
                this->rect_health.setSize(sf::Vector2f(player->health,10.f));
                cout<<"Health changed"<<endl; 
            case state::ATTACK_KICK : 
                
                if ( player->side==state::LEFT){
                this->sprite.setPosition(player->getPosition().x,player->getPosition().y);
                this->sprite.setScale(1.3,1.3);
                this->sprite.setTextureRect(sf::IntRect(140, 480, 70, 80));
                this->sprite.setTexture(texture);
                cout<<"Attack Kick from Player " + player->name<<endl;
                }
                
                if ( player->side==state::RIGHT){
                this->sprite.setPosition(player->getPosition().x,player->getPosition().y);
                this->sprite.setScale(1.3,1.3);
                this->sprite.setTextureRect(sf::IntRect(280, 480, 70, 80));
                this->sprite.setTexture(texture);
                cout<<"Attack from Player " + player->name<<endl;
                }
               
                break; 
                 case state::ATTACK_PUNCH : 
                
                if ( player->side==state::LEFT){
                this->sprite.setPosition(player->getPosition().x,player->getPosition().y);
                this->sprite.setScale(1.3,1.3);
                this->sprite.setTextureRect(sf::IntRect(83, 162, 70, 80));
                this->sprite.setTexture(texture);
                cout<<"Attack Punch from Player " + player->name<<endl;
                }
                
                if ( player->side==state::RIGHT){
                this->sprite.setPosition(player->getPosition().x,player->getPosition().y);
                this->sprite.setScale(1.3,1.3);
                this->sprite.setTextureRect(sf::IntRect(350, 160, 70, 80));
                this->sprite.setTexture(texture);
                cout<<"Attack from Player " + player->name<<endl;
                }
               
                break;
            case state::HURTED : 
                
                if ( player->side==state::LEFT){
                this->sprite.setPosition(player->getPosition().x,player->getPosition().y);
                this->sprite.setScale(1.3,1.3);
                this->sprite.setTextureRect(sf::IntRect(0, 562, 70, 80));
                this->sprite.setTexture(texture);
                cout<<"Hurt Player " + player->name<<" Side " << player->getSide()<<endl;
                }
                
                if ( player->side==state::RIGHT){
                this->sprite.setPosition(player->getPosition().x,player->getPosition().y);
                this->sprite.setScale(1.3,1.3);
                this->sprite.setTextureRect(sf::IntRect(286, 562, 70, 80));
                this->sprite.setTexture(texture);
                cout<<"Hurt Player " + player->name <<" Side " << player->getSide()<<endl;
                }
                break;
      case state::NOTHING_CHANGED :
                if ( player->side==state::LEFT)
                 this->sprite.setTextureRect(sf::IntRect(10, 80, 50, 80));
                else {
                this->sprite.setTextureRect(sf::IntRect(430,80,50,80));
                
                }
               
                 break;
                
        }
    }
    void Layer::setSprite() {
            
    
    }
    void Layer::setTexture( ) {
        if (player->getName().compare("Ryu")==0) {
            this->texture.loadFromFile("res/ken2.png");
        }
        if (player->getName().compare("Ken")==0) {
            this->texture.loadFromFile("res/ia_ken2.png");
        }
            
    }
    void Layer::setSpriteSet(){}
    
    void Layer::initSprite() {
        this->sprite.setTexture(this->texture);
        if (player->getName().compare("Ryu")) {
            this->sprite.setTextureRect(sf::IntRect(11, 82, 50, 80));
            this->sprite.setScale(1.3,1.3);
            this->sprite.setPosition(player->getPosition());   
        }
        if (player->getName().compare("Ken")) {
            this->sprite.setTextureRect(sf::IntRect(430,80,50,80));
            this->sprite.setPosition(player->getPosition());
            this->sprite.setScale(1.3,1.3);
        
        }
    } 
    void Layer::setRectHealth(){
        if (player->getSide()==state::LEFT) {
            sf::Vector2f size1(119.f,10.f);
            rect_health.setSize(size1);
            sf::Color health_color;
            rect_health.setFillColor(health_color.Green);
            rect_health.setPosition(102,25);
        }
        if (player->getSide()==state::RIGHT) {
            sf::Vector2f size1(120.f,10.f);
            rect_health.setSize(size1);
            sf::Color health_color;
            rect_health.setFillColor(health_color.Green);
            rect_health.setPosition(544,25.5);
        }  
    }
    
    
}


#include <iostream>
#include "Layer.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "state/State.h"

using namespace std;

namespace render {

    Layer::Layer(state::Player* observedPlayer ) : player(observedPlayer) {
        if (player->getName().compare("Ryu")) {
            this->texture.loadFromFile("../res/ken2.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setTextureRect(sf::IntRect(10, 80, 50, 80));
            this->sprite.setScale(1.3,1.3);
            this->sprite.setPosition(observedPlayer->getPosition());
            cout<<"Layer Linked to Player " + player->name << endl; 
            sf::Vector2f size1(119.f,10.f);
            rect_health.setSize(size1);
            sf::Color health_color;
            rect_health.setFillColor(health_color.Green);
            rect_health.setPosition(102,25);}
        if (player->getName().compare("Ken")) {
            this->texture.loadFromFile("../res/ia_ken2.png");
            this->sprite.setTexture(this->texture);
            this->sprite.setTextureRect(sf::IntRect(430,80,50,80));
            this->sprite.setPosition(observedPlayer->getPosition());
            this->sprite.setScale(1.3,1.3);
            cout<<"Layer Linked to Player " + player->name << endl; 
            sf::Vector2f size1(120.f,10.f);
            rect_health.setSize(size1);
            sf::Color health_color;
            rect_health.setFillColor(health_color.Green);
            rect_health.setPosition(544,25.5);}
        
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
                cout<<"Attack from Player " + player->name<<endl;
                }
                
                if ( player->side==state::RIGHT){
                this->sprite.setPosition(player->getPosition().x,player->getPosition().y);
                this->sprite.setScale(1.3,1.3);
                this->sprite.setTextureRect(sf::IntRect(280, 480, 70, 80));
                this->sprite.setTexture(texture);
                cout<<"Attack from Player " + player->name<<endl;
                }
               
                break;    
        }
    }
    void Layer::setSprite() {
            
    
    }
    void Layer::setTexture( ) {
        //if (this->player->getName().compare("Ryu")) this->texture.loadFromFile("../res/ryu_normal.png");
       // else if (this->player->getName().compare("Ken")) this->texture.loadFromFile("../res/ken_normal.png");
    }

}


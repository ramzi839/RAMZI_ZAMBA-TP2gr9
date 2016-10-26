/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Layer.h"

namespace render {
Layer::Layer() {};    
Layer::Layer(std::string s){
    myTexture.loadFromFile(s);
    mySprite.setTexture(myTexture);

};
    

void Layer::setAnimation (Animation anim){


};

void Layer::setSurface (std::string texture){
    myTexture.loadFromFile(texture);
    mySprite.setTexture(myTexture);


}

void Layer::setPosition (float x, float y){

    mySprite.setPosition(x,y);
    
}



sf::Sprite Layer::getSurface (){

    return this->mySprite;
    
}


};
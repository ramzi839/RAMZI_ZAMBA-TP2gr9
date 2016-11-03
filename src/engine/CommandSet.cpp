/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CommandSet.h"

namespace engine{
    
CommandSet::CommandSet(){



}   


void CommandSet::addCommand(sf::Keyboard::Key Key){

    commands.push_back(Key);


}

CommandTypeId CommandSet::get(){

    return this->id;
}
void CommandSet::execute(){

if (sf::Keyboard::isKeyPressed(commands[0]))
{
    this->id=CommandTypeId::LEFT;
    noKeyWasPressed=false;
}

if (sf::Keyboard::isKeyPressed(commands[1]))
{
       this->id=CommandTypeId::RIGHT;  
       noKeyWasPressed=false;
}

if (sf::Keyboard::isKeyPressed(commands[2]))
{
       this->id=CommandTypeId::JUMP; 
       noKeyWasPressed=false;
}

 if (noKeyWasPressed)
        {
           this->id=CommandTypeId::NO_KEY;
        }
 noKeyWasPressed = true;

}




}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CommandSet.h"
#include <iostream>    
       


namespace engine{
    
CommandSet::CommandSet(){



}   


void CommandSet::addCommand(sf::Keyboard::Key Key){

    commands.push_back(Key);


}

CommandTypeId CommandSet::get(){
    
    return this->id;
}

bool CommandSet::commandChanged(){
    
    return this->noKeyWasPressed;
}


void CommandSet::execute(){
    

if (sf::Keyboard::isKeyPressed(commands[0]))
{
    //std::cout<<"ok"<<std::endl;
    this->id=CommandTypeId::LEFT;
    noKeyWasPressed = false;
    
}

if (sf::Keyboard::isKeyPressed(commands[1]))
{
       this->id=CommandTypeId::RIGHT;  
       noKeyWasPressed = false;
       
       
}

if (sf::Keyboard::isKeyPressed(commands[2]))
{
       this->id=CommandTypeId::JUMP; 
       noKeyWasPressed = false;
       
}

if (sf::Keyboard::isKeyPressed(commands[3]))
{
       this->id=CommandTypeId::KICK; 
       noKeyWasPressed = false;
       
}
if (sf::Keyboard::isKeyPressed(commands[4]))
{
       this->id=CommandTypeId::SPELL; 
       noKeyWasPressed = false;
       
}

if (sf::Keyboard::isKeyPressed(commands[5]))
{
       this->id=CommandTypeId::COMBO; 
       noKeyWasPressed = false;
       
}
if (sf::Keyboard::isKeyPressed(commands[6]))
{
       this->id=CommandTypeId::LEFT_IA; 
       noKeyWasPressed = false;
       
}

 if (noKeyWasPressed)
        {
           this->id=CommandTypeId::NO_KEY;
        }

noKeyWasPressed = false;
}




}
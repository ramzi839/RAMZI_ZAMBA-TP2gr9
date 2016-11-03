/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"

namespace engine{
    
    
Engine::Engine(){
   
       
       
       myPlayerCommands.addCommand(sf::Keyboard::Left);
       myPlayerCommands.addCommand(sf::Keyboard::Right);
       myPlayerCommands.addCommand(sf::Keyboard::Space);
       myPlayerCommands.execute();
   
   } 
    
void Engine::run(){

      
      currentState.update(myPlayerCommands.get());
      


}
  
    
}
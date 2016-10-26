#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "state.hpp"
#include "render.h"
#include "render/Scene.h"

using namespace std;
using namespace sf;



int main()
{
    
  
    // create the window
    RenderWindow window(sf::VideoMode(766, 478), "My window");
    window.setVerticalSyncEnabled(false);
   
    
    window.setFramerateLimit(50);	
    
    
    sf::Clock clock;
    
    
    
     
       
     /*********************Scene******************************/
        
        
       
        render::Scene myBackground = render::Scene(0);
        render::Scene player = render::Scene(1);
        render::Scene enemy = render::Scene(2);
        myBackground.setScene();
        player.setScene();
        enemy.setScene();
        
        
      /*******************************************************/     
     
// Run the program as long as the window is open
    while (window.isOpen())
    {
        
        Event event;
        while (window.pollEvent(event))
        {
           
            if (event.type == Event::Closed)
                window.close();
        }
        
        sf::Time frameTime = clock.restart();
        
        
        
        
        
         player.stateChanged(state::StateEvent::SMTH_CHANGED);
         
         player.update(frameTime);
        /*********Drawing and Displaying*********/
         window.draw(myBackground.getScene());
         window.draw(player.getScene());
         //window.draw(enemy.getScene());
         window.display();
        
        
      

    }


    

    return 0;
}

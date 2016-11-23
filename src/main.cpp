#include <iostream>


#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.hpp"
#include "render.hpp"
#include "state/State.h"
#include "state/PlayerStatus.h"
#include "render/Layer.h"
#include "engine.h"
#include "ai/DumbAI.h"
using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

class Game {
public :
    void run() {
        sf::Texture backgroundTexture;
        sf::Sprite background;
        backgroundTexture.loadFromFile("res/Map0.png");
        background.setTexture(backgroundTexture);
        
        Player ken("Ken");
        Player ryu("Ryu");
        
        Layer* lken = new Layer(&ken);
        Layer* lryu = new Layer(&ryu);
  
        ken.addObserver(lken);
        ryu.addObserver(lryu);

        State state(&ryu,&ken);
        Engine engine(&state);
        
        //DumbAI dumb(&state);
        
        
    
    sf::RenderWindow window(sf::VideoMode(766, 478), "Street Fighters");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        //dumb.run(&state);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            
            engine.execute(engine::KEY_W);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;}
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))   {     
            engine.execute(engine::KEY_C);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))   { 
         //   dumb.run(&state);
            engine.execute(engine::KEY_LEFT);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))   { 
           engine.execute(engine::KEY_RIGHT);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))   { 
           engine.execute(engine::KEY_KICK_P1);
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))   { 
            ken.decreaseHealth(5);
            //lken->update(state::HEALTH_CHANGED);
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))   { 
            ryu.decreaseHealth(10);
            lryu->update(state::HEALTH_CHANGED);
            }
        
       
        window.clear();
        window.draw(background);
        window.draw(lken->sprite);
        window.draw(lken->rect_health);
        window.draw(lryu->sprite);
        window.draw(lryu->rect_health);
        window.display();
    }
        
    }
};


int main(int argc,char* argv[]) 
{
    cout<<"Beginning..."<<endl;
    
    Game game;
    game.run();
    
    
    //state.players[0]->setPlayerStatus((PlayerStatus)1);
    //state.players[1]->setPlayerStatus((PlayerStatus)2);
    
    
    cout << "It works !" << endl;
    

    return 0;
}

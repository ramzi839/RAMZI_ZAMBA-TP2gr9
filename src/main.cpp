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
#include "ai/HeuristicAI.h"
using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

class Game {
public :
    void run() {
        sf::Texture backgroundTexture,imgTexture;
        sf::Sprite background,picture1,picture2;
        backgroundTexture.loadFromFile("../res/Map0.png");
        imgTexture.loadFromFile("../res/ken_profil.jpg");
        picture1.setTexture(imgTexture);
        picture2.setTexture(imgTexture);
        background.setTexture(backgroundTexture);
        picture1.scale(0.11,0.08);
        picture1.setPosition(4,4);
        picture2.scale(0.11,0.08);
        picture2.setPosition(684,4);
        
        
        
        
        Player ken("Ken");
        Player ryu("Ryu");
        
        Layer* lken = new Layer(&ken);
        Layer* lryu = new Layer(&ryu);
  
        ken.addObserver(lken);
        ryu.addObserver(lryu);

        State state(&ryu,&ken);
        Engine engine(&state);
        
        //DumbAI dumb(&state);
        HeuristicAI heuristic(&state);
        
        sf::Font font;
        font.loadFromFile("../res/arial.ttf");
        sf::Color myColor;
        
        sf::Text text, text2;
        text.setCharacterSize(70);
        text.setString("Game Over !");
        text.setPosition(200.f,150.f);
        text.setStyle(sf::Text::Bold | sf::Text::Italic);
        text.setColor(myColor.Red);
        text.setFont(font);
        text2.setCharacterSize(70);
        text2.setString("You are the winner !");
        text2.setPosition(100.f,150.f);
        text2.setStyle(sf::Text::Bold | sf::Text::Italic);
        text2.setColor(myColor.Green);
        text2.setFont(font);
        
        bool noKeyWasPressed = true;
    
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
        heuristic.run(&state);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            
            engine.execute(engine::KEY_W);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;
        noKeyWasPressed = false;}
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))   {     
            engine.execute(engine::KEY_C);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;
        noKeyWasPressed = false;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))   { 
         
            engine.execute(engine::KEY_LEFT);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;
        noKeyWasPressed = false;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))   { 
           engine.execute(engine::KEY_RIGHT);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;
        noKeyWasPressed = false;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))   { 
           engine.execute(engine::KEY_KICK_P1);
           noKeyWasPressed = false;
            }
        
        if (noKeyWasPressed) {
            ken.notifyObservers(state::NOTHING_CHANGED);   
      }
     
        noKeyWasPressed = true;
       
        window.clear();
        window.draw(background);
        window.draw(lken->sprite);
        window.draw(lken->rect_health);
        window.draw(lryu->sprite);
        window.draw(lryu->rect_health);
        window.draw(picture1);
        window.draw(picture2);
        
        
        
        
        
        
        if (ken.getHealth()<0){
        window.draw(text);
        ryu.setHealth(5);    
        }
        else {
        if (ryu.getHealth()<0){
            ken.setHealth(5);
        window.draw(text2);   
        }}
        window.display();
    }
        
    }
};


int main(int argc,char* argv[]) 
{
    cout<<"Beginning..."<<endl;
    
    Game game;
    game.run();
    
 
    
    
    
    

    return 0;
}

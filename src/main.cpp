#include <iostream>
#include <mutex>
#include <thread>
#include <exception> 
#include <SFML/System.hpp>

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

std::mutex m;
void update(Engine &engine) {
    while(1) {
        lock_guard<mutex> lock(m);
        engine.execute();
    }


}


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
        thread t1(update,ref(engine));
        
        
        sf::Font font;
        font.loadFromFile("../res/arial.ttf");
        sf::Color myColor;
        
        bool noKeyWasPressed = true;
    
    sf::RenderWindow window(sf::VideoMode(766, 478), "Street Fighters");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            try {
               t1.detach();
                }
            catch (std::exception& e) {
        std::cerr << "ERROR: could not allocate storage\n";
        std::terminate();}
            }
        }
        
       
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            Action * moveLeft = new Move(1,state::WEST);
            engine.addCommand(moveLeft);
           // engine.execute(engine::KEY_W);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;
        noKeyWasPressed = false;}
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))   { 
            Action * cmd = new Move(1,state::EAST);
            engine.addCommand(cmd);
            //engine.execute(engine::KEY_C);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;
        noKeyWasPressed = false;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))   { 
            Action * cmd = new Move(2,state::WEST);
            engine.addCommand(cmd);
            //engine.execute(engine::KEY_LEFT);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;
        noKeyWasPressed = false;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))   { 
            Action * cmd = new Move(2,state::EAST);
            engine.addCommand(cmd);
           //engine.execute(engine::KEY_RIGHT);
            cout<<ryu.getPosition().x << " "<< ryu.getPosition().y<<endl;
        noKeyWasPressed = false;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))   { 
            Action * cmd = new Kick(1);
            engine.addCommand(cmd);
           //engine.execute(engine::KEY_KICK_P1);
           noKeyWasPressed = false;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))   { 
            Action * cmd = new Punch(1);
            engine.addCommand(cmd);
          // engine.execute(engine::KEY_PUNCH_P1);
           noKeyWasPressed = false;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))   { 
            ken.decreaseHealth(2);
            cout<<ken.getHealth()<<endl;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))   { 
            ken.notifyObservers(state::ATTACK_KICK);
            cout<<"Ken Hurted"<<endl;
            }
        
        if (noKeyWasPressed) {
            ken.notifyObservers(state::NOTHING_CHANGED);   
      }
     
        noKeyWasPressed = true;
        //engine.execute();
        window.clear();
        window.draw(background);
        window.draw(lken->sprite);
        window.draw(lken->rect_health);
        window.draw(lryu->sprite);
        window.draw(lryu->rect_health);
        window.draw(picture1);
        window.draw(picture2);
        window.display();
    }
        t1.join();
    }
};


int main(int argc,char* argv[]) 
{
    cout<<"Beginning..."<<endl;
   
    Game game;
   
    game.run();
     //sf::Thread th(&Game::run,&game);
     
   //  th.launch();
    
    
    
    

    return 0;
}

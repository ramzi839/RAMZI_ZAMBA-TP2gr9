/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Scene.h"
#include "state/Side.h"

namespace render{
Scene::Scene(){
    
       
}

void Scene::stateChanged(state::StateEvent e){
    
    
}



void Scene::update(state::Side status){

    
    sf::Vector2i screenDimensions(766,478);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Street Fighter");
    window.setFramerateLimit(60);
    
    sf::Sprite background;
    sf::Texture backgroundTexture,playerTexture;
    
    playerTexture.loadFromFile("../res/Players/ken2.png");
    backgroundTexture.loadFromFile("../res/Background/Map0.png");
    background.setTexture(backgroundTexture);

    Animation  Crouch;
    Crouch.setSprite(playerTexture);
    Crouch.addFrame(sf::IntRect(10, 740, 70, 60));
   

    Animation walkingLeft;
    walkingLeft.setSprite(playerTexture);
    walkingLeft.addFrame(sf::IntRect(10, 80, 50, 80));
    walkingLeft.addFrame(sf::IntRect(80, 80, 50, 80));
    walkingLeft.addFrame(sf::IntRect(150, 80, 50, 80));
    walkingLeft.addFrame(sf::IntRect(220, 80, 60, 80));

    Animation walkingRight;
    walkingRight.setSprite(playerTexture);
    walkingRight.addFrame(sf::IntRect(10, 80, 50, 80));
    walkingRight.addFrame(sf::IntRect(80, 80, 50, 80));
    walkingRight.addFrame(sf::IntRect(150, 80, 50, 80));
    walkingRight.addFrame(sf::IntRect(220, 80, 60, 80));
    
    Animation Jump;
    Jump.setSprite(playerTexture);
    Jump.addFrame(sf::IntRect(80, 640, 70, 80));

    Animation* currentAnimation = &walkingRight;
    Layer playerLayer(sf::seconds(0.2), true, false);
    playerLayer.scale(1.5,1.5);
    playerLayer.setPosition(0,350);
    
    
    sf::Clock frameClock;

    float speed = 80.f;
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        sf::Time frameTime = frameClock.restart();

        
        sf::Vector2f movement(0.f, 0.f);
        if (status==state::JUMP)
        {
            currentAnimation = &Jump;
            movement.y -= speed;
            
        }
        if (status==state::CROUCH)
        {
            currentAnimation = &Crouch;
            movement.y += speed;
            
        }
        if(status==state::LEFT)
        {
            currentAnimation = &walkingLeft;
            movement.x -= speed;
            
        }
        if (status==state::RIGHT)
        {
            currentAnimation = &walkingRight;
            //movement.x += speed;
            
        }
        playerLayer.play(*currentAnimation);
        playerLayer.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (status==state::NO_MOVE)
        {
            playerLayer.stop();
        }
        

        // update AnimatedSprite
        playerLayer.update(frameTime);

        // draw
        window.clear();
        window.draw(background);
        window.draw(playerLayer);
        window.display();
    
    }
    

}
}


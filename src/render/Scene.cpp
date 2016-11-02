/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Scene.h"

namespace render{
Scene::Scene(){
    
       
}

void Scene::stateChanged(state::StateEvent e){
    
}



void Scene::update(){

    
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
    bool noKeyWasPressed = true;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        sf::Time frameTime = frameClock.restart();

        
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            currentAnimation = &Jump;
            movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            currentAnimation = &Crouch;
            movement.y += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            currentAnimation = &walkingLeft;
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            currentAnimation = &walkingRight;
            movement.x += speed;
            noKeyWasPressed = false;
        }
        playerLayer.play(*currentAnimation);
        playerLayer.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
            playerLayer.stop();
        }
        noKeyWasPressed = true;

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


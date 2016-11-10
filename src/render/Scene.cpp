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



void Scene::run(){

    
    sf::Vector2i screenDimensions(766,478);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Street Fighter");
    window.setFramerateLimit(60);
    
    sf::Sprite background, picture1,picture2;
    sf::Texture backgroundTexture,playerTexture,comboTexture,imageCharacter1,imageCharacter2,ia_texture;
    
    playerTexture.loadFromFile("../res/Players/ken2.png");
    ia_texture.loadFromFile("../res/Players/ia_ken2.png");
    comboTexture.loadFromFile("../res/Players/joueur.png");
    backgroundTexture.loadFromFile("../res/Background/Map0.png");
    imageCharacter1.loadFromFile("../res/Players/ken_profil.jpg");
    imageCharacter2.loadFromFile("../res/Players/ken_profil.jpg");
    
    sf::Vector2f size1(119.f, 10.f);
    sf::Vector2f size2(119.f, 10.f);
    
    sf::Color myColor, myColor2;
    int xp, xi;
    
    
    background.setTexture(backgroundTexture);
    picture1.setTexture(imageCharacter1);
    picture2.setTexture(imageCharacter2);
    
    picture1.scale(0.11,0.08);
    picture1.setPosition(4,4);
    
    picture2.scale(0.11,0.08);
    picture2.setPosition(684,4);
    
    
    sf::RectangleShape rect1, rect2;
    
    

    Animation  Crouch;
    Crouch.setSprite(playerTexture);
    Crouch.addFrame(sf::IntRect(10, 740, 70, 60));
   

    Animation walkingLeft;
    walkingLeft.setSprite(playerTexture);
    walkingLeft.addFrame(sf::IntRect(10, 80, 50, 80));
    walkingLeft.addFrame(sf::IntRect(80, 80, 50, 80));
    walkingLeft.addFrame(sf::IntRect(150, 80, 50, 80));
    walkingLeft.addFrame(sf::IntRect(210, 80, 60, 80));
    
    Animation IA_walkingLeft;
    IA_walkingLeft.setSprite(ia_texture);
    IA_walkingLeft.addFrame(sf::IntRect(430, 80, 50, 80));
    IA_walkingLeft.addFrame(sf::IntRect(360, 80, 50, 80));
    IA_walkingLeft.addFrame(sf::IntRect(290, 80, 50, 80));
    IA_walkingLeft.addFrame(sf::IntRect(220, 80, 60, 80));

    Animation walkingRight;
    walkingRight.setSprite(playerTexture);
    walkingRight.addFrame(sf::IntRect(10, 80, 50, 80));
    walkingRight.addFrame(sf::IntRect(80, 80, 50, 80));
    walkingRight.addFrame(sf::IntRect(150, 80, 50, 80));
    walkingRight.addFrame(sf::IntRect(220, 80, 60, 80));
    
    Animation makingCombo;
    makingCombo.setSprite(playerTexture);
    makingCombo.addFrame(sf::IntRect(10, 0, 50, 75));
    makingCombo.addFrame(sf::IntRect(80, 0, 50, 75));
    makingCombo.addFrame(sf::IntRect(140, 0, 70, 75));
    makingCombo.addFrame(sf::IntRect(220, 0, 80, 75));
    
    Animation throwingSpell;
    throwingSpell.setSprite(playerTexture);
    throwingSpell.addFrame(sf::IntRect(10, 0, 50, 75));
    throwingSpell.addFrame(sf::IntRect(80, 0, 50, 75));
    throwingSpell.addFrame(sf::IntRect(140, 0, 70, 75));
    throwingSpell.addFrame(sf::IntRect(220, 0, 80, 75));
    
    Animation Jump;
    Jump.setSprite(playerTexture);
    Jump.addFrame(sf::IntRect(80, 640, 70, 80));
    
    Animation kick;
    kick.setSprite(playerTexture);
    kick.addFrame(sf::IntRect(10, 480, 50, 80));
    kick.addFrame(sf::IntRect(80, 480, 50, 80));
    kick.addFrame(sf::IntRect(140, 480, 70, 80));
    kick.addFrame(sf::IntRect(220, 480, 80, 80));
    
    Animation spell;
    spell.setSprite(playerTexture);
    spell.addFrame(sf::IntRect(10, 320, 40, 50));
    
    Animation combo;
    combo.setSprite(comboTexture);
    combo.addFrame(sf::IntRect(160, 320, 70, 60));
    
    std::vector<Layer>::const_iterator iter;
    std::vector<Layer> ballArray;
    
    std::vector<Layer>::const_iterator iter2;
    std::vector<Layer> ballArray2;
    

    Animation* currentAnimation = &walkingRight;
    Animation* IA_currentAnimation = &IA_walkingLeft;
    
    
    Layer playerLayer(sf::seconds(0.2), true, false);
    Layer IA(sf::seconds(0.2), true, false);
    Layer spellsLayer(sf::seconds(0.2), true, false);
    Layer comboLayer(sf::seconds(0.2), true, false);
    
    playerLayer.scale(1.5,1.5);
    IA.scale(1.5,1.5);
    spellsLayer.scale(1.5,1.5);
    comboLayer.scale(3,3);
    
    
    playerLayer.setPosition(0,350);
    IA.setPosition(690,350);
    
    
    int counter=0, counter2=0;
    
    
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

        window.clear();
        window.draw(background);
        
        sf::Time frameTime = frameClock.restart();
       
        
        
        sf::Vector2f movement(0.f, 0.f);
        sf::Vector2f movement2(0.f, 0.f);
        
        
        
        myEngine.execute();
        
        
        
        if (myEngine.getMode()== engine::JUMP)
        {
            
            currentAnimation = &Jump;
            //movement.y -= speed;
                 
            
        }
       
        if(myEngine.getMode()== engine::LEFT)
        {
            currentAnimation = &walkingLeft;
            
            if(playerLayer.getPosition().x>0)
            movement.x -= speed;
            
        }
        if (myEngine.getMode()== engine::RIGHT)
        {
            currentAnimation = &walkingRight;
            if(playerLayer.getPosition().x<700)
            movement.x += speed;
           
            
        }
         if (myEngine.getMode()== engine::KICK)
        {
             
            currentAnimation = &kick;
           
           
            
        }
        
         
         if (myEngine.getMode()== engine::SPELL)
        {
            spellsLayer.setPosition(playerLayer.getPosition().x+40,
            playerLayer.getPosition().y-10);
            ballArray.push_back(spellsLayer);
            
            currentAnimation = &throwingSpell;
      
            
   
       
            
        }
        
        if (myEngine.getMode()== engine::COMBO)
          
        {
            
            comboLayer.setPosition(playerLayer.getPosition().x+60,
            playerLayer.getPosition().y-50);
            ballArray2.push_back(comboLayer);
             
   
            currentAnimation = &makingCombo;
            
        }
        
         counter=0;
        
          
        for(iter = ballArray.begin(); iter!=ballArray.end();iter++){
        
        ballArray[counter].move(10.f,0);
        
        ballArray[counter].play(spell);
        
        window.draw(ballArray[counter]);
        counter++;
        }
         
         counter2=0;
         for(iter2 = ballArray2.begin(); iter2!=ballArray2.end();iter2++){
        
        ballArray2[counter2].move(10.f,0);
        
        ballArray2[counter2].play(combo);
        window.draw(ballArray2[counter2]);
        counter2++;
        
        }
          
          
          
        if (myEngine.getMode()== engine::LEFT_IA)
        {
             
            IA_currentAnimation = &IA_walkingLeft;
           if(IA.getPosition().x>0)
           movement2.x -= speed;
           
            
        }
                 
                 
                 
        playerLayer.play(*currentAnimation);
        IA.play(*IA_currentAnimation);
        
        
        playerLayer.move(movement * frameTime.asSeconds());
        IA.move(movement2 * frameTime.asSeconds());
        
        
        

        
        if (myEngine.getMode()== engine::NO_KEY)
        {
            playerLayer.stop();
        }
        
        
        playerLayer.update(frameTime);
        IA.update(frameTime);
       
   
        xi = playerLayer.getPosition().x;
        xp = IA.getPosition().x-40;
        
        /*test d'un coup reçu*/
        if(xi==xp){
        size2.x-= 10;
        IA.setColor(myColor2.Cyan);
        
        } else{
        
        IA.setColor(myColor2.White);
        }
        
        if (size2.x<0) size2.x=0;
        
        rect1.setSize(size1);
        rect1.setFillColor(myColor.Green);
        rect1.setPosition(102,25);
    
        rect2.setSize(size2);
        rect2.setFillColor(myColor.Green);
        rect2.setPosition(544,25.5);
        
        
        window.draw(IA);
        window.draw(playerLayer);
        
        window.draw(picture1);
        window.draw(picture2);
        window.draw(rect1);
        window.draw(rect2);
        window.display();
    
    }
    

}
}


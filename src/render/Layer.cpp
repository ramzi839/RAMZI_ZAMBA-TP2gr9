/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Layer.h"
#include "state/Player.h"
using namespace std;
using namespace state;
namespace render {   
Layer::Layer(sf::Time frameTime, bool pause, bool loop):
    my_animation(NULL), my_frameTime(frameTime), my_currentFrame(0), isPaused(pause), isLooped(loop), my_texture(NULL)
{
    
 
}

void Layer::stateChanged(state::StateEvent e, engine::CommandTypeId c ) {}
void Layer::setFrame(std::size_t newFrame, bool resetTime)
{
    if (my_animation)
    {
        //calculate new vertex positions and texture coordiantes
        sf::IntRect rect = my_animation->getFrame(newFrame);
        
        my_vertices[0].position = sf::Vector2f(0.f, 0.f);
        my_vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
        my_vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
        my_vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

        float left = static_cast<float>(rect.left) + 0.0001f;
        float right = left + static_cast<float>(rect.width);
        float top = static_cast<float>(rect.top);
        float bottom = top + static_cast<float>(rect.height);

        my_vertices[0].texCoords = sf::Vector2f(left, top);
        my_vertices[1].texCoords = sf::Vector2f(left, bottom);
        my_vertices[2].texCoords = sf::Vector2f(right, bottom);
        my_vertices[3].texCoords = sf::Vector2f(right, top);
    }

    if (resetTime)
        my_currentTime = sf::Time::Zero;
}


    
    
void Layer::update(sf::Time deltaTime){
    
    if (!isPaused && my_animation)
    {
        
        my_currentTime += deltaTime;

        
        if (my_currentTime >= my_frameTime)
        {
            
            my_currentTime = sf::microseconds(my_currentTime.asMicroseconds() % my_frameTime.asMicroseconds());

            
            if (my_currentFrame + 1 < my_animation->getSize())
                my_currentFrame++;
            else
            {
                
                my_currentFrame = 0; 

                if (!isLooped)
                {
                    isPaused = true;
                }

            }
          
            setFrame(my_currentFrame, false);
        }
    }
}

void Layer::play()
{
    isPaused = false;
}

void Layer::play(const Animation& animation)
{
    if (getAnimation() != &animation)
        setAnimation(animation);
    play();
}

void Layer::setColor(const sf::Color& color)
{
    // Update the vertices' color
    my_vertices[0].color = color;
    my_vertices[1].color = color;
    my_vertices[2].color = color;
    my_vertices[3].color = color;
}

void Layer::setAnimation(const Animation& animation)
{
    my_animation = &animation;
    my_texture = my_animation->getSprite();
    my_currentFrame = 0;
    setFrame(my_currentFrame);
}

const Animation* Layer::getAnimation() const
{
    return my_animation;
}


void Layer::stop()
{
    isPaused = true;
    my_currentFrame = 0;
    setFrame(my_currentFrame);
}

void Layer::pause()
{
    isPaused = true;
}

    
void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    if (my_animation && my_texture)
    {
        states.transform *= getTransform();
        states.texture = my_texture;
        target.draw(my_vertices, 4, sf::Quads, states);
    }
}
   void Layer::linkToPlayer(state::Player* p)  {
           this->player_observed=p;
           cout<<"Player " +this->player_observed->getName() +" linked To Layer "<<endl;
                    }
}
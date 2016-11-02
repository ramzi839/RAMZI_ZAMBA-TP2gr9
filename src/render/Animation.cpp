/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Animation.h"
namespace render {
Animation::Animation() : my_texture(NULL)
{

}

void Animation::addFrame(sf::IntRect rect)
{
    my_frames.push_back(rect);
}

void Animation::setSprite(const sf::Texture& texture)
{
    my_texture = &texture;
}

const sf::Texture* Animation::getSprite() const
{
    return my_texture;
}

std::size_t Animation::getSize() const
{
    return my_frames.size();
}

const sf::IntRect& Animation::getFrame(std::size_t i) const
{
    return my_frames[i];
}

}
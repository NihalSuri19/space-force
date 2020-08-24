#include "cannon.h"

Cannon::Cannon()
{
    movement_speed_ = 250.0f;
    loadTexture();
    initializeSprite();

}

void Cannon::movement(const float &dirX, const float &dirY,sf::Time &elapsed)
{
    move(movement_speed_*elapsed.asSeconds()*dirX,movement_speed_*elapsed.asSeconds()*dirY);

}

void Cannon::loadTexture()
{
    if(!c_texture_.loadFromFile("Textures/cannon.png"))
    {
        std::cout << "Texture Failed cannon" << std::endl;
    }

}

void Cannon::initializeSprite()
{
    setTexture(c_texture_);
    setTextureRect(sf::IntRect(94,102,108,131));
    setScale(0.6f,0.6f);
    setPosition(0,0);
    setPosition(300,600 - getGlobalBounds().height);


}

void Cannon::explosion()
{
    if(!c_texture_.loadFromFile("Textures/explosion.png"))
    {
        std::cout << "NO EXPLOSION" << std::endl;
    }
    setTexture(c_texture_);
    setScale(5.0f,5.0f);
}






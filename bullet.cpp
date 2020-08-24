#include "bullet.h"

Bullet::Bullet()
{
    max_speed = 15.0f;
    currVelocity = sf::Vector2f(0.0f,0.0f);
    loadTexture();
    initializeBullet();

}

void Bullet::loadTexture()
{
    if(!b_text_.loadFromFile("Textures/bullet.png"))
    {
        std::cout << "No load from file" << std::endl;
    }
}

void Bullet::initializeBullet()
{
    setTexture(b_text_);
    setTextureRect(sf::IntRect(12,4,16,61));
    setScale(0.5f,0.5f);
    setPosition(-30,-30);

}




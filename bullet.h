#ifndef BULLET_H
#define BULLET_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <memory>
#include <map>



class Bullet : public sf::Sprite
{
public:
     Bullet();
     virtual ~Bullet() = default;
     sf::Vector2f currVelocity;
     float max_speed;

private:
    sf::Texture b_text_;



    //private functions
    void loadTexture();
    void initializeBullet();

};

#endif // BULLET_H

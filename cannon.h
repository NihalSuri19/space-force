#ifndef CANNON_H
#define CANNON_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <memory>
#include <map>


class Cannon : public sf::Sprite
{
public:
    Cannon();
    virtual~Cannon() = default;

    void render(sf::RenderTarget &target);
    void movement(const float &dirX, const float &dirY, sf::Time &elapsed);
    void explosion();



private:
    float movement_speed_;
    sf::Texture c_texture_;
    void loadTexture();
    void initializeSprite();


};

#endif // CANNON_H

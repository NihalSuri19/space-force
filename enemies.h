#ifndef ENEMIES_H
#define ENEMIES_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <memory>
#include <map>
#include<cmath>
#include"bullet.h"
#include"cannon.h"



class Enemy : public sf::Sprite
{
public:
    virtual ~Enemy() = default;
    void set_texture(const std::string &path);
    void window_move(sf::Time &elasped);


protected:
    float y_speed_ = 150.0f;
    float x_speed_ = 50.0f;
    sf:: Texture e_text_;
};

class PinkEnemy : public Enemy
{
public:
    PinkEnemy()
    {
        set_texture("Textures/pink_enemy.png");
        setTextureRect(sf::IntRect(39,40,21,20));
        setScale(1.5f,1.5f);
        setPosition(sf::Vector2f(rand()%800,rand()%600));

    }

};

class OctEnemy : public Enemy
{
public:
    OctEnemy()
    {
        set_texture("Textures/octagon_enemy.png");
        setTextureRect(sf::IntRect(21,23,51,39));
        setScale(1.5f,1.5f);
        setPosition(sf::Vector2f(rand()%800,rand()%600));
    }

};

class PentEnemy : public Enemy
{
public:
    PentEnemy()
    {
        set_texture("Textures/pentagon_enemy.png");
        setTextureRect(sf::IntRect(26,15,36,24));
        setScale(1.8f,1.8f);
        setPosition(sf::Vector2f(rand()%800,rand()%600));
    }

};



class SpecialEnemy : public Enemy
{
public:
    SpecialEnemy()
    {
        set_texture("Textures/pokeball.png");
        setTextureRect(sf::IntRect(38,38,23,24));
        y_speed_ = 300.0f;
        x_speed_ = 100.0f;
        //setScale(0.7f,0.7f);
    }


};





//class MonsterEnemy : public Enemy
//{
//public:
//    MonsterEnemy() {

//    }

//    virtual void do_sth_on_hit()
//    {
//        std::cout << "MONSTER" << std::endl;
//    }
//};

//class PlaneEnemy : public Enemy
//{
//public:
//    PlaneEnemy() {

//    }

//    virtual void do_sth_on_hit()
//    {
//         std::cout << "PLANE" << std::endl;
//    }
//};








#endif // ENEMIES_H









//public:
//    Enemies();

//    int spawnCounter = 30;

//    void movement();
//    void setSpeed(sf::Vector2f& speed);
//    void rotate(sf::Time &elapsed);
//    void move(sf::Time &elapsed);



//private:
//    sf::Vector2f speed_;
//    float angular_velocity_ = 50;
//    sf::RectangleShape rect_;
//    sf::CircleShape circ_;




//class RectEnemies : public sf::RectangleShape
//{
//public:
//    RectEnemies();
//    virtual ~RectEnemies() = default;
//private:
//    void initializeRect();
//};


//class CircleEnemies : public sf::CircleShape
//{
//public:
//    CircleEnemies();
//    virtual ~CircleEnemies() = default;
//private:
//    void initializeCirc();


//};

//class Enemies
//{
//public:
//    void movement(sf::Time &elapsed, std::vector<std::unique_ptr<sf::Drawable>> &enemies);
//    virtual ~Enemies() = default;

////protected:
////    Enemies(const sf::Vector2f &speed, const sf::Vector3i &color,
////            const float &size_x, const float &size_y)
////        :speed_(speed),color_(color),size_x_(size_x),size_y_(size_y){}

////    sf::Vector2f speed_;
////    sf::Vector3i color_;
////    float size_x_;
////    float size_y_;

//};


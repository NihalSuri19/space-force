#ifndef GAME_H
#define GAME_H

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
#include<string>
#include<cstring>
#include<sstream>
#include "cannon.h"
#include "bullet.h"
#include "enemies.h"

class Game : public sf::Sprite
{
public:
    Game();
    virtual~Game() = default;

    void run();
    void update(sf::Time &elapsed);
    void updateInput(sf::Time &elapsed);
    void render();
    void menuRender();
    void updatePollEvents();
    void menuupdatePollEvents();
    void enemy_movement(std::vector<std::unique_ptr<sf::Drawable>> &enemies);
    void collisionMech(std::vector<std::unique_ptr<Enemy>>&enemies,std::vector<std::unique_ptr<Bullet>>&bullets);

    int hp = 15;
    int score = 0;

private:
    //window
    std::unique_ptr<sf::RenderWindow>window_;

    //music
    sf::Music game_music;
    sf::SoundBuffer buffer;
    sf::Sound shooting;


    //special abilities
    bool godMode_ = false;
    sf::Time shootTime = sf::seconds(5.0f);

    //enemy lives
    int octLives = 9;
    int pentLives = 6;


    //parts of background
    sf::Texture t_back_;
    sf::Sprite s_back_;

    //enemies
    std::vector<std::unique_ptr<Enemy>>enemies_;

    //parts of player
    sf::RectangleShape hpBar;
    std::unique_ptr<Cannon>cannon_;
    std::unique_ptr<Bullet>b1_;
    std::vector<std::unique_ptr<Bullet>>bullets_;


    //Vectors for 360 Shooting
    sf::Vector2f playerCenter_;
    sf::Vector2f mousePosWindow_;
    sf::Vector2f aimDir_;
    sf::Vector2f aimDirNorm_;

    //fonts on main window
    sf::Font font_;
    sf::Text health_;
    sf::Text highscore_;
    sf::Text score_;
    sf::Text godmode_;



    //private functions
    void initializeHealtBar();
    void initializeFonts();
    void initializeWindow();
    void initializeBackground();
    void initializeCannon();
    void initializeVectors();
    void initializeEnemies();
    void initializeMusic();



    //counters for enemies
    int spawnCounter = 40;
    int spawnCounterOct = 150;
    int spawnCounterPent = 90;





};

#endif // GAME_H

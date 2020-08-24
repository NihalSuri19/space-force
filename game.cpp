#include "game.h"

void Game::initializeBackground()
{
    if(!t_back_.loadFromFile("Textures/space.png"))
    {
        std::cout << "Back no load" << std::endl;
    }
    t_back_.setRepeated(true);

    s_back_.setTexture(t_back_);
    //s_back_.setScale(0.3f,0.3f);
    s_back_.setTextureRect(sf::IntRect(0,0,static_cast<int>(window_->getSize().x),static_cast<int>(window_->getSize().y)));


}
void Game::initializeWindow()
{
    window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(800,600), "First Game", sf::Style::Close | sf::Style::Titlebar);
    window_ ->setFramerateLimit(60);
    window_ ->setVerticalSyncEnabled(false);

}

void Game::initializeCannon()
{
    cannon_ = std::make_unique<Cannon>();

}

void Game::initializeVectors()
{
    playerCenter_ = sf::Vector2f((cannon_->getGlobalBounds().left+(cannon_->getGlobalBounds().width/2)),cannon_->getGlobalBounds().top);
    mousePosWindow_ = sf::Vector2f(sf::Mouse::getPosition(*window_));
    aimDir_ = mousePosWindow_ - playerCenter_;
    aimDirNorm_ = aimDir_/(static_cast<float>(sqrt(pow(aimDir_.x, 2) + pow(aimDir_.y, 2))));
}

void Game::initializeHealtBar()
{
    hpBar.setFillColor(sf::Color::Red);
    hpBar.setSize(sf::Vector2f((float)hp*20.f,20.f));
    hpBar.setOutlineThickness(5.0f);
    hpBar.setOutlineColor(sf::Color::White);
    hpBar.setPosition(200.0f,10.0f);

}

void Game::initializeFonts()
{
    if(!font_.loadFromFile("fonts/Prisma.ttf"))
    {
        std::cout << "Load failure font" << std::endl;
    }
    health_.setFont(font_);
    health_.setString("HP BAR");
    health_.setFillColor(sf::Color::Green);
    health_.setLetterSpacing(3);
    health_.setCharacterSize(40);
    health_.setPosition(20.0f,0.0f);

    highscore_.setFont(font_);
    highscore_.setString("SCORE:");
    highscore_.setFillColor(sf::Color::White);
    highscore_.setLetterSpacing(3);
    highscore_.setCharacterSize(40);
    highscore_.setPosition(520.0f,0.0f);

    godmode_.setFont(font_);
    godmode_.setString("GODMODE!");
    godmode_.setFillColor(sf::Color::Yellow);
    godmode_.setLetterSpacing(3);
    godmode_.setCharacterSize(70);
    godmode_.setPosition(180.0f,200.0f);



}

void Game::initializeMusic()
{
    if(!game_music.openFromFile("OutThere.ogg"))
    {
        std::cout << "NO MUSIC PLAY" << std::endl;
    }

    game_music.play();

    if(!buffer.loadFromFile("laser.wav"))
    {
        std::cout << "NO SOUND EFFECT PLAY" << std::endl;
    }

    shooting.setBuffer(buffer);
}


Game::Game()
{
    initializeWindow();
    initializeFonts();
    initializeMusic();
    initializeCannon();
    initializeBackground();
    initializeHealtBar();


}

void Game::updatePollEvents()
{
    sf::Event events;
    while (window_ ->pollEvent(events))
    {
        if(events.Event::type == sf::Event::Closed || (events.Event::KeyPressed && events.key.code == sf::Keyboard::Escape))
        {
            window_->close();
        }

    }

}

void Game::collisionMech(std::vector<std::unique_ptr<Enemy>>&enemies,std::vector<std::unique_ptr<Bullet>>&bullets)
{
    for(size_t i = 0; i<bullets.size(); i++)
    {
        bullets[i]->move(bullets[i]->currVelocity);

        //out of bounds
        if( bullets[i]->getPosition().x <0 || bullets[i]->getPosition().x>window_->getSize().x
                ||bullets[i]->getPosition().y <0 || bullets[i]->getPosition().y>window_->getSize().y)
        {
            bullets.erase(bullets.begin() + i);

        }
        else
        {
            //enemy collision
            for(int k =0; k<enemies.size(); k++)
            {
                if(bullets[i]->getGlobalBounds().intersects(dynamic_cast<sf::Sprite *>(enemies[k].get())->getGlobalBounds()))
                {
                    bullets.erase(bullets.begin() + i);
                    //enemies.erase(enemies.begin() + k);
                    if(enemies[k]->getGlobalBounds().width == 76.5)
                    {
                        octLives--;
                        if(octLives == 0)
                        {
                            enemies.erase(enemies.begin() +k);
                            score  += 8;
                        }
                    }
//                    else if(107<=enemies[k]->getGlobalBounds().width +enemies[k]->getGlobalBounds().height>=108)
//                     {
//                       if(pentLives == 0)
//                        {
//                          enemies.erase(enemies.begin() +k);
//                          score += 5;
//                        }
//                        pentLives--;
//                    }
                    else
                    {
                        enemies.erase(enemies.begin() + k);
                        score += 1;
                    }

                    break;
                }




            }

        }
    }
    std::stringstream ss;
    ss << score;
    std::string str = ss.str();
    score_.setFont(font_);
    score_.setString(str);
    score_.setFillColor(sf::Color::Red);
    score_.setLetterSpacing(3);
    score_.setCharacterSize(40);
    score_.setPosition(700.0f,0.0f);

}


void Game::updateInput(sf::Time &elapsed)
{
    sf::Clock clockGod;
    //hero movement
    initializeVectors();
    //std::cout << aimDir_.x << " " << aimDir_.y << " " << std::endl;
   // std::cout << aimDirNorm_.x << " " << aimDirNorm_.y << std::endl;
    sf::FloatRect bounds = cannon_->getGlobalBounds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (bounds.left>-10))
    {
        godMode_ = false;
        cannon_->movement(-1.0f,0.0f,elapsed);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&(bounds.left + bounds.width<800))
    {
        godMode_ = false;
        cannon_->movement(1.0f,0.0f,elapsed);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&(bounds.top>-10))
    {
        godMode_ = false;
        cannon_->movement(0.0f,-1.0f,elapsed);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&(bounds.top+bounds.height<600))
    {
        godMode_ = false;
        cannon_->movement(0.0f,1.0f,elapsed);

    }

    //enemies generation

    if(spawnCounter < 30)
    {
        spawnCounter++;
    }
    if(spawnCounterOct < 150)
    {
        spawnCounterOct++;
    }
    if(spawnCounterPent < 90)
    {
        spawnCounterPent++;
    }
    if(spawnCounter>=30)
    {
        enemies_.emplace_back(std::make_unique<PinkEnemy>());
        spawnCounter = 0;
    }
    if(spawnCounterOct>=150)
    {
          enemies_.emplace_back(std::make_unique<OctEnemy>());
          spawnCounterOct = 0;
    }
    if(spawnCounterPent>=90)
    {
        enemies_.emplace_back(std::make_unique<PentEnemy>());
        spawnCounterPent = 0;

    }


    //enemy movement
    for(auto &e: enemies_)
    {
        e->window_move(elapsed);
    }

    //godmode
    sf::Time elapsedShoot;
    elapsedShoot = clockGod.getElapsedTime();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        godMode_ = true;


    }


    //godMode_ = false;




    //bullet generation
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        shooting.play();

        b1_ = std::make_unique<Bullet>();

        b1_->setPosition((cannon_->getGlobalBounds().left+(cannon_->getGlobalBounds().width/2)),cannon_->getGlobalBounds().top-25);
        b1_->currVelocity = aimDirNorm_*b1_->max_speed;
        bullets_.emplace_back(std::move(b1_));
        if(!godMode_ && elapsedShoot<shootTime)
        {
            if(bullets_.size() == 13)
            {
                bullets_.clear();

            }
        }
    }

    //bullet collision mechanisim
    collisionMech(enemies_,bullets_);



    //player collison
    for(int i = 0; i<enemies_.size(); i++)
    {
       if(dynamic_cast<sf::Sprite *>(cannon_.get())->getGlobalBounds().intersects(dynamic_cast<sf::Sprite *>(enemies_[i].get())->getGlobalBounds()))
         {
           hp--;
           enemies_.erase(enemies_.begin() + i);
         }
       if(hp == 0)
       {
           cannon_->explosion();

       }
    }

    hpBar.setSize(sf::Vector2f(static_cast<float>(hp*20.f),20.f));


}


void Game::update(sf::Time &elapsed)
{
    updatePollEvents();
    updateInput(elapsed);

}

void Game::render()
{


    window_ ->clear();


    window_->draw(s_back_);
    window_->draw(health_);
    //fonts drawing
    window_->draw(highscore_);
    window_->draw(score_);
    if(godMode_)
    {
        window_->draw(godmode_);
    }


    for(const auto &e : enemies_)
    {
        window_->draw(*e);
    }


    window_->draw(*cannon_);

    for(const auto &b : bullets_)
    {
        window_->draw(*b);
    }

    window_->draw(hpBar);


    window_ ->display();

}

void Game::run()
{
    sf::Clock clock;
    while(window_->isOpen())
    {
        sf::Time time = clock.restart();
        update(time);
        render();
        if(hp <-3) break;
        if(score == 300) break;
    }

}






























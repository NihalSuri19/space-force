#include "enemies.h"

void Enemy::set_texture(const std::string &path)
{
    if(!e_text_.loadFromFile(path))
    {
        std::cout << "No load enemy" << std::endl;
    }

    setTexture(e_text_);


}

void Enemy::window_move(sf::Time &elasped)
{
    move(x_speed_*elasped.asSeconds(),y_speed_*elasped.asSeconds());
    if(getGlobalBounds().top<0)
    {
        y_speed_ = abs(y_speed_);

    }
    if(getGlobalBounds().top + getGlobalBounds().height>600)
    {
       y_speed_ = -abs(y_speed_);
    }
    if(getGlobalBounds().left<0)
    {
        x_speed_ = abs(x_speed_);
    }
    if(getGlobalBounds().left + getGlobalBounds().width>800)
    {
        x_speed_ = -abs(x_speed_);

    }

}




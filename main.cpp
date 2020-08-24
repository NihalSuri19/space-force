#include "game.h"


int main()
{

    sf::RenderWindow menu(sf::VideoMode(800, 600), "MENU");
    bool openRules = false;
    bool openGame = true;
    bool x_bound_play;
    bool y_bound_play;
    bool x_bound_rules;
    bool y_bound_rules;
    bool x_bound_exit;
    bool y_bound_exit;
    sf::Texture back_ground;
    sf::Sprite back_ground_s;
    sf::Text play;
    sf::Text spaceForce;
    sf::Text howTo;
    sf::Text exit;
    sf::Font font;

    if(!font.loadFromFile("fonts/Prisma.ttf"))
    {
        std::cout << "Load failure font" << std::endl;
    }
    if(!back_ground.loadFromFile("Textures/background_1.png"))
    {
        std::cout << "NO LOAD SPACE BACK" << std::endl;
    }

    back_ground.setRepeated(true);

    back_ground_s.setTexture(back_ground);
    back_ground_s.setTextureRect(sf::IntRect(0,0,static_cast<int>(menu.getSize().x),static_cast<int>(menu.getSize().y)));

    play.setFont(font);
    play.setString("PLAY");
    play.setFillColor(sf::Color::Green);
    play.setLetterSpacing(3);
    play.setCharacterSize(60);
    play.setPosition(300,180);

    howTo.setFont(font);
    howTo.setString("RULES");
    howTo.setFillColor(sf::Color::Red);
    howTo.setLetterSpacing(3);
    howTo.setCharacterSize(60);
    howTo.setPosition(300,270);

    spaceForce.setFont(font);
    spaceForce.setString("SPACE FORCE");
    spaceForce.setFillColor(sf::Color::Magenta);
    spaceForce.setLetterSpacing(3);
    spaceForce.setCharacterSize(90);
    spaceForce.setPosition(100,30);

    exit.setFont(font);
    exit.setString("EXIT");
    exit.setFillColor(sf::Color::Cyan);
    exit.setLetterSpacing(3);
    exit.setCharacterSize(60);
    exit.setPosition(300,350);


    while (menu.isOpen())
    {
        x_bound_play = sf::Mouse::getPosition(menu).x > play.getGlobalBounds().left &&
                       sf::Mouse::getPosition(menu).x < play.getGlobalBounds().left + play.getGlobalBounds().width;
        y_bound_play = sf::Mouse::getPosition(menu).y > play.getGlobalBounds().top &&
                       sf::Mouse::getPosition(menu).y < play.getGlobalBounds().top + play.getGlobalBounds().height;

        x_bound_rules = sf::Mouse::getPosition(menu).x > howTo.getGlobalBounds().left &&
                       sf::Mouse::getPosition(menu).x < howTo.getGlobalBounds().left + howTo.getGlobalBounds().width;
        y_bound_rules = sf::Mouse::getPosition(menu).y > howTo.getGlobalBounds().top &&
                       sf::Mouse::getPosition(menu).y < howTo.getGlobalBounds().top + howTo.getGlobalBounds().height;

        x_bound_exit = sf::Mouse::getPosition(menu).x > exit.getGlobalBounds().left &&
                       sf::Mouse::getPosition(menu).x < exit.getGlobalBounds().left + exit.getGlobalBounds().width;
        y_bound_exit = sf::Mouse::getPosition(menu).y > exit.getGlobalBounds().top &&
                       sf::Mouse::getPosition(menu).y < exit.getGlobalBounds().top + exit.getGlobalBounds().height;

        sf::Event event;
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                menu.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(x_bound_play && y_bound_play)
            {
                menu.close();
            }

            if(x_bound_rules && y_bound_rules)
            {
                openRules = true;
            }
            if(x_bound_exit && y_bound_exit)
            {
                openGame = false;
                menu.close();
            }
        }


         menu.clear(sf::Color::Black);
         menu.draw(back_ground_s);
         menu.draw(spaceForce);
         menu.draw(play);
         menu.draw(howTo);
         menu.draw(exit);


         menu.display();
    }


    Game game;
    if(!menu.isOpen() && openGame)
    {
    game.run();
    }

    //endgame window
    if(game.hp<=0)
    {
    sf::RenderWindow endgame(sf::VideoMode(800, 600), "GAME OVER");
    sf::Text end;

    end.setFont(font);
    end.setString("GAME OVER :(");
    end.setFillColor(sf::Color::White);
    end.setLetterSpacing(3);
    end.setCharacterSize(60);
    end.setPosition(120,250);


    while (endgame.isOpen())
    {
        sf::Event event;
        x_bound_exit = sf::Mouse::getPosition(endgame).x > exit.getGlobalBounds().left &&
                       sf::Mouse::getPosition(endgame).x < exit.getGlobalBounds().left + exit.getGlobalBounds().width;
        y_bound_exit = sf::Mouse::getPosition(endgame).y > exit.getGlobalBounds().top &&
                       sf::Mouse::getPosition(endgame).y < exit.getGlobalBounds().top + exit.getGlobalBounds().height;
        while (endgame.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                endgame.close();

            if(event.Event::type == sf::Event::Closed || (event.Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                endgame.close();
            }
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            if(x_bound_exit && y_bound_exit)
            {

                endgame.close();
            }
        }

         endgame.clear(sf::Color::Black);
         endgame.draw(end);
         endgame.draw(exit);

         endgame.display();
    }
    }

    if(openRules)
    {

    sf::RenderWindow options(sf::VideoMode(800, 600), "RULES");
    sf::Text rule_1_move;
    sf::Text rule_2_shoot;
    sf::Text rule_3_god;
    sf::Text rule_4_mouse;

    rule_1_move.setFont(font);
    rule_1_move.setString("PRESS WSAD TO MOVE PLAYER");
    rule_1_move.setFillColor(sf::Color::White);
    rule_1_move.setLetterSpacing(3);
    rule_1_move.setCharacterSize(60);
    rule_1_move.setPosition(120,250);

    while (options.isOpen())
    {
        sf::Event event;
        x_bound_exit = sf::Mouse::getPosition(options).x > exit.getGlobalBounds().left &&
                       sf::Mouse::getPosition(options).x < exit.getGlobalBounds().left + exit.getGlobalBounds().width;
        y_bound_exit = sf::Mouse::getPosition(options).y > exit.getGlobalBounds().top &&
                       sf::Mouse::getPosition(options).y < exit.getGlobalBounds().top + exit.getGlobalBounds().height;
        while (options.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                options.close();

            if(event.Event::type == sf::Event::Closed || (event.Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                options.close();
            }
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            if(x_bound_exit && y_bound_exit)
            {

                options.close();
            }
        }


        options.clear(sf::Color::Black);
        options.draw(exit);
        options.draw(rule_1_move);

        options.display();
    }
    }





    //winning window
    sf::RenderWindow wingame(sf::VideoMode(800, 600), "WIN");
    sf::Text win;

    sf::Texture t_soldier;
    sf::Texture t_back;
    sf::Sprite s_back;
    sf::Sprite s_soldier;

    if(!t_soldier.loadFromFile("Textures/soldier.png"))
    {
        std::cout << "NO LOAD SOLDIER" << std::endl;

    }

    if(!t_back.loadFromFile("Textures/background_1.png"))
    {
        std::cout << "NO LOAD BACK" << std::endl;

    }

    s_soldier.setTexture(t_soldier);
    s_soldier.setScale(4.5f,4.5f);
    s_soldier.setPosition(250,100);

    t_back.setRepeated(true);

    s_back.setTexture(t_back);
    s_back.setTextureRect(sf::IntRect(0,0,static_cast<int>(wingame.getSize().x),static_cast<int>(wingame.getSize().y)));

    win.setFont(font);
    win.setString("COMMANDER! YOU HAVE CONQUERED SPACE FORCE!");
    win.setFillColor(sf::Color::Red);
    win.setLetterSpacing(2);
    win.setCharacterSize(30);
    win.setPosition(10,50);


    if(game.score == 300)
    {


    while (wingame.isOpen())
    {
        sf::Event event;
        x_bound_exit = sf::Mouse::getPosition(wingame).x > exit.getGlobalBounds().left &&
                       sf::Mouse::getPosition(wingame).x < exit.getGlobalBounds().left + exit.getGlobalBounds().width;
        y_bound_exit = sf::Mouse::getPosition(wingame).y > exit.getGlobalBounds().top &&
                       sf::Mouse::getPosition(wingame).y < exit.getGlobalBounds().top + exit.getGlobalBounds().height;
        while (wingame.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                wingame.close();

            if(event.Event::type == sf::Event::Closed || (event.Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                wingame.close();
            }

        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            if(x_bound_exit && y_bound_exit)
            {

                wingame.close();
            }
        }



         wingame.clear(sf::Color::Black);
         wingame.draw(s_back);
         wingame.draw(win);
         wingame.draw(exit);
         wingame.draw(s_soldier);

         wingame.display();
    }
    }

    //    rules window
}

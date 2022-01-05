#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"


#include<iostream>
#include<fstream>

int main()
{
   
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::Texture texture;
    if (!texture.loadFromFile("Data/Textures/Retro Mario 2.png"))
        return EXIT_FAILURE;

    sf::Font font;
    if(!font.loadFromFile(("Data/Fonts/arial.ttf")))
        return EXIT_FAILURE;

    sf::Text text;
    text.setPosition(300, 300);

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Hello world");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);
    text.setOutlineColor(sf::Color::Blue);
    text.setOutlineThickness(1);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::Sprite mario_sprite(texture);
    
        

    std::vector<sf::RectangleShape> platforms;

    sf::RectangleShape platform1;
    platform1.setOrigin(0, 0);
    platform1.setPosition(225, 400);
    platform1.setSize(sf::Vector2f(100, 20));
    platform1.setOutlineColor(sf::Color::Black);
    platform1.setFillColor(sf::Color::Blue);

    platforms.push_back(platform1);

    sf::RectangleShape platform2;
    platform2.setOrigin(0, 0);
    platform2.setPosition(400, 300);
    platform2.setSize(sf::Vector2f(100, 20));
    platform2.setOutlineColor(sf::Color::Black);
    platform2.setFillColor(sf::Color::Blue);

    platforms.push_back(platform2);

    mario_sprite.setPosition(210, 271);
    
   
    
    //Game Loop
    while (window.isOpen())
    {

        /*sf::Transform mario_hitbox(mario_sprite.getPosition().x, mario_sprite.getPosition().y, texture.getSize().x, texture.getSize().y);
        std::cout << "mario sprites position" << std::endl;
        std::cout << "x: " << mario_sprite.getPosition().x << std::endl;
        std::cout << "y: " << mario_sprite.getPosition().y << std::endl << std::endl;

        mario_sprite.getTransform().transformRect(mario_hitbox).

        std::cout << "mario hitbox position" << std::endl;
        std::cout << "x: " << mario_hitbox.left << std::endl;
        std::cout << "y: " << mario_hitbox.top << std::endl << std::endl;
        */

        //after rotation
        
        //Events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Green);

        for (sf::RectangleShape platform : platforms)
        {
            window.draw(platform);
        }
        
        
        window.draw(mario_sprite);
        window.draw(text);
        window.display();
    }
    
    return EXIT_SUCCESS;
}
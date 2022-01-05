

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "The Game");
   
    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    //Flag circle
    sf::CircleShape circle(200, 800);
    circle.setPosition(300, 300);
    circle.setFillColor(sf::Color::Red);

    //Trapezes
   /* sf::ConvexShape convex1;
    convex1.setPointCount(4);
    convex1.setPoint(0, sf::Vector2f(100,0));
    convex1.setPoint(1, sf::Vector2f(0, 100));
    convex1.setPoint(2, sf::Vector2f(200, 100));
    convex1.setFillColor(sf::Color::Black);
    */

    while (window.isOpen())
    {
        
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;

        while (window.pollEvent(event))
        {

            switch (event.type)
            {

            // évènement "fermeture demandée" : on ferme la fenêtre
            case sf::Event::Closed:
                window.close();
                break;

            default:
                break;
            }

        }

        // Graphical Region
        window.clear(sf::Color::White);

        window.draw(circle);
        
        

        //Window Display
        window.display();

    }



}

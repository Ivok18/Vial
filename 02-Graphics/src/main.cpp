// SAE-01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>


#include "SFML/OpenGL.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");
    sf::Texture wall;

    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    // Loading a file as texture
    wall.loadFromFile("data/sprites/wall.jpg");

    // Using a sprite
    // https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
    sf::Sprite sprite;
    sprite.setTexture(wall);
    sprite.setOrigin(wall.getSize().x / 2.0f, wall.getSize().y / 2.0f);
    const auto center = window.getSize();
    sprite.setPosition(center.x / 2.0f, center.y / 2.0f);

    // Define a Shape
    // https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Shape.php
    sf::CircleShape shape(50.f);
    // set the shape color to green
    shape.setFillColor(sf::Color(150, 50, 250, 100));
    // set a 10-pixel wide orange outline
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250, 150, 100));
    // define a position
    shape.setOrigin(shape.getRadius() / 2.0f, shape.getRadius() / 2.0f);
    shape.setPosition(center.x / 2.0f, center.y / 2.0f);

    // Redefine Size
    shape.setRadius(40.0f);

    while (window.isOpen())
    {

        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {

            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();

        }

        // Here we draw
        // Draw the sprite
        window.draw(sprite);

        // Draw the shape
        window.draw(shape);

        // effacement les tampons de couleur/profondeur
        window.display();

    }

    return EXIT_SUCCESS;
}

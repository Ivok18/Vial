// SAE-01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>


#include "SFML/OpenGL.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");
    
    // Basic Setup of the window
    // Vertical sync, framerate
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        // Clear white
        //window.clear(sf::Color(255, 255, 255));

        // Clear with a color Const
        //sf::Color yellow = sf::Color::Yellow;
        //window.clear(yellow);

        // Clear with a custom color
        sf::Color myColor(100, 60, 75, 100);
        window.clear(myColor);

        
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {

            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();

        }

        // effacement les tampons de couleur/profondeur
        window.display();

    }

    return EXIT_SUCCESS;
}

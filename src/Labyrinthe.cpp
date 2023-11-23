// Labyrinthe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "Case.h"
#include "Generate.h"
#include "Solver.h"

int main()
{
    // create a window
    sf::RenderWindow window(sf::VideoMode(600, 600), "Labyrinthe");

    // size of the case
    double size(4.0);

    // the list of the case
    std::vector<std::vector<Case>> listCase;

    // the way to exit
    std::vector<Case> solveCase;

    // generate a labyrinthe
    listCase = generateList(size, window.getSize().x, window.getSize().x);
    generateLaby(&listCase);

    // get the distance from the last case
    getDist(&listCase);

    // get the way to exit
    solveCase = solve(listCase);

    // main loop
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color(50, 50, 50));

        // draw the case
        for (int i = 0; i < listCase.size(); i++)
        {
            for (int j = 0; j < listCase[i].size(); j++)
            {
                window.draw(listCase[i][j]._appearance);
            }
        }

        for (int i = 0; i < solveCase.size(); i++)
        {
            solveCase[i]._appearance.setFillColor(sf::Color(0, 255, 255));
            window.draw(solveCase[i]._appearance);
        }

        window.display();
    }

    return 0;
}

#ifndef JEU_H
#define JEU_H

#include "Snake.h"
#include "Fruit.h"
#include <SFML/Graphics.hpp>

class Jeu {
public:
    void lancer();

private:
    Snake snake;
    Fruit fruit;
    void afficher(sf::RenderWindow &window);
    void gererEntrée();
};

#endif

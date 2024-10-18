#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

class Snake {
public:
    void initialiser();
    void afficher(sf::RenderWindow &window);
    void changerDirection(char direction);
    bool avancer(const class Fruit &fruit);
    const std::vector<std::pair<int, int>>& getCorps() const;

private:
    std::vector<std::pair<int, int>> corps;
    char direction;
    void mettreAJourPosition();
    void verifierCollision();
};

#endif

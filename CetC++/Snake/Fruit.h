#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

class Fruit {
public:
    void generer(const std::vector<std::pair<int, int>>& corps);
    void afficher(sf::RenderWindow &window) const;
    const std::pair<int, int>& getPosition() const;

private:
    std::pair<int, int> position;
};

#endif

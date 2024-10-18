#include "Fruit.h"

void Fruit::generer(const std::vector<std::pair<int, int>>& corps) {
    do {
        position = {rand() % 30, rand() % 40};
    } while (std::find(corps.begin(), corps.end(), position) != corps.end());
}

void Fruit::afficher(sf::RenderWindow &window) const {
    sf::RectangleShape rectangle(sf::Vector2f(20, 20));
    rectangle.setPosition(position.second * 20, position.first * 20);
    rectangle.setFillColor(sf::Color::Red);
    window.draw(rectangle);
}

const std::pair<int, int>& Fruit::getPosition() const {
    return position;
}

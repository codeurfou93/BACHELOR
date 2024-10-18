#include "Snake.h"
#include "Fruit.h"

void Snake::initialiser() {
    corps.clear();
    corps.push_back({5, 5});
    direction = 'd';
}

void Snake::afficher(sf::RenderWindow &window) {
    for (const auto& segment : corps) {
        sf::RectangleShape rectangle(sf::Vector2f(20, 20));
        rectangle.setPosition(segment.second * 20, segment.first * 20);
        rectangle.setFillColor(sf::Color::Green);
        window.draw(rectangle);
    }
}

void Snake::changerDirection(char nouvelleDirection) {
    if ((nouvelleDirection == 'w' && direction != 's') ||
        (nouvelleDirection == 's' && direction != 'w') ||
        (nouvelleDirection == 'a' && direction != 'd') ||
        (nouvelleDirection == 'd' && direction != 'a')) {
        direction = nouvelleDirection;
    }
}

bool Snake::avancer(const Fruit &fruit) {
    mettreAJourPosition();
    verifierCollision();
    if (corps.front() == fruit.getPosition()) {
        corps.push_back(corps.back());
        return true;
    }
    return false;
}

const std::vector<std::pair<int, int>>& Snake::getCorps() const {
    return corps;
}

void Snake::mettreAJourPosition() {
    std::pair<int, int> nouvellePosition = corps.front();
    switch (direction) {
        case 'w': nouvellePosition.first--; break;
        case 's': nouvellePosition.first++; break;
        case 'a': nouvellePosition.second--; break;
        case 'd': nouvellePosition.second++; break;
    }
    corps.insert(corps.begin(), nouvellePosition);
    corps.pop_back();
}

void Snake::verifierCollision() {
    auto tête = corps.front();
    if (tête.first < 0 || tête.first >= 30 || tête.second < 0 || tête.second >= 40) {
        exit(0);
    }
    for (size_t i = 1; i < corps.size(); i++) {
        if (corps[i] == tête) {
            exit(0);
        }
    }
      }

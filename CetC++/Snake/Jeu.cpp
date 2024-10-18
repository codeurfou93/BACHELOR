#include "Jeu.h"

void Jeu::lancer() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jeu Snake");
    snake.initialiser();
    fruit.generer(snake.getCorps());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        gererEntrée();
        if (!snake.avancer(fruit)) {
            window.close();
        }

        window.clear();
        afficher(window);
        window.display();
    }
}

void Jeu::afficher(sf::RenderWindow &window) {
    snake.afficher(window);
    fruit.afficher(window);
}

void Jeu::gererEntrée() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) snake.changerDirection('w');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) snake.changerDirection('s');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) snake.changerDirection('a');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) snake.changerDirection('d');
}

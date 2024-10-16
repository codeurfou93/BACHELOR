#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    
    
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    
    shape.setPosition(400.f - shape.getRadius(), 300.f - shape.getRadius());

  
    float speed = 5.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            shape.move(-speed, 0); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            shape.move(speed, 0); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            shape.move(0, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            shape.move(0, speed); 
        }

       
        if (shape.getPosition().x < 0)
            shape.setPosition(0, shape.getPosition().y); 
        if (shape.getPosition().x + shape.getRadius() * 2 > window.getSize().x)
            shape.setPosition(window.getSize().x - shape.getRadius() * 2, shape.getPosition().y);  
        if (shape.getPosition().y < 0)
            shape.setPosition(shape.getPosition().x, 0); 
        if (shape.getPosition().y + shape.getRadius() * 2 > window.getSize().y)
            shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getRadius() * 2); 

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "drawable.hpp"

class circle : public drawable{
public:
	circle(sf::Vector2f position, float size, sf::Color color);

	void draw(sf::RenderWindow & window) override;

    void write_to_file() override;

    void moving(sf::RenderWindow & window) override;
private:
	sf::CircleShape ball;
    sf::Vector2f position;
    float size;
    sf::Color color;
};

#endif
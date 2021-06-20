#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "drawable.hpp"

class rectangle : public drawable{
public:
	rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	
	void draw(sf::RenderWindow & window) override;

    void write_to_file() override;

    void moving(sf::RenderWindow & window) override;
private:
	sf::RectangleShape cube;
    sf::Vector2f position;
	sf::Vector2f size;
    sf::Color color;
};

#endif
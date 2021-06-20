#ifndef WALL_HPP
#define WALL_HPP

#include "drawable.hpp"

class wall : public drawable{
public:
	wall( sf::Vector2f position, sf::Vector2f size);

	void draw( sf::RenderWindow & window ) override;

	sf::FloatRect globalBounds() override;

	sf::Vector2f getPos() override;
private:
	sf::RectangleShape border;
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif
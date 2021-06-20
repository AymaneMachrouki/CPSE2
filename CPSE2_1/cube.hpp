#ifndef CUBE_HPP
#define CUBE_HPP

#include "drawable.hpp"

class cube : public drawable{
public:
	cube( sf::Vector2f position, sf::Vector2f size);

	void draw( sf::RenderWindow & window ) override;

	void move( sf::Vector2f delta );

	sf::FloatRect globalBounds() override;

	sf::Vector2f getPos() override;
private:
	sf::RectangleShape square;
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif

#include "cube.hpp"

cube::cube( sf::Vector2f position, sf::Vector2f size ) :
	position{ position },
	size{ size }
{
	square.setFillColor(sf::Color::Red);
	square.setSize(size);
	// square.setOrigin(size.x/2, size.y/2);
}

void cube::draw( sf::RenderWindow & window ){
	square.setPosition(position);
	window.draw(square);
}

void cube::move( sf::Vector2f delta ){
	position += delta;
}

sf::FloatRect cube::globalBounds(){
	return square.getGlobalBounds();
}

sf::Vector2f cube::getPos(){
	return square.getPosition();
}
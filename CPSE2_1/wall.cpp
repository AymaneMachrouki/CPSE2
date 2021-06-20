#include "wall.hpp"

wall::wall( sf::Vector2f position, sf::Vector2f size ) :
	position{ position },
	size{ size }
{
	border.setSize(size);
	border.setPosition(position);
    border.setFillColor(sf::Color::Green);
}

void wall::draw( sf::RenderWindow & window ){
	window.draw(border);
}

sf::FloatRect wall::globalBounds(){
	return border.getGlobalBounds();
}

sf::Vector2f wall::getPos(){
	return border.getPosition();
}

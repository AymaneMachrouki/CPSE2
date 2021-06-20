#include "circle.hpp"

circle::circle(sf::Vector2f position, float size, sf::Color color):
	position{position},
	size{size},
    color{color}
{
	ball.setRadius(size);
    ball.setFillColor(color);
    ball.setPosition(position);
}

void circle::draw(sf::RenderWindow & window){
	ball.setPosition(position);
	window.draw(ball);
}

void circle::write_to_file(){
	std::ofstream txt;
	txt.open("object.txt", std::ios_base::app);
	txt << "circle " << "(" << position.x << ", " << position.y << ") green " << size << "\n";
	txt.close();
}

void circle::moving(sf::RenderWindow & window){
	sf::FloatRect globalBounds = ball.getGlobalBounds();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(globalBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
			position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    		position.x -= size;
    		position.y -= size;
        }
    }
}
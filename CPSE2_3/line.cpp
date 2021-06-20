#include "line.hpp"

line::line(sf::Vector2f position, sf::Vector2f size, sf::Color color):
	position{position},
	size{size},
    color{color}
{
    bar.setPosition(position);
    bar.setSize(size);
    bar.setFillColor(color);
}

void line::draw(sf::RenderWindow & window){
	bar.setPosition(position);
	window.draw(bar);
}

void line::write_to_file(){
	std::ofstream txt;
	txt.open("object.txt", std::ios_base::app);
	txt << "line " << "(" << position.x << ", " << position.y << ") " << "(" << size.x << ", " << size.y << ") red\n";
	txt.close();
}

void line::moving(sf::RenderWindow & window){
    sf::FloatRect globalBounds = bar.getGlobalBounds();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(globalBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
            position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            position.x -= size.x * 0.5;
            position.y -= size.y * 0.5;
        }
    }
}
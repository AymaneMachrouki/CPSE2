#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color):
	position{position},
	size{size},
    color{color}
{
    cube.setPosition(position);
    cube.setSize(size);
    cube.setFillColor(color);
}

void rectangle::draw(sf::RenderWindow & window){
	cube.setPosition(position);
	window.draw(cube);
}

void rectangle::write_to_file(){
	std::ofstream txt;
	txt.open("object.txt", std::ios_base::app);
	txt << "rectangle " << "(" << position.x << ", " << position.y << ") " << "(" << size.x << ", " << size.y << ") blue\n";
	txt.close();
}

void rectangle::moving(sf::RenderWindow & window){
    sf::FloatRect globalBounds = cube.getGlobalBounds();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(globalBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
            position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            position.x -= size.x * 0.5;
            position.y -= size.y * 0.5;
        }
    }
}
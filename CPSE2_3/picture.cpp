#include "picture.hpp"

picture::picture(sf::Vector2f position, sf::Vector2f size, std::string fileName):
	position{position},
	size{size},
    fileName{fileName}
{
    photo.setPosition(position);
    photo.setSize(size);
	texture.loadFromFile(fileName);
    photo.setTexture(&texture);
}

void picture::draw(sf::RenderWindow & window){
	photo.setPosition(position);
	window.draw(photo);
}

void picture::write_to_file(){
	std::ofstream txt;
	txt.open("object.txt", std::ios_base::app);
	txt << "picture " << "(" << position.x << ", " << position.y << ") " << "(" << size.x << ", " << size.y << ") " << fileName << "\n";
	txt.close();
}

void picture::moving(sf::RenderWindow & window){
    sf::FloatRect globalBounds = photo.getGlobalBounds();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(globalBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
            position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            position.x -= size.x * 0.5;
            position.y -= size.y * 0.5;
        }
    }
}
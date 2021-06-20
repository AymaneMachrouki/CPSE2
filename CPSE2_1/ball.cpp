#include "ball.hpp"

ball::ball( sf::Vector2f position, sf::Vector2f speed, float size) :
	position{position},
	speed{speed},
	size{size}
{
	circle.setRadius(size);
	circle.setFillColor(sf::Color::Blue);
	circle.setOrigin(size/2, size/2);
}

void ball::draw( sf::RenderWindow & window ){
	circle.setPosition(position);
	window.draw(circle);
}

void ball::move(){
	position += speed;
}

sf::FloatRect ball::globalBounds(){
	return circle.getGlobalBounds();
}

sf::Vector2f ball::getPos(){
	return circle.getPosition();
}

void ball::bounce(std::vector<drawable*> objects){
	if(globalBounds().intersects(objects[1]->globalBounds())){
		if((circle.getPosition().x < objects[1]->getPos().x || circle.getPosition().x > objects[1]->getPos().x +50.0) && 
			(circle.getPosition().y > objects[1]->getPos().y && circle.getPosition().y < objects[1]->getPos().y +50.0)){
			speed.x *= -1;
		}
		else if((circle.getPosition().y < objects[1]->getPos().y || circle.getPosition().y > objects[1]->getPos().y +50.0) && 
				(circle.getPosition().x > objects[1]->getPos().x && circle.getPosition().x < objects[1]->getPos().x +50.0)){
			speed.y *= -1;
		}
	}
	else if(globalBounds().intersects(objects[2]->globalBounds()) || globalBounds().intersects(objects[3]->globalBounds())){
		speed.x *= -1;
	}
	if(globalBounds().intersects(objects[4]->globalBounds()) || globalBounds().intersects(objects[5]->globalBounds())){
		speed.y *= -1;
	}
}
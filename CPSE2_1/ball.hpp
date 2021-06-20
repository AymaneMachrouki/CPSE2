#ifndef BALL_HPP
#define BALL_HPP

#include "drawable.hpp"

class ball : public drawable{
public:
	ball( sf::Vector2f position, sf::Vector2f speed, float size = 10.0 );

	void draw( sf::RenderWindow & window ) override;

	void move();

	void bounce(std::vector<drawable*> objects);

	sf::FloatRect globalBounds() override;

	sf::Vector2f getPos() override;
private:
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Vector2f speed;
	float size;
};

#endif

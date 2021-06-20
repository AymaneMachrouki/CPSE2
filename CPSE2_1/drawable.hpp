#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>

class drawable{
public:
	virtual void draw( sf::RenderWindow & window ) = 0;

	virtual sf::FloatRect globalBounds();

	virtual sf::Vector2f getPos();
};

#endif
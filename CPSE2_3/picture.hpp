#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "drawable.hpp"

class picture : public drawable{
public:
	picture(sf::Vector2f position, sf::Vector2f size, std::string fileName);
	
	void draw(sf::RenderWindow & window) override;

    void write_to_file() override;

    void moving(sf::RenderWindow & window) override;
private:
    sf::RectangleShape photo;
	sf::Vector2f position;
	sf::Vector2f size;
    std::string fileName;
    sf::Texture texture;
};

#endif
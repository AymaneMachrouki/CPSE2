#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <exception>
#include <fstream>

class drawable{
public:
    virtual void draw( sf::RenderWindow & window) = 0;
    
    virtual void write_to_file() = 0;
    
    virtual void moving(sf::RenderWindow & window) = 0;
};

#endif
#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "circle.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "picture.hpp"
#include "drawable.hpp"
#include "exceptions.hpp"

std::ifstream & operator>>( std::ifstream & input, sf::Vector2f & rhs){
    char c;
    if( ! ( input >> c )){ throw end_of_file(); } 
    if( c != '(' ){ throw invalid_position( c ); } 
    if( ! ( input >> rhs.x )){ throw end_of_file(); }
    if( ! ( input >> c )){ throw end_of_file(); }
    if( ! ( input >> rhs.y )){ throw end_of_file(); }
    if( ! ( input >> c )){ throw end_of_file(); }
    if( c != ')' ){ throw invalid_position( c ); }
    
    return input;
}

std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs ){
    std::string s;
    input >> s;
    const struct { const char * name; sf::Color color; } colors[]{
        {"red",    sf::Color::Red},
        {"green",  sf::Color::Green},
        {"blue",   sf::Color::Blue}
    };
    for( auto const & color : colors ){
        if( color.name == s ){
            rhs = color.color;
            return input;
        }
    }
    if( s == "" ){
        throw end_of_file();
    }
    throw unknown_color( s );
}

drawable* screen_object_read( std::ifstream &input ){
    sf::Vector2f position;
    std::string name;
    sf::Color color;
    std::string fileName;
    sf::Vector2f v2fSize;
    float fSize;
    
    input >> name;

    if(name == "circle"){
        input >> position >> color >> fSize;
        return new circle(position, fSize, color);
    }
    else if(name == "rectangle"){
        input >> position >> v2fSize >> color;
        return new rectangle(position, v2fSize, color);
    }
    else if(name == "picture"){
        input >> position >> v2fSize >> fileName;
        return new picture(position, v2fSize, fileName);
    }
    else if(name == "line"){
        input >> position >> v2fSize >> color;
        return new line(position, v2fSize, color);
    }
    else if (name == "")
        throw end_of_file();

    throw unkown_shape( name );
}

#endif
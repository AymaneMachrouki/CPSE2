#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "drawable.hpp"

class unknown_color : public std::exception {
public: 
    unknown_color( const std::string & name  ):
        s{ std::string( "unknown color [" ) + name + "]" }
    {}
    const char * what() const noexcept override{
        return s.c_str();
    }
private:
    std::string s;
};

class unkown_shape : public std::exception {
public: 
    unkown_shape( const std::string & name  ):
        s{ std::string( "unkown shape [" ) + name + "]" }
    {}
    const char * what() const noexcept override{
        return s.c_str();
    }
private:
    std::string s;
};

class invalid_position : public std::exception {
public: 
    invalid_position( const char & name  ):
        s{ std::string( "invalid position [" ) + name + "]" }
    {}
    const char * what() const noexcept override{
        return s.c_str();
    }
private:
    std::string s;
};

class end_of_file : public std::exception{
public:
    end_of_file():
        s{ std::string( "end of file" ) }
    {}
    const char * what() const noexcept override{
        return s.c_str();
    }
private:
    std::string s;
};

#endif
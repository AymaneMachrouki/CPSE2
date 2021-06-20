#include "ball.hpp"
#include "cube.hpp"
#include "wall.hpp"
#include "drawable.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		bool moving,
		std::function< void() > work
	) :
		condition(
			[ moving ]()->bool { return moving; }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main( int argc, char *argv[] ){
	sf::RenderWindow window{ sf::VideoMode{ 900, 600 }, "Week 1" };
	
	ball my_ball{ sf::Vector2f{ 300.0, 300.0 }, sf::Vector2f{ 2.0, 2.0 }};
	cube my_cube{ sf::Vector2f{ 200.0, 200.0 }, sf::Vector2f{ 50.0, 50.0 }};
	wall left_wall{ sf::Vector2f{ 0.0, 0.0 }, sf::Vector2f{ 50.0, 600.0 }};
	wall right_wall{ sf::Vector2f{ 850.0, 0.0 }, sf::Vector2f{ 50.0, 600.0 }};
	wall up_wall{ sf::Vector2f{ 0.0, 0.0 }, sf::Vector2f{ 900.0, 50.0 }};
	wall down_wall{ sf::Vector2f{ 0.0, 550.0 }, sf::Vector2f{ 900.0, 50.0 }};

	std::vector<drawable*> objects = {&my_ball, &my_cube, &left_wall, &right_wall, &up_wall, &down_wall};

	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ my_cube.move( sf::Vector2f( -5.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ my_cube.move( sf::Vector2f( +5.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ my_cube.move( sf::Vector2f(  0.0, -5.0 )); }),
		action( sf::Keyboard::Down,  [&](){ my_cube.move( sf::Vector2f(  0.0, +5.0 )); }),
		action( true,  [&](){ my_ball.bounce(objects);}),
		action( true,  [&](){ my_ball.move();})
	};

	while(window.isOpen()){
		for( auto &action : actions ){
			action();
		}

		window.clear();
		for(auto &item : objects){
			item->draw(window);
		}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}
}


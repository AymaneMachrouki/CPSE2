#include "circle.hpp"
#include "rectangle.hpp"
#include "picture.hpp"
#include "drawable.hpp"
#include "factory.hpp"
#include "exceptions.hpp"

class action {
private:
	std::function<bool()> condition;
	std::function<void()> work;
public:
	action(
		std::function<bool()> condition, 
		std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
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
		if( condition() )
			work();
	}
};

int main(){
	sf::RenderWindow window{ sf::VideoMode{ 900, 600 }, "Week 3" };

	std::vector<drawable*> screen_objects;

	std::ifstream input("object.txt");
	try {
		for(;;)
			screen_objects.push_back(screen_object_read(input));	
	}	
	catch(const end_of_file &){
		//do nothing
	}
	catch(std::exception & problem){
		std::cout << problem.what();
	}

	while(window.isOpen()){		
		window.clear();
			for(auto &item : screen_objects){
				item->draw(window);
				item -> moving(window); 
			}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed )
				window.close();
		}	
	}
	std::ofstream txt;
	txt.open("object.txt");
	for(auto &item : screen_objects)
		item->write_to_file();
	txt.close();
}
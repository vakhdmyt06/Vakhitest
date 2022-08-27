#include "deps.h"

std::string winame="VAKHITEST5";
#include "game.h"

game gam;
int main() {
cout << " - CREATING " << winame << endl;
	gam.win.create(sf::VideoMode(800,600),winame, sf::Style::Default);
	gam.win.setFramerateLimit(60);
	cout << " - Welcome to " << winame << endl;
	gam.init();
	while(gam.win.isOpen()){
	    while(gam.win.pollEvent(gam.eve)){
	        if(gam.eve.type == sf::Event::Closed) gam.win.close();
	        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) gam.win.close();
        }
    //gam.update();
    gam.render();
	}
	cout << " - Exiting " << winame << endl;
    return 0;
}

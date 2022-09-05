
#include "header/game.h"
game gam;
#ifndef VAKHITEST
#define VAKHITEST
#include "header/deps.h"
std::string winame="VAKHITEST5";

int main() {
#ifdef devel
cout << " - CREATING " << winame << endl;
#endif // devel
	gam.win.create(sf::VideoMode(800,600),winame, sf::Style::Default);
	gam.win.setFramerateLimit(60);
	cout << " - Welcome to " << winame << endl;
	gam.init();
	bool focus;
	while(gam.win.isOpen()){
	    while(gam.win.pollEvent(gam.eve)){
	        if(gam.eve.type == sf::Event::Closed) gam.win.close();
	        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) gam.win.close();
	        if(gam.eve.type == sf::Event::GainedFocus) focus = true;
	        if(gam.eve.type == sf::Event::LostFocus) focus = false;
        }
        if(focus) {
//            gam.update();
            gam.render();
        }
	}
	cout << " - Exiting " << winame << endl;
    return 0;
}
#endif

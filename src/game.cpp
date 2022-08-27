#include "header/game.h"

game::game(){
    cout << "gaming" << endl;
}

void game::slep(int milliseconds, int mode){
    sf::Clock clock;clock.restart();timevar = 0;milliseconds--; while( timevar < milliseconds){ mode==1 ? timevar = clock.getElapsedTime().asSeconds() : timevar = clock.getElapsedTime().asMilliseconds(); } //cout << time << endl; }
}

void game::init(){
}
void game::update(){
//    if(devel) editormain();
    menutable();
}
void game::render(){
    win.clear();
    update();
    win.display();
}






#include "header/game.h"

game::game()
{
}
game::~game(){

}

void game::slep(int milliseconds, int mode){
    sf::Clock clock;clock.restart();timevar = 0;milliseconds--; while( timevar < milliseconds){ mode==1 ? timevar = clock.getElapsedTime().asSeconds() : timevar = clock.getElapsedTime().asMilliseconds(); } //cout << time << endl; }
}

void game::init(){
//    fade_init();
}
void game::update(){
//    if(devel) editormain();
    //ONLY USED FOR DEBUG ENABLING lol  nvm
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
//        #define devel
//    }

}
void game::render(){
    win.clear();
    hbobjs.clear();
    menutable();
    win.display();
}

void game::printxt(string text, int x, int y, int MODE, int charsize, sf::Color chrcol){
    text_print.make(text, x, y, MODE, charsize, chrcol);
    win.draw(text_print.textname);
}
void game::printanm(string text, int x, int y, int ms, int charsize, int MODE, sf::Color chrcol){
    text_anm.makeanm(text, x, y, charsize, ms, MODE, chrcol);
    win.draw(text_anm.textname);
}
//§°–…·µ€
string game::str(int &input){
    return std::to_string(input);
}
string game::str(float &input){
    return std::to_string(input);
}
string game::str(double &input){
    return std::to_string(input);
}
string game::str(unsigned int &input){
    return std::to_string(input);
}

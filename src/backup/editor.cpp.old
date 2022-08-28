#include "game.h"

void game::editormain(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)&&sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)&&sf::Keyboard::isKeyPressed((sf::Keyboard::E))) menum=2;
}

string game::editorinput(){
return "WIP";
}
int game::editoroffX(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) edoffX++;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) edoffX--;
    return edoffX;
}
int game::editoroffY(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) edoffY--;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) edoffY++;
    return edoffY;
}
int game::editorcharsiz(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) edcharsiz++;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) edcharsiz--;
    return edcharsiz;
}
int game::editorposX(){
//if(edmove){
    edposY=sf::Mouse::getPosition(win).y;
    return edposY;
//}
}
int game::editorposY(){
//if(edmove){
    edposX=sf::Mouse::getPosition(win).x;
    return edposX;
//}
}

void game::editor(){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right));
    cout << "This Editor has been abandonded" << endl;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){ //button
        buttonmk(editorposY(), editorposX(), editorinput(), sf::Color::Red, editoroffX(), editoroffY(), editorcharsiz(), sf::Color::Black, sf::Color::White, 1, sf::Color::Cyan);
    }
}

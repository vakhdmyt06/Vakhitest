#include "header/game.h"

void game::buttonmk(int x, int y, string text0, sf::Color colfill, int offsetX, int offsetY, int charsize, sf::Color charcol, sf::Color coloutline, int outlinesize, sf::Color colfillpress, int offsetXpress, int offsetYpress, unsigned int msPress, action type, int menu_number, sf::Keyboard::Key key){
    buttontext.make(text0, x, y-offsetY/2-2, 2, charsize, charcol);
    int xsize=offsetX+(buttontext.textname.getLocalBounds().width)/2, ysize=offsetY+(buttontext.textname.getLocalBounds().height)/2;
    if(collisio(buttonbox.getPosition().x-(buttonbox.getLocalBounds().width/2), buttonbox.getPosition().y-(buttonbox.getLocalBounds().height/2)+buttontext.textname.getLocalBounds().height, xsize*2, ysize*2) && sf::Mouse::isButtonPressed(sf::Mouse::Left)||sf::Keyboard::isKeyPressed(key)) {y+=offsetXpress; x+=offsetYpress; buttontext.make(text0, x, y-offsetY/2-200, 2, charsize, charcol); buttonbox.setFillColor(colfillpress); slep(msPress); buttonact(type, menu_number);}
    buttonbox.setPosition(sf::Vector2f(x,y)); buttonbox.setFillColor(colfill); buttonbox.setOutlineColor(coloutline); buttonbox.setOutlineThickness(outlinesize);
    if(collisio(buttonbox.getPosition().x-(buttonbox.getLocalBounds().width/2), buttonbox.getPosition().y-(buttonbox.getLocalBounds().height/2)+buttontext.textname.getLocalBounds().height, xsize*2, ysize*2)) {buttontext.make(text0, x, y-offsetY/2-200, 2, charsize, charcol); buttonbox.setFillColor(colfillpress);}
    buttonbox.setOrigin(sf::Vector2f(xsize, ysize-buttontext.textname.getLocalBounds().height-5));
    buttonbox.setSize(sf::Vector2f(xsize*2,ysize*2));
    win.draw(buttonbox); buttontext.make(text0, x, y, 2, charsize, charcol);
    win.draw(buttontext.textname);
}

bool game::collisio(int x, int y, int width, int height){
    sf::RectangleShape bound; bound.setPosition(sf::Vector2f(x, y)); bound.setSize(sf::Vector2f(width,height)); bound.setFillColor(sf::Color::Green);
    if(bound.getGlobalBounds().contains(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y)) {return true;}
    return false;
}
void game::buttonact(int acttype, int menunumber){
    switch(acttype){
        case 0://NOTHING
            break;
        case 1://CHANGE MENU
            menum=menunumber;
            break;
    }
    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
}

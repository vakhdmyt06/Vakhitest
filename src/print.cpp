#include "header/print.h"
#include "header/game.h"

print::print()
{
    if(!textfont.loadFromFile("assets/font/norm.ttf")) cout << "Error: FONT FILE INVALID" << endl;
}

print::~print()
{
    //dtor
}

void print::make(string text, int x, int y, int MODE, int charsize, sf::Color chrcol){
    int xpos, ypos;
    textname.setString(text); textname.setFont(textfont); textname.setCharacterSize(charsize); textname.setFillColor(chrcol);
    switch(MODE){
    case 0: //LEFT ALIGNED
        ypos=y;
        xpos=x;
        break;
    case 1: //MIDDLE, SELECT OPTION
//        ypos=gam->win.getSize().y/2-((gam->ys+y)*50)+4;
//        xpos=gam->win.getSize().x/2-(textname.getLocalBounds().width/2);
        textname.setString(text+"\nMODE=2 DEPRECATED");
        break;
    case 2: //CENTERED X
        ypos=y;
        xpos=x-textname.getLocalBounds().width/2;
        break;
    case 3://CENTERED X Y
        ypos=y-textname.getLocalBounds().height/2;
        xpos=x-textname.getLocalBounds().width/2;
        break;
    case 4://CENTERED Y
        ypos=y-textname.getLocalBounds().height/2;
        xpos=x;
        break;
    }
    textname.setPosition(sf::Vector2f(xpos, ypos));
    //dot.setPosition(sf::Vector2f(xpos+textname.getLocalBounds().width/2-2, ypos+textname.getLocalBounds().height)); win.draw(dot);
}

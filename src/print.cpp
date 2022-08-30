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

int print::make(string text, int x, int y, int MODE, int charsize, sf::Color chrcol){
    int xpos, ypos;
    textname.setString(text); textname.setFont(textfont); textname.setCharacterSize(charsize); textname.setFillColor(chrcol);
    switch(MODE){
    case 0: //LEFT ALIGNED
        ypos=y;
        xpos=x;
        break;
    case 1: //MIDDLE, SELECT OPTION
        textname.setString(string_debug);
        menuum=print_debug();
        ypos=300-((y)*50)+4;
        xpos=400-(textname.getLocalBounds().width/2);
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
    return menuum;
}

int print::print_debug(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ ys--; slep(300); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ ys++; slep(300); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) return ys;
    switch(ys){
    case 0:
        string_debug=std::to_string(ys)+" Debug Map Select";
        break;
    case 1:
        string_debug=std::to_string(ys)+" Test Object/ Collision";
        break;
    case 2:
        string_debug=std::to_string(ys)+" Reserved";
        break;
    case 3:
        string_debug=std::to_string(ys)+" Reserved";
        break;
    case 4:
        string_debug=std::to_string(ys)+" Test Grid";
        break;
    default:
        string_debug="INVALID MAP";
    }
    return 0;
}

void print::slep(int milliseconds, int mode){
    sf::Clock clock;clock.restart();timevar = 0;milliseconds--; while( timevar < milliseconds){ mode==1 ? timevar = clock.getElapsedTime().asSeconds() : timevar = clock.getElapsedTime().asMilliseconds(); } //cout << time << endl; }
}

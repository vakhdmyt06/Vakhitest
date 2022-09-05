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
#ifdef debug
    dot.setPosition(sf::Vector2f(xpos+textname.getLocalBounds().width/2-2, ypos+textname.getLocalBounds().height)); win.draw(dot);
#endif
    return menuum;
}

int print::print_debug(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ ys--; slep(240); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ ys++; slep(240); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) return ys;
    switch(ys){
    case 0:
        lvlname="Debug Map Select";
        break;
    case 1:
        lvlname="Test Object/ Collision";
        break;
    case 4:
        lvlname="Test Grid";
        break;
    case 5:
        lvlname="Instruction";
        break;
    case 6:
        lvlname="Test Door";
        break;
    case 2:
        lvlname="Level Maker/\"Editor\"";
        break;
    case 3:
        lvlname="do not enter";
        break;
    case 7:
        lvlname="Test Door0";
        break;
    default:
        lvlname="INVALID MAP";
    }
    string_debug=std::to_string(ys)+"> "+lvlname+" <";
    return 0;
}

void print::makeanm(sf::String text, int x, int y, int charsize, int ms, int MODE, sf::Color chrcol){
    int xpos, ypos;
    textname.setString(tx); textname.setFont(textfont); textname.setCharacterSize(charsize); textname.setFillColor(chrcol);
    switch(MODE){
    case 0: //LEFT ALIGNED
        ypos=y;
        xpos=x;
        break;
    case 1: //CENTERED X
        ypos=y;
        xpos=x-textname.getLocalBounds().width/2;
        break;
    case 2://CENTERED X Y
        ypos=y-textname.getLocalBounds().height/2;
        xpos=x-textname.getLocalBounds().width/2;
        break;
    case 3://CENTERED Y
        ypos=y-textname.getLocalBounds().height/2;
        xpos=x;
        break;
    }
    textname.setPosition(sf::Vector2f(xpos, ypos));
    if(clock.getElapsedTime().asMilliseconds()==0) clock.restart();
    if(textnm!=text.getSize()) { if(clock.getElapsedTime().asMilliseconds()>ms){
        clock.restart();
        cout<<textnm<<endl;
        tx=tx+text[textnm];
        textnm++;
    }
    } else {
        tx="";
        textnm=0;
    }
}

void print::slep(int milliseconds, int mode){
    sf::Clock clock;
    clock.restart();
    timevar = 0;
    milliseconds--;
    while( timevar < milliseconds)
    { mode==1 ? timevar = clock.getElapsedTime().asSeconds() : timevar = clock.getElapsedTime().asMilliseconds();
    } //cout << time << endl; }
}

#include "header/game.h"
void game::collision(int posxa, int posya, int widtha, int heighta, int collbehav){
    posx=posxa, posy=posya, width=widtha, height=heighta;
    drawlines();
    detector(collbehav); //his stream is better
}

void game::detector(int collbehav){
    charx=plbox.getPosition().x, chary=playery-plypos, charw=plbox.getGlobalBounds().width, charh=plbox.getGlobalBounds().height;
    drawcharaline();
    collbehaviour(collbehav);
}

void game::collbehaviour(int collbehav){
    switch(collbehav)
    {
    case 1: //OUTSIDE WALL
        if(detectionout()==1) { plblockwalk=1; }
        if(detectionout()==2) { plblockwalk=2; }
        if(detectionout()==3) { plblockwalk=3; }
        if(detectionout()==4) { plblockwalk=4; }
        break;
    case 2: //INSIDE WALL
        if(detectionin()==1) { plblockwalk=1; }
        if(detectionin()==2) { plblockwalk=2; }
        if(detectionin()==3) { plblockwalk=3; }
        if(detectionin()==4) { plblockwalk=4; }
        break;
    }
}

void game::drawcharaline(){
    chartop.setSize(sf::Vector2f(charw+16, 8));
    charbottom.setSize(sf::Vector2f(charw+16, 8));
    charleft.setSize(sf::Vector2f(8, charh+16));
    charright.setSize(sf::Vector2f(8, charh+16));
    chartop.setPosition(sf::Vector2f(charx,chary-charh/2)); chartop.setOrigin(sf::Vector2f(8, -charh/2+8));
    charbottom.setPosition(sf::Vector2f(charx,chary+charh/2)); charbottom.setOrigin(sf::Vector2f(8, -charh/2));
    charleft.setPosition(sf::Vector2f(charx-charw/2,chary)); charleft.setOrigin(sf::Vector2f(-charw/2+8, 8));
    charright.setPosition(sf::Vector2f(charx+charw/2,chary)); charright.setOrigin(sf::Vector2f(-charw/2, 8));
    chtop=chartop.getGlobalBounds(); chbott=charbottom.getGlobalBounds(); chleft=charleft.getGlobalBounds(); chrigh=charright.getGlobalBounds();
#ifdef devel
    chartop.setFillColor(sf::Color::White); charbottom.setFillColor(sf::Color::White); charleft.setFillColor(sf::Color::White); charright.setFillColor(sf::Color::White);
//    cout<<posx<<" "<<posy<<" "<<width<<" "<<height<<endl;
    win.draw(chartop); win.draw(charbottom); win.draw(charleft); win.draw(charright);
#endif
}

int game::detectionout(){
    if(bottcol.intersects(chtop)) return 2; //CHARACTER TOP
    if(topcol.intersects(chbott)) return 1; //CHARACTER BOTTOM
    if(leftcol.intersects(chrigh)) return 3; //CHARACTER RIGHT
    if(righcol.intersects(chleft)) return 4; //CHARACTER LEFT
}
int game::detectionin(){
    if(topcol.intersects(chtop)) return 2; //CHARACTER TOP
    if(leftcol.intersects(chleft)) return 4; //CHARACTER LEFT
    if(bottcol.intersects(chbott)) return 1; //CHARACTER BOTTOM
    if(righcol.intersects(chrigh)) return 3; //CHARACTER RIGHT
}

void game::drawlines(){
    top.setSize(sf::Vector2f(width+16, 8));
    bottom.setSize(sf::Vector2f(width+16, 8));
    left.setSize(sf::Vector2f(8, height+16));
    right.setSize(sf::Vector2f(8, height+16));
    top.setPosition(sf::Vector2f(posx,posy-height/2)); top.setOrigin(sf::Vector2f(width/2+8, +8));
    bottom.setPosition(sf::Vector2f(posx,posy+height/2)); bottom.setOrigin(sf::Vector2f(width/2+8, 0));
    left.setPosition(sf::Vector2f(posx-width/2,posy)); left.setOrigin(sf::Vector2f(+8, height/2+8));
    right.setPosition(sf::Vector2f(posx+width/2,posy)); right.setOrigin(sf::Vector2f(0, height/2+8));
    topcol=top.getGlobalBounds(); bottcol=bottom.getGlobalBounds(); leftcol=left.getGlobalBounds(); righcol=right.getGlobalBounds();
#ifdef devel
    //top.setFillColor(sf::Color::White); bottom.setFillColor(sf::Color::White); left.setFillColor(sf::Color::White); right.setFillColor(sf::Color::White);
//    cout<<posx<<" "<<posy<<" "<<width<<" "<<height<<endl;
    win.draw(top); win.draw(bottom); win.draw(left); win.draw(right);
#endif
}

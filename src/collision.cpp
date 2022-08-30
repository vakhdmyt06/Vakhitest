#include "header/game.h"
void game::collision(int posxa, int posya, int widtha, int heighta, int collbehav){
    posx=posxa, posy=posya, width=widtha, height=heighta;
    drawlines();
    detector(collbehav); //his stream is better
}

void game::detector(int collbehav){
    charx=playerx, chary=playery-plypos, charw=plbox.getGlobalBounds().width, charh=plbox.getGlobalBounds().height;
    drawcharaline();
    collbehaviour(collbehav, detection());
}

void game::collbehaviour(int collbehav, int side){
    switch(collbehav)
    {
    case 1: //OUTSIDE WALL
        if(side==1) { plblockwalk=1; }
        if(side==2) { plblockwalk=2; }
        if(side==3) { plblockwalk=3; }
        if(side==4) { plblockwalk=4; }
        break;
    }
    case 1: //INSIDE WALL
        if(side==1) { plblockwalk=2; }
        if(side==2) { plblockwalk=2; }
        if(side==3) { plblockwalk=4; }
        if(side==4) { plblockwalk=3; }
        break;
    }
}

void game::drawcharaline(){
    chartop.setFillColor(sf::Color::White);
    chartop.setSize(sf::Vector2f(charw, 8));
    charbottom.setSize(sf::Vector2f(charw, 8));
    charleft.setSize(sf::Vector2f(8, charh));
    charright.setSize(sf::Vector2f(8, charh));
    chartop.setPosition(sf::Vector2f(charx,chary-charh/2+8)); chartop.setOrigin(sf::Vector2f(0, -charh/2+8));
    charbottom.setPosition(sf::Vector2f(charx,chary+charh/2-8)); charbottom.setOrigin(sf::Vector2f(0, -charh/2));
    charleft.setPosition(sf::Vector2f(charx-charw/2+8,chary)); charleft.setOrigin(sf::Vector2f(-charw/2+8, 0));
    charright.setPosition(sf::Vector2f(charx+charw/2-8,chary)); charright.setOrigin(sf::Vector2f(-charw/2, 0));
    chtop=chartop.getGlobalBounds(); chbott=charbottom.getGlobalBounds(); chleft=charleft.getGlobalBounds(); chrigh=charright.getGlobalBounds();
#ifdef devel
    chartop.setFillColor(sf::Color::White); charbottom.setFillColor(sf::Color::White); charleft.setFillColor(sf::Color::White); charright.setFillColor(sf::Color::White);
//    cout<<posx<<" "<<posy<<" "<<width<<" "<<height<<endl;
    win.draw(chartop); win.draw(charbottom); win.draw(charleft); win.draw(charright);
#endif
}

int game::detection(){
    if(bottcol.intersects(chtop)) return 2; //CHARACTER TOP
    if(topcol.intersects(chbott)) return 1; //CHARACTER BOTTOM
    if(leftcol.intersects(chrigh)) return 3; //CHARACTER LEFT
    if(righcol.intersects(chleft)) return 4; //CHARACTER RIGHT
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
    //win.draw(top); win.draw(bottom); win.draw(left); win.draw(right);
#endif
}

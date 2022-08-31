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
    chartop.setSize(sf::Vector2f(charw+hitbsz*2, hitbsz));
    charbottom.setSize(sf::Vector2f(charw+hitbsz*2, hitbsz));
    charleft.setSize(sf::Vector2f(hitbsz, charh+hitbsz*2));
    charright.setSize(sf::Vector2f(hitbsz, charh+hitbsz*2));
    chartop.setPosition(sf::Vector2f(charx,chary-charh/2)); chartop.setOrigin(sf::Vector2f(hitbsz, -charh/2+hitbsz));
    charbottom.setPosition(sf::Vector2f(charx,chary+charh/2)); charbottom.setOrigin(sf::Vector2f(hitbsz, -charh/2));
    charleft.setPosition(sf::Vector2f(charx-charw/2,chary)); charleft.setOrigin(sf::Vector2f(-charw/2+hitbsz, hitbsz));
    charright.setPosition(sf::Vector2f(charx+charw/2,chary)); charright.setOrigin(sf::Vector2f(-charw/2, hitbsz));
#ifdef hitbox
    chartop.setFillColor(sf::Color::White); charbottom.setFillColor(sf::Color::White); charleft.setFillColor(sf::Color::White); charright.setFillColor(sf::Color::White);
//    cout<<"CHARA: "<<posx<<" "<<posy<<" "<<width<<" "<<height<<endl;
    win.draw(chartop); win.draw(charbottom); win.draw(charleft); win.draw(charright);
#endif
}

int game::detectionout(){
    if(top.getGlobalBounds().intersects(charbottom.getGlobalBounds())) return 1; //CHARACTER BOTTOM
    if(bottom.getGlobalBounds().intersects(chartop.getGlobalBounds())) return 2; //CHARACTER TOP
    if(left.getGlobalBounds().intersects(charright.getGlobalBounds())) return 3; //CHARACTER RIGHT
    if(right.getGlobalBounds().intersects(charleft.getGlobalBounds())) return 4; //CHARACTER LEFT
}
int game::detectionin(){
    if(bottom.getGlobalBounds().intersects(charbottom.getGlobalBounds())) return 1; //CHARACTER BOTTOM
    if(top.getGlobalBounds().intersects(chartop.getGlobalBounds())) return 2; //CHARACTER TOP
    if(right.getGlobalBounds().intersects(charright.getGlobalBounds())) return 3; //CHARACTER RIGHT
    if(left.getGlobalBounds().intersects((charleft.getGlobalBounds()))) return 4; //CHARACTER LEFT
}

void game::drawlines(){
    top.setSize(sf::Vector2f(width+hitbsz*2, hitbsz));
    bottom.setSize(sf::Vector2f(width+hitbsz*2, hitbsz));
    left.setSize(sf::Vector2f(hitbsz, height+hitbsz*2));
    right.setSize(sf::Vector2f(hitbsz, height+hitbsz*2));
    top.setPosition(sf::Vector2f(posx,posy-height/2)); top.setOrigin(sf::Vector2f(width/2+hitbsz, +hitbsz));
    bottom.setPosition(sf::Vector2f(posx,posy+height/2)); bottom.setOrigin(sf::Vector2f(width/2+hitbsz, 0));
    left.setPosition(sf::Vector2f(posx-width/2,posy)); left.setOrigin(sf::Vector2f(+hitbsz, height/2+hitbsz));
    right.setPosition(sf::Vector2f(posx+width/2,posy)); right.setOrigin(sf::Vector2f(0, height/2+hitbsz));
#ifdef hitbox
    //top.setFillColor(sf::Color::White); bottom.setFillColor(sf::Color::White); left.setFillColor(sf::Color::White); right.setFillColor(sf::Color::White);
//    cout<<"OBJ:   "<<posx<<" "<<posy<<" "<<width<<" "<<height<<endl;
    win.draw(top); win.draw(bottom); win.draw(left); win.draw(right);
#endif
}

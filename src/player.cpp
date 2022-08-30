#include "header/game.h"
void game::spawn_player(int startx, int starty){
    startX=startx, startY=starty;
    input();
    plxpos+=xvel;
    plypos+=yvel;
    playerx=startX+plxpos, playery=startY+plypos;
    #ifdef devel
    velprint.make("xv:"+std::to_string(xvel)+" yv:"+std::to_string(yvel)+" x:"+std::to_string(playerx)+" y:"+std::to_string(playery),3, 6, 0,20);
    win.draw(velprint.textname);
    #endif
    plboxdef();
    win.draw(plbox);
//    #ifdef devel
//    cout<<startX<<", "<<startY<<endl;
//    #endif
}

void game::plboxdef(){
    plbox.setFillColor(sf::Color::Red); plbox.setSize(sf::Vector2f(40, 60));
    plbox.setPosition(sf::Vector2f(startX+plxpos, startY));
    if(plxpos>300) plbox.setPosition(sf::Vector2f(400, startY));
    else plbox.setPosition(sf::Vector2f(startX+plxpos, startY));
}

void game::input(){
    //hEEhEE
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))speed=speeds[1]; else speed=speeds[0];
    if(plblockwalk!=3&&sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(xvel>=0.f&&xvel<speed) {xvel+=0.2f;} else xvel=speed;
    } else if(xvel>0.f) xvel=0.f;
    if(plblockwalk!=4&&sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(xvel<=0.f&&xvel>-speed) {xvel-=0.2f;} else xvel=-speed;
    } else if(xvel<0.f) xvel=0.f;
    if(plblockwalk!=1&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(yvel>=0.f&&yvel<speed) {yvel+=0.2f;} else yvel=speed;
    } else if(yvel>0.f) yvel=0.f;
    if(plblockwalk!=2&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(yvel<=0.f&&yvel>-speed) {yvel-=0.2f;} else yvel=-speed;
    } else if(yvel<0.f) yvel=0.f;
    plblockwalk=0;
}

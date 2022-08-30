#include "header/game.h"
void game::spawn_player(int startx, int starty){
    startX=startx, startY=starty;
    input();
    plxpos+=xvel;
    plypos+=yvel;
    playerx=startX+plxpos, playery=startY+plypos;
    #ifdef devel
    velprint.make("xv:"+std::to_string(xvel)+" yv:"+std::to_string(yvel)+" x:"+std::to_string(playerx)+" y:"+std::to_string(playery),3, 6, 0,30);
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){if(xvel>=0.f&&xvel<8.f) {xvel+=0.2f;} else xvel=8.f;} else if(xvel>0.f) xvel=0.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){if(xvel<=0.f&&xvel>-8.f) {xvel-=0.2f;} else xvel=-8.f;} else if(xvel<0.f) xvel=0.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){if(yvel>=0.f&&yvel<8.f) {yvel+=0.2f;} else yvel=8.f;} else if(yvel>0.f) yvel=0.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){if(yvel<=0.f&&yvel>-8.f) {yvel-=0.2f;} else yvel=-8.f;} else if(yvel<0.f) yvel=0.f;
    } else {
    if(plblockwalk!=3&&sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){if(xvel>=0.f&&xvel<5.f) {xvel+=0.3f;} else xvel=5.f;} else if(xvel>0.f) xvel=0.f;
    if(plblockwalk!=4&&sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){if(xvel<=0.f&&xvel>-5.f) {xvel-=0.3f;} else xvel=-5.f;} else if(xvel<0.f) xvel=0.f;
    if(plblockwalk!=1&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){if(yvel>=0.f&&yvel<5.f) {yvel+=0.3f;} else yvel=5.f;} else if(yvel>0.f) yvel=0.f;
    if(plblockwalk!=2&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){if(yvel<=0.f&&yvel>-5.f) {yvel-=0.3f;} else yvel=-5.f;} else if(yvel<0.f) yvel=0.f;
    }
}

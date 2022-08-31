#include "header/game.h"
void game::room_init(){
    cout<<"Room: "<<menum<<endl;
    plxpos=startX, plypos=startY;
    load_textures();
    plboxdef();
}

void game::spawn_player(int startx, int starty){
    startX=startx, startY=starty; plxpos+=xvel; plypos+=yvel;
    #ifdef devel
    velprint.make("xv:"+std::to_string(xvel)+" yv:"+std::to_string(yvel)+" x:"+std::to_string(plxpos)+" y:"+std::to_string(plypos),3, 6, 0,20);
    win.draw(velprint.textname);
    #endif
    input();
    playercollision();
    win.draw(plbox);
    plname.make("Gubed", plbox.getPosition().x+plbox.getGlobalBounds().width/2, plbox.getPosition().y-plbox.getGlobalBounds().height/2+10, 2,25);
    win.draw(plname.textname);
//    #ifdef devel
//    cout<<startX<<", "<<startY<<endl;
//    #endif
}

void game::plboxdef(){
//    plbox.setSize(sf::Vector2f(32,32));
    plbox.setTexture(tex_player); plbox.setScale(sf::Vector2f(1.5,1.5));
    plbox.setPosition(sf::Vector2f(plxpos,  win.getSize().y/2));
    if(plxpos>win.getSize().x/2) plbox.setPosition(sf::Vector2f(win.getSize().x/2, win.getSize().y/2)); // add y up down scroll  and x left right scroll  STOPS if needed
    else plbox.setPosition(sf::Vector2f(plxpos,  win.getSize().y/2));

}

void game::input(){
//    //hEEhEE
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))speed=speeds[1]; else speed=speeds[0];
//    if(plblockwalk!=3&&sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//    {
//        if(xvel>=0.f&&xvel<speed) {xvel+=0.2f;} else xvel=speed;
//    } else if(xvel>0.f) xvel=0.f;
//    if(plblockwalk!=4&&sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//    {
//        if(xvel<=0.f&&xvel>-speed) {xvel-=0.2f;} else xvel=-speed;
//    } else if(xvel<0.f) xvel=0.f;
//    if(plblockwalk!=1&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//    {
//        if(yvel>=0.f&&yvel<speed) {yvel+=0.2f;} else yvel=speed;
//    } else if(yvel>0.f) yvel=0.f;
//    if(plblockwalk!=2&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//    {
//        if(yvel<=0.f&&yvel>-speed) {yvel-=0.2f;} else yvel=-speed;
//    } else if(yvel<0.f) yvel=0.f;
    xvel=0; yvel=0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        xvel += speeds[0];
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        xvel -= speeds[0];
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        yvel -= speeds[0];
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        yvel += speeds[0];
    }
    if(plxpos>400.f) plbox.move(0, 0); else plbox.move(xvel, 0);
}

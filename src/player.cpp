#include "header/game.h"
void game::room_init(){
#ifdef devel
    cout<<"Room: "<<menum<<endl;
#endif // devel
    load_textures();
    plboxdef();
    room_entries.clear();
    room_entries.push_back(sf::Vector2i(win.getSize().x/2, 0));
    meninit=1;
}
void game::room_set(){
    RoomMaxRight=0, RoomMaxLeft=0, RoomMaxUp=0, RoomMaxDown=0;
    int objcount=0;
    for(auto &hitboxobj : hbobjs){
        if(RoomMaxRight<hitboxobj.getPosition().x+hitboxobj.getGlobalBounds().width) RoomMaxRight=hitboxobj.getPosition().x;
        if(RoomMaxLeft>hitboxobj.getPosition().x) RoomMaxLeft=hitboxobj.getPosition().x;
        if(RoomMaxDown<hitboxobj.getPosition().y+hitboxobj.getGlobalBounds().height) RoomMaxDown=hitboxobj.getPosition().y;
        if(RoomMaxUp>hitboxobj.getPosition().y) RoomMaxUp=hitboxobj.getPosition().y;
        objcount++;
    }
#ifdef devel
    cout<<"Entrance Number: "<<room_entrynum<<endl;
    cout<<"Left: "<<RoomMaxLeft<<", Right:"<<RoomMaxRight<<", Up: "<<RoomMaxUp<<", Down:" <<RoomMaxDown<<endl;
    cout<<objcount<<" objects with collision"<<endl;
#endif // devel
    plxpos=room_entries[room_entrynum].x, plypos=room_entries[room_entrynum].y;
    meninit=0;
}

void game::debug_player(){
    debug_input();
    playercollision();
    plbox.setTexture(tex_playerload);
    win.draw(plbox);
}
void game::debug_input(){
    xvel=0; yvel=0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        xvel -= speeds;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        xvel += speeds;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        yvel -= speeds;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        yvel += speeds;
    }
    plbox.move(xvel, yvel);
}

void game::spawn_player(int startx, int starty){
    startX=startx, startY=starty; plxpos+=xvel; plypos+=yvel;//remove startYX
//    #ifdef devel
    velprint.make("xv:"+std::to_string((int)xvel)+" yv:"+std::to_string((int)yvel)+" x:"+std::to_string((int)plxpos)+" y:"+std::to_string((int)plypos)+" xobj:"+str(boxposx)+" yobj:"+str(boxposy)+" dir:"+std::to_string(pldir),3, 6, 0,30);
    win.draw(velprint.textname);
//    #endif
    input();
    playercollision();
    win.draw(plbox);
    plname.make("Gubed", plbox.getPosition().x+plbox.getGlobalBounds().width/2, plbox.getPosition().y-plbox.getGlobalBounds().height/2+10, 2,25);
    win.draw(plname.textname);
    plbox.setPosition(win.getSize().x/2, win.getSize().y/2);
//    #ifdef devel
//    cout<<startX<<", "<<startY<<endl;
//    #endif
}

void game::plboxdef(){
//    plbox.setSize(sf::Vector2f(32,32));
    plbox.setTexture(tex_playerload);
    plbox.setScale(sf::Vector2f(3.6,3.6));

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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        xvel -= speeds;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        xvel += speeds;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        yvel -= speeds;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        yvel += speeds;
    }
//    if(plxpos>win.getSize(),x/2) plbox.move(0, 0); else plbox.move(xvel, 0);
//    if(plxpos<RoomMaxLeft+win.getSize().x/2||plxpos>RoomMaxRight-win.getSize().x/3)
//    {
//        if(plypos<RoomMaxUp-40||plypos>RoomMaxDown-win.getSize().y/1.3-40){
//            plbox.move(xvel, yvel);
//        } else {
////            scrollingX=false;
//            plbox.move(xvel, 0);
//        }
//    } else if(plypos<RoomMaxUp-40||plypos>RoomMaxDown-win.getSize().y/1.3-40){
//            plbox.move(0, yvel);
//        } else {
////            scrollingX=true;
//            plbox.move(0,0); //Intensife thinking ... intensifies
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) plbox.setTexture(tex_playerconfuse);
//    else {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { anim_plwalk.player(plbox, 2, speeds); pldir=LEFT; }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { anim_plwalk.player(plbox, 1, speeds); pldir=RIGHT; }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { anim_plwalk.player(plbox, 3, speeds); pldir=UP; }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { anim_plwalk.player(plbox, 4, speeds); pldir=DOWN; }
        else if(pldir==LEFT) anim_plwalk.player(plbox, 7, speeds);
        else if(pldir==RIGHT) anim_plwalk.player(plbox, 8, speeds);
        else if(pldir==UP) anim_plwalk.player(plbox, 6, speeds);
        else if(pldir==DOWN) anim_plwalk.player(plbox, 5, speeds);
//    }

}
#ifdef _editor
void game::debug_cam(){
    debugcam=1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) boxposy-=10;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) boxposy+=10;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) boxposx-=10;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) boxposx+=10;
}
#endif // editor

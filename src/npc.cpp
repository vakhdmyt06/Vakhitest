#include "header/npc.h"

npc::npc()
{
    //ctor
}

npc::~npc()
{
    //dtor
}

void npc::spawn(string name, int x, int y, int scaley, int scalex, int type, int behaviur, float &boxposx, float &boxposy, bool collide, std::vector<sf::RectangleShape>& hbobjs){
    //DO NPC NAME FLOAT IF debug OR show_npcname
    npcmain.setColor(sf::Color::White);
    npcmain.setOrigin(scalex/2, scaley/2);
    npcmain.setPosition(x-boxposx,y-boxposy);
    npcmain.setScale(scalex*4,scaley*4);
    npcanim.player(npcmain, 2, 1);
    if(collide) collision(hbobjs);
    behaviour(type, behaviur);
}
void npc::collision(std::vector<sf::RectangleShape>& hbobjs){
    hitboxobj.setPosition(npcmain.getPosition()); hitboxobj.setSize(sf::Vector2f(npcmain.getGlobalBounds().width, npcmain.getGlobalBounds().height)); hitboxobj.setOrigin(npcmain.getOrigin());
    hbobjs.push_back(hitboxobj);
}

void npc::behaviour(int type, int id){
    switch(type){
        case 1:
            switch(id){
                case 1:
                    break;
            }
        break;
    }
}

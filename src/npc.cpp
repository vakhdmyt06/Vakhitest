#include "header/npc.h"

npc::npc()
{
    //ctor
}

npc::~npc()
{
    //dtor
}

void npc::spawn(string name, int x, int y, int scaley, int scalex, int type, int behaviur, float &boxposx, float &boxposy, bool collide, std::vector<sf::RectangleShape>& hbobjs, sf::FloatRect plbound, sf::RenderWindow &win){
    //DO NPC NAME FLOAT IF debug OR show_npcname
    this->plbound=plbound;
    npcmain.setOrigin(scalex/2, scaley/2);
    npcmain.setPosition(x-boxposx,y-boxposy);
    npcmain.setScale(scalex,scaley);
    if(collide) collision(hbobjs);
    behaviour(type, behaviur, win);
}
void npc::collision(std::vector<sf::RectangleShape>& hbobjs){
    hitboxobj.setPosition(npcmain.getPosition()); hitboxobj.setSize(sf::Vector2f(npcmain.getGlobalBounds().width, npcmain.getGlobalBounds().height)); hitboxobj.setOrigin(npcmain.getOrigin());
    hbobjs.push_back(hitboxobj);
}

void npc::behaviour(int type, int id, sf::RenderWindow &win){
    switch(type){
        case 1: //testguy
            switch(id){
                case 1: //talkable, test anim
                    if(collides()&&sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) npcmsghappening=1;
                    if(npcmsghappening) { msg.create(2,0,win); if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) if(msg.msgtext.txdone){npcmsghappening=0;}else{msg.msgms=0;} }
                    npcanim.npc(npcmain, 1);
                    break;
            }
        break;
    }
}

bool npc::collides(){
    npcbound.top=npcmain.getGlobalBounds().top-bound;
    npcbound.left=npcmain.getGlobalBounds().left-bound;
    npcbound.width=npcmain.getGlobalBounds().width+bound;
    npcbound.height=npcmain.getGlobalBounds().height+bound;
    if(plbound.intersects(npcbound)) return true;
    return false;
}

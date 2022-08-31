#include "header/game.h"
void game::collision(int posx, int posy, int width, int height, int collbehav){
    hitboxobj.setPosition(sf::Vector2f(posx, posy)); hitboxobj.setSize(sf::Vector2f(width+2, height+2)); hitboxobj.setOrigin(sf::Vector2f(1,1));

    charx=plbox.getPosition().x, chary=playery-plypos, charw=plbox.getGlobalBounds().width, charh=plbox.getGlobalBounds().height;

    detector(collbehav);
#ifdef show_hitbox
    win.draw(hitboxobj);
#endif // show_hitbox
}

void game::detector(int collbehav){
    switch(collbehav){
        case 1:
            hbobjs.push_back(hitboxobj);
            break;
//        case 2:
//            break;
    }
}

void game::playercollision(){
    for(auto &hitboxobj : hbobjs){
        hbplayer = plbox.getGlobalBounds();
        hbobj = hitboxobj.getGlobalBounds();
        nextPos = hbplayer;
        nextPos.left += xvel;
        nextPos.top += yvel;
        cout<<nextPos.top<<", "<<nextPos.left<<", "<<nextPos.height<<", "<<nextPos.width<<",  "<<hbobj.top<<", "<<hbobj.left<<", "<<hbobj.width<<", "<<hbobj.height<<endl;
        if(hbobj.intersects(nextPos)){
            if(nextPos.top < hbobj.top //TOP
            && hbplayer.top + hbplayer.height < hbobj.top + hbobj.height
            && hbplayer.left < hbobj.left + hbobj.width
            && hbplayer.left + hbplayer.width > hbobj.left){
                yvel=0.f;
                plbox.setPosition(hbplayer.left, hbobj.top - hbplayer.height);
            }
            else if(nextPos.top > hbobj.top //BOTTOM
            && hbplayer.top + hbplayer.height > hbobj.top + hbobj.height
            && hbplayer.left < hbobj.left + hbobj.width
            && hbplayer.left + hbplayer.width > hbobj.left){
                yvel=0.f;
                plbox.setPosition(hbplayer.left, hbobj.top + hbobj.height);
            }
            if(nextPos.left < hbobj.left
            && hbplayer.left + hbplayer.width < hbobj.left + hbobj.width
            && hbplayer.top < hbobj.top + hbobj.height
            && hbplayer.top + hbplayer.height > hbobj.top){
                xvel=0.f;
                plbox.setPosition(hbobj.left - hbplayer.width, hbplayer.top);
            }
            else if(nextPos.left > hbobj.left
            && hbplayer.left + hbplayer.width > hbobj.left + hbobj.width
            && hbplayer.top < hbobj.top + hbobj.height -3
            && hbplayer.top + hbplayer.height -3 > hbobj.top){
                xvel=0.f;
                plbox.setPosition(hbobj.left + hbobj.width, hbplayer.top);
            }
        }
    }
}

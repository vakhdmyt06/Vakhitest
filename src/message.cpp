#include "header/message.h"

message::message()
{
    //ctor
}

message::~message()
{
    //dtor
}

void message::create(int type, int id, sf::RenderWindow &win){
    msgbox.setOrigin(375, 100); msgbox.setPosition(win.getSize().x/2, 120);
    msgbox.setSize(sf::Vector2f(750, 200));
    msgbox.setFillColor(sf::Color::Black);
    msgbox.setOutlineColor(sf::Color::White); msgbox.setOutlineThickness(3);
    win.draw(msgbox);
    switch(id){//MESSAGE ID
        case 0:
            msgtxt="TEST MESSAGE";
            break;
    }
    msgtext.makeanm(msgtxt, msgbox.getGlobalBounds().left+26, msgbox.getGlobalBounds().top+5, 40, 100);
    win.draw(msgtext.textname);
}

#ifndef MESSAGE_H
#define MESSAGE_H

#include "print.h"

class message
{
    public:
        message();
        virtual ~message();
        void create(int type, int id, sf::RenderWindow &win);
        print msgtext;
        unsigned int msgms=400;
    private:
        sf::RectangleShape msgbox;
        string msgtxt="ERROR";
};

#endif // MESSAGE_H

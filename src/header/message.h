#ifndef MESSAGE_H
#define MESSAGE_H

#include "print.h"

class message
{
    public:
        message();
        virtual ~message();
        void create(int type, int id, sf::RenderWindow &win);
    private:
        sf::RectangleShape msgbox;
        print msgtext;
        string msgtxt="ERROR";
};

#endif // MESSAGE_H

#include "deps.h"

#ifndef BOX_H
#define BOX_H

class game;
class box
{
    public:
        box();
        virtual ~box();
        void main(int posX, int posY, int width, int height, sf::Color col, float charaposX=0.f);
        sf::RectangleShape rectbox;
    private:
        float posx;
};

#endif // BOX_H

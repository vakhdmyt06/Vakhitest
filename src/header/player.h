#include "deps.h"
#ifndef PLAYER_H
#define PLAYER_H
#include "print.h"

class game;
class player
{
    public:
        player();
        virtual ~player();
        void main(int startx, int starty);
        float velocity=0.f;
        int startX, startY;
        sf::RectangleShape box;
        print velprint;
        float xpos=0;
    private:
        void plbox();
        void input();
        void slep(int milliseconds, int mode=0); int timevar=0;
};
#endif // PLAYER_H

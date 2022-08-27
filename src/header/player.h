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
        void main(int startX, int startY);
        float velocity=0.f;
        int startX=100, startY=700;
        sf::RectangleShape box;
        print velprint;
    private:
        void plbox();
        void input();
        void slep(int milliseconds, int mode=0); int timevar=0;
        float xpos=0;
};
#endif // PLAYER_H

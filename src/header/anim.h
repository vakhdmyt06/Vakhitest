#include "deps.h"

#ifndef ANIM_H
#define ANIM_H


class anim
{
    public:
        anim(int anmtype);
        virtual ~anim();
        void player(sf::Sprite& spr, int id, double speed=4);
        sf::Clock clock;
        int anmtype, id, oldid;
    private:
        sf::Texture plrw0, plrw1, plrw2; //player walk right
        sf::Texture pllw0, pllw1, pllw2; //player walk left
        sf::Texture pluw0, pluw1, pluw2; //player walk up
        sf::Texture pldw0, pldw1, pldw2; //player walk down
        float timevar=0.f;
};

#endif // ANIM_H

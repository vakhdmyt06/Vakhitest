#include "deps.h"
#ifndef NPC_H
#define NPC_H
#include "print.h"
#include "anim.h"


class npc
{
    public:
        npc();
        virtual ~npc();
        void spawn(string name, int x, int y, int scaley, int scalex, int type, int behaviur, float &boxposx, float &boxposy, bool collide, std::vector<sf::RectangleShape>& hbobjs);
        sf::Sprite npcmain;
    private:
        int test;
        print npcname;
        void collision(std::vector<sf::RectangleShape>& hbobjs);
        void behaviour(int type, int id);
        anim npcanim=1;
        sf::RectangleShape hitboxobj;
};

#endif // NPC_H

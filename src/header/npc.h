#include "deps.h"
#ifndef NPC_H
#define NPC_H
#include "print.h"
#include "anim.h"
#include "message.h"


class npc
{
    public:
        npc();
        virtual ~npc();
        void spawn(string name, int x, int y, int scaley, int scalex, int type, int behaviur, float &boxposx, float &boxposy, bool collide, std::vector<sf::RectangleShape>& hbobjs, sf::FloatRect plbound, sf::RenderWindow &win);
        sf::Sprite npcmain;
    private:
        int test;
        print npcname;
        void collision(std::vector<sf::RectangleShape>& hbobjs);
        bool collides();
        void behaviour(int type, int id, sf::RenderWindow &win);
        anim npcanim=2;
        sf::RectangleShape hitboxobj;
        sf::FloatRect plbound, npcbound;
        const unsigned int bound=20;
        message msg;
};

#endif // NPC_H

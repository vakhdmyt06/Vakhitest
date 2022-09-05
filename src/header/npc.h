#include "deps.h"
#ifndef NPC_H
#define NPC_H


class npc
{
    public:
        npc();
        virtual ~npc();
        void spawn(int &test);
    private:
        int test;
};

#endif // NPC_H

#ifndef PRINT_H
#define PRINT_H
#include "header/player.h"

class game;
class print
{
    public:
        print();
        virtual ~print();
//        game* gam;
        string text;
        int x, y, MODE, charsize;
        sf::Text textname;
        sf::Font textfont;
        void make(string text, int x, int y, int MODE=0, int charsize=40, sf::Color chrcol=sf::Color::White);
    private:
};
#endif // PRINT_H

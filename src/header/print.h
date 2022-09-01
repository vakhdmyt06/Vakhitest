#ifndef PRINT_H
#define PRINT_H
#include "deps.h"

class game;
class print
{
    public:
        print();
        virtual ~print();
        string text;
        int x, y, MODE, charsize;
        sf::Text textname;
        sf::Font textfont;
        int make(string text, int x, int y, int MODE=0, int charsize=40, sf::Color chrcol=sf::Color::White);
        unsigned int menuum=0;
    private:
        unsigned int ys=4;
        int print_debug();
        sf::String string_debug;
        void slep(int milliseconds, int mode=0);
        int timevar=0;
        string lvlname;

};
#endif // PRINT_H

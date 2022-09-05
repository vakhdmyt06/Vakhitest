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
        void makeanm(sf::String text, int x, int y, int ms, int MODE=0, int charsize=40, sf::Color chrcol=sf::Color::White);
        unsigned int textnm=0;
        sf::String tx="";
        bool txdone=0;
        unsigned int menuum=0;
    private:
        unsigned int ys=6;
        int print_debug();
        sf::String string_debug;
        void slep(int milliseconds, int mode=0);
        sf::Clock clock;
        int timevar=0;
        string lvlname;

};
#endif // PRINT_H

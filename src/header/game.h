#include "deps.h"

#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "print.h"
class game{
private:
    public:
        game();
        void init(); void update(); void render();
        sf::RenderWindow win;
        sf::Event eve;
        bool devel=1;
//        int ys=0;
        void slep(int milliseconds, int mode=0);
        void rendr(sf::Drawable &objdraw);
    private:
        void menutable();
        void debugm(); void titlem(); void editorsplash();
        int timevar=0;
    public:
        enum menus{ debug=0, title, editorshot, edit} menunum;
        int menum=menunum;
    private:
        print debugtitle;
        print debg;
        print test;
        print editorshout;
        player chara;
        enum action{NOTHING=0, MENU}actionnum;
        void buttonact(int acttype, int menunumber);
    public:
        void buttonmk(int x, int y, string text0, sf::Color colfill=sf::Color(100,100,100,255), int offsetX=10, int offsetY=10, int charsize=40, sf::Color charcol=sf::Color::Black, sf::Color coloutline=sf::Color::White, int outlinesize=1, sf::Color colfillpress=sf::Color(200,200,200,255), int offsetXpress=3, int offsetYpress=3, unsigned int msPress=50, action type=NOTHING, int menu_number=0, sf::Keyboard::Key key=sf::Keyboard::Unknown);
        bool collision(int x, int y, int width, int height);
        sf::RectangleShape buttonbox;
        print buttontext;
    private:
        void editormain(); void editor(); string editorinput(); int editoroffX(); int editoroffY(); int editorcharsiz(); int editorposX(); int editorposY();
        int edoffX=10, edoffY=10, edcharsiz=40, edposY=0, edposX=0;
};
#endif // GAME_H


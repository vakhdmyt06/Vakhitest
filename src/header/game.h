#include "deps.h"

#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "print.h"
#include "box.h"
class game{
private:
    public:
        game();
        void init(); void update(); void render();
        sf::RenderWindow win;
        sf::Event eve;
//        int ys=0;
        void slep(int milliseconds, int mode=0);
        void rendr(sf::Drawable &objdraw);
    private: //menu system
        void menutable();
        int timevar=0;
        enum action{NOTHING=0, MENU}actionnum;
        void buttonact(int acttype, int menunumber);
    public:
        enum menus{ debug=0, title, editorshot, edit} menunum;
        int menum=menunum;
        player chara;
    private: //menu defines
        void debugm(); void titlem(); void editorsplash();
        print debugtitle;
        print debg;
        print test;
        print editorshout;
        box testbox;
    public: //button
        void buttonmk(int x, int y, string text0, sf::Color colfill=sf::Color(100,100,100,255), int offsetX=10, int offsetY=10, int charsize=40, sf::Color charcol=sf::Color::Black, sf::Color coloutline=sf::Color::White, int outlinesize=1, sf::Color colfillpress=sf::Color(200,200,200,255), int offsetXpress=3, int offsetYpress=3, unsigned int msPress=50, action type=NOTHING, int menu_number=0, sf::Keyboard::Key key=sf::Keyboard::Unknown);
        bool collision(int x, int y, int width, int height);
        sf::RectangleShape buttonbox;
        print buttontext;
//    private: //EDITOR
//        void editormain(); void editor(); string editorinput(); int editoroffX(); int editoroffY(); int editorcharsiz(); int editorposX(); int editorposY();
//        int edoffX=10, edoffY=10, edcharsiz=40, edposY=0, edposX=0;
};
#endif // GAME_H


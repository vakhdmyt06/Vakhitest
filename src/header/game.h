#include "deps.h"

#ifndef GAME_H
#define GAME_H
#include "print.h"
class game{
private:
    public:
        game();
        virtual ~game();
        void init(); void update(); void render();
        sf::RenderWindow win;
        sf::Event eve;
//        int ys=0;
        void slep(int milliseconds, int mode=0);

    private: //menu system
        void menutable();
        int timevar=0;
        enum action{NOTHING=0, MENU}actionnum;
        void buttonact(int acttype, int menunumber);
    public:
        enum menus{ debug=0, title, editorshot, edit} menunum;
        int menum=menunum;
        //collision chara;
    private: //menu defines
        void debugm(); void titlem(); void editorsplash();
        print debugtitle;
        print debg;
        print test;
        print editorshout;
        //box testbox;

    public: //button
        void buttonmk(int x, int y, string text0, sf::Color colfill=sf::Color(100,100,100,255), int offsetX=10, int offsetY=10, int charsize=40, sf::Color charcol=sf::Color::Black, sf::Color coloutline=sf::Color::White, int outlinesize=1, sf::Color colfillpress=sf::Color(200,200,200,255), int offsetXpress=3, int offsetYpress=3, unsigned int msPress=50, action type=NOTHING, int menu_number=0, sf::Keyboard::Key key=sf::Keyboard::Unknown);
        bool collisio(int x, int y, int width, int height);
        sf::RectangleShape buttonbox;
        print buttontext;

//    private: //EDITOR
//        void editormain(); void editor(); string editorinput(); int editoroffX(); int editoroffY(); int editorcharsiz(); int editorposX(); int editorposY();
//        int edoffX=10, edoffY=10, edcharsiz=40, edposY=0, edposX=0;

    public: //player
        void spawn_player(int startx, int starty);
        float xvel=0.f, yvel=0.f;
        int startX, startY;
        sf::RectangleShape plbox;
        print velprint;
        float plxpos=0, plypos=0;
    private:
        void plboxdef();
        void input();
        float playerx, playery;

    public: //collision
        void collision(int posxa, int posya, int widtha, int heighta, int collbehav=0);
        void detector(int collbehav);
        void collbehaviour(int collbehav, int side);
        int charx, chary, charw, charh;
        int posx, posy, width, height;
        sf::RectangleShape top, bottom ,left, right;
        sf::RectangleShape chartop, charbottom, charleft, charright;
        sf::FloatRect topcol, bottcol, leftcol, righcol;
        sf::FloatRect chtop, chbott, chleft, chrigh;
        int plblockwalk=0;
    private:
        void drawlines();
        int detection();
        void drawcharaline();
        float speeds[2]{5.f, 8.f}, speed;

    public: //box
        void make_box(int posX, int posY, int width, int height, sf::Color col, int behavior);
        sf::RectangleShape rectbox;
    private:
        float boxposx, boxposy;
};
#endif // GAME_H


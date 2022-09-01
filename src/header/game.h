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
        void menu_debug(); void menu_test(); void editorsplash(); void menu_global(); void menu_testgrid(); void menu_instructions();
        print debugtitle;
        print debuginfo;
        print debg;
        print test;
//        print editorshout;
        print text_instr_title;
        print text_instr_text;
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
        sf::Sprite plbox;
        print velprint;
        float plxpos=0, plypos=0;
        void room_init();
        void room_set(
        );
    private:
        void plboxdef();
        void input();
        const float speeds[2]{3.5f, 8.f};
        print plname;
        bool scrolling=false;
/*
    public: //collision
        void collision(int posxa, int posya, int widtha, int heighta, int collbehav=0);
        void detector(int collbehav);
        void collbehaviour(int collbehav);
        int charx, chary, charw, charh;
        int posx, posy, width, height;
        sf::RectangleShape top, bottom ,left, right;
        sf::RectangleShape chartop, charbottom, charleft, charright;
    private:
        int hitbsz=3;
        void drawlines();
        int detectionout();
        int detectionin();
        void drawcharaline();
*/
    public: //box
        void make_box(int posX, int posY, int width, int height, sf::Color col, int behavior);
        sf::RectangleShape rectbox;
        sf::Sprite sprbox;
        void make_sprite(int posX, int posY, int width, int height, int behavior);
        float boxposx=0.f, boxposy=0.f;
    private:
        sf::Texture image_test;

    public:
        void make_tile(int xtile, int yrow, sf::Color col=sf::Color::Black, int behaviur=0);
        void make_tile(int xtile, int yrow, sf::Texture &texture, int behaviur=0);
        void make_tile_extend(int Xbegin, int Ybegin, int repeatNumX, int repeatNumY, sf::Texture material, int behaviour);
        void make_tile_extend(int Xbegin, int Ybegin, int repeatNumX, int repeatNumY, sf::Color material, int behaviour);
        sf::RectangleShape tilecol;
        sf::RectangleShape tilespr;
    private:
        unsigned int gridsize=32;
//        const unsigned int gridscale=2;

    public:
        void collision(int posx, int posy, int width, int height, int collbehav=0);
        void detector(int collbehav);
        sf::RectangleShape hitboxobj,testass;
        float charx, chary, charw, charh;
        const int hitboxsize = 2;
        std::vector<sf::RectangleShape> hbobjs, hbwalls;
        void playercollision();
        sf::FloatRect nextPos, hbplayer, hbobj;
        int menuinit;
        bool meninit=0;
        int RoomMaxUp, RoomMaxDown, RoomMaxLeft, RoomMaxRight;

    private: //TEXTURES
        void load_textures();
        sf::Texture tex_grass;
        sf::Texture tex_test;
        sf::Texture tex_player;
        sf::Texture tex_bound;
};
#endif // GAME_H


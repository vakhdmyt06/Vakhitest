#include "deps.h"

#ifndef GAME_H
#define GAME_H
#include "print.h"
#include "anim.h"
class game{
private:
    public:
        game();
        virtual ~game();
        void init(); void update(); void render();
        sf::RenderWindow win;
        sf::Event eve;
        void slep(int milliseconds, int mode=0);
        string str(int &input);
        string str(float &input);
        string str(double &input);
        string str(unsigned int &input);

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
        void menu_debug();
        void menu_test(); /*void editorsplash();*/
        void menu_global();
        void menu_testgrid();
        void menu_instructions();
        void menu_boredom();
        print text_print;
        print debgsel;
//        print editorshout;
        //box testbox;
        void printxt(string text, int x, int y, int MODE=0, int charsize=40, sf::Color chrcol=sf::Color::White);

    public: //button
        void buttonmk(int x, int y, string text0, sf::Color colfill=sf::Color(100,100,100,255), int offsetX=10, int offsetY=10, int charsize=40, sf::Color charcol=sf::Color::Black, sf::Color coloutline=sf::Color::White, int outlinesize=1, sf::Color colfillpress=sf::Color(200,200,200,255), int offsetXpress=3, int offsetYpress=3, unsigned int msPress=50, action type=NOTHING, int menu_number=0, sf::Keyboard::Key key=sf::Keyboard::Unknown);
        bool collisio(int x, int y, int width, int height);
        sf::RectangleShape buttonbox;
        print buttontext;

    private: //EDITOR
        void editor(); void editorsplash();
        void debug_cam();
        bool debugcam;
        bool editor_poscheck(int xb, int yb);
        sf::Vector2i editilepos;
        std::vector<sf::Vector2i> editbox;
        void editor_print();
        bool editor_playing, editor_printed=false;
        void debug_player(); void debug_input();


    public: //player
        void spawn_player(int startx, int starty);
        double xvel=0, yvel=0;
        int startX, startY;
        sf::Sprite plbox;
        print velprint;
        int plxpos=0, plypos=0;
        void room_init();
        void room_set();
    private:
        void plboxdef();
        void input();
        double speeds=4;
        print plname;
        bool scrollingX=false, scrollingY=false;

        anim anim_plwalk=1;
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
        void make_box(int posX, int posY, int width, int height, sf::Color col, int behavior, int id=0);
        sf::RectangleShape rectbox;
        sf::Sprite sprbox;
        void make_sprite(int posX, int posY, int width, int height, sf::Texture &texture, int behavior, int id=0);
        float boxposx=0.f, boxposy=0.f;

    public:
        void make_tile(int xtile, int yrow, sf::Color col=sf::Color::Black, int behaviur=0, int id=0);
        void make_tile(int xtile, int yrow, sf::Texture &texture, int behaviur=0, int id=0);
        void make_tile_extend(int Xbegin, int Ybegin, int repeatNumX, int repeatNumY, sf::Texture material, int behaviour, int id=0);
        void make_tile_extend(int Xbegin, int Ybegin, int repeatNumX, int repeatNumY, sf::Color material, int behaviour, int id=0);
        sf::RectangleShape tilecol;
        sf::RectangleShape tilespr;
    private:
        unsigned int gridsize=32;
//        const unsigned int gridscale=2;

    public: //NEW COLLISION
        void collision(int posx, int posy, int width, int height, int collbehav=0, int id=0);
        void detector(int collbehav, int id);
        sf::RectangleShape hitboxobj,testass;
        int charx, chary, charw, charh;
        const int hitboxsize = 2;
        std::vector<sf::RectangleShape> hbobjs;
        void playercollision();
        sf::FloatRect nextPos, hbplayer, hbobj;
        int menuinit;
        bool meninit=0;
        int RoomMaxUp, RoomMaxDown, RoomMaxLeft, RoomMaxRight;

    private: //TEXTURES
        void load_textures();
        sf::Texture tex_grass;
        sf::Texture tex_test;
        sf::Texture tex_playerload;
        sf::Texture tex_playerconfuse;
        sf::Texture tex_bound;
};
#endif // GAME_H


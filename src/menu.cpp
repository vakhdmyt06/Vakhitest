#include "header/game.h"

void game::menutable(){
    switch(menum){
    case 1:
        menu_test();
        break;
    case 0:
        menu_debug();
        break;
    case 4:
        menu_testgrid();
        break;
    case 5:
        menu_instructions();
        break;
//    case 2:
//        editorsplash();
//        break;
//    case 3:
//        editor();
//        break;
    }
    if(menum!=0)menu_global();
    if(menuinit!=menum) room_init();
    menuinit=menum;
}

void game::menu_global(){
    buttonmk(win.getSize().x/2, win.getSize().y-50, "-DEBUG", sf::Color(100,100,100,255), 10, 10, 40, sf::Color::Blue, sf::Color::White, 1, sf::Color(111,111,111,255),2,2, 0, MENU,0,sf::Keyboard::Backspace);
    if(plxpos<400.f)boxposx=0.f; else boxposx=plxpos-400.f;
    boxposy=plypos;
    hbobjs.clear();

}

void game::menu_debug(){
    /*print("Hello World", 1, 0, 1, 40, sf::Color::White);
    print("y: "+std::to_string(y), 5, 30, 0, 30, sf::Color::White);
    mkbutton(win.getSize().x/2, win.getSize().y/2+100, "PRESS", sf::Color::Red, 90, 50, 40, sf::Color::Green, sf::Color::Blue, 40, 2);*/
    debugtitle.make("VAKHITEST 5\nDmytro Vakhitov", win.getSize().x/2, 4, 2, 50);
    debuginfo.make("INFO\nPress UP | DOWN Arrows to change map\nPress Enter to enter map\nPress Backspace or -DEBUG to go back", win.getSize().x/2, 130, 2, 33);
    win.draw(debuginfo.textname);
    win.draw(debugtitle.textname);
    menum=debg.make("Hello World", 0, 0, 1, 40);
    win.draw(debg.textname);
    buttonmk(win.getSize().x/2, win.getSize().y-200, "INSTRUCTIONS", sf::Color(100,100,100,255), 10, 10, 100, sf::Color::Blue, sf::Color::White, 1, sf::Color(111,111,111,255),2,2, 20, MENU, 5, sf::Keyboard::H);
}

void game::menu_test(){
    make_box(300, 400, 380, 300, sf::Color::Cyan, 0);
    make_box(200, 400, 30, 40, sf::Color::Yellow, 1);
    make_box(300, 400, 50, 40, sf::Color::Green, 1);
    make_box(400, 400, 10, 5, sf::Color::Blue, 1);
    make_sprite(0, 100, 1, 1, 1);
    make_sprite(400, 100, 10, 10, 1);
    spawn_player(110, win.getSize().y/2);
}/*
void game::editorsplash(){
    debugtitle.make("VAKHITEST 5\nDmytro Vakhitov", win.getSize().x/2, 4, 2, 30);
    win.draw(debugtitle.textname);
    editorshout.make("DEVEL EDITOR", win.getSize().x/2, win.getSize().y/2, 3, 100);
    win.draw(editorshout.textname);
    buttonmk(win.getSize().x/2, win.getSize().y/2+200, " ", sf::Color(100,100,100,255), 10, 10, 40, sf::Color::Blue, sf::Color::White, 1, sf::Color(111,111,111,255),2,2, 40, MENU,3);

}
*/
void game::menu_instructions(){
    text_instr_title.make("INSTRUCTIONS", win.getSize().x/2, 20, 2, 50, sf::Color::Blue);
    text_instr_text.make("Arrow Keys(Up Down Left Right) = Move Around\nBackspace = Open Debug Map Select\nESC = Quit Game", win.getSize().x/2, win.getSize().y/2, 3, 33);
    win.draw(text_instr_text.textname); win.draw(text_instr_title.textname);
}

void game::menu_testgrid(){
//    for(int i=-6; i!=50; i++) for(int j=0; j!=24;j++) make_tile(i,j, tex_grass, 0);
    make_tile(2,2, tex_grass, 0);
    spawn_player(100, win.getSize().y/2);
}

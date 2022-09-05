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
    case 6:
        menu_boredom();
        break;
    case 7:
        menu_testdoor();
        break;
    case 2:
#ifdef _editor
        editor();
#else
        printanm("The EDITOR$#02\nis only included in the$#01\nDebug-Build (;", win.getSize().x/2, 100, 100, 60, 2, sf::Color::Red);
#endif

//        editorsplash();
        break;
    case 3: //äöü§°–\n…·µ€
        printanm("VAKHITEST 5$#02\nby\nMODDIMATION",  win.getSize().x/2, win.getSize().y/2-50, 100, 100, 2, sf::Color::Green);
        printxt("Press Enter | Backspace",  win.getSize().x/2, win.getSize().y/2+200, 2, 40, sf::Color::White);
//        editor();
        break;
    }
    if(meninit) room_set();
    if(menuinit!=menum) room_init();
    if(menum!=0)menu_global();
    menuinit=menum;
}

void game::menu_global(){
    buttonmk(win.getSize().x/2, win.getSize().y-50, "MAP SELECT", sf::Color(100,100,100,255), 10, 10, 40, sf::Color::Blue, sf::Color::White, 1, sf::Color(111,111,111,255),2,2, 0, MENU,0,sf::Keyboard::Backspace);
//    if(!debugcam){if(plxpos<RoomMaxLeft+win.getSize().x/2) boxposx=0.f;
//    else if(plxpos>RoomMaxRight-win.getSize().x/3) boxposx=boxposx; else
    boxposx=plxpos-400;/*
    if(plypos>RoomMaxUp-40&&plypos<RoomMaxDown-win.getSize().y/1.3-40) */boxposy=plypos;/*}
//    cout<<plypos<<" "<<RoomMaxUp<<" "<< RoomMaxDown<<endl;*/

}

void game::menu_debug(){
    gridsize=32;
    speeds=4;
    /*print("Hello World", 1, 0, 1, 40, sf::Color::White);
    print("y: "+std::to_string(y), 5, 30, 0, 30, sf::Color::White);
    mkbutton(win.getSize().x/2, win.getSize().y/2+100, "PRESS", sf::Color::Red, 90, 50, 40, sf::Color::Green, sf::Color::Blue, 40, 2);*/
    printxt("Debug Map Select", win.getSize().x/2, 20, 2, 70);
    printxt("INFO\nPress UP | DOWN Arrows to change map\nPress Enter to enter map\nPress Backspace or -DEBUG to go back", win.getSize().x/2, 120, 2, 30);
    menum=debgsel.make("Hello World", 0, 0, 1, 40); win.draw(debgsel.textname);
    buttonmk(win.getSize().x/2, win.getSize().y-200, "INSTRUCTIONS", sf::Color(100,100,100,255), 10, 10, 100, sf::Color::Blue, sf::Color::White, 1, sf::Color(111,111,111,255),10,10, 10, MENU, 5, sf::Keyboard::H);
}

void game::menu_test(){
    speeds=6;
    make_box(300, 400, 380, 300, sf::Color::Cyan, 0);
    make_box(200, 400, 30, 40, sf::Color::Yellow, 1);
    make_box(300, 400, 50, 40, sf::Color::Green, 1);
    make_box(400, 400, 10, 5, sf::Color::Blue, 1);
    make_sprite(0, 100, 1, 1, tex_test, 1);
    make_sprite(400, 100, 10, 10, tex_test, 1);
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
    printxt("INSTRUCTIONS", win.getSize().x/2, 20, 2, 50, sf::Color::Blue);
    printanm("Arrow Keys(Up Down Left Right) = Move Around$#01\nBackspace = Open Debug Map Select$#01\nESC = Quit Game$#06\n\nGot it?\n$#06You know whats Backspace for...\n$#05if your afk turn off the Program atleast.$#03\nit MAY use alot ram and energy$#04\nDont forget to wash your Hands!$#06\nCmon you must be rich or something$#06\n\nOh no..$#01 i flooded the instructions.....$#01\nbye..", win.getSize().x/2, win.getSize().y/2, 34, 35, 2);
}

void game::menu_testgrid(){
    gridsize=64;
    make_tile_extend(0, 1, 20, 10, tex_grass, 0);
    make_tile_extend(0, 0, 20,0, tex_bound, 1);
    make_tile_extend(0,11, 20,11, tex_bound, 1);
    make_tile_extend(21,0, 21,11, tex_bound, 1);
    spawn_player(10, 300);
}
void game::menu_boredom(){
    printxt("walk to the right", win.getSize().x/2, 200, 2, 50, sf::Color::Blue);
    room_setentry(690,-26,1);
make_tile_extend(0, 4, 0, 14, sf::Color::White, 1);
make_tile(1, 15, sf::Color::White, 1);
make_tile(1, 16, sf::Color::White, 1);
make_tile(1, 2, sf::Color::White, 1);
make_tile(1, 3, sf::Color::White, 1);
make_tile(10, 0, sf::Color::White, 1);
make_tile(10, 18, sf::Color::White, 1);
make_tile(11, 0, sf::Color::White, 1);
make_tile(11, 18, sf::Color::White, 1);
make_tile(12, 0, sf::Color::White, 1);
make_tile(12, 18, sf::Color::White, 1);
make_tile(13, 0, sf::Color::White, 1);
make_tile(13, 18, sf::Color::White, 1);
make_tile(14, 0, sf::Color::White, 1);
make_tile(14, 18, sf::Color::White, 1);
make_tile(15, 0, sf::Color::White, 1);
make_tile(15, 18, sf::Color::White, 1);
make_tile(16, 0, sf::Color::White, 1);
make_tile(16, 18, sf::Color::White, 1);
make_tile(17, 0, sf::Color::White, 1);
make_tile(17, 18, sf::Color::White, 1);
make_tile(18, 0, sf::Color::White, 1);
make_tile(18, 18, sf::Color::White, 1);
make_tile(19, 0, sf::Color::White, 1);
make_tile(19, 18, sf::Color::White, 1);
make_tile(2, 1, sf::Color::White, 1);
make_tile(2, 17, sf::Color::White, 1);
make_tile(20, 0, sf::Color::White, 1);
make_tile(20, 18, sf::Color::White, 1);
make_tile(21, 0, sf::Color::White, 1);
make_tile(21, 18, sf::Color::White, 1);
make_tile(22, 1, sf::Color::White, 1);
make_tile(22, 17, sf::Color::White, 1);
make_tile(23, 15, sf::Color::White, 1);
make_tile(23, 16, sf::Color::White, 1);
make_tile(23, 2, sf::Color::White, 1);
make_tile(23, 3, sf::Color::White, 1);
make_tile_extend(24, 4, 24, 14, sf::Color::White, 1);
make_tile(3, 0, sf::Color::White, 1);
make_tile(3, 18, sf::Color::White, 1);
make_tile(4, 0, sf::Color::White, 1);
make_tile(4, 18, sf::Color::White, 1);
make_tile(5, 0, sf::Color::White, 1);
make_tile(5, 18, sf::Color::White, 1);
make_tile(6, 0, sf::Color::White, 1);
make_tile(6, 18, sf::Color::White, 1);
make_tile(7, 0, sf::Color::White, 1);
make_tile(7, 18, sf::Color::White, 1);
make_tile(8, 0, sf::Color::White, 1);
make_tile(8, 18, sf::Color::White, 1);
make_tile(9, 0, sf::Color::White, 1);
make_tile(9, 18, sf::Color::White, 1);
    make_tile(24, 9, tex_bound, 2, 7, 1);
    spawn_player(win.getSize().x/2, win.getSize().y/2);
}

void game::menu_testdoor(){
    printxt("walk to the left", win.getSize().x/2, 200, 2, 50, sf::Color::Blue);
    room_setentry(70,-26,1);
make_tile_extend(0, 4, 0, 14, sf::Color::White, 1);
make_tile(1, 15, sf::Color::White, 1);
make_tile(1, 16, sf::Color::White, 1);
make_tile(1, 2, sf::Color::White, 1);
make_tile(1, 3, sf::Color::White, 1);
make_tile(10, 0, sf::Color::White, 1);
make_tile(10, 18, sf::Color::White, 1);
make_tile(11, 0, sf::Color::White, 1);
make_tile(11, 18, sf::Color::White, 1);
make_tile(12, 0, sf::Color::White, 1);
make_tile(12, 18, sf::Color::White, 1);
make_tile(13, 0, sf::Color::White, 1);
make_tile(13, 18, sf::Color::White, 1);
make_tile(14, 0, sf::Color::White, 1);
make_tile(14, 18, sf::Color::White, 1);
make_tile(15, 0, sf::Color::White, 1);
make_tile(15, 18, sf::Color::White, 1);
make_tile(16, 0, sf::Color::White, 1);
make_tile(16, 18, sf::Color::White, 1);
make_tile(17, 0, sf::Color::White, 1);
make_tile(17, 18, sf::Color::White, 1);
make_tile(18, 0, sf::Color::White, 1);
make_tile(18, 18, sf::Color::White, 1);
make_tile(19, 0, sf::Color::White, 1);
make_tile(19, 18, sf::Color::White, 1);
make_tile(2, 1, sf::Color::White, 1);
make_tile(2, 17, sf::Color::White, 1);
make_tile(20, 0, sf::Color::White, 1);
make_tile(20, 18, sf::Color::White, 1);
make_tile(21, 0, sf::Color::White, 1);
make_tile(21, 18, sf::Color::White, 1);
make_tile(22, 1, sf::Color::White, 1);
make_tile(22, 17, sf::Color::White, 1);
make_tile(23, 15, sf::Color::White, 1);
make_tile(23, 16, sf::Color::White, 1);
make_tile(23, 2, sf::Color::White, 1);
make_tile(23, 3, sf::Color::White, 1);
make_tile_extend(24, 4, 24, 14, sf::Color::White, 1);
make_tile(3, 0, sf::Color::White, 1);
make_tile(3, 18, sf::Color::White, 1);
make_tile(4, 0, sf::Color::White, 1);
make_tile(4, 18, sf::Color::White, 1);
make_tile(5, 0, sf::Color::White, 1);
make_tile(5, 18, sf::Color::White, 1);
make_tile(6, 0, sf::Color::White, 1);
make_tile(6, 18, sf::Color::White, 1);
make_tile(7, 0, sf::Color::White, 1);
make_tile(7, 18, sf::Color::White, 1);
make_tile(8, 0, sf::Color::White, 1);
make_tile(8, 18, sf::Color::White, 1);
make_tile(9, 0, sf::Color::White, 1);
make_tile(9, 18, sf::Color::White, 1);
    testguy.spawn("testguy", 600, 300, 1, 1, 0, 0, boxposx, boxposy, true, hbobjs);
    win.draw(testguy.npcmain);
    make_tile(0, 9, tex_bound, 2, 6, 1);
    spawn_player(0, 0);
}

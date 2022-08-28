#include "header/game.h"

void game::menutable(){
    switch(menum){
    case 1:
        titlem();
        break;
    case 0:
        debugm();
        break;
    /*case 2:
        editorsplash();
        break;
    case 3:
        editor();
        break;*/
    }
}

void game::debugm(){
    /*print("Hello World", 1, 0, 1, 40, sf::Color::White);
    print("y: "+std::to_string(y), 5, 30, 0, 30, sf::Color::White);
    mkbutton(win.getSize().x/2, win.getSize().y/2+100, "PRESS", sf::Color::Red, 90, 50, 40, sf::Color::Green, sf::Color::Blue, 40, 2);*/
    debugtitle.make("VAKHITEST 5\nDmytro Vakhitov", win.getSize().x/2, 4, 2, 30);
    win.draw(debugtitle.textname);
    debg.make("Hello World", 10, 0, 0, 40);
    win.draw(debg.textname);
    buttonmk(win.getSize().x/2, win.getSize().y/2, "PRESS START", sf::Color(100,100,100,255), 10, 10, 100, sf::Color::Blue, sf::Color::White, 1, sf::Color(111,111,111,255),2,2, 10, MENU,1,sf::Keyboard::Enter);
}

void game::titlem(){
    buttonmk(win.getSize().x/2, win.getSize().y-50, "-DEBUG", sf::Color(100,100,100,255), 10, 10, 40, sf::Color::Blue, sf::Color::White, 1, sf::Color(111,111,111,255),2,2, 0, MENU,0,sf::Keyboard::Backspace);
    chara.main(100, 450);
    win.draw(chara.box); win.draw(chara.velprint.textname);
    testbox.main(200, 400, 10, 10, sf::Color::White,chara.xpos);
    win.draw(testbox.rectbox);
}
void game::editorsplash(){
    debugtitle.make("VAKHITEST 5\nDmytro Vakhitov", win.getSize().x/2, 4, 2, 30);
    win.draw(debugtitle.textname);
    editorshout.make("DEVEL EDITOR", win.getSize().x/2, win.getSize().y/2, 3, 100);
    win.draw(editorshout.textname);
    buttonmk(win.getSize().x/2, win.getSize().y/2+200, " ", sf::Color(100,100,100,255), 10, 10, 40, sf::Color::Blue, sf::Color::White, 1, sf::Color(111,111,111,255),2,2, 40, MENU,3);

}

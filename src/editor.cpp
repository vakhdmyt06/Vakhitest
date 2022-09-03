#include "header/game.h"
#ifdef _editor
void game::editor(){
    debug_cam();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) gridsize++; if(sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) gridsize--;
    printxt("objx:"+std::to_string(boxposx)+", objy:"+std::to_string(boxposy), 0, 50, 0, 30);
    int fieldx=(boxposx+sf::Mouse::getPosition(win).x)/gridsize, fieldy=(boxposy+sf::Mouse::getPosition(win).y)/gridsize;
    printxt("x:"+str(fieldx)+", y:"+str(fieldy), 0, 70, 0, 30); editilepos.x=fieldx, editilepos.y=fieldy;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) if(!editor_poscheck(fieldx,fieldy))editbox.push_back(editilepos);
    for(auto &editilepos : editbox){
        make_tile(editilepos.x, editilepos.y, sf::Color::White, 1);
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) std::remove(editbox.begin(), editbox.end(), sf::Vector2i(fieldx,fieldy));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) editor_print();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) if(editor_playing) {editor_playing=false; plbox.setPosition(sf::Vector2f(win.getPosition().x/2,win.getPosition().y/2)); } else editor_playing=true;
    if(editor_playing) debug_player();
}

bool game::editor_poscheck(int xb, int yb){
    for(auto &editilepos : editbox){
        cout<<editilepos.x<<" "<<xb<<" "<<editilepos.y<<" "<<yb<<endl;
        if(editilepos.x==xb&&editilepos.y==yb){ cout<<"Placed"<<endl; return true; }
    }
    return false;
}

void game::editor_print(){
    for(auto &editilepos : editbox){
        cout<<"make_tile("<<editilepos.x<<", "<<editilepos.y<<", sf::Color::White, 1)"<<endl;
    }
    slep(3, 1);
}
#endif

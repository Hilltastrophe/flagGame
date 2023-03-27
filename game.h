//Zack Hill
//Lab 7 Out
//Flag Game


#ifndef GAME_H
#define GAME_H

#include "menu.h"

class Game
{
private:
    Menu menu;
    int no_correct;


public:
    Game();
    int play();
    void setMenu(Menu menu);
    Menu getMenu();
    int getNoCorrect();
};

#endif


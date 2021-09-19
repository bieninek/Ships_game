// =========================
//
//  Author: Bartosz Bien
//
//  !!! Details about this project in README.md  !!!
//
//  This is the main.cpp file from the game called \ships_game\
//  The project is finished, it works well
//  Current version: v1.2
//  There aren't plans for the future, the project won't be developed
//  There were plans about making AI more smart (details in user.cpp)
//  but it's not likely to be done
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"

int main()
{
    // welcome user in the game interface
    my_interface temp;
    temp.userChoice();

    //start_singleplayer (other options leads to exit)
    // so i generate the computer's board
    my_computer statComputer;
    statComputer.createComputerBoard();

    // and i generate user's board
    my_user statUser;
    statUser.userPosition();

    // and i start the game
    // when game is finished, one of the two methods below return 0
    while(true)
    {
        statUser.startTheGame(statComputer);
        statComputer.startTheGameComp(statUser);
    }

    // the program shouldn't make instructions below
    // that's the reason for \return -1\ writing
    return -1;
}

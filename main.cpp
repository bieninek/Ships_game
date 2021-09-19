
// 2. gdy komputer trafi to sprawdza otoczenie punktu
#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"

int main()
{
    my_interface temp;
    temp.userChoice();

//start_singleplayer

    // so i generate the computer's board
    my_computer statComputer;
    statComputer.createComputerBoard();

    // and i generate user's board
    my_user statUser;
    statUser.userPosition();

    while(true)
    {
        statUser.startTheGame(statComputer);
        statComputer.startTheGameComp(statUser);
    }

    return -1;
}

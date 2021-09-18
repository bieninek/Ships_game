// =========================
//
//  Author: Bartosz Bien
//
//  These methods run when the programme will be soon closed, this is a kind of saying \goodbye\ to user:
//  - my_exit::exitCompWins() when computer won the game
//  - my_exit::exitUserWins() when user won the game
//  - my_exit::exitMenu() when user decides to quit the game from the main menu
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


// =========================
//
//  void my_exit::exitCompWins() - this method ends the game, says \goodbye\ and sets the return status to 0
//
//    INPUT:  none
//    OUTPUT: none
//
// =========================
void my_exit::exitCompWins()
{
    system("cls");
    cout << "\aKomputer wygral\n\nWcisnij dowolny klawisz, aby wyjsc...";
    getch();
    exit(0);
}


// =========================
//
//  void my_exit::exitMenu() - this method ends the game, says \goodbye\ and sets the return status to 0
//
//    INPUT:  none
//    OUTPUT: none
//
// =========================
void my_exit::exitMenu()
{
    system("cls");
    cout << "\aWyjscie z programu...";
    Sleep(2000);
    exit(0);
}


// =========================
//
//  void my_exit::exitUserWins() - this method ends the game, says \goodbye\ and sets the return status to 0
//
//    INPUT:  none
//    OUTPUT: none
//
// =========================
void my_exit::exitUserWins()
{
    system("cls");
    cout << "\aUzytkownik wygral\n\nWcisnij dowolny klawisz, aby wyjsc...";
    getch();
    exit(0);
}



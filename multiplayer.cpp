// =========================
//
//  Author: Bartosz Bien
//
//  This file was created because the game has \multiplayer\ option
//  But I didn't created and probably won't create multiplayer (details in README.md)
//  So this is to handle the situation when user chooses multiplayer
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"



// =========================
//
//  multiplayer::multiplayer() - this only shows a small info that multiplayer isn't working
//
//    INPUT:  none
//    OUTPUT: none
//    NOTE:   It requires \conio.h\ because of using \getch()\
//            and \windows.h\ because of the \system("cls")\
//
// =========================
multiplayer::multiplayer()
{
    system("cls");
    cout << "Multiplayer nie dziala\n\nNacisnij dowolny klawisz, by kontynuowac...";
    getch();
    exit(0);
}

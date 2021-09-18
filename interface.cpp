// =========================
//
//  Author: Bartosz Bien
//
//  These methods run when the programme starts
//  They task is to operate in the game menu
//  - void my_interface::userChoice() react depends on which arrow or enter user touched
//  - void my_interface::display(int) only displays appropriate words on the screen
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


// =========================
//
//  void my_interface::userChoice() - this method turns on when the menu appears
//                                    cKey is the number of the last pressed button
//                                    iPosition keeps the current position in menu, the numbers mean:
//                                        1 - singleplayer
//                                        2 - multiplayer
//                                        3 - quit
//                                    When user hits \ENTER\ one from these options is choosen
//
//    INPUT:  none
//    OUTPUT: none
//    NOTE:   It requires \conio.h\ because of using \getch()\
//            The number of elements in menu is kept in ELEMENTS_IN_MENU in the defines.hpp file, it's recommended to leave it set to 3
//            This function many times invokes \void my_interface::display(int)\
//
// =========================
void my_interface::userChoice()
{
    int iPosition = 1;
    char cKey;

    while (true)
    {
        // display
        display(iPosition);

        // get user's key
        cKey = getch();

        // the next step depends on which button was hit
        switch(cKey)
        {
        // user decided to change the highlighted element to one down
        case ARROW_DOWN:
            if (iPosition == ELEMENTS_IN_MENU)
                iPosition = 1;
            else
                iPosition++;
            break;
        // user decided to change the highlighted element to one up
        case ARROW_UP:
            if (iPosition == 1)
                iPosition = ELEMENTS_IN_MENU;
            else
                iPosition--;
            break;
        // user decided to choose the current highlighted option
        case ENTER:
            switch (iPosition)
            {
                // user chose singleplayer
                case 1:
                {
                    return;
                }
                // user choose multiplayer so I go there (details in multiplayer.cpp)
                case 2:
                {
                    multiplayer();
                    return;
                }
                // user chose quit
                case 3:
                {
                    my_exit tempExit;
                    tempExit.exitMenu();
                    return;
                }
            }
            break;
        }
    }
}


// =========================
//
//  void my_interface::display(int) - this method only displays the appropriate version of menu
//                                    The version of menu depends on the variable \iPosition\
//
//    INPUT:  iPosition - int variable means which element is highlighted
//    OUTPUT: none
//    NOTE:   It requires \windows.h\ because of using \system("cls")\
//
// =========================
void my_interface::display(int iPosition)
{
    system("cls");
    cout << "Statki \n\n";  // it's written to let the user know what's the name of the project


    switch (iPosition)
    {
        // now \singleplayer\ is highlighted
        case 1:
            cout << "\n\t\t\t\t>>>\t\tTryb Singleplayer\t\t<<<\n\t\t\t\tTryb Multiplayer\n\t\t\t\tWyjscie\n";
            break;
        // now \multiplayer\ is highlighted
        case 2:
            cout << "\n\t\t\t\tTryb Singleplayer\n\t\t\t\t>>>\t\tTryb Multiplayer\t\t<<<\n\t\t\t\tWyjscie\n";
            break;
        // now quit is highlighted
        case 3:
            cout << "\n\t\t\t\tTryb Singleplayer\n\t\t\t\tTryb Multiplayer\n\t\t\t\t>>>\t\tWyjscie\t\t\t\t<<<\n";
            break;
    }
}


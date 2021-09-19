// =========================
//
//  Author: Bartosz Bien
//
//  Method in this file is responsible for game with a computer
//  The user guesses the ships and the computer's board is displayed
//  When user correctly guessed it's also done by this method
//  Also the game of the game, when user wins
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


// =========================
//
//  void my_computer::startTheGameComp(my_user&) - this method is responsible for game with the computer
//
//    INPUT:  a reference to an object class my_user, simply the user's board
//    OUTPUT: none
//
// =========================
void my_computer::startTheGameComp(my_user& statUserBoard)
{
    bool ifGuessed = true;
    char cSign, cNumber;
    int iNumber, iSign, iRemainShips;

    // if user starts the round or guessed correctly can enter the loop
    while (ifGuessed)
    {
        // display the board
        cout << endl << endl;
        showComputerBoard();
        statUserBoard.showBoard(0);
        cout << "\n*********************\n";

        // i count how many ships remain
        iRemainShips = 0;
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++)
                if (iComputerBoard[i][j] == 1)
                    iRemainShips++;

        // if there're ships i go to true, otherwise to false
        if (iRemainShips)
        {
            // user guesses the position
            cout << "\n\nTeraz Ty zgadnij gdzie lezy statek komputera:\n\n";
            cout << "Znak: ";
            cin >> cSign;
            cout << "Numer: ";
            cin >> cNumber;
            cout << "Wpisane pole: " << cNumber << cSign << endl;

            // i change to a proper format
            iSign = (int)(cSign - 'a');
            iNumber = (int)(cNumber - '1');

            // if guessed correctly
            if (iComputerBoard[iNumber][iSign] == 1)
            {
                cout << "Uzytkownik zgadl" << endl;
                iComputerBoard[iNumber][iSign] = 2;

                cout << endl << "Wcisnij dowolny klawisz\n";
                getch();
            }
            // user was wrong
            else
            {
                cout << "Uzytkownik nie zgadl" << endl;
                iComputerBoard[iNumber][iSign] = 3;
                ifGuessed = false;
            }
        }
        // no ships left = end of the game, user wins
        else
        {
            my_exit pomExit;
            pomExit.exitUserWins();
        }
    }
    return;
}

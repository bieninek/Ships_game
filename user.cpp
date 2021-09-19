// =========================
//
//  Author: Bartosz Bien
//
//  Method in this file is responsible for game with a computer
//  Here the computer guesses where the users' ships are
//  There's a nice trick: the computer never checks the same field twice
//  Maybe in the future the computer would check the fields near the field where was the ship
//  But in this case the game is hard and computer often wins - the user must win more often!
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


// =========================
//
//  void my_user::startTheGame(my_computer&) - this method is responsible for game with the computer
//
//    INPUT:  a reference to an object class my_computer, simply the computers's board
//    OUTPUT: none
//
// =========================
void my_user::startTheGame(my_computer& statCompBoard)
{
    bool ifGuessed = true;
    int iSign, iNumber, iRemainShips;

    // if it's the first guess in round or computer guessed correctly
    while (ifGuessed)
    {
        // display board
        statCompBoard.showComputerBoard();
        showBoard(0);

        // count how many ships remain
        iRemainShips = 0;
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++)
                if (statCompBoard.iComputerBoard[i][j] == 1)
                    iRemainShips++;

        // if any ships remain, guess for more
        if (iRemainShips)
        {
            // computer generates coordinates
            do
            {
                iSign = rand() % BOARD_SIZE;
                iNumber = rand() % BOARD_SIZE;
            }   while (ifFieldCheckedByComp[iNumber][iSign] == true);
            ifFieldCheckedByComp[iNumber][iSign] = true;

            cout << "\n*********************\n";
            cout << "Komputer losuje pole..." << endl;
            Sleep(2000);
            cout << "Wylosowane pole: " << (iNumber + 1) << (char)(iSign + 'a') << endl;

            // if computer was correct
            if (userBoard[iNumber][iSign] == 1)
            {
                cout << "Komputer zgadl" << endl;
                userBoard[iNumber][iSign] = 2;
            }
            // incorrect guess
            else
            {
                cout << "Komputer nie zgadl" << endl;
                ifGuessed = false;
            }

            cout << endl << "Wcisnij dowolny klawisz\n";
            getch();
        }
        // there are no ships left = computer won
        else
        {
            my_exit tempExit;
            tempExit.exitCompWins();
        }
    }
    return;
}

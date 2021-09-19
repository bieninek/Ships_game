// =========================
//
//  Author: Bartosz Bien
//
//  These methods are only used to display the board
//  There are two methods in this file, one displays computer's board
//  The second displays user's board
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


// =========================
//
//  void my_computer::showComputerBoard() - this method simply displays computer's board to standard output
//
//    INPUT:  none
//    OUTPUT: none
//
// =========================
void my_computer::showComputerBoard()
{
    system("cls");
    cout << "============================\n";
    cout << "Plansza komputera: \n\n \t";

    // here i display the signs to make the board more readable
    char cTemp;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cTemp = i + 'a';
        cout << cTemp <<" ";
    }
    cout << endl;

    // now i display the numbers to make the board more readable
    // and i display computer's ships
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (i + 1 < 10)
            cout << "0" << i + 1 << "\t";
        else
            cout << i + 1 << "\t";

        for(int j = 0; j < BOARD_SIZE; j++)
        {
            // computer's ship can be not found or found
            switch(iComputerBoard[i][j])
            {
            case 0:
                cout << "  "; // no ship
                break;
            case 1:
                cout << "  "; // ship but user doesn't know there's ship
                break;
            case 2:
                cout << "x "; // hit
                break;
            case 3:
                cout << "- "; // user chose this filed but no ship
                break;
            }
        }
        cout << endl;
    }
}


// =========================
//
//  void my_user::showBoard(bool) - this method simply displays user's board to standard output
//
//    INPUT:  bool variable which decides whether the number of users' ships is displayed
//    OUTPUT: none
//
// =========================
void my_user::showBoard(bool bShowShipsNum)
{
    cout << "=======================\n";
    cout << "Plansza gracza\n\n \t";

    // i write signs to improve readability
    char cTemp;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cTemp = i + 'a';
        cout << cTemp <<" ";
    }
    cout << endl;

    // then numbers and ships
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (i + 1 < 10)
            cout << "0" << i + 1 << "\t";
        else
            cout << i + 1 << "\t";

        for(int j = 0; j < BOARD_SIZE; j++)
        {
            switch(userBoard[i][j])
            {
            case 0:
                cout << "  "; // no ship
                break;
            case 1:
                cout << "o "; // ship safe (so far)
                break;
            case 2:
                cout << "x "; // ship hit
                break;
            }
        }
        cout << endl;
    }

    // decides whether display the number of users' ships
    if (bShowShipsNum)
        for (int i = 1, j = 4; i < 5; i++, j--)
            cout << endl << "Masz " << userShipsNumber[i] << " na " << j << " statkow o rozmiarze " << i << " na 1";
}

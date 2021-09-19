// =========================
//
//  Author: Bartosz Bien
//
//  These methods run when the user decides to play singleplayer everything works after generating computer's table
//  All these methods work until the user sets all his ships on the board
//  The main purpose of the methods is to set user's ships on the board
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


// =========================
//
//  void my_user::userPosition() - this method is responsible to put user's ships on the board
//                                 The board when data is saved is called \userBoard[][]\ and there:
//                                   0 - no ship
//                                   1 - there's a ship
//                                   2 - ship was but it was hit
//                                 We can assume that there are ships: 4x1 field, 3x2 fileds, 2x3 fields, 1x4 fields
//                                 The number of the ships is saved in \userShipsNumber[]\
//
//    INPUT:  none
//    OUTPUT: none
//
// =========================
void my_user::userPosition()
{
    // i clear the table = set all the fileds to no ship
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
          userBoard[i][j] = 0;

    // i set that there is no ship
    for (int i = 0; i < 5; i++)
        userShipsNumber[i] = 0;

    int iPositionNumber, iPositionSign, iNum1, iNum2, iSign1, iSign2;
    int iTypeOfShip;
    int iHowManyShipsRemain = 10;

    // i generate ships when they are left
    while(iHowManyShipsRemain)
    {
        system("cls");
        cout << "Witaj w trybie singleplayer. Wpisz wspolrzedne statkow (zero, numer, znak)\n\n";
        showBoard(1);

        cout << "\n\nWspolrzedna poczatku -> enter -> wspolrzedna konca:\n";

        // i beg user to write the positions of the ship
        usersShips(&iPositionNumber, &iPositionSign);
        iNum1 = iPositionNumber;
        iSign1 = iPositionSign;

        usersShips(&iPositionNumber, &iPositionSign);
        iNum2 = iPositionNumber;
        iSign2 = iPositionSign;

        // swap to make bigger value the first
        if (iNum1 < iNum2)
            swap(iNum1, iNum2);

        if (iSign1 < iSign2)
            swap(iSign1, iSign2);

        // i check whether the input is correct
        if ((iNum1 >= 0 && iNum1 < BOARD_SIZE && iSign1 >= 0 && iSign1 < BOARD_SIZE) &&
            (iNum2 >= 0 && iNum2 < BOARD_SIZE && iSign2 >= 0 && iSign2 < BOARD_SIZE) &&
            (iNum1 == iNum2 || iSign1 == iSign2))
        {
            // i check the length of the ship in input
            iTypeOfShip = lengthValidator(iNum1, iNum2, iSign1, iSign2);

            // it means input is correct so the ship can be put
            if (iTypeOfShip)
            {
                userBoard[iNum1][iSign1] = 1;
                userBoard[iNum2][iSign2] = 1;

                while(iNum2 < iNum1)
                {
                    userBoard[iNum2][iSign2] = 1;
                    iNum2++;
                }
                while(iSign2 < iSign1)
                {
                    userBoard[iNum2][iSign2] = 1;
                    iSign2++;
                }
                userShipsNumber[iTypeOfShip]++;
                iHowManyShipsRemain--;
            }
        }
    }

    // this is a kind of the AI - the computer never checks the same field, so i need to set all fields to false
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
          ifFieldCheckedByComp[i][j] = false;
}


// =========================
//
//  void my_user::usersShips(int*, int*) - this method takes the user input and forwards to void my_user::userPosition()
//
//    INPUT:  two pointers which points to the value, coordinates wrote by the user
//    OUTPUT: none explicity
//
// =========================
void my_user::usersShips(int* iPositionNumber, int* iPositionSign)
{
    int a, b;

    // user writes the string with numbers
    string choice;
    choice.clear();
    cin >> choice;

    // and then the string is transformed into the proper format
    a = ((int) choice[0] - '0') * 10 + (int) choice[1] - '0';
    a--;
    *iPositionNumber = a;

    b = (int) choice[2] - 'a';
    *iPositionSign = b;
}


// =========================
//
//  int my_user::lengthValidator(int, int, int, int) - this method checks what the ship length is and returns the length
//
//    INPUT:  four ints which are coordinates of the ship
//    OUTPUT: length of the ship
//
// =========================
int my_user::lengthValidator(int iNum1, int iNum2, int iSign1, int iSign2)
{
    // -1 means there's error when the value doesn't change
    int iLength = -1;

    // the same numbers = different signs
    if (iNum1 == iNum2)
    {
        iLength = iSign1 - iSign2 + 1;
        if (userShipsNumber[iLength] == (5 - iLength) || iLength > 4)
            return 0;
        else
            return iLength;
    }
    // the same signs = different numbers
    else
    {
        iLength = iNum1 - iNum2 + 1;
        if (userShipsNumber[iLength] == (5 - iLength) || iLength > 4)
            return 0;
        else
            return iLength;
    }
}

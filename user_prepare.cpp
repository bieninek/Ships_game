#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


void my_user::userPosition()
{
    //int userBoard[BOARD_SIZE][BOARD_SIZE] = {0}; // 0 - no ship, 1 - there is a ship, 2 - it was hit
    //int userShipsNumber[5] = {0}; // 4x1 field, 3x2 fileds, 2x3 fields, 1x4 fields
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
          userBoard[i][j] = 0;

    for (int i = 0; i < 5; i++)
        userShipsNumber[i] = 0;

    int iPositionNumber, iPositionSign, iNum1, iNum2, iSign1, iSign2;
    int iTypeOfShip;
    int iHowManyShipsRemain = 10;

    while(iHowManyShipsRemain)
    {
        system("cls");
        cout << "Witaj w trybie singleplayer. Wpisz wspolrzedne statkow (zero, numer, znak)\n\n";
        showBoard(1);

        cout << "\n\nWspolrzedna poczatku -> enter -> wspolrzedna konca:\n";

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

        if ((iNum1 >= 0 && iNum1 < BOARD_SIZE && iSign1 >= 0 && iSign1 < BOARD_SIZE) &&
            (iNum2 >= 0 && iNum2 < BOARD_SIZE && iSign2 >= 0 && iSign2 < BOARD_SIZE) &&
            (iNum1 == iNum2 || iSign1 == iSign2)) // it needs to be improved eg. sign the first, next number or two times the same ship
        {
            iTypeOfShip = lengthValidator(iNum1, iNum2, iSign1, iSign2);

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

    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
          ifFieldCheckedByComp[i][j] = false;


}




void my_user::usersShips(int* iPositionNumber, int* iPositionSign)
{
    int a, b;

    string choice; // requires cstring
    choice.clear();
    cin >> choice;

    a = ((int) choice[0] - '0') * 10 + (int) choice[1] - '0';
    a--;
    *iPositionNumber = a;

    b = (int) choice[2] - 'a';
    *iPositionSign = b;
}


int my_user::lengthValidator(int iNum1, int iNum2, int iSign1, int iSign2)
{
    int iLength = -1;

    if (iNum1 == iNum2)
    {
        iLength = iSign1 - iSign2 + 1;
        if (userShipsNumber[iLength] == (5 - iLength) || iLength > 4)
        {
            return 0;
        }
        else
        {
            return iLength;
        }
    }
    else
    {
        iLength = iNum1 - iNum2 + 1;
        if (userShipsNumber[iLength] == (5 - iLength) || iLength > 4)
        {
            return 0;
        }
        else
        {
            return iLength;
        }
    }
}


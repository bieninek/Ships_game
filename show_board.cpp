#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"

void my_computer::showComputerBoard()
{
    system("cls");
    cout << "============================\n";
    cout << "Plansza komputera: \n\n \t";

    // ====

    char cTemp;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cTemp = i + 'a';
        cout << cTemp <<" ";
    }
    cout << endl;

    // ====

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (i + 1 < 10)
            cout << "0" << i + 1 << "\t";
        else
            cout << i + 1 << "\t";

        for(int j = 0; j < BOARD_SIZE; j++)
        {
            switch(iComputerBoard[i][j])
            {
            case 0:
                cout << "  ";
                break;
            case 1:
                cout << "  "; // space bar because we dont know ships' positions
                break;
            case 2:
                cout << "x ";
                break;
            case 3:
                cout << "- ";
                break;
            }
        }
        cout << endl;
    }
}

void my_user::showBoard(bool bShowShipsNum)
{
    cout << "=======================\n";
    cout << "Plansza gracza\n\n \t";


    char cTemp;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cTemp = i + 'a';
        cout << cTemp <<" ";
    }
    cout << endl;

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
                cout << "  ";
                break;
            case 1:
                cout << "o ";
                break;
            case 2:
                cout << "x ";
                break;
            }
        }
        cout << endl;
    }

    if (bShowShipsNum)
    {
        for (int i = 1, j = 4; i < 5; i++, j--)
        {
            cout << endl << "Masz " << userShipsNumber[i] << " na " << j << " statkow o rozmiarze " << i << " na 1";
        }
    }
}

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


//int iComputerBoard[BOARD_SIZE][BOARD_SIZE];
//int userBoard[BOARD_SIZE][BOARD_SIZE]; // 0 - no ship, 1 - there is a ship, 2 - it was hit
//int userShipsNumber[5];
//bool ifFieldCheckedByComp[BOARD_SIZE][BOARD_SIZE];


void my_computer::startTheGameComp(my_user& statUserBoard)
{
    bool ifGuessed = true;
    char cSign, cNumber;
    int iNumber, iSign, iRemainShips;
    while (ifGuessed)
    {
        cout << endl << endl;

        showComputerBoard();
        statUserBoard.showBoard(0);
        cout << "\n*********************\n";

        iRemainShips = 0;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (iComputerBoard[i][j] == 1)
                {
                    iRemainShips++;
                }
            }
        }

        if (iRemainShips)
        {
            cout << "\n\nTeraz Ty zgadnij gdzie lezy statek komputera:\n\n";
            cout << "Znak: ";
            cin >> cSign;
            cout << "Numer: ";
            cin >> cNumber;

            cout << "Wpisane pole: " << cNumber << cSign << endl;

            iSign = (int)(cSign - 'a');
            iNumber = (int)(cNumber - '1');
            if (iComputerBoard[iNumber][iSign] == 1)
            {
                cout << "Uzytkownik zgadl" << endl;
                iComputerBoard[iNumber][iSign] = 2;

                cout << endl << "Wcisnij dowolny klawisz\n";
                getch();
            }
            else
            {
                cout << "Uzytkownik nie zgadl" << endl;
                iComputerBoard[iNumber][iSign] = 3;
                ifGuessed = false;
            }
        }
        else
        {
            my_exit pomExit;
            pomExit.exitUserWins();
        }
    }
    //============================
/*
    cout << endl << "Wcisnij dowolny klawisz\n";
    getch();

    my_user pomUser;
    pomUser.startTheGame();*/
    return;
}

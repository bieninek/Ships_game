#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"



void my_user::startTheGame(my_computer& statCompBoard)
{
    bool ifGuessed = true;
    int iSign, iNumber, iRemainShips;
    while (ifGuessed)
    {
        //system("cls");
        //cout << "Plansza gracza\n\n";

        statCompBoard.showComputerBoard();
        showBoard(0);

        iRemainShips = 0;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (statCompBoard.iComputerBoard[i][j] == 1)
                {
                    iRemainShips++;
                }
            }
        }

//        cout << "remain \n" << iRemainShips;
//    getch();

        if (iRemainShips)
        {
            do
            {
                iSign = rand() % BOARD_SIZE;
                iNumber = rand() % BOARD_SIZE;
            } while (ifFieldCheckedByComp[iNumber][iSign] == true);
            ifFieldCheckedByComp[iNumber][iSign] = true;

            cout << "\n*********************\n";
            cout << "Komputer losuje pole..." << endl;
            Sleep(2000);
            cout << "Wylosowane pole: " << (iNumber + 1) << (char)(iSign + 'a') << endl;

            if (userBoard[iNumber][iSign] == 1)
            {
                cout << "Komputer zgadl" << endl;
                userBoard[iNumber][iSign] = 2;
            }
            else
            {
                cout << "Komputer nie zgadl" << endl;
                ifGuessed = false;
            }

            cout << endl << "Wcisnij dowolny klawisz\n";
            getch();
        }
        else
        {
            my_exit tempExit;
            tempExit.exitCompWins();
        }
    }
    //============================
/*
    my_computer pomComp;
    pomComp.startTheGameComp();*/
    return;
}

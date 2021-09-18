#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"



void my_computer::createComputerBoard()
{
    // I clear the board and then fulfill with ships
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            iComputerBoard[i][j] = 0;

    // i prepare to generate positions for the ships
    srand(time(NULL)); // requires ctime, cstdio

    // this loop creates 4 sizes of ships
    // the nested one creates 5-n ships for n-sized ship
    for (int i = 4; i > 0; i--)
        for (int j = 1; (j + i) <= 5; j++)
            randomShips(i);

    // at the end i save the computer's board to .txt file
    saveComputerBoard();
}


void my_computer::randomShips(int iNumOfFields)
{
    int iFieldX, iFieldY, iDirection; // direction: 0 - to the right, 1 downwards
    int iPom;

    while (1 == 1) // !!!!!!! true?
    {
        iPom = 0;

        iFieldX = rand() % BOARD_SIZE;
        iFieldY = rand() % BOARD_SIZE;

        while (iFieldX > (BOARD_SIZE - iNumOfFields))
            iFieldX --;
        while (iFieldY > (BOARD_SIZE - iNumOfFields))
            iFieldY --;

        iDirection = rand() % 2;

        if (iDirection == 0)
        {
            for (int i = 0; i < iNumOfFields; i++)
            {
                if (iComputerBoard[iFieldX + i][iFieldY] == 1)
                {
                    iPom++;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < iNumOfFields; i++)
            {
                if (iComputerBoard[iFieldX][iFieldY + i] == 1)
                {
                    iPom++;
                    break;
                }
            }
        }

        // fields checked
        if (iPom == 0)
        {
            if (iDirection == 0)
            {
                for (int i = 0; i < iNumOfFields; i++)
                {
                    iComputerBoard[iFieldX + i][iFieldY] = 1;
                }
            }
            else
            {
                for (int i = 0; i < iNumOfFields; i++)
                {
                    iComputerBoard[iFieldX][iFieldY + i] = 1;
                }
            }
            return;
        }
    }
}


void my_computer::saveComputerBoard()
{
    ofstream output("computer_board.txt");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            output << iComputerBoard[i][j];
        output << endl;
    }
}

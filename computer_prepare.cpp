// =========================
//
//  Author: Bartosz Bien
//
//  These methods run when the user decides to play singleplayer
//  That means he wants to play with the computer, so the computer has to place somewhere its ships
//  All the methods inside this file are used during placing computer's ships
//
// =========================

#include "classes.hpp"
#include "includes.hpp"
#include "defines.hpp"


// =========================
//
//  void my_computer::createComputerBoard() - this method creates computer's board
//                                            The computer's board is held in \iComputerBoard[][]\ - see \classes.hpp\ for details
//                                            This method invokes method void my_computer::randomShips(int) to generate one ship with a specified size
//                                            This method invokes method void my_computer::saveComputerBoard() to save the board to a .txt file
//
//    INPUT:  none
//    OUTPUT: none
//    NOTE:   This function requires \ctime\ and \cstdio\ because of using pseudo-generating numbers
//
// =========================
void my_computer::createComputerBoard()
{
    // I clear the board and then fulfill with ships
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            iComputerBoard[i][j] = 0;

    // i prepare to generate positions for the ships
    srand(time(NULL));

    // this loop creates 4 sizes of ships
    // the nested one creates 5-n ships for n-sized ship
    for (int i = 4; i > 0; i--)
        for (int j = 1; (j + i) <= 5; j++)
            randomShips(i);

    // at the end i save the computer's board to .txt file
    saveComputerBoard();
}

// =========================
//
//  void my_computer::randomShips(int iNumOfFields) - this method is used to generate one ship on the board
//                                                    The ship's size is specified in the variable \iNumOfFields\
//
//    INPUT:  iNumOfFields - it carries the requested number of fields which should be occupied by a ship
//    OUTPUT: none
//
// =========================
void my_computer::randomShips(int iNumOfFields)
{
    // iFieldX keeps the position (like on the map) of the beginning of the ship
    // iFieldY keeps the position but depended on the other axis
    // iDirection means whether the ship is horizontally (0) or upright (1)
    int iFieldX, iFieldY, iDirection;
    int iTemp;

    while (true)
    {
        iTemp = 0;
        iFieldX = rand() % BOARD_SIZE;
        iFieldY = rand() % BOARD_SIZE;

        // this prevents from generating a ship which would stick out behind the board
        while (iFieldX > (BOARD_SIZE - iNumOfFields))
            iFieldX --;
        while (iFieldY > (BOARD_SIZE - iNumOfFields))
            iFieldY --;

        // now i choose the direction
        iDirection = rand() % 2;

        // and i generate the ship depend on the direction
        if (iDirection == 0)
            for (int i = 0; i < iNumOfFields; i++)
                if (iComputerBoard[iFieldX + i][iFieldY] == 1)
                {
                    iTemp++;
                    break;
                }
        else
            for (int i = 0; i < iNumOfFields; i++)
                if (iComputerBoard[iFieldX][iFieldY + i] == 1)
                {
                    iTemp++;
                    break;
                }

        // fields checked
        if (iTemp == 0)
        {
            if (iDirection == 0)
                for (int i = 0; i < iNumOfFields; i++)
                    iComputerBoard[iFieldX + i][iFieldY] = 1;
            else
                for (int i = 0; i < iNumOfFields; i++)
                    iComputerBoard[iFieldX][iFieldY + i] = 1;
            return;
        }
    }
}

// =========================
//
//  void my_computer::saveComputerBoard() - this method simply prints the computer's board to a .txt file
//                                          Inside the file 1 means \there's a ship\ and 0 means \no ship\
//
//    INPUT:  none
//    OUTPUT: none
//    NOTE:   This method requires \fstream\ because of redirection of the output stream
//
// =========================
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

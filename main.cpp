// 1. poprawic dane wpisane przez uzytkownika
// 2. gdy komputer trafi to sprawdza otoczenie punktu

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <fstream>
using namespace std;


#define ARROW_UP 72
#define ARROW_DOWN 80
#define ELEMENTS_IN_MENU 3 // 3 elements: singleplayer, multiplayer, exit
#define ENTER 13

#define BOARD_SIZE 7

// przeniesc to jak bedzie dzialac, dac to do klasy. Zmieniam wartosc zmiennej za pomoca metody, zeby sie zmienila wartosc w calej klasie.
int iComputerBoard[BOARD_SIZE][BOARD_SIZE];
int userBoard[BOARD_SIZE][BOARD_SIZE]; // 0 - no ship, 1 - there is a ship, 2 - it was hit
int userShipsNumber[5];
bool ifFieldCheckedByComp[BOARD_SIZE][BOARD_SIZE];

// ========================================


void multiplayer()
{
    system("cls");
    cout << "multiplayer\n";
    getch();
}

// *************** Prototypes **********************************************

class my_user
{
public:
    void userPosition();

public:
    void showBoard(int tab[BOARD_SIZE][BOARD_SIZE], int*, int);

private:
    void usersShips(int*, int*);

private:
    int lengthValidator(int, int, int, int, int*);

public:
    void startTheGame();
};


class my_computer
{
public:
    void createComputerBoard();

private:
    void randomShips(int, int tab[BOARD_SIZE][BOARD_SIZE]);

public:
    void showComputerBoard(int tab[BOARD_SIZE][BOARD_SIZE]);

public:
    void startTheGameComp();

private:
    void saveComputerBoard(); // requires <fstream>
};


class my_exit
{
public:
    void exitMenu();

public:
    void exitCompWins();

public:
    void exitUserWins();
};


// *************** COMPUTER **********************************************

void my_computer::createComputerBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            iComputerBoard[i][j] = 0;
        }
    }

    srand(time(NULL)); // requires ctime, cstdio

    for (int i = 4; i > 0; i--)
    {
        for (int j = 1; (j + i) <= 5; j++)
        {
            randomShips(i, iComputerBoard);
        }
    }

    saveComputerBoard();
}


void my_computer::randomShips(int iNumOfFields, int iComputerBoard[BOARD_SIZE][BOARD_SIZE])
{
    int iFieldX, iFieldY, iDirection; // direction: 0 - to the right, 1 downwards
    int iPom;

    while (1 == 1)
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


void my_computer::showComputerBoard(int iComputerBoard[BOARD_SIZE][BOARD_SIZE])
{
    system("cls");
    cout << "============================\n";
    cout << "Plansza komputera: \n\n";
    int i, j;
    char cPom;

    cout << " \t";
    for (i = 0; i < BOARD_SIZE; i++)
    {
        cPom = i + 'a';
        cout << cPom <<" ";
    }
    cout << endl;

    for (i = 0; i < BOARD_SIZE; i++)
    {
        if (i + 1 < 10)
            cout << "0" << i + 1 << "\t";
        else
            cout << i + 1 << "\t";

        for(j = 0; j < BOARD_SIZE; j++)
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


void my_computer::startTheGameComp()
{
    bool ifGuessed = true;
    char cSign, cNumber;
    int iNumber, iSign, iRemainShips;
    while (ifGuessed)
    {
        cout << endl << endl;

        showComputerBoard(iComputerBoard);
        my_user pomUserBoard;
        pomUserBoard.showBoard(userBoard, userShipsNumber, 0);
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

    cout << endl << "Wcisnij dowolny klawisz\n";
    getch();

    my_user pomUser;
    pomUser.startTheGame();
}


void my_computer::saveComputerBoard()
{
    ofstream output("computer_board.txt");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            output << iComputerBoard[i][j];
        }
        output << endl;
    }
}
// *************** USER *************************************************


void my_user::userPosition()
{
    //int userBoard[BOARD_SIZE][BOARD_SIZE] = {0}; // 0 - no ship, 1 - there is a ship, 2 - it was hit
    //int userShipsNumber[5] = {0}; // 4x1 field, 3x2 fileds, 2x3 fields, 1x4 fields
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
          userBoard[i][j] = 0;

    for (int i = 0; i < 5; i++)
        userShipsNumber[i] = 0;

    bool t = true;
    int iPositionNumber, iPositionSign, iNum1, iNum2, iSign1, iSign2;
    int iTypeOfShip;
    int iHowManyShipsRemain = 10;

    while(iHowManyShipsRemain)
    {
        system("cls");
        cout << "Witaj w trybie singleplayer. Wpisz wspolrzedne statkow (zero, numer, znak)\n\n";
        showBoard(userBoard, userShipsNumber, 1);

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
            iTypeOfShip = lengthValidator(iNum1, iNum2, iSign1, iSign2, userShipsNumber);

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

    startTheGame();
}

void my_user::showBoard(int userBoard[BOARD_SIZE][BOARD_SIZE], int userShipsNumber[5], int iShowShipsNum)
{
    cout << "=======================\n";
    cout << "Plansza gracza\n\n";

    int i, j;
    char cPom;

    cout << " \t";
    for (i = 0; i < BOARD_SIZE; i++)
    {
        cPom = i + 'a';
        cout << cPom <<" ";
    }
    cout << endl;

    for (i = 0; i < BOARD_SIZE; i++)
    {
        if (i + 1 < 10)
            cout << "0" << i + 1 << "\t";
        else
            cout << i + 1 << "\t";

        for(j = 0; j < BOARD_SIZE; j++)
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

    if (iShowShipsNum)
    {
        for (int i = 1, j = 4; i < 5; i++, j--)
        {
            cout << endl << "Masz " << userShipsNumber[i] << " na " << j << " statkow o rozmiarze " << i << " na 1";
        }
    }
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


int my_user::lengthValidator(int iNum1, int iNum2, int iSign1, int iSign2, int userShipsNumber[5])
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


void my_user::startTheGame()
{
    bool ifGuessed = true;
    int iSign, iNumber, iRemainShips;
    while (ifGuessed)
    {
        //system("cls");
        //cout << "Plansza gracza\n\n";

        my_computer pomCompBoard;
        pomCompBoard.showComputerBoard(iComputerBoard);
        showBoard(userBoard, userShipsNumber, 0);

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
            my_exit pomExit;
            pomExit.exitCompWins();
        }
    }
    //============================

    my_computer pomComp;
    pomComp.startTheGameComp();
}


// *************** EXIT *****************************************************

void my_exit::exitCompWins()
{
    system("cls");
    cout << "\aKomputer wygral\n\nWcisnij dowolny klawisz, aby wyjsc...";

    getch();
    exit(0);
}

void my_exit::exitMenu()
{
    system("cls");
    cout << "\aWyjscie z programu...";

    Sleep(2000);
    exit(0);
}

void my_exit::exitUserWins()
{
    system("cls");
    cout << "\aUzytkownik wygral\n\nWcisnij dowolny klawisz, aby wyjsc...";

    getch();
    exit(0);
}

//**************** INTERFACE**************************************************

class my_interface
{
public:
    void userChoice();

private:
    void display(int);
};


void my_interface::userChoice()
{
    int iPosition = 1;
    char cKey;

    while (true)
    {
        // display
        display(iPosition);

        // get user's key
        cKey = getch(); // getch() requires conio.h
        switch(cKey)
        {
        case ARROW_DOWN:
            if (iPosition == ELEMENTS_IN_MENU)
                iPosition = 1;
            else
                iPosition++;
            break;
        case ARROW_UP:
            if (iPosition == 1)
                iPosition = ELEMENTS_IN_MENU;
            else
                iPosition--;
            break;
        case ENTER:
            switch (iPosition)
            {
            case 1:
            {
                my_computer pomComputer;
                pomComputer.createComputerBoard();

                my_user pomUser;
                pomUser.userPosition();

                return;
            }
            case 2:
            {
                multiplayer();
                return;
            }
            case 3:
            {
                my_exit pomExit;
                pomExit.exitMenu();
                return;
            }
            }
            break;
        }
    }
}


void my_interface::display(int iPosition)  // requires windows.h
{
    system("cls");
    cout << "Statki \n\n";
    switch (iPosition)
    {
    case 1:
        cout << "\n\t\t\t\t>>>\t\tTryb Singleplayer\t\t<<<\n\t\t\t\tTryb Multiplayer\n\t\t\t\tWyjscie\n";
        break;
    case 2:
        cout << "\n\t\t\t\tTryb Singleplayer\n\t\t\t\t>>>\t\tTryb Multiplayer\t\t<<<\n\t\t\t\tWyjscie\n";
        break;
    case 3:
        cout << "\n\t\t\t\tTryb Singleplayer\n\t\t\t\tTryb Multiplayer\n\t\t\t\t>>>\t\tWyjscie\t\t\t\t<<<\n";
        break;
    }
}



// *************************** MAIN *********************************
int main()
{
    my_interface pom;
    pom.userChoice();

    return 0;
}

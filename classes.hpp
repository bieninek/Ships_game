#include "defines.hpp"

class my_computer;

class my_user
{
    friend class my_computer;
    friend class my_interface;

    public:
        void userPosition();
        void startTheGame(my_computer&);

    private:
        void usersShips(int*, int*);
        int lengthValidator(int, int, int, int);
        void showBoard(bool);

        int userBoard[BOARD_SIZE][BOARD_SIZE];
        int userShipsNumber[5];
        bool ifFieldCheckedByComp[BOARD_SIZE][BOARD_SIZE];
};


class my_computer
{
    friend class my_user;
    friend class my_interface;

    public:
        void createComputerBoard();
        void startTheGameComp(my_user&);

    private:
        void randomShips(int);
        void saveComputerBoard(); // requires <fstream>
        void showComputerBoard();

        int iComputerBoard[BOARD_SIZE][BOARD_SIZE];
};


class my_exit
{
    friend class my_interface;
    friend class my_user;
    friend class my_computer;

    private:
        void exitMenu();
        void exitCompWins();
        void exitUserWins();
};

class my_interface
{
    public:
        void userChoice();

    private:
        void display(int);
};


class multiplayer
{
    friend class my_interface;

    private:
        multiplayer();
};

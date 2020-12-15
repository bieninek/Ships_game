#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


#define ARROW_UP 72
#define ARROW_DOWN 80
#define ELEMENTS_IN_MENU 3 // 3 elements: singleplayer, multiplayer, exit
#define ENTER 13
#define ESC 27 // not in use yet


void singleplayer()
{
    system("cls");
    cout << "Sigleplayer\n";
    getch();
}


void multiplayer()
{
    system("cls");
    cout << "multiplayer\n";
    getch();
}

void my_exit()
{
    system("cls");
    return;
}



class my_interface
{
public:
    void userChoice();

public:
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
                singleplayer();
                return;
            case 2:
                multiplayer();
                return;
            case 3:
                my_exit();
                return;
            }
            break;
        }
    }
}


void my_interface::display(int iPosition)  // requires windows.h
{
    system("cls");
    cout << "Statki 0.1\n\n";
    switch (iPosition)
    {
    case 1:
        cout << "\n\t\t\t\t>>>\t\tSingleplayer\t\t<<<\n\t\t\t\tMultiplayer\n\t\t\t\tExit\n";
        break;
    case 2:
        cout << "\n\t\t\t\tSingleplayer\n\t\t\t\t>>>\t\tMultiplayer\t\t<<<\n\t\t\t\tExit\n";
        break;
    case 3:
        cout << "\n\t\t\t\tSingleplayer\n\t\t\t\tMultiplayer\n\t\t\t\t>>>\t\tExit\t\t\t<<<\n";
        break;
    }
}


int main()
{
    my_interface pom;
    pom.userChoice();

    return 0;
}

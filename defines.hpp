// =========================
//
//  Author: Bartosz Bien
//
//  This file keeps all the constans values which are used in the programme
//  There is more decriptive info below
//  Of course all the values can be modified (e.g. because of having more options in menu, bigger board),
//  but it's not reccomended to change these values without changes in the other files
//
// =========================

// =========================
//  This section is used in the main menu
//  All the button on keyboard has its number
//  But it's easier to use names like "ENTER" instead of 13
// =========================

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ENTER 13

// =========================
// This defines number of elements in menu
// Now we have three options: singleplayer, multiplayer (not working), exit
// =========================

#define ELEMENTS_IN_MENU 3

// =========================
// This defines board size
// I was playing and switching this value but I think number 7 is optimal
// Its consequence is about 7-10 minute game
// =========================

#define BOARD_SIZE 7

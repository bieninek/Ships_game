// =========================
//
//  Author: Bartosz Bien
//
//  This file has all the external files which aren't parts of my project
//  All the libraries have informations below
//  There are of course listed reasons why the includes appear
//  This is to prevent the situation that someone modifies other files and some libraries are unnecessary
//  And they are like rubish...
//
// =========================

// =========================
//  It's a primary library, I don't think it would be removed...
// =========================

#include <iostream>

// =========================
//  This appears because of using \system("cls")\ in interface.cpp
// =========================

#include <windows.h>

// =========================
//  This appears because of using \getch()\ in many, many files
// =========================

#include <conio.h>

// =========================
//  This appears because of generating psudo-randomly computer's board in computer.cpp
// =========================
#include <ctime>
#include <cstdio>

// =========================
//  This is used because after generating computer's board, the board is saved in the .txt file
// =========================

#include <fstream>

// =========================
//  This is used in user_prepare.cpp file
// =========================

#include <cstring>

// =========================
//  Meh, I don't use any external namespaces and I don't create any mine, so I decided to keep this line
// =========================

using namespace std;

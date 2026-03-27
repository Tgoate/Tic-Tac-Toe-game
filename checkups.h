#ifndef CHECKUPS_H
#define CHECKUPS_H
#include <iostream>
using std::cout; using std::cin;

void CheckForMistakeAndUpdate(char board[][3], char *ptr, char playerX, char playerO);
int CheckForWinner(char board[][3]);

#endif 
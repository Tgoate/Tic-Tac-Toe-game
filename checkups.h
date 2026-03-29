#ifndef CHECKUPS_H
#define CHECKUPS_H

void CheckForMistakeAndUpdate(char board[][3], char *ptr, char playerX, char playerO);
int CheckForWinner(char board[][3]);
bool safeToRead(int &output);

#endif 
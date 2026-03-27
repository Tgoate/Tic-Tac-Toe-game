#include <iostream>
#include <cmath>
#include "checkups.h"
using std::cout; using std::cin;

void CheckForMistakeAndUpdate(char board[][3], char *ptr, char playerX, char playerO){
    int row = -1;
    int column = -1;
    
    while(true){
        cout << "\nEnter the row and column (0-2) you wish to fill: ";
        cin >> row >> column;
        if (row < 0 || column < 0 || row >= 3 || column >= 3){
            cout << "Error: Row or Column out of range.\nTry again.\n\n";
        }
        else if (board[row][column] != ' '){
            cout << "Space already occupied.\nTry again.\n\n";
        }
        if (cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Wrong Input!\nTry again.\n\n";
        }

        if ((row >= 0 && row <= 2) && (column >= 0 && column <= 2)){
            board[row][column] = *ptr;
            cin.ignore();
            *ptr = (*ptr == playerO) ? playerX : playerO;
            break;
        }

        int row = -1;
        int column = -1;
        }

    return;
}

int CheckForWinner(char board[][3]){
    
    for (int i = 0 ; i < 3 ; i++){
     //check for vertical winner
       if (board [i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            cout << "Player " << board[i][0] << " won!\n";
            return 1;
       }
    //check for horizontal winner
        if (board [0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            cout << "Player " << board[0][i] << " won!\n";
            return 1;
        }
    //check for diagonal winner
        //main diagonal
        if (board [0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            cout << "Player " << board[0][0] << " won!\n";
            return 1;
       }
       //second diagonal
       if (board [0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            cout << "Player " << board[0][2] << " won!\n";
            return 1;
        }
    }

    return 0;
}


#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include "checkups.h"
using std::cout; using std::cin; using std::getline; using std::string;

bool safeToRead(int &output){
    string input;
    getline(cin, input);

    if (input.empty())
        return false;

    //checks if every char of the input is an int
    for (int c = 0; c < input.size(); c++){
        if (!isdigit(input[c]))
            return false;
    }
    
    output = stoi(input);
    return true;
}

void CheckForMistakeAndUpdate(char board[][3], char *ptr, char playerX, char playerO){
    int row = -1;
    int column = -1;

    while(true){
        cout << "\nEnter the row and column (0-2) you wish to fill:\n";
        cout << "Row: ";
        if (!safeToRead(row) || row > 2 || row < 0){
            cout << "Wrong Input!\nTry again.\n\n";
            continue;
        }
        
        cout << "Column: ";
        if (!safeToRead(column) || column < 0 || column > 2){
            cout << "Wrong Input!\nTry again.\n\n";
            continue;
        }

        if (board[row][column] != ' '){
            cout << "Wrong Input! Spot taken.\nTry again.\n\n";
            continue;
        }

        else 
            break;

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


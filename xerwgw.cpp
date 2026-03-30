#include <iostream>
#include <iomanip>
#include <string>
#include "checkups.h"
#include "compAlgorithm.h"
using std::cout; using std::cin; using std::endl; using std::getline; using std::string; using std::setw;

void PrintBoard(char board[][3]){
    cout << endl;
    cout << setw(50) << "    0    1    2 " << endl;
    cout << setw(50) << "      |    |    " << endl;
    cout << setw(38) << "0   " << board[0][0] << " |  " << board[0][1] << " |  " << board[0][2] << endl;
    cout << setw(50) << "  ____|____|____" << endl;
    cout << setw(50) << "      |    |    " << endl;
    cout << setw(38) << "1   " << board[1][0] << " |  " << board[1][1] << " |  " << board[1][2] << endl;
    cout << setw(50) << "  ____|____|____" << endl;
    cout << setw(50) << "      |    |    " << endl;
    cout << setw(38) << "2   " << board[2][0] << " |  " << board[2][1] << " |  " << board[2][2] << endl;
    cout << setw(50) <<"      |    |    " << endl << endl;

}

void letsplayHuman(char board[][3], int result , char *ptr , char playerX , char playerO){  
    for (int i = 0 ; i < 9 ; i++){
        PrintBoard(board);

        if (i >= 4)
            result = CheckForWinner(board);
        if (result == 1)
            break;

        cout << "Player: " << *ptr << " is playing.\n";
        
        CheckForMistakeAndUpdate(board, ptr, playerX, playerO);
    }
    
    if (result == 0)
        cout << "Y'all both trash, get better bruh.\n\n";
    
    return;
}

void CompPlaysFirst(char board[][3], int result, char* ptr, char playerX, char playerO){
    for (int i = 0; i <= 4; i++){
        
        CompPlays1(i, board, ptr, playerX, playerO);
        
        if (i >= 2)
            result = CheckForWinner(board);

        PrintBoard(board);    

        if (result == 1)
            break;

        if (i == 4)
            break;
        
        CheckForMistakeAndUpdate(board, ptr, playerX, playerO);

        PrintBoard(board);

        if (i >= 2)
            result = CheckForWinner(board);

        if (result == 1)
            break;
    }

    if (result == 0)
        cout << "Boy you trash, cant even beat a damn computer.\n\n";
    
    return;
}

void HumanPlaysFirst(char board[][3], int result, char* ptr, char playerX, char playerO){
    for (int i = 0; i <= 4; i++){
        if (i >= 2)
            result = CheckForWinner(board);

        PrintBoard(board);

        if (result == 1)
            break;     

        CheckForMistakeAndUpdate(board, ptr, playerX, playerO);
        
        if (result == 1)
            break;

        if (i == 4){
            PrintBoard(board);    
            break;
        }
        
        if (i >= 2)
            result = CheckForWinner(board);

        PrintBoard(board);

        if (result == 1)
            break;

        CompPlays2(i, board, ptr, playerX, playerO);
    }

    if (result == 0)
        cout << "Boy you trash, cant even beat a damn computer.\n\n";
    
    return;
}

void letsplayComputer(char board[][3], int result , char* ptr , char playerX , char playerO){
    int answer = -1;

    while(true){
        cout << "\nDo you wish to play first? (0 - No / 1 - Yes)\n";
        cout << "Answer: ";
        if(!safeToRead(answer) || (answer != 0 && answer != 1)){
            cout << "Damn bruh learn how to type fr.\nTry again though.\n\n";
            continue;
        }
        else 
            break;
    }

    if (answer == 0){
        CompPlaysFirst(board, result, ptr, playerX, playerO);
    }
    else if(answer == 1){
        HumanPlaysFirst(board, result, ptr, playerX, playerO);
    }

    return ;
}

void letsplay(){

    char board[3][3]={
        {' ', ' ', ' ' },
        {' ', ' ', ' ' },
        {' ', ' ', ' ' }
    };

    char playerX = 'X';
    char playerO = 'O';
    char winner = ' ';
    char currentPlayer = playerX;
    char *ptr = &currentPlayer; 

    int result = -1;
    int gameOption;

    while(true){
        cout << "\nDo you wish to play with a computer or with a person? (1 - Person / 2 - Computer):\nAnswer ";
        if(!safeToRead(gameOption) || (gameOption != 1 && gameOption != 2)){
            cout << "Damn bruh learn how to type.\n";
            cout << "Try again big guy.\n\n";
            continue;
        }
        else 
            break;   
    }

    if (gameOption == 1){
        letsplayHuman(board, result , ptr , playerX , playerO);
    }
    else if (gameOption == 2){
        letsplayComputer(board, result , ptr , playerX , playerO);
    }
}

int main(){
    int answer = -1;
    
    while(true){
        cout << "Do you wish to play a game of TicTacToe? (1 - Yes / 0 - No)\nAnswer: ";
        if (!safeToRead(answer) || (answer != 0 && answer != 1)){
            cout << "Wrong Input!\nTry again.\n\n";
            continue;
        }
        if (answer == 0){
            cout << "Damn bruh, fuh you";
            return 0;
        }
        if (answer == 1){
            letsplay();
            break;
        }
    }

    while(true){
        cout << "Do you wish to play another game of Tic Tac Toe? (1. Yes / 0. No):\nAnswer: ";
        if (!safeToRead(answer) || (answer != 0 && answer != 1)){
            cout << "Wrong Input!\nTry again.\n\n";
            continue;
        }
        if (answer == 0){
            cout << "Alright Buddy!";
            return 0;
        }
        if (answer == 1){
            letsplay();
        }
    }

}
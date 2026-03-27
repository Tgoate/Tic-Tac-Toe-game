#include <iostream>
#include <iomanip>
#include "checkups.h"
#include "compAlgorithm.h"
using std::cout; using std::cin; using std::endl;

void PrintBoard(char board[][3]){
    cout << "   0     1     2 " << endl;
    cout << "      |    |    " << endl;
    cout << "0   " << board[0][0] << " |  " << board[0][1] << " |  " << board[0][2] << endl;
    cout << "  ____|____|____" << endl;
    cout << "      |    |    " << endl;
    cout << "1   " << board[1][0] << " |  " << board[1][1] << " |  " << board[1][2] << endl;
    cout << "  ____|____|____" << endl;
    cout << "      |    |    " << endl;
    cout << "2   " << board[2][0] << " |  " << board[2][1] << " |  " << board[2][2] << endl;
    cout << "      |    |    " << endl;

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
        cout << "Y'all both trash, get better bruh.\n";
    
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
        cout << "Y'all both trash, get better bruh.\n\n";
    
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
        cout << "Y'all both trash, get better bruh.\n\n";
    
    return;
}

void letsplayComputer(char board[][3], int result , char* ptr , char playerX , char playerO){
    int answer = -1;
    while(true){
        cout << "Do you wish to play first? (0 - No / 1 - Yes)\n";
        cout << "Answer: ";
        cin >> answer;
        if (answer == 0 || answer == 1)
            break;
        else {
            cout << "Try again buddy!\n";
        } 

        cin.clear();
        cin.ignore(INT_MAX, '\n');
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
        cout << "Do you wish to play with a computer or with a person? (1 - Person / 2 - Computer): ";
        cin >> gameOption;
            if (gameOption == 1 || gameOption == 2){
                break;
            }
            else if (gameOption > 2 || gameOption < 1){
                cout << "Damn bruh learn how to type.\n";
                cout << "Try again big guy.\n\n";
            }
    }
    if (gameOption == 1){
        letsplayHuman(board, result , ptr , playerX , playerO);
    }
    else if (gameOption == 2){
        letsplayComputer(board, result , ptr , playerX , playerO);
    }
}

int main(){
    int answer = -1, gameOption = -1;
    
    cout << "Do you wish to play a game of TicTacToe? (1 - Yes / 0 - No)\nAnswer: ";

    while(true){
        cin >> answer;
        if (answer == 1){    
            letsplay();
            break;
        }
        else if (answer == 0){
            cout << "\nDamn bruh fuh you";
            return 0;
        }
        else if (cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nDamn bruh learn how to type.\n";
            cout << "Try again big guy.\n\n";
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }

    while(true){
        cout << "Would you like to play another game? (1 - Yes / 0 - No)\nAnswer: ";
        cin >> answer;

        if (answer == 0){
            cout << "\nOkay buddy!";
            return 0;
        } 
        if (answer == 1){
            letsplay();            
        }
        else if(cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Damn bruh, you genuinely can't type for shit.\n";
            cout << "Try again though.\n\n";
        }
        
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }

}
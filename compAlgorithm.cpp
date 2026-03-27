#include <iostream>
#include "compAlgorithm.h"
#include <cstdlib>
#include <time.h>
#include <cmath>

void CompPlays1(int i,char board[][3],char* ptr, char playerX,char playerO){
    srand(time(NULL));
    int random = rand() % 4 + 1;

    //horizontal variables
    int horizontalCounter = 0;
    int hsavedRow = -1;
    int hsavedColumn = -1;
    bool hsafeSpot = false;
        
    //vertical variables
    int verticalCounter = 0;
    int vsavedRow = -1;
    int vsavedColumn = -1;
    bool vsafeSpot = false;
    
    //main diagonal variables
    int diagonalCounter1 = 0;
    int diagonalSavedRow1 = -1;
    int diagonalSavedColumn1 = -1;
    bool diagonalSafeSpot1 = false;
     
    //second diagonal variables
    int diagonalCounter2 = 0;
    int diagonalSavedRow2 = -1;
    int diagonalSavedColumn2 = -1;
    bool diagonalSafeSpot2 = false;


    if (i == 0 && board[1][1] == ' '){
        board[1][1] = *ptr;
        *ptr = (*ptr == playerO) ? playerX : playerO;
        return;
    }
    
    if (i == 1){
        for (int row = 0 ; row < 3 ; row++){
            if (row != 1 && board[row][row] != ' '){
                if (row + 2 == 2){
                    board[row + 2][row + 2] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
                else{
                    board[row - 2][row - 2] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
            }
            if (row == 0)
                if (board[row][row + 2] != ' '){
                    board[row + 2][row] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
            if (row == 2)
                if (board[row][row - 2] != ' '){
                    board[row - 2][row] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
        }
        
        switch(random){
            case 1:
                if (board[0][0] == ' ')
                    board[0][0] = *ptr;
                break;
            case 2:
                if (board[0][2] == ' ')
                    board[0][2] = *ptr;
                break;
            case 3:
                if (board[2][0] == ' ')
                    board[2][0] = *ptr;
                break;
            case 4:
                if (board[2][2] == ' ') 
                    board[2][2] = *ptr;
                break;
        }
        *ptr = (*ptr == playerO) ? playerX : playerO;
        return;
    }
    
    {
        //checks if comp can win
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column++){
                //horizontal check
                if (board[row][column] == *ptr){
                    horizontalCounter++;
                }
                else if(board[row][column] == ' '){
                    hsavedColumn = column;
                    hsavedRow = row;
                    hsafeSpot = true;
                }
                if (horizontalCounter == 2 && hsafeSpot == true){
                    board[hsavedRow][hsavedColumn] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }

                //vertical check
                if (board[column][row] == *ptr){
                    verticalCounter++;
                }
                else if (board[column][row] == ' '){
                    vsavedColumn = row;
                    vsavedRow = column;
                    vsafeSpot = true;
                }
                if (verticalCounter == 2 && vsafeSpot == true){
                    board[vsavedRow][vsavedColumn] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
            }
            vsafeSpot = false;
            hsafeSpot = false;
            verticalCounter = 0;
            horizontalCounter = 0;
        }

        //checks if comp can win in the main diagonal
        for (int counter = 0; counter < 3; counter++){
            if (board[counter][counter] == *ptr){
                diagonalCounter1++;
            }
            else if(board[counter][counter] == ' '){
                diagonalSavedColumn1 = counter;
                diagonalSavedRow1 = counter;
                diagonalSafeSpot1 = true;
            }

            if (diagonalCounter1 == 2 && diagonalSafeSpot1 == true){
                board[diagonalSavedRow1][diagonalSavedColumn1] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }

        //checks if comp can win in the second diagonal
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column++){
                if (abs(row - column) == 2){
                    if (board[row][column] == *ptr){
                        diagonalCounter2++;
                    }
                    else if (board[row][column] == ' '){
                        diagonalSafeSpot2 = true;
                        diagonalSavedColumn2 = column;
                        diagonalSavedRow2 = row;
                    }
                }
                if (row == 1 && column == 1){
                    if (board[row][column] == *ptr){
                        diagonalCounter2++;
                    }
                    else if (board[row][column] == ' '){
                        diagonalSafeSpot2 = true;
                        diagonalSavedColumn2 = column;
                        diagonalSavedRow2 = row;
                    }
                }
            }
            if (diagonalCounter2 == 2 && diagonalSafeSpot2 == true){
                board[diagonalSavedRow2][diagonalSavedColumn2] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
    }

    char blockingMove = (*ptr == playerO) ? playerX : playerO;
    
    {
        //checks which is the blocking move
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column++){
                //horizontal check
                if (board[row][column] == blockingMove){
                    horizontalCounter++;
                }
                else if(board[row][column] == ' '){
                    hsavedColumn = column;
                    hsavedRow = row;
                    hsafeSpot = true;
                }
                if (horizontalCounter == 2 && hsafeSpot == true){
                    board[hsavedRow][hsavedColumn] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }

                //vertical check
                if (board[column][row] == blockingMove){
                    verticalCounter++;
                }
                else if (board[column][row] == ' '){
                    vsavedColumn = row;
                    vsavedRow = column;
                    vsafeSpot = true;
                }
                if (verticalCounter == 2 && vsafeSpot == true){
                    board[vsavedRow][vsavedColumn] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
            }

            vsafeSpot = false;
            hsafeSpot = false;
            verticalCounter = 0;
            horizontalCounter = 0;
        }

        //checks if comp can block in the main diagonal
        for (int counter = 0; counter < 3; counter++){
            if (board[counter][counter] == blockingMove){
                diagonalCounter1++;
            }
            else if(board[counter][counter] == ' '){
                diagonalSavedColumn1 = counter;
                diagonalSavedRow1 = counter;
                diagonalSafeSpot1 = true;
            }

            if (diagonalCounter1 == 2 && diagonalSafeSpot1 == true){
                board[diagonalSavedRow1][diagonalSavedColumn1] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }

        //checks if comp can block in the second diagonal
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column++){
                if (abs(row - column) == 2){
                    if (board[row][column] == blockingMove){
                        diagonalCounter2++;
                    }
                    else if (board[row][column] == ' '){
                        diagonalSafeSpot2 = true;
                        diagonalSavedColumn2 = column;
                        diagonalSavedRow2 = row;
                    }
                }
                if (row == 1 && column == 1){
                    if (board[row][column] == blockingMove){
                        diagonalCounter2++;
                    }
                    else if (board[row][column] == ' '){
                        diagonalSafeSpot2 = true;
                        diagonalSavedColumn2 = column;
                        diagonalSavedRow2 = row;
                    }
                }
            }
            if (diagonalCounter2 == 2 && diagonalSafeSpot2 == true){
                board[diagonalSavedRow2][diagonalSavedColumn2] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
    }


    int numRows[3] = {};
    int spacesRows[3] = {};

    int numColumns[3] = {};
    int spacesColumns[3] = {};

    int savedRow = -1;
    int savedColumn = -1;

    for (int row = 0 ; row < 3 ; row ++){
        for (int column = 0 ; column < 3 ; column ++ ){
            if (board[row][column] == *ptr){
                numRows[row]++;
            }
            else if (board[row][column] == ' '){
                spacesRows[row]++;
            }
            if (numRows[row] == 1 && spacesRows[row] == 2){
                savedRow = row;
            }
            if (board[column][row] == *ptr){
                numColumns[row]++;
            }
            else if (board[column][row] == ' '){
                spacesColumns[row]++;
            }
            if (numColumns[row] == 1 && spacesColumns[row] == 2){
                savedColumn = row;
            }
            if (savedColumn != -1 && savedRow != -1){
                board[savedRow][savedColumn] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
    }

    for (int counter = 0 ; counter < 3 ; counter++){
        if (savedRow != -1){
            if(board[savedRow][counter] == ' '){
                board[savedRow][counter] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
        else if(savedColumn != -1){
            if(board[counter][savedColumn] == ' '){
                board[counter][savedColumn] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
    }

    if (i == 4){
        for (int row = 0 ; row < 3 ; row++){
            for (int column = 0 ; column < 3 ; column++){
                if (board[row][column] == ' '){
                    board[row][column] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
            }
        }
    }

    return;
}

void CompPlays2(int i,char board[][3],char* ptr, char playerX,char playerO){
    srand(time(NULL));
    int random = rand() % 4 + 1;
    
    //horizontal variables
    int horizontalCounter = 0;
    int hsavedRow = -1;
    int hsavedColumn = -1;
    bool hsafeSpot = false;
        
    //vertical variables
    int verticalCounter = 0;
    int vsavedRow = -1;
    int vsavedColumn = -1;
    bool vsafeSpot = false;
    
    //main diagonal variables
    int diagonalCounter1 = 0;
    int diagonalSavedRow1 = -1;
    int diagonalSavedColumn1 = -1;
    bool diagonalSafeSpot1 = false;
     
    //second diagonal variables
    int diagonalCounter2 = 0;
    int diagonalSavedRow2 = -1;
    int diagonalSavedColumn2 = -1;
    int diagonalSafeSpot2 = 0;


    {
        //checks if comp can win
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column++){
                //horizontal check
                if (board[row][column] == *ptr){
                    horizontalCounter++;
                }
                else if(board[row][column] == ' '){
                    hsavedColumn = column;
                    hsavedRow = row;
                    hsafeSpot = true;
                }
                if (horizontalCounter == 2 && hsafeSpot == true){
                    board[hsavedRow][hsavedColumn] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }

                //vertical check
                if (board[column][row] == *ptr){
                    verticalCounter++;
                }
                else if (board[column][row] == ' '){
                    vsavedColumn = row;
                    vsavedRow = column;
                    vsafeSpot = true;
                }
                if (verticalCounter == 2 && vsafeSpot == true){
                    board[vsavedRow][vsavedColumn] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
            }
            vsafeSpot = false;
            hsafeSpot = false;
            verticalCounter = 0;
            horizontalCounter = 0;
        }

        //checks if comp can win in the main diagonal
        for (int counter = 0; counter < 3; counter++){
            if (board[counter][counter] == *ptr){
                diagonalCounter1++;
            }
            else if(board[counter][counter] == ' '){
                diagonalSavedColumn1 = counter;
                diagonalSavedRow1 = counter;
                diagonalSafeSpot1 = true;
            }

            if (diagonalCounter1 == 2 && diagonalSafeSpot1 == true){
                board[diagonalSavedRow1][diagonalSavedColumn1] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }

        //checks if comp can win in the second diagonal
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column++){
                if (abs(row - column) == 2){
                    if (board[row][column] == *ptr){
                        diagonalCounter2++;
                    }
                    else if (board[row][column] == ' '){
                        diagonalSafeSpot2++;
                        diagonalSavedColumn2 = column;
                        diagonalSavedRow2 = row;
                    }
                }
                if (row == 1 && column == 1){
                    if (board[row][column] == *ptr){
                        diagonalCounter2++;
                    }
                    else if (board[row][column] == ' '){
                        diagonalSafeSpot2++;
                        diagonalSavedColumn2 = column;
                        diagonalSavedRow2 = row;
                    }
                }
            }
            if (diagonalCounter2 == 2 && diagonalSafeSpot2 == 1){
                board[diagonalSavedRow2][diagonalSavedColumn2] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
    }

    char blockingMove = (*ptr == playerO) ? playerX : playerO;
    
    {
        //checks which is the blocking move
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column++){
                //horizontal check
                if (board[row][column] == blockingMove){
                    horizontalCounter++;
                }
                else if(board[row][column] == ' '){
                    hsavedColumn = column;
                    hsavedRow = row;
                    hsafeSpot = true;
                }
                if (horizontalCounter == 2 && hsafeSpot == true){
                    board[hsavedRow][hsavedColumn] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }

                //vertical check
                if (board[column][row] == blockingMove){
                    verticalCounter++;
                }
                else if (board[column][row] == ' '){
                    vsavedColumn = row;
                    vsavedRow = column;
                    vsafeSpot = true;
                }
                if (verticalCounter == 2 && vsafeSpot == true){
                    board[vsavedRow][vsavedColumn] = *ptr;
                    *ptr = (*ptr == playerO) ? playerX : playerO;
                    return;
                }
            }

            vsafeSpot = false;
            hsafeSpot = false;
            verticalCounter = 0;
            horizontalCounter = 0;
        }

        //checks if comp can block in the main diagonal
        for (int counter = 0; counter < 3; counter++){
            if (board[counter][counter] == blockingMove){
                diagonalCounter1++;
            }
            else if(board[counter][counter] == ' '){
                diagonalSavedColumn1 = counter;
                diagonalSavedRow1 = counter;
                diagonalSafeSpot1 = true;
            }

            if (diagonalCounter1 == 2 && diagonalSafeSpot1 == true){
                board[diagonalSavedRow1][diagonalSavedColumn1] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }

        //checks if comp can block in the second diagonal
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column++){
                if (abs(row - column) == 2){
                    if (board[row][column] == blockingMove){
                        diagonalCounter2++;
                    }
                    else if (board[row][column] == ' '){
                        diagonalSafeSpot2 = true;
                        diagonalSavedColumn2 = column;
                        diagonalSavedRow2 = row;
                    }
                }
                if (row == 1 && column == 1){
                    if (board[row][column] == blockingMove){
                        diagonalCounter2++;
                    }
                    else if (board[row][column] == ' '){
                        diagonalSafeSpot2 = true;
                        diagonalSavedColumn2 = column;
                        diagonalSavedRow2 = row;
                    }
                }
            }
            if (diagonalCounter2 == 2 && diagonalSafeSpot2 == true){
                board[diagonalSavedRow2][diagonalSavedColumn2] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
    }


    if (i == 0 && board[1][1] == ' '){
        board[1][1] = *ptr;
        *ptr = (*ptr == playerO) ? playerX : playerO;
        return;
    }
    else if(i == 0){
        switch(random){
            case 1:
                if (board[0][0] == ' ')
                    board[0][0] = *ptr;
                break;
            case 2:
                if (board[0][2] == ' ')
                    board[0][2] = *ptr;
                break;
            case 3:
                if (board[2][0] == ' ')
                    board[2][0] = *ptr;
                break;
            case 4:
                if (board[2][2] == ' ') 
                    board[2][2] = *ptr;
                break;
        }
        *ptr = (*ptr == playerO) ? playerX : playerO;
        return;
    }

    if (i == 1 && board[1][1] != *ptr){
        if (board[0][0] == *ptr){
            board[2][0] = *ptr;
        }
        else if (board[0][2] == *ptr){
            board[2][2] = *ptr;
        }
        else if (board[2][2] == *ptr){
            board[0][2] = *ptr;
        }
        else if(board[2][0] == *ptr){
            board[0][0] = *ptr;
        }
        *ptr = (*ptr == playerO) ? playerX : playerO;
        return;
    }

    if (i == 1 && board[1][1] == *ptr){
        if (board[1][2] == blockingMove && board[2][1] == blockingMove){
            board[2][2] = *ptr;
            *ptr = (*ptr == playerO) ? playerX : playerO;
            return;
        }
        else if (board[0][1] == blockingMove && board[1][0] == blockingMove){
            board[0][0] = *ptr;
            *ptr = (*ptr == playerO) ? playerX : playerO;
            return;
        }
    }
        
    int counterPtrV = 0;
    int counterSpaceV = 0;
    
    int counterPtrH = 0;
    int counterSpaceH = 0; 

    int savedRowV = -1;
    int savedColumnV = -1;

    int savedRowH = -1;
    int savedColumnH = -1;

    for (int row = 0 ; row < 3 ; row++){
        for (int column = 0 ; column < 3 ; column++){
            if (board[row][column] == *ptr){
                counterPtrV++;
            }
            else if (board[row][column] == ' '){
                counterSpaceV++;
                savedRowV = row;
                savedColumnV = column;
            }
            if (counterPtrV == 1 && counterSpaceV == 2){
                board[savedRowV][savedColumnV] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
            if (board[column][row] == *ptr){
                counterPtrH++;
            }
            else if (board[column][row] == ' '){
                counterSpaceH++;
                savedRowH = column;
                savedColumnH = row;
            }
            if (counterPtrH == 1 && counterSpaceH == 2){
                board[savedRowH][savedColumnH] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
        counterPtrH = 0;
        counterSpaceH = 0;
        counterPtrV = 0;
        counterSpaceV = 0;
    }    

    if (board[1][1] == *ptr){
        if (board[2][0] == ' ' && board[0][2] == ' '){
            board[2][0] = *ptr;
            *ptr = (*ptr == playerO) ? playerX : playerO;
            return;
        }
        else if (board[0][0] == ' ' && board[2][2] == ' '){
            board[2][2] = *ptr;
            *ptr = (*ptr == playerO) ? playerX : playerO;
            return;
        }
    }

    for (int row = 0 ; row < 3 ; row++){
        for (int column = 0 ; column < 3 ; column++){
            if (board[row][column] == ' '){
                board[row][column] = *ptr;
                *ptr = (*ptr == playerO) ? playerX : playerO;
                return;
            }
        }
    }

return;
}
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>    
#include "morpion.h"

void initializeBoard(char board[9]) {
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i;
    }
}

void printBoard(const char board[9]) {
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}


int checkWin(const char board[9]) {
    
    if (board[0] == board[1] && board[1] == board[2]) return 1;
    if (board[3] == board[4] && board[4] == board[5]) return 1;
    if (board[6] == board[7] && board[7] == board[8]) return 1;

    
    if (board[0] == board[3] && board[3] == board[6]) return 1;
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    if (board[2] == board[5] && board[5] == board[8]) return 1;

   
    if (board[0] == board[4] && board[4] == board[8]) return 1;
    if (board[2] == board[4] && board[4] == board[6]) return 1;

    return 0; 
}


int isValidMove(const char board[9], int move) {
    if (move >= 0 && move < 9 && board[move] != 'X' && board[move] != 'O') {
        return 1;
    }
    return 0;
}


void computerMove(char board[9]) {
    int move;
    srand(time(0));  

   
    do {
        move = rand() % 9;  
    } while (!isValidMove(board, move));

    board[move] = 'O';  
}

void findBestMove(char board[9]) {
    int move = -1;  

    
    for (int i = 0; i < 9; i++) {
        if (isValidMove(board, i)) {
            board[i] = 'O';  
            if (checkWin(board)) {  
                return;  
            }
            board[i] = '1' + i;  
        }
    }

    
    for (int i = 0; i < 9; i++) {
        if (isValidMove(board, i)) {
            board[i] = 'X';  
            if (checkWin(board)) {  
                board[i] = 'O';  
                return;
            }
            board[i] = '1' + i;  
        }
    }

    
    computerMove(board);  
}
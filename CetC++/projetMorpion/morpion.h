#ifndef MORPION_H
#define MORPION_H

void initializeBoard(char board[9]);
void printBoard(const char board[9]);
int checkWin(const char board[9]);
int isValidMove(const char board[9], int move);
void computerMove(char board[9]);  
void findBestMove(char board[9]);  

#endif

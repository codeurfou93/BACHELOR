// #include <stdio.h>
// #include "morpion.h"
// #include "tests.h"

// int test_checkWin() {
//     char board1[9] = {'X', 'X', 'X', '4', '5', '6', '7', '8', '9'};
//     char board2[9] = {'O', 'X', 'X', 'O', 'O', '6', '7', '8', '9'};
//     char board3[9] = {'X', 'O', 'X', '4', '5', '6', 'O', 'O', 'X'};
//     return checkWin(board1) && !checkWin(board2) && checkWin(board3);
// }

// int test_isValidMove() {
//     char board[9] = {'X', 'O', 'X', '4', '5', '6', '7', '8', '9'};
//     return isValidMove(board, 3) && !isValidMove(board, 0) && !isValidMove(board, 1);
// }

// void run_tests() {
//     printf("Test checkWin: %s\n", test_checkWin() ? "Passed" : "Failed");
//     printf("Test isValidMove: %s\n", test_isValidMove() ? "Passed" : "Failed");
// }

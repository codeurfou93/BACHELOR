#include <stdio.h>
#include "morpion.h"

int main() {
    char board[9];    
    int move;         
    int game_over = 0;  

    initializeBoard(board);  

    while (!game_over) {
        printBoard(board);  

        
        printf("Joueur (X), entrez un numéro de case : ");
        scanf("%d", &move);

        
        move = move - 1;

        
        if (isValidMove(board, move)) {
            board[move] = 'X';  
        } else {
            printf("Mouvement invalide, réessayez.\n");
            continue;
        }

        
        if (checkWin(board)) {
            printBoard(board);
            printf("Félicitations ! Le joueur a gagné !\n");
            game_over = 1;
            continue;
        }

        
        int draw = 1;
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                draw = 0;
                break;
            }
        }
        if (draw) {
            printBoard(board);
            printf("C'est un match nul !\n");
            game_over = 1;
            continue;
        }


        findBestMove(board);
        printf("L'ordinateur a joué.\n");

        
        if (checkWin(board)) {
            printBoard(board);
            printf("L'ordinateur a gagné !\n");
            game_over = 1;
        }
    }

    return 0;
}

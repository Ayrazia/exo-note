
// Created by ayrazia on 06/10/24.

#ifndef TICTACTOE_H
#define TICTACTOE_H
#endif

#define Vide ' '
#define P1 'X'
#define PIA 'O'
//TICTACTOE_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char board[3][3];
void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = Vide;
        }
    }
}
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c", board[i][j]);
            if (j < 2) printf(" |");
        }
        printf("\n");
        if (i < 2) printf("+--+---+--+\n");
    }
    printf("\n");
}
int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != Vide) {
            return board[i][0];
        }
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != Vide) {
            return board[0][j];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != Vide) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != Vide) {
        return board[0][2];
    }
    return 0;
}
int boardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == Vide) {
                return 0;
            }
        }
    }
    return 1;
}
void turnP1() {
    int line, column;
    do {
        printf("Votre tour (X), entrez une ligne et une colonne (1-3) : ");
        scanf("%d%d", &line, &column);
        line--;
        column--;
    } while (line < 0 || line >= 3 || column < 0 || column >= 3 || board[line][column] != Vide);
    board[line][column] = P1;
}
void turnPIA() {
    int line, column;
    do {
        line = rand() % 3;
        column = rand() % 3;
    } while (board[line][column] != Vide);
    printf("L'ordinateur (O) a joué en ligne %d et colonne %d.\n", line + 1, column + 1);
    board[line][column] = PIA;
}

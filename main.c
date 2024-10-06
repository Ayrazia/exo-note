#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tic-tac-toe.h"
#define Vide ' '
#define P1 'X'
#define PIA 'O'

int main() {
    restart:
    int winner = 0;
    srand(time(0));
    initBoard();
    while (!winner && !boardFull()) {
        displayBoard();
        turnP1();
        winner = checkWinner();
        if (winner || boardFull()) break;
        turnPIA();
        winner = checkWinner();
    }
    displayBoard();
    if (winner == P1) {
        printf("Vous avez gagné !\n");
    } else if (winner == PIA) {
        printf("L'ordinateur a gagné, tu a le niveau d'un i5-3350p !\n");
    } else {
        printf("Match nul, tu devrais upgrade tes neurones \n");
    }
    char Oui;
    char Non;
    printf("Souhaitez-vous recommencer? Oui ou Non\n");
    scanf("%s", &Oui);
    if (Oui == 'O' || Oui == 'o' )
    {
        goto restart;
    }
    else if(Non == 'N' || Non == 'n')
    {
        return 0;
    }
}

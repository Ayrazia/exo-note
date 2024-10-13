//code by Ayrazia
#include "define.h"
#include "header.h"



int main(void) {

        char board[10][10];

        srand(time(NULL));
// random
        int line_player = rand() %8;
        int column_player = rand() %8;
        int line_case = 3+ rand()%(6 - 3 + 1);
        int column_case = 3+ rand()%(6 - 3 + 1);
        printf("%d\n", line_case);
        printf("%d\n", column_case);
        int line_objectif = rand() %8;
        int column_objectif = rand() %8;

        int i;
        int j;

        int check_win = 0;
        int check_lose = 0;
//int board
        for ( i = 0; i < 10; i++) {
                for ( j = 0;j < 10; j++) {
                        board[i][j] = ' ';
                }
        }

        board[line_player][column_player] = PLAYER;
        board[line_case][column_case] = CASE;
        board[line_objectif][column_objectif] = OBJECTIF;
//display board
        char input;
        respawn:
        printf("##########\n");

        for (i = 0; i < 8; i++) {
                printf("#");
                for (j = 0; j < 8; j++) {
                        printf("%c", board[i][j]);
                }
                printf("#\n");
        }
        printf("##########\n");

        printf("Votre personnage est en l%d c%d\n", line_player + 1, column_player + 1);
        printf("Appuyer sur Z pour monter, D pour droite, S pour descendre et Q pour gauche\n");

        scanf("%c", &input);

        board[line_player][column_player] = ' ';


        switch (input) {
            case 'z':
     case 'Z':
           if (line_player > 0) {
               if (line_player - 1 == line_case && column_player == column_case) {
                   if (line_case > 0 && (board[line_case - 1][column_case] == ' ' || (line_case - 1 == line_objectif && column_case == column_objectif))) {
                       line_case--;
                   } else {
                       break;
                   }
               }
               line_player--;
           }
            break;
            case 's':
                    case 'S':
           if (line_player < 7) {
               if (line_player + 1 == line_case && column_player == column_case) {
                   if (line_case < 7 && (board[line_case + 1][column_case] == ' ' || (line_case + 1 == line_objectif && column_case == column_objectif))) {
                       line_case++;
                   } else {
                       break;
                   }
               }
               line_player++;
           }
            break;
            case 'q':
                    case 'Q':
           if (column_player > 0) {
                   if (line_player == line_case && column_player - 1 == column_case) {
                       if (column_case > 0 && (board[line_case][column_case - 1] == ' ' || (line_case == line_objectif && column_case - 1 == column_objectif))) {
                           column_case--;
                       } else {
                           break;
                       }
                   }
                   column_player--;
               }
               break;
               case 'd':
                       case 'D':
           if (column_player < 7) {
               if (line_player == line_case && column_player + 1 == column_case) {
                   if (column_case < 7 && (board[line_case][column_case + 1] == ' ' || (line_case == line_objectif && column_case + 1 == column_objectif))) {
                       column_case++;
                   } else {
                       break;
                   }
               }
               column_player++;
           }
               break;
               default:
                   printf("Erreur, commande non valide\n");
               break;
           }


            board[line_player][column_player] = PLAYER;
            board[line_case][column_case] = CASE;
            board[line_objectif][column_objectif] = OBJECTIF;


            if (line_case == line_objectif && column_case == column_objectif) {
                check_win = 1;
            }
            if ((line_case == 0 && column_case == 0) ||  // coin haut-gauche
                        (line_case == 0 && column_case == 7) ||  // coin haut-droit
                        (line_case == 7 && column_case == 0) ||  // coin bas-gauche
                        (line_case == 7 && column_case == 7)) {  // coin bas-droit
                check_lose = 1;
                        }

            if (check_win) {
                board[line_case][column_case] = OBJECTIF;
                printf("Vous avez réussi ! Félicitation!");
            }
            else if (check_lose) {
                printf("Vous avez perdu!");
            }

            else {
                system("clear");
                goto respawn;
            }
            return 0;
        }
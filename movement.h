#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef GRID_H //Inclusion des fonctions nécessaires pour la fonction
    #define GRID_H
    #include "grid.h"
    #endif
#ifndef GRAVITY_H
    #define GRAVITY_H
    #include "gravity.h"
    #endif
void moveLetter(char grid[][26], int GRID_SIZE, int GRID_LETTERS);


void moveLetter(char grid[][26], int GRID_SIZE, int GRID_LETTERS) {
    int x1, x2, x3, x4, y3, y4;
    char  y1 ,y2, max='A'+GRID_LETTERS+1; //max correspond à la lettre de la dernière colonne la grille
    printf("Entrez les coordonnees de la lettre que vous voulez deplacer (ligne, colonne): ");
    scanf("%d %c", &x1, &y1);
    //On vérifie que l'élément est dans le tableau
    if (x1 < 0 || x1 > GRID_SIZE+1 || y1 < 'A' || y1 > max) {
        printf("Coordonnees invalides. Entrez de nouvelles coordonnees.\n");
        return moveLetter(grid, GRID_SIZE,GRID_LETTERS);
    }
    printf("Entrez les coordonnees de la destination (ligne, colonne): ");
    scanf("%d %c", &x2, &y2);
    //On vérifie que l'élément est dans le tableau
    if (x2 < 0 || x2 > GRID_SIZE+1 || y2 < 'A' || y2 > max) {
        printf("Coordonnees invalides,vous sortez du tableau. Entrez de nouvelles coordonnees.\n");
        return moveLetter(grid, GRID_SIZE,GRID_LETTERS);
    }
    //On vérifie que la case de destination n'est pas à une distance supérieure à une unité horizontalement ou verticalement de la case de départ et n'est pas la case de départ
    else if ((abs(x2 - x1) > 1) || (abs(y2 - y1) > 1) || (x1==x2 && y1==y2)) {
        printf("Coordonnees invalides, les cases ne sont pas cote a cote. Entrez de nouvelles coordonnees.\n");
        return moveLetter(grid, GRID_SIZE,GRID_LETTERS);
    }
    switch(y1){
        case 'A':
            y3=0;
        break;
        case 'B':
            y3=1;
        break;
        case 'C':
            y3=2;
        break;
        case 'D':
            y3=3;
        break;
        case 'E':
            y3=4;
        break;
        case 'F':
            y3=5;
        break;
        case 'G':
            y3=6;
        break;
        case 'H':
            y3=7;
        break;
        case 'I':
            y3=8;
        break;
        case 'J':
            y3=9;
        break;
        case 'K':
            y3=10;
        break;
        case 'L':
            y3=11;
        break;
        case 'M':
            y3=12;
        break;
        case 'N':
            y3=13;
        break;
        case 'O':
            y3=14;
        break;
        case 'P':
            y3=15;
        break;
        case 'Q':
            y3=16;
        break;
        case 'R':
            y3=17;
        break;
        case 'S':
            y3=18;
        break;
        case 'T':
            y3=19;
        break;
        case 'U':
            y3=20;
        break;
        case 'V':
            y3=21;
        break;
        case 'W':
            y3=22;
        break;
        case 'X':
            y3=23;
        break;
        case 'Y':
            y3=24;
        break;
        case 'Z':
            y3=25;
        break;
    }
    switch(y2){
        case 'A':
            y4=0;
        break;
        case 'B':
            y4=1;
        break;
        case 'C':
            y4=2;
        break;
        case 'D':
            y4=3;
        break;
        case 'E':
            y4=4;
        break;
        case 'F':
            y4=5;
        break;
        case 'G':
            y4=6;
        break;
        case 'H':
            y4=7;
        break;
        case 'I':
            y4=8;
        break;
        case 'J':
            y4=9;
        break;
        case 'K':
            y4=10;
        break;
        case 'L':
            y4=11;
        break;
        case 'M':
            y4=12;
        break;
        case 'N':
            y4=13;
        break;
        case 'O':
            y4=14;
        break;
        case 'P':
            y4=15;
        break;
        case 'Q':
            y4=16;
        break;
        case 'R':
            y4=17;
        break;
        case 'S':
            y4=18;
        break;
        case 'T':
            y4=19;
        break;
        case 'U':
            y4=20;
        break;
        case 'V':
            y4=21;
        break;
        case 'W':
            y4=22;
        break;
        case 'X':
            y4=23;
        break;
        case 'Y':
            y4=24;
        break;
        case 'Z':
            y4=25;
        break;
    }
    x3=x1-1;
    x4=x2-1;
    if((grid[x3][y3]==grid[x4][y4+1] && grid[x3][y3]==grid[x4][y4+2]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x4][y4-1] && grid[x3][y3]==grid[x4][y4-2]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x4][y4-1] && grid[x3][y3]==grid[x4][y4+1]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x4+1][y4] && grid[x3][y3]==grid[x4+2][y4]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x4+1][y4] && grid[x3][y3]==grid[x4-1][y4]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x4-1][y4] && grid[x3][y3]==grid[x4-2][y4]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x4+1][y4+1] && grid[x3][y3]==grid[x4+2][y4+2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x4-1][y4-1] && grid[x3][y3]==grid[x4+1][y4+1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x4-1][y4-1] && grid[x3][y3]==grid[x4-2][y4-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x4+1][y4-1] && grid[x3][y3]==grid[x4+2][y4-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x4+1][y4-1] && grid[x3][y3]==grid[x4+1][y4+1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x4-1][y4+1] && grid[x3][y3]==grid[x4-2][y4+2])){ // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        char temp = grid[x3][y3];
        grid[x3][y3] = grid[x4][y4];
        grid[x4][y4] = temp;
        for(int i=0; i<3;i++) {
        grid_delete(grid, GRID_SIZE);
        }
        print_grid(grid, GRID_SIZE, GRID_LETTERS);
    }
    else{//Echange des cases
        printf("\033[1;31m");
        printf("Le deplacement doit aligner au minimum 3 symboles identiques\n");
        printf("\033[1;37m");
        moveLetter(grid, GRID_SIZE, GRID_LETTERS);
    }
}

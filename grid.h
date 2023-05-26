#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS); //Définition des fonctions éviter des erreus d'appel


char generateGrid(char grid[][26], int GRID_SIZE, int GRID_LETTERS){
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            do {
                grid[i][j] = 'A' + rand() % GRID_LETTERS;
            } while ((grid[i][j]==grid[i][j-1] && grid[i][j]==grid[i][j-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                    || (i >= 2 && grid[i][j]==grid[i-1][j] && grid[i][j]==grid[i-2][j]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                    || (i >= 2 && grid[i][j]==grid[i-1][j-1] && grid[i][j]==grid[i-2][j-2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                    || (i >= 2 && j <= GRID_SIZE-3 && grid[i][j]==grid[i-1][j+1] && grid[i][j]==grid[i-2][j+2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)
        }
    }
    print_grid(grid, GRID_SIZE, GRID_LETTERS);
}


void print_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS){
    printf("\n");
    printf("   ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    printf("   ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("_ ");
    }
    printf("\n");
    //Affichage des colonnes d'itération (en haut)
    for (int i = 0; i < GRID_SIZE; i++) {
        if(i<9){
            printf("%d |",i+1);
        }
        else{
            printf("%d|",i+1);
        }
        //Affichage des lignes d'itération(à gauche)
        for (int j = 0; j < GRID_SIZE; j++) {
            switch(grid[i][j]){
                case 'A':
                    printf("\033[1;31m");//rouge
                break;
                case 'B':
                    printf("\033[1;32m");//vert
                break;
                case 'C':
                    printf("\033[1;33m");//jaune
                break;
                case 'D':
                    printf("\033[1;34m");//bleu
                break;
                case 'E':
                    printf("\033[1;36m");//cyan
                break;
                case 'F':
                    printf("\033[1;35m");//violet
                break;
                case ' ':
                break;
            }
            printf("%c ", grid[i][j]);//Affichage du tableau entier
        }
        printf("\033[1;37m");
        printf("\n");
    }
}

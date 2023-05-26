#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"game.h"

//Définition des fonctions pour éviter des problèmes d'appels
char generateGrid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
int grid_delete(char grid[][26], int GRID_SIZE);
void print_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
int game_stopper(char grid[][26], int GRID_SIZE, int p);
void grid_filler(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
int good_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);


int main() {
    int GRID_SIZE, GRID_LETTERS;
    printf("\033[1;31m");
    printf("Cliquez sur Caps Lock");
    printf("\033[1;37m");
    printf("\n");
    do{
    printf("Entrez la taille de la grille (entre 4 et 26): ");
    scanf("%d", &GRID_SIZE);
    }while(GRID_SIZE<4||GRID_SIZE>26);
    do{
    printf("Entrez le nombre de lettres que vous voulez dans la grille (entre 4 et 6) : ");
    scanf("%d", &GRID_LETTERS);
    }while(GRID_LETTERS<4||GRID_LETTERS>6);
    char grid[GRID_SIZE][26];
    generateGrid(grid, GRID_SIZE, GRID_LETTERS);
    game(grid, GRID_SIZE, GRID_LETTERS);
    return 0;
}

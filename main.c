#include <stdio.h>
#include <stdlib.h>
#include "game.h" //Inclusion des fonctions nécessaires pour la fonction

int main() {
    int GRID_SIZE, GRID_LETTERS, p=0;
    printf("\033[1;31m");
    printf("Cliquez sur Caps Lock\n");
    printf("Ecrivez 50S pour sauvegarder votre jeu");
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
    game(grid, GRID_SIZE, GRID_LETTERS,p);
    return 0;
}

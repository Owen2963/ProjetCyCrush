#include <stdio.h>
#include <stdlib.h>
#include "game.h" //Inclusion des fonctions nécessaires pour la fonction

int main() {
    FILE* fichier = NULL;
    int GRID_SIZE, GRID_LETTERS, p, m1=0, m2=0, m3=0;
    char del;
    // ouverture du fichier test.txt en lecture/écriture
    fichier = fopen("Joueurs.txt", "r+");
    if (fichier == NULL){
    printf("Ouverture du fichier impossible\n");
    exit(1);
    }
    printf("\033[1;31m");
    printf("Cliquez sur Caps Lock\n");
    printf("Ecrivez 50S pour sauvegarder votre jeu");
    printf("\033[1;37m");
    printf("\n");
    fscanf(fichier, "%d", &p);
    fscanf(fichier, "%d", &GRID_SIZE);
    do{
        fscanf(fichier, "%c", &del);
    }while (del!=':');    
    char grid[GRID_SIZE][26];
    for (int i = 0; i <GRID_SIZE; i++) {
        for (int j = 0; j<GRID_SIZE; j++) {
            grid[i][j]=fgetc(fichier);
        }
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if(grid[i][j]=='F'){
                GRID_LETTERS=6;
                break;
            }
            if(grid[i][j]=='E'){
                GRID_LETTERS=5;
                break;
            }
            if(grid[i][j]=='D'){
                GRID_LETTERS=4;
                break;
            }
        }
    }
    print_grid(grid, GRID_SIZE, GRID_LETTERS);
    game(grid, GRID_SIZE, GRID_LETTERS,p);
    return 0;
}

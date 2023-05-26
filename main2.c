#include <stdio.h>
#include <stdlib.h>
#include "game.h" //Inclusion des fonctions nécessaires pour la fonction

int main() {
    FILE* fichier = NULL;
    int GRID_SIZE=0, GRID_LETTERS, p, m1=0, m2=0, m3=0;
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
    do{
        printf("Pourriez écrire le nombre de ligne et colonnes du fichier svp. Les lignes correspondent au nombre lettres entre les SOH dans le fichier Joueurs.txt :");
        scanf("%d", &GRID_SIZE);
    }while(GRID_SIZE<4||GRID_SIZE>26);
    char grid[GRID_SIZE][26];
    fscanf(fichier, "%d", &p);
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j<GRID_SIZE; j++) {
            fseek(fichier, 0, SEEK_END);
            grid[i][j]=fgetc(fichier);
        }
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if(grid[i][j]=='F'){
                m1=6;
                break;
            }
            if(grid[i][j]=='E'){
                m2=5;
                break;
            }
            if(grid[i][j]=='D'){
                m3=4;
                break;
            }
        }
    }
    if(m1!=0){
        GRID_LETTERS=m1;
    }
    else if(m2!=0){
        GRID_LETTERS=m2;
    }
    else if(m3!=0){
        GRID_LETTERS=m3;
    }
    print_grid(grid, GRID_SIZE, GRID_LETTERS);
    return 0;
}

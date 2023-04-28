#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char generateGrid(char grid[][100],int GRID_SIZE);
char gridverifier(char grid[][100],int GRID_SIZE);
void checkAlignment(char grid[][100], int GRID_SIZE, int row, int col);

//Création d'une grille aléatoire
char generateGrid(char grid[][100],int GRID_SIZE) {
    srand(time(NULL));
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
            grid[i][j] = 'A' + rand() % 4;
            checkAlignment(grid, GRID_SIZE, i, j);
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
            }
            printf("%c ", grid[i][j]);//Affichage du tableau entier
        }
        printf("\033[0;37m");
        printf("\n");
    }
    gridverifier(grid,GRID_SIZE);
}


void checkAlignment(char grid[][100], int GRID_SIZE, int row, int col) {
    // On vérifie les alignements possibles pour les deux directions horizontale et verticale
    if (row > 1) {
        if (grid[row][col] == grid[row - 1][col] && grid[row - 1][col] == grid[row - 2][col]) {
            // Si l'alignement est détecté, on réassigne une lettre à la case courante
            do {
                grid[row][col] = 'A' + rand() % 4;
            } while (grid[row][col] == grid[row - 1][col] && grid[row - 1][col] == grid[row - 2][col]);
        }
    }

    if (col > 1) {
        if (grid[row][col] == grid[row][col - 1] && grid[row][col - 1] == grid[row][col - 2]) {
            // Si l'alignement est détecté, on réassigne une lettre à la case courante
            do {
                grid[row][col] = 'A' + rand() % 4;
            } while (grid[row][col] == grid[row][col - 1] && grid[row][col - 1] == grid[row][col - 2]);
        }
    }
}



char gridverifier(char grid[][100],int GRID_SIZE){
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if(grid[i][j]==grid[i+1][j]&&grid[i+1][j]==grid[i+2][j]){//3 chiffres alignés verticalement
                printf("\n");
                return generateGrid(grid,GRID_SIZE);
            }
            else if(grid[i][j]==grid[i][j+1]&&grid[i][j+1]==grid[i][j+2]){//3 chiffres alignés horizontalement
                printf("\n");
                return generateGrid(grid,GRID_SIZE);
            }
            else if(grid[i][j]==grid[i+1][j+1]&&grid[i+1][j+1]==grid[i+2][j+2]){//3 chiffres alignés diagonalement d'en haut à gauche vers en bas à droite
                printf("\n");
                return generateGrid(grid,GRID_SIZE);
            }
            else if(grid[i][j]==grid[i+1][j-1]&&grid[i+1][j-1]==grid[i+2][j-2]){//3 chiffres alignés diagonalement d'en bas gauche vers en haut à droite
                printf("\n");
                return generateGrid(grid,GRID_SIZE);
            }
        }
    }
}


void moveLetter(char grid[][100], int GRID_SIZE) {
    int x1, x2, v3, v4;
    char  y1 ,y2;
    printf("Entrez les coordonnees de la lettre que vous voulez deplacer (ligne colonne): ");
    scanf("%d %c", &x1, &y1);
    //On vérifie que l'élément est dans le tableau
    if (x1 < 0 || x1 > GRID_SIZE+1 || y1 < 'A' || y1 > 'D') {
        printf("Coordonnees invalides. Entrez de nouvelles coordonnees.\n");
        moveLetter(grid, GRID_SIZE);
        return;
    }
    printf("Entrez les coordonnees de la destination (ligne colonne): ");
    scanf("%d %c", &x2, &y2);
    //On vérifie que l'élément est dans le tableau
    if (x2 < 0 || x2 > GRID_SIZE+1 || y2 < 'A' || y2 > 'D') {
        printf("Coordonnees invalides,vous sortez du tableau. Entrez de nouvelles coordonnees.\n");
        moveLetter(grid, GRID_SIZE);
        return;
    }
    //On vérifie que la case de destination n'est pas à une distance supérieure à une unité horizontalement ou verticalement de la case de départ et n'est pas la case de départ
    else if ((abs(x2 - x1) > 1) || (abs(y2 - y1) > 1) || (x1 == x2 && y1 == y2)) {
        printf("Coordonnees invalides, les cases ne sont pas cote a cote. Entrez de nouvelles coordonnees.\n");
        moveLetter(grid, GRID_SIZE);
        return;
}
    switch(y1){
            case 'A':
                v3=1;
            break;
            case 'B':
                v3=2;
            break;
            case 'C':
                v3=3;
            break;
            case 'D':
                v3=4;
            break;
        }
        switch(y2){
            case 'A':
                v4=1;
            break;
            case 'B':
                v4=2;
            break;
            case 'C':
                v4=3;
            break;
            case 'D':
                v4=4;
            break;
        }
    //Echange des cases
    char temp = grid[x1-1][v3-1];
    grid[x1-1][v3-1] = grid[x2-1][v4-1];
    grid[x2-1][v4-1] = temp;
    printf("   ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%c ",'A'+i);
    }
    printf("\n");
    printf("   ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("_ ");
    }
    printf("\n");
    //Affichage des colonnes d'itération (en haut)
    for (int i = 0; i < GRID_SIZE; i++) {
        if(i<9){ // tableau au dessus de 9
            printf("%d |",i+1);
        }
        else{
            printf("%d|",i+1);
        }
        for (int j = 0; j < GRID_SIZE; j++) {
            switch(grid[i][j]){
                case 'A':
                    printf("\033[1;31m");//rouge
                break;
                case 'B':
                    printf("\033[1;32m");//vert
                break;
                case 'C':
                    printf("\033[1;33m");//rouge
                break;
                case 'D':
                    printf("\033[1;34m");//bleu
                break;
            }
            printf("%c ", grid[i][j]);
        }
        printf("\033[1;37m");
        printf("\n");
    }
}

int main() {
    int GRID_SIZE;
    do{
    printf("Entrez la taille de la grille : ");
    scanf("%d", &GRID_SIZE);
    }while(GRID_SIZE>26);
    char grid[GRID_SIZE][100];
    generateGrid(grid,GRID_SIZE);
    moveLetter(grid,GRID_SIZE);
    return 0;
}

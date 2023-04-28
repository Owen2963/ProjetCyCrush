#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char generateGrid(char grid[][100],int GRID_SIZE);
char gridverifier(char grid[][100],int GRID_SIZE);
//Définition des fonctions pour éviter des problèmes d'appels
char generateGrid(char grid[][100],int GRID_SIZE) {
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
        if(i<9){
            printf("%d |",i+1);
        }
        else{
            printf("%d|",i+1);
        }
        //Affichage des lignes d'itération(à gauche)
        for (int j = 0; j < GRID_SIZE; j++) {
            switch(grid[i][j] = 'A' + rand() % 6){
                case 'A':
                    printf("\033[0;31m");//rouge
                break;
                case 'B':
                    printf("\033[0;32m");//vert
                break;
                case 'C':
                    printf("\033[0;33m");//rouge
                break;
                case 'D':
                    printf("\033[0;34m");//bleu
                break;
                case 'E':
                    printf("\033[0;30m");//gris/noir
                break;
                case 'F':
                    printf("\033[0;36m");//cyan
                break;
            }
            printf("%c ", grid[i][j]);//Affichage du tableau entier
        }
        printf("\033[0;37m");
        printf("\n");
    }
    gridverifier(grid,GRID_SIZE);
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
            else if(grid[i][j]==grid[i+1][j+1]&&grid[i+1][j+1]==grid[i+2][j+2]){//3 chiffres alignés diagonalement à droite
                printf("\n");
                return generateGrid(grid,GRID_SIZE);
            }
            else if(grid[i][j]==grid[i+1][j-1]&&grid[i+1][j-1]==grid[i+2][j-2]){//3 chiffres alignés diagonalement à gauche
                printf("\n");
                return generateGrid(grid,GRID_SIZE);
            }
        }
    }
}

void moveLetter(char grid[][100], int GRID_SIZE) {
    int x1, x2, y3, y4;
    char  y1 ,y2;
    printf("Entrez les coordonnees de la lettre que vous voulez deplacer (ligne, colonne): ");
    scanf("%d %c", &x1, &y1);
    //On vérifie que l'élément est dans le tableau
    if (x1 < 0 || x1 > GRID_SIZE+1 || y1 < 'A' || y1 > 'F') {
        printf("Coordonnees invalides. Entrez de nouvelles coordonnees.\n");
        moveLetter(grid, GRID_SIZE);
        return;
    }
    printf("Entrez les coordonnees de la destination (ligne, colonne): ");
    scanf("%d %c", &x2, &y2);
    //On vérifie que l'élément est dans le tableau
    if (x2 < 0 || x2 > GRID_SIZE+1 || y2 < 'A' || y2 > 'F') {
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
                y3=1;
            break;
            case 'B':
                y3=2;
            break;
            case 'C':
                y3=3;
            break;
            case 'D':
                y3=4;
            break;
            case 'E':
                y3=5;
            break;
            case 'F':
                y3=6;
            break;
        }
        switch(y2){
            case 'A':
                y4=1;
            break;
            case 'B':
                y4=2;
            break;
            case 'C':
                y4=3;
            break;
            case 'D':
                y4=4;
            break;
            case 'E':
                y4=5;
            break;
            case 'F':
                y4=6;
            break;
        }
    //Echange des cases
    char temp = grid[x1-1][y3-1];
    grid[x1-1][y3-1] = grid[x2-1][y4-1];
    grid[x2-1][y4-1] = temp;
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
        if(i<9){
            printf("%d |",i+1);
        }
        else{
            printf("%d|",i+1);
        }
        for (int j = 0; j < GRID_SIZE; j++) {
            switch(grid[i][j]){
                case 'A':
                    printf("\033[0;31m");//rouge
                break;
                case 'B':
                    printf("\033[0;32m");//vert
                break;
                case 'C':
                    printf("\033[0;33m");//rouge
                break;
                case 'D':
                    printf("\033[0;34m");//bleu
                break;
                case 'E':
                    printf("\033[0;30m");//gris/noir
                break;
                case 'F':
                    printf("\033[0;36m");//cyan
                break;
            }
            printf("%c ", grid[i][j]);
        }
        printf("\033[0;37m");
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

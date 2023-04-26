#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Création d'une grille aléatoire
char generateGrid(char grid[][100],int GRID_SIZE) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            switch(grid[i][j] = 'A' + rand() % 4){
                case 'A':
                printf("\033[1;31m");
                break;
                case 'B':
                printf("\033[1;32m");
                break;
                case 'C':
                printf("\033[1;33m");
                break;
                case 'D':
                printf("\033[1;34m");
                break;
            }   
            printf("%c ", grid[i][j]);
        }
    printf("\n");
    }
}


void countGrid(char grid[][100], int GRID_SIZE) {
    int i, j, delete;
    delete = 0;
    // Vérification des lettres alignées horizontalement (3 minimum)
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == grid[i][j+1] && grid[i][j+1] == grid[i][j+2]) {
                delete++;
            }
        }
    }
    // Vérification des lettres alignées verticalement (3 minimum)
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == grid[i+1][j] && grid[i+1][j] == grid[i+2][j]) {
                delete++;
            }
        }
    }
    // Vérification des lettres alignées diagonalement (3 minimum)
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if ((grid[i][j] == grid[i+1][j+1] && grid[i+1][j+1] == grid[i+2][j+2]) || (grid[i][j] == grid[i-1][j+1] && grid[i-1][j+1] == grid[i-2][j+2])) {
                delete++;
            }
        }
    }
    printf("%d",delete);
}


//Affichage de la futur grille modifiée
void printGrid(char grid[][100], int GRID_SIZE) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            switch(grid[i][j]) {
                case 'A':
                    printf("\033[1;31m");
                    break;
                case 'B':
                    printf("\033[1;32m");
                    break;
                case 'C':
                    printf("\033[1;33m");
                    break;
                case 'D':
                    printf("\033[1;34m");
                    break;
            }
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}


void moveLetter(char grid[][100], int GRID_SIZE) {
    int x1, y1, x2, y2;
    printf("Entrez les coordonnees de la lettre que vous voulez deplacer (x y): ");
    scanf("%d %d", &x1, &y1);
    //On vérifie que l'élément est dans le tableau
    if (x1 < 0 || x1 >= GRID_SIZE || y1 < 0 || y1 >= GRID_SIZE) {
        printf("Coordonnees invalides. Entrez de nouvelles coordonnees.\n");
        moveLetter(grid, GRID_SIZE);
        return;
    }
    printf("Entrez les coordonnees de la destination (x y): ");
    scanf("%d %d", &x2, &y2);
    //On vérifie que l'élément est dans le tableau
    if (x2 < 0 || x2 >= GRID_SIZE || y2 < 0 || y2 >= GRID_SIZE) {
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
    //Echange des cases
    char temp = grid[x1][y1];
    grid[x1][y1] = grid[x2][y2];
    grid[x2][y2] = temp;
}


int main() {
    int GRID_SIZE;
    printf("Entrez la taille de la grille : ");
    scanf("%d", &GRID_SIZE);
    printf("\n");
    char grid[GRID_SIZE][100];
    generateGrid(grid,GRID_SIZE);
    printf("\n");
    moveLetter(grid,GRID_SIZE);
    printGrid(grid,GRID_SIZE);
    countGrid(grid,GRID_SIZE);
    return 0;
}

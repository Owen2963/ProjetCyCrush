#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void deleteGrid(char grid[][100], int GRID_SIZE) {
    srand(time(NULL));
    int i, j, delete;
    delete = 0;
    // Vérification des (3) lettres alignées horizontalement
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE - 2; j++) {
            if (grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i][j+2]) {
                delete++;
            }
        }
    }
    // Vérification des (3) lettres alignées verticalement
    for (i = 0; i < GRID_SIZE - 2; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i+2][j]) {
                delete++;
            }
        }
    }
    printf("%d\n",delete);
}


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


int main() {
int GRID_SIZE;
printf("Entrez la taille de la grille : ");
scanf("%d", &GRID_SIZE);
char grid[GRID_SIZE][100];
generateGrid(grid,GRID_SIZE);
printf("\n");
deleteGrid(grid,GRID_SIZE);
return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Définition des fonctions pour éviter des problèmes d'appels
char generateGrid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
int grid_delete(char grid[][26], int GRID_SIZE);
void print_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
void game_stopper(char grid[][26], int GRID_SIZE, int p);


char generateGrid(char grid[][26], int GRID_SIZE, int GRID_LETTERS) {
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

int grid_delete(char grid[][26], int GRID_SIZE){
    char del = ' '; // caractère qui représente une case vide
    int found_align = 0;
    for(int h = 0; h < 3; h++){
        for (int i = 0; i < GRID_SIZE - 2; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if(grid[i][j]==grid[i+1][j] && grid[i+1][j]==grid[i+2][j] && grid[i+2][j]==grid[i+3][j] && grid[i+3][j]==grid[i+4][j]){//vérifie et élimine 5 lettres alignés verticalement
                    grid[i][j]=del;
                    grid[i+1][j]=del;
                    grid[i+2][j]=del;
                    grid[i+3][j]=del;
                    grid[i+4][j]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i][j+1] && grid[i][j+1]==grid[i][j+2] && grid[i][j+2]==grid[i][j+3] && grid[i][j+3]==grid[i][j+4]){//vérifie et élimine 5 lettres alignés horizontalement
                    grid[i][j]=del;
                    grid[i][j+1]=del;
                    grid[i][j+2]=del;
                    grid[i][j+3]=del;
                    grid[i][j+4]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i+1][j+1] && grid[i+1][j+1]==grid[i+2][j+2] && grid[i+2][j+2]==grid[i+3][j+3] && grid[i+3][j+3]==grid[i+4][j+4]){//vérifie et élimine 5 lettres alignés en bas à gauche vers en haut à droite
                    grid[i][j]=del;
                    grid[i+1][j+1]=del;
                    grid[i+2][j+2]=del;
                    grid[i+3][j+3]=del;
                    grid[i+4][j+4]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i+1][j-1] && grid[i+1][j-1]==grid[i+2][j-2] && grid[i+2][j-2]==grid[i+3][j-3] && grid[i+3][j-3]==grid[i+4][j-4]){//vérifie et élimine 5 lettres alignés en bas à droite vers en haut à gauche
                    grid[i][j]=del;
                    grid[i+1][j-1]=del;
                    grid[i+2][j-2]=del;
                    grid[i+3][j-3]=del;
                    grid[i+4][j-4]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i+1][j] && grid[i+1][j]==grid[i+2][j] && grid[i+2][j]==grid[i+3][j]){//vérifie et élimine 4 lettres alignés verticalement
                    grid[i][j]=del;
                    grid[i+1][j]=del;
                    grid[i+2][j]=del;
                    grid[i+3][j]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i][j+1] && grid[i][j+1]==grid[i][j+2] && grid[i][j+2]==grid[i][j+3]){//vérifie et élimine 4 lettres alignés horizontalement
                    grid[i][j]=del;
                    grid[i][j+1]=del;
                    grid[i][j+2]=del;
                    grid[i][j+3]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i+1][j+1] && grid[i+1][j+1]==grid[i+2][j+2] && grid[i+2][j+2]==grid[i+3][j+3]){//vérifie et élimine 4 lettres alignés en bas à gauche vers en haut à droite
                    grid[i][j]=del;
                    grid[i+1][j+1]=del;
                    grid[i+2][j+2]=del;
                    grid[i+3][j+3]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i+1][j-1] && grid[i+1][j-1]==grid[i+2][j-2] && grid[i+2][j-2]==grid[i+3][j-3]){//vérifie et élimine 4 lettres alignés en bas à droite vers en haut à gauche
                    grid[i][j]=del;
                    grid[i+1][j-1]=del;
                    grid[i+2][j-2]=del;
                    grid[i+3][j-3]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i+1][j] && grid[i+1][j]==grid[i+2][j]){//vérifie et élimine 3 lettres alignés verticalement
                    grid[i][j]=del;
                    grid[i+1][j]=del;
                    grid[i+2][j]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i][j+1] && grid[i][j+1]==grid[i][j+2]){//vérifie et élimine 3 lettres alignés horizontalement
                    grid[i][j]=del;
                    grid[i][j+1]=del;
                    grid[i][j+2]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i+1][j+1] && grid[i+1][j+1]==grid[i+2][j+2]){//vérifie et élimine 3 lettres alignés en bas à gauche vers en haut à droite
                    grid[i][j]=del;
                    grid[i+1][j+1]=del;
                    grid[i+2][j+2]=del;
                    found_align = 1;
                }
                else if(grid[i][j]==grid[i+1][j-1] && grid[i+1][j-1]==grid[i+2][j-2]){//vérifie et élimine 3 lettres alignés en bas à droite vers en haut à gauche
                    grid[i][j]=del;
                    grid[i+1][j-1]=del;
                    grid[i+2][j-2]=del;
                    found_align = 1;
                }
            }
        }
    }
    return found_align; //Si TRUE,on suprrime
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
            }
            printf("%c ", grid[i][j]);//Affichage du tableau entier
        }
        printf("\033[1;37m");
        printf("\n");
    }
}


void moveLetter(char grid[][26], int GRID_SIZE, int GRID_LETTERS) {
    int x1, x2, x3, x4, y3, y4;
    char  y1 ,y2;
    printf("Entrez les coordonnees de la lettre que vous voulez deplacer (ligne, colonne): ");
    scanf("%d %c", &x1, &y1);
    //On vérifie que l'élément est dans le tableau
    if (x1 < 0 || x1 > GRID_SIZE+1 || y1 < 'A' || y1 > 'Z') {
        printf("Coordonnees invalides. Entrez de nouvelles coordonnees.\n");
        return moveLetter(grid, GRID_SIZE,GRID_LETTERS);
    }
    printf("Entrez les coordonnees de la destination (ligne, colonne): ");
    scanf("%d %c", &x2, &y2);
    //On vérifie que l'élément est dans le tableau
    if (x2 < 0 || x2 > GRID_SIZE+1 || y2 < 'A' || y2 > 'Z') {
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
    if((grid[x3][y3]==grid[x3][y3+2] && grid[x3][y3]==grid[x3][y3+3]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x3][y3-2] && grid[x3][y3]==grid[x3][y3-3]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x3+1][y3+1] && grid[x3][y3]==grid[x3+1][y3+2]) // vérification que le joueur aligne 3 lettres horizontalement 
        || (grid[x3][y3]==grid[x3+1][y3-1] && grid[x3][y3]==grid[x3+1][y3-2]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x3+1][y3-1] && grid[x3][y3]==grid[x3+1][y3+1]) // vérification que le joueur aligne 3 lettres horizontalement 
        || (grid[x3][y3]==grid[x3-1][y3+1] && grid[x3][y3]==grid[x3-1][y3+2]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x3-1][y3-1] && grid[x3][y3]==grid[x3-1][y3-2]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x3-1][y3-1] && grid[x3][y3]==grid[x3-1][y3+1]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x3+2][y3] && grid[x3][y3]==grid[x3+3][y3]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x3+1][y3+1] && grid[x3][y3]==grid[x3+2][y3+1]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x3+1][y3-1] && grid[x3][y3]==grid[x3+2][y3-1]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x3+1][y3-1] && grid[x3][y3]==grid[x3-1][y3-1]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x3+1][y3+1] && grid[x3][y3]==grid[x3-1][y3+1]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x3-2][y3] && grid[x3][y3]==grid[x3-3][y3]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x3-1][y3+1] && grid[x3][y3]==grid[x3-2][y3+1]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x3-1][y3-1] && grid[x3][y3]==grid[x3-2][y3-1]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x3+1][y3+2] && grid[x3][y3]==grid[x3+2][y3+3]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3][y3+1] && grid[x3][y3]==grid[x3+1][y3+2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3+2][y3+1] && grid[x3][y3]==grid[x3+3][y3+2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3+1][y3] && grid[x3][y3]==grid[x3+2][y3+1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3][y3-1] && grid[x3][y3]==grid[x3+2][y3+1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3-1][y3] && grid[x3][y3]==grid[x3+1][y3+2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3][y3+1] && grid[x3][y3]==grid[x3-2][y3-1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3+1][y3] && grid[x3][y3]==grid[x3-1][y3-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3-1][y3-2] && grid[x3][y3]==grid[x3][y3-1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3-2][y3-3] && grid[x3][y3]==grid[x3-1][y3-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3-2][y3-1] && grid[x3][y3]==grid[x3-3][y3-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3-1][y3] && grid[x3][y3]==grid[x3-2][y3-1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x3][y3-2] && grid[x3][y3]==grid[x3][y3-3]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3+1][y3-2] && grid[x3][y3]==grid[x3+2][y3-3]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3][y3-1] && grid[x3][y3]==grid[x3+1][y3-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3+2][y3-1] && grid[x3][y3]==grid[x3+3][y3-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3+1][y3] && grid[x3][y3]==grid[x3+2][y3-1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3][y3+1] && grid[x3][y3]==grid[x3+2][y3-1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3-1][y3] && grid[x3][y3]==grid[x3+1][y3-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3][y3-1] && grid[x3][y3]==grid[x3-2][y3+1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3+1][y3] && grid[x3][y3]==grid[x3-1][y3+2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3-1][y3+2] && grid[x3][y3]==grid[x3][y3+1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3-2][y3+3] && grid[x3][y3]==grid[x3-1][y3+2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3-2][y3+1] && grid[x3][y3]==grid[x3-3][y3+2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x3-1][y3] && grid[x3][y3]==grid[x3-2][y3+1])){ // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        char temp = grid[x3][y3];
        grid[x3][y3] = grid[x4][y4];
        grid[x4][y4] = temp;
        for(int i=0; i<4;i++) {
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


void grid_filler(char grid[][26], int GRID_SIZE, int GRID_LETTERS){
    char del = ' ';
    for (int j = 0; j < GRID_SIZE; j++) {
        for (int h = 0; h < GRID_SIZE; h++) {     
            if(grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2] && grid[j][h]==grid[j][h+3]&& grid[j][h]==grid[j][h+4]){// remplissage de 5 lettres alignées horizontalement
                for(int i = j; i > 0; i--){
                    grid[i][h] = grid[i-1][h];
                    grid[i][h+1] = grid[i-1][h+1];
                    grid[i][h+2] = grid[i-1][h+2];
                    grid[i][h+3] = grid[i-1][h+3];
                    grid[i][h+4] = grid[i-1][h+4];
                }
                for(int k=h; k>h+5 ;k++){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)        
                }
            } 
            if(grid[j][h]==del && grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h] && grid[j][h]==grid[j+3][h] && grid[j][h]==grid[j+4][h]){// remplissage de 5 lettres alignées verticalement
                for(int i = j; i > 0; i-=5){
                    grid[i][h] = grid[i-5][h];
                    grid[i+1][h] = grid[i-4][h];
                    grid[i+2][h] = grid[i-3][h];
                    grid[i+3][h] = grid[i-2][h];
                    grid[i+4][h] = grid[i-1][h];
                }
                for(int k=0; k<6 ;k++){
                    do {
                        grid[k][h] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[k][h]==grid[k][h-1] && grid[k][h]==grid[k][h-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[k][h]==grid[k-1][h] && grid[k][h]==grid[k-2][h]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[k][h]==grid[k+1][h+1] && grid[k][h]==grid[k+2][h+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[k][h]==grid[k+1][h-1] && grid[k][h]==grid[k+2][h-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)
                }
            }
            if(grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2] && grid[j][h]==grid[j+3][h+3] && grid[j][h]==grid[j+4][h+4]){// remplissage de 5 lettres alignées diagonalement (haut-gauche -> bas-droite)
                for(int i = j; i > -4; i--){
                    if(i>0){
                    grid[i][h] = grid[i-1][h];
                    }
                    if(i>-1){
                    grid[i+1][h+1] = grid[i][h+1];
                    }
                    if(i>-2){
                    grid[i+2][h+2] = grid[i+1][h+2];
                    }
                    if(i>-3){
                    grid[i+3][h+3] = grid[i+2][h+3];
                    }
                    grid[i+4][h+4] = grid[i+3][h+4];
                }
                for(int k=h; k<h+5 ;k++){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)     
                }
            }
            if(grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2] && grid[j][h]==grid[j+3][h-3] && grid[j][h]==grid[j+4][h-4]){// remplissage de 5 lettres alignées diagonalement (haut-droite -> bas-gauche)
                for(int i = j; i > -4; i--){
                    if(i>0){
                    grid[i][h] = grid[i-1][h];
                    }
                    if(i>-1){
                    grid[i+1][h-1] = grid[i][h-1];
                    }
                    if(i>-2){
                    grid[i+2][h-2] = grid[i+1][h-2];
                    }
                    if(i>-3){
                    grid[i+3][h-3] = grid[i+2][h-3];
                    }
                    grid[i+4][h-4] = grid[i+3][h-4];
                }
                for(int k=h-4; k<h+1 ;k--){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)    
                }
            }
            if(grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2] && grid[j][h]==grid[j][h+3]){// remplissage de 4 lettres alignées horizontalement
                for(int i = j; i > 0; i--){
                    grid[i][h] = grid[i-1][h];
                    grid[i][h+1] = grid[i-1][h+1];
                    grid[i][h+2] = grid[i-1][h+2];
                    grid[i][h+3] = grid[i-1][h+3];
                }
                for(int k=h; k>h+4 ;k++){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)        
                }
            } 
            if(grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h] && grid[j][h]==grid[j+3][h]){// remplissage de 4 lettres alignées verticalement
                for(int i = j; i > 0; i-=4){
                    grid[i][h] = grid[i-4][h];
                    grid[i+1][h] = grid[i-3][h];
                    grid[i+2][h] = grid[i-2][h];
                    grid[i+3][h] = grid[i-1][h];
                }
                for(int k=0; k<5 ;k++){
                    do {
                        grid[k][h] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[k][h]==grid[k][h-1] && grid[k][h]==grid[k][h-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement deux valeures antérieures
                            || (grid[k][h]==grid[k][h-1] && grid[k][h]==grid[k][h+1]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[k][h]==grid[k][h+1] && grid[k][h]==grid[k][h+2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[k][h]==grid[k-1][h] && grid[k][h]==grid[k-2][h]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[k][h]==grid[k+1][h+1] && grid[k][h]==grid[k+2][h+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[k][h]==grid[k+1][h-1] && grid[k][h]==grid[k+2][h-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)
                }
            }
            if(grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2] && grid[j][h]==grid[j+3][h+3]){// remplissage de 4 lettres alignées diagonalement (haut-gauche -> bas-droite)
                for(int i = j; i > -3; i--){
                    if(i>0){
                    grid[i][h] = grid[i-1][h];
                    }
                    if(i>-1){
                    grid[i+1][h+1] = grid[i][h+1];
                    }
                    if(i>-2){
                    grid[i+2][h+2] = grid[i+1][h+2];
                    }
                    grid[i+3][h+3] = grid[i+2][h+3];
                }
                for(int k=h; k<h+4 ;k++){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)    
                }
            }
            if(grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2] && grid[j][h]==grid[j+3][h-3]){// remplissage de 4 lettres alignées diagonalement (haut-droite -> bas-gauche)
                for(int i = j; i > -3; i--){
                    if(i>0){
                    grid[i][h] = grid[i-1][h];
                    }
                    if(i>-1){
                    grid[i+1][h+1] = grid[i][h-1];
                    }
                    if(i>-2){
                    grid[i+2][h+2] = grid[i+1][h-2];
                    }
                    grid[i+3][h+3] = grid[i+2][h-3];
                }
                for(int k=h-3; k<h+1 ;k++){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)    
                }
            }
            if(grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2]){// remplissage de 3 lettres alignées horizontalement
                for(int i = j; i > 0; i--){
                    grid[i][h] = grid[i-1][h];
                    grid[i][h+1] = grid[i-1][h+1];
                    grid[i][h+2] = grid[i-1][h+2];
                }
                for(int k=h; k>h+3 ;k++){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)        
                }
            } 
            if(grid[j][h]==del && grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h]){// remplissage de 3 lettres alignées verticalement
                for(int i = j; i > 0; i-=3){
                    grid[i][h] = grid[i-3][h];
                    grid[i+1][h] = grid[i-2][h];
                    grid[i+2][h] = grid[i-1][h];
                }
                for(int k=0; k<3 ;k++){
                    do {
                        grid[k][h] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[k][h]==grid[k][h-1] && grid[k][h]==grid[k][h-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[k][h]==grid[k-1][h] && grid[k][h]==grid[k-2][h]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[k][h]==grid[k+1][h+1] && grid[k][h]==grid[k+2][h+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[k][h]==grid[k+1][h-1] && grid[k][h]==grid[k+2][h-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)
                }
            }
            if(grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2]){// remplissage de 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                for(int i = j; i > -2; i--){
                    if(i>0){
                    grid[i][h] = grid[i-1][h];
                    }
                    if(i>-1){
                    grid[i+1][h+1] = grid[i][h+1];
                    }
                    grid[i+2][h+2] = grid[i+1][h+2];
                }
                for(int k=h; k<h+3 ;k++){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)    
                }
            }
            if(grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2]){// remplissage de 3 lettres alignées diagonalement (haut-droite -> bas-gauche)
                for(int i = j; i > -2; i--){
                    if(i>0){
                    grid[i][h] = grid[i-1][h];
                    }
                    if(i>-1){
                    grid[i+1][h-1] = grid[i][h-1];
                    }
                    grid[i+2][h-2] = grid[i+1][h-2];
                }
                for(int k=h-3; k<h+1 ;k++){
                    do {
                        grid[0][k] = 'A' + rand() % GRID_LETTERS;
                    } while ((grid[0][k]==grid[0][k-1] && grid[0][k]==grid[0][k-2]) // vérification qu'il n'y a pas 3 lettres alignées horizontalement
                            || (grid[0][k]==grid[1][k] && grid[0][k]==grid[2][k]) // vérification qu'il n'y a pas 3 lettres alignées verticalement
                            || (grid[0][k]==grid[1][k+1] && grid[0][k]==grid[2][k+2]) // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                            || (grid[0][k]==grid[1][k-1] && grid[0][k]==grid[2][k-2])); // vérification qu'il n'y a pas 3 lettres alignées diagonalement (haut-droite -> bas-gauche)      
                }
            }
        }    
    }
}

void game(char grid[][26], int GRID_SIZE, int GRID_LETTERS){
    int p = 0;
    char del = ' ';
	for(int i=0;i<100;i++){
        game_stopper(grid, GRID_SIZE, p);
        printf("Points: %d\n", p);
        moveLetter(grid, GRID_SIZE, GRID_LETTERS);
        for (int j = 0; j < GRID_SIZE; j++) {
            for (int h = 0; h < GRID_SIZE; h++) {
                if((grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2] && grid[j][h]==grid[j][h+3]&& grid[j][h]==grid[j][h+4]) //vérification qu'il y a 5 lettres alignées horizontalement
                        || (grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h] && grid[j][h]==grid[j+3][h] && grid[j][h]==grid[j+4][h]) // vérification qu'il y a 5 lettres alignées verticalement
                        || (grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2] && grid[j][h]==grid[j+3][h+3] && grid[j][h]==grid[j+4][h+4]) // vérification qu'il y a 5 lettres alignées diagonalement (haut-gauche -> bas-droite)
                        || (grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2] && grid[j][h]==grid[j+3][h-3] && grid[j][h]==grid[j+4][h-4])){// vérification qu'il y a 5 lettres alignées diagonalement (haut-droite -> bas-gauche)
                        p+=150;
                }
                else if((grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2] && grid[j][h]==grid[j][h+3]) // vérification qu'il y a 4 lettres alignées horizontalement
                        || (grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h] && grid[j][h]==grid[j+3][h]) // vérification qu'il y a 4 lettres alignées verticalement
                        || (grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2] && grid[j][h]==grid[j+3][h+3]) // vérification qu'il y a 4 lettres alignées diagonalement (haut-gauche -> bas-droite)
                        || (grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2] && grid[j][h]==grid[j+3][h-3])){// vérification qu'il y a 4 lettres alignées diagonalement (haut-droite -> bas-gauche)
                        p+=100;
                }
                else if((grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2]) // vérification qu'il y a 3 lettres alignées horizontalement
                        || (grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h]) // vérification qu'il y a 3 lettres alignées verticalement
                        || (grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2]) // vérification qu'il y a 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                        || (grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2])){ // vérification qu'il y a 3 lettres alignées diagonalement (haut-droite -> bas-gauche)
                        p+=50;
                }
            }
        }
        grid_filler(grid, GRID_SIZE, GRID_LETTERS);
        print_grid(grid, GRID_SIZE, GRID_LETTERS);
    }
}

void game_stopper(char grid[][26], int GRID_SIZE, int p){// vérification que le joueur ne peut plus aligner 3 lettres
    char joueur[30];
    int verifier=0, t=GRID_SIZE*GRID_SIZE;
    for(int x3=0; x3<GRID_SIZE; x3++){
        for(int y3=0; y3<GRID_SIZE; y3++){
            if((grid[x3][y3]!=grid[x3][y3+2] && grid[x3][y3]!=grid[x3][y3+3]) 
        && (grid[x3][y3]!=grid[x3][y3-2] && grid[x3][y3]!=grid[x3][y3-3]) 
        && (grid[x3][y3]!=grid[x3+1][y3+1] && grid[x3][y3]!=grid[x3+1][y3+2]) 
        && (grid[x3][y3]!=grid[x3+1][y3-1] && grid[x3][y3]!=grid[x3+1][y3-2])
        && (grid[x3][y3]!=grid[x3+1][y3-1] && grid[x3][y3]!=grid[x3+1][y3+1])
        && (grid[x3][y3]!=grid[x3-1][y3+1] && grid[x3][y3]!=grid[x3-1][y3+2])
        && (grid[x3][y3]!=grid[x3-1][y3-1] && grid[x3][y3]!=grid[x3-1][y3-2])
        && (grid[x3][y3]!=grid[x3-1][y3-1] && grid[x3][y3]!=grid[x3-1][y3+1]) 
        && (grid[x3][y3]!=grid[x3+2][y3] && grid[x3][y3]!=grid[x3+3][y3]) 
        && (grid[x3][y3]!=grid[x3+1][y3+1] && grid[x3][y3]!=grid[x3+2][y3+1]) 
        && (grid[x3][y3]!=grid[x3+1][y3-1] && grid[x3][y3]!=grid[x3+2][y3-1]) 
        && (grid[x3][y3]!=grid[x3+1][y3-1] && grid[x3][y3]!=grid[x3-1][y3-1]) 
        && (grid[x3][y3]!=grid[x3+1][y3+1] && grid[x3][y3]!=grid[x3-1][y3+1]) 
        && (grid[x3][y3]!=grid[x3-2][y3] && grid[x3][y3]!=grid[x3-3][y3])
        && (grid[x3][y3]!=grid[x3-1][y3+1] && grid[x3][y3]!=grid[x3-2][y3+1]) 
        && (grid[x3][y3]!=grid[x3-1][y3-1] && grid[x3][y3]!=grid[x3-2][y3-1]) 
        && (grid[x3][y3]!=grid[x3+1][y3+2] && grid[x3][y3]!=grid[x3+2][y3+3]) 
        && (grid[x3][y3]!=grid[x3][y3+1] && grid[x3][y3]!=grid[x3+1][y3+2]) 
        && (grid[x3][y3]!=grid[x3+2][y3+1] && grid[x3][y3]!=grid[x3+3][y3+2])
        && (grid[x3][y3]!=grid[x3+1][y3] && grid[x3][y3]!=grid[x3+2][y3+1]) 
        && (grid[x3][y3]!=grid[x3][y3-1] && grid[x3][y3]!=grid[x3+2][y3+1]) 
        && (grid[x3][y3]!=grid[x3-1][y3] && grid[x3][y3]!=grid[x3+1][y3+2]) 
        && (grid[x3][y3]!=grid[x3][y3+1] && grid[x3][y3]!=grid[x3-2][y3-1]) 
        && (grid[x3][y3]!=grid[x3+1][y3] && grid[x3][y3]!=grid[x3-1][y3-2]) 
        && (grid[x3][y3]!=grid[x3-1][y3-2] && grid[x3][y3]!=grid[x3][y3-1]) 
        && (grid[x3][y3]!=grid[x3-2][y3-3] && grid[x3][y3]!=grid[x3-1][y3-2]) 
        && (grid[x3][y3]!=grid[x3-2][y3-1] && grid[x3][y3]!=grid[x3-3][y3-2]) 
        && (grid[x3][y3]!=grid[x3-1][y3] && grid[x3][y3]!=grid[x3-2][y3-1]) 
        && (grid[x3][y3]!=grid[x3][y3-2] && grid[x3][y3]!=grid[x3][y3-3]) 
        && (grid[x3][y3]!=grid[x3+1][y3-2] && grid[x3][y3]!=grid[x3+2][y3-3]) 
        && (grid[x3][y3]!=grid[x3][y3-1] && grid[x3][y3]!=grid[x3+1][y3-2]) 
        && (grid[x3][y3]!=grid[x3+2][y3-1] && grid[x3][y3]!=grid[x3+3][y3-2]) 
        && (grid[x3][y3]!=grid[x3+1][y3] && grid[x3][y3]!=grid[x3+2][y3-1]) 
        && (grid[x3][y3]!=grid[x3][y3+1] && grid[x3][y3]!=grid[x3+2][y3-1]) 
        && (grid[x3][y3]!=grid[x3-1][y3] && grid[x3][y3]!=grid[x3+1][y3-2]) 
        && (grid[x3][y3]!=grid[x3][y3-1] && grid[x3][y3]!=grid[x3-2][y3+1]) 
        && (grid[x3][y3]!=grid[x3+1][y3] && grid[x3][y3]!=grid[x3-1][y3+2]) 
        && (grid[x3][y3]!=grid[x3-1][y3+2] && grid[x3][y3]!=grid[x3][y3+1]) 
        && (grid[x3][y3]!=grid[x3-2][y3+3] && grid[x3][y3]!=grid[x3-1][y3+2]) 
        && (grid[x3][y3]!=grid[x3-2][y3+1] && grid[x3][y3]!=grid[x3-3][y3+2]) 
        && (grid[x3][y3]!=grid[x3-1][y3] && grid[x3][y3]!=grid[x3-2][y3+1])){ 
            verifier++;
            }
        }
    }
    if(verifier==t){
        printf("Votre Gamertag : ");
        scanf("%s\n",joueur);
        printf("%s, vous avais fait %d points\n",joueur, p);
        exit(5);
    }
}

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

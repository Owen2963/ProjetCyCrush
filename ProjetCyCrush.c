#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Définition des fonctions pour éviter des problèmes d'appels
char generateGrid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
int grid_delete(char grid[][26], int GRID_SIZE);
void print_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
int game_stopper(char grid[][26], int GRID_SIZE, int p);
void grid_filler(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
int good_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);


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
    for (int h = 0; h < 10; h++) {
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
                case ' ':
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
    if((grid[x3][y3]==grid[x4][y4+1] && grid[x3][y3]==grid[x4][y4+2]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x4][y4-1] && grid[x3][y3]==grid[x4][y4-2]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x4][y4-1] && grid[x3][y3]==grid[x4][y4+1]) // vérification que le joueur aligne 3 lettres horizontalement
        || (grid[x3][y3]==grid[x4+1][y4] && grid[x3][y3]==grid[x4+2][y4])
        || (grid[x3][y3]==grid[x4+1][y4] && grid[x3][y3]==grid[x4-1][y4]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x4-1][y4] && grid[x3][y3]==grid[x4-2][y4]) // vérification que le joueur aligne 3 lettres verticalement
        || (grid[x3][y3]==grid[x4+1][y4+1] && grid[x3][y3]==grid[x4+2][y4+2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x4-1][y4-1] && grid[x3][y3]==grid[x4+1][y4+1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x4-1][y4-1] && grid[x3][y3]==grid[x4-2][y4-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-gauche -> bas-droite)
        || (grid[x3][y3]==grid[x4+1][y4-1] && grid[x3][y3]==grid[x4+2][y4-2]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x4+1][y4-1] && grid[x3][y3]==grid[x4+1][y4+1]) // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        || (grid[x3][y3]==grid[x4-1][y4+1] && grid[x3][y3]==grid[x4-2][y4+2])){ // vérification que le joueur aligne 3 lettres diagonalement (haut-droite -> bas-gauche)
        char temp = grid[x3][y3];
        grid[x3][y3] = grid[x4][y4];
        grid[x4][y4] = temp;
        for(int i=0; i<3;i++) {
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


void gravite_new(char grid[][26], int GRID_SIZE, int GRID_LETTERS){
    char del = ' '; // caractère qui représente une case vide
 
    for(int rep=0; rep<GRID_SIZE;rep++){       //permet de faire monter les cases vide
     for(int i= 1; i <GRID_SIZE ; i++){
                for(int j= 0; j< GRID_SIZE; j++){
                    if(grid[i][j] == del){
                       grid[i][j] = grid[i-1][j];
                       grid[i-1][j] = del;
                    }
                }
            
         }
    }
        for (int j = 0; j < GRID_SIZE; j++) {       //permet de remplir les cases vides 
            do {
                if(grid[0][j]==del){//verifier si il y a une case vide
            	 grid[0][j] = 'A' + rand() % GRID_LETTERS;

        
                for(int i=1; i<GRID_SIZE; i++){
                    if (grid[i][j] == del){
                       grid[i][j] = grid[i-1][j];
                       grid[i-1][j] = del;
                    }
                }
            }
            }while(grid[0][j] == del);
        }
    
    
}

int good_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS){
    char del = ' '; // caractère qui représente une case vide
    for(int j=0;j< GRID_SIZE; j++){
        for(int i =0;i<GRID_SIZE;i++){
            if (grid[i][j] == del){
              return 0; //return 0 si il y a encore des cas vide dans la grille
            }
        }
    }

    return 1; //return 1 si il la grille ne contient aucune case vide
}

int score(char grid[][26], int GRID_SIZE, int GRID_LETTERS, int *p){


 for (int j = 0; j < GRID_SIZE; j++) {
            for (int h = 0; h < GRID_SIZE; h++) {     
                if((grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2] && grid[j][h]==grid[j][h+3]&& grid[j][h]==grid[j][h+4]) // 5 lettres alignées horizontalement
                        || (grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h] && grid[j][h]==grid[j+3][h] && grid[j][h]==grid[j+4][h]) // 5 lettres alignées verticalement
                        || (grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2] && grid[j][h]==grid[j+3][h+3] && grid[j][h]==grid[j+4][h+4]) // 5 lettres alignées diagonalement (haut-gauche -> bas-droite)
                        || (grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2] && grid[j][h]==grid[j+3][h-3] && grid[j][h]==grid[j+4][h-4])){// 5 lettres alignées diagonalement (haut-droite -> bas-gauche)
                        *p+=150;
                }
                else if((grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2] && grid[j][h]==grid[j][h+3]) // 4 lettres alignées horizontalement
                        || (grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h] && grid[j][h]==grid[j+3][h]) // 4 lettres alignées verticalement
                        || (grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2] && grid[j][h]==grid[j+3][h+3]) // 4 lettres alignées diagonalement (haut-gauche -> bas-droite)
                        || (grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2] && grid[j][h]==grid[j+3][h-3])){// 4 lettres alignées diagonalement (haut-droite -> bas-gauche)
                        *p+=100;
                }
                else if((grid[j][h]==grid[j][h+1] && grid[j][h]==grid[j][h+2]) // 3 lettres alignées horizontalement
                        || (grid[j][h]==grid[j+1][h] && grid[j][h]==grid[j+2][h]) // 3 lettres alignées verticalement
                        || (grid[j][h]==grid[j+1][h+1] && grid[j][h]==grid[j+2][h+2]) // 3 lettres alignées diagonalement (haut-gauche -> bas-droite)
                        || (grid[j][h]==grid[j+1][h-1] && grid[j][h]==grid[j+2][h-2])){ // 3 lettres alignées diagonalement (haut-droite -> bas-gauche)
                        *p+=50;
                }
            }
        }

    return *p;
    
}

void game(char grid[][26], int GRID_SIZE, int GRID_LETTERS){
    int *p;
    int point=0;
    p=&point;
    char del = ' ';
	for(int i=0;i<5;i++){
        moveLetter(grid, GRID_SIZE, GRID_LETTERS);
        point = score(grid, GRID_SIZE, GRID_LETTERS,p);
         do{
           gravite_new(grid, GRID_SIZE, GRID_LETTERS); //gravité plus faire apparaitre des nouvelles lettres
           point = score(grid, GRID_SIZE, GRID_LETTERS,p);
           grid_delete(grid, GRID_SIZE);               //supprimer si il y a encore des lettres alignés
         }while(good_grid(grid, GRID_SIZE, GRID_LETTERS)==0); //verifier qu'il n'y a pas de case vide dans la grille
        print_grid(grid, GRID_SIZE, GRID_LETTERS);
        printf("Points: %d\n", point);
    }
}


int game_stopper(char grid[][26], int GRID_SIZE, int p){// vérification que le joueur ne peut plus aligner 3 lettres
    char joueur[30];
    int verifier=0, t=GRID_SIZE*GRID_SIZE, x1, y1, x2, y2, x3, y3, x4, y4;
    for(int x=0; x<GRID_SIZE; x++){
        for(int y=0; y<GRID_SIZE; y++){
            // vérification que le joueur ne peut plus aligner 3 lettres avec la case au dessus
            x1=x-1;
            y1=y;
            // vérification que le joueur ne peut plus aligner 3 lettres avec la case à gauche
            x2=x;
            y2=y-1;
            // vérification que le joueur ne peut plus aligner 3 lettres avec la case à droite
            x3=x;
            y3=y+1;
            // vérification que le joueur ne peut plus aligner 3 lettres avec la case en dessous
            x4=x+1;
            y4=y;
            if((grid[x][y]==grid[x1][y1+1] && grid[x][y]==grid[x1][y1+2])
            && (grid[x][y]==grid[x1][y1-1] && grid[x][y]==grid[x1][y1-2])
            && (grid[x][y]==grid[x1][y1-1] && grid[x][y]==grid[x1][y1+1])
            && (grid[x][y]==grid[x1+1][y1] && grid[x][y]==grid[x1+2][y1])
            && (grid[x][y]==grid[x1+1][y1] && grid[x][y]==grid[x1-1][y1])
            && (grid[x][y]==grid[x1-1][y1] && grid[x][y]==grid[x1-2][y1])
            && (grid[x][y]==grid[x1+1][y1+1] && grid[x][y]==grid[x1+2][y1+2])
            && (grid[x][y]==grid[x1-1][y1-1] && grid[x][y]==grid[x1+1][y1+1])
            && (grid[x][y]==grid[x1-1][y1-1] && grid[x][y]==grid[x1-2][y1-2])
            && (grid[x][y]==grid[x1+1][y1-1] && grid[x][y]==grid[x1+2][y1-2])
            && (grid[x][y]==grid[x1+1][y1-1] && grid[x][y]==grid[x1+1][y1+1])
            && (grid[x][y]==grid[x1-1][y1+1] && grid[x][y]==grid[x1-2][y1+2])){
            verifier++;
            }
        }
    }
    if(verifier==t){
        printf("Votre Gamertag : ");
        scanf("%s\n",joueur);
        printf("%s, vous avais fait %d points\n",joueur, p);
        return 1;
    }
    return 0;
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

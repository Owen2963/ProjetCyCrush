#include <stdio.h>
#include <stdlib.h>
#ifndef GRID_H//Inclusion des fonctions nécessaires pour la fonction
    #define GRID_H
    #include "grid.h"
    #endif
#ifndef GRAVITY_H
    #define GRAVITY_H
    #include "gravity.h"
    #endif
    #ifndef MOVEMENT_H
    #define MOVEMENT_H
    #include "movement.h"
    #endif
int game_stopper(char grid[][26], int GRID_SIZE, int p);//Définition des fonctions éviter des erreus d'appel


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
    int *p, gs=0;
    int point=0;
    p=&point;
    char del = ' ';
	do{
        gs=game_stopper(grid, GRID_SIZE, point);
        moveLetter(grid, GRID_SIZE, GRID_LETTERS);
        point = score(grid, GRID_SIZE, GRID_LETTERS,p);
         do{
           gravite_new(grid, GRID_SIZE, GRID_LETTERS); //gravité + faire apparaitre des nouvelles lettres
           point = score(grid, GRID_SIZE, GRID_LETTERS,p);
           grid_delete(grid, GRID_SIZE); //supprimer si il y a encore des lettres alignés
         }while(good_grid(grid, GRID_SIZE, GRID_LETTERS)==0); //verifier(tant que) qu'il n'y a pas de case vide dans la grille
        print_grid(grid, GRID_SIZE, GRID_LETTERS);
        printf("Points: %d\n", point);
    }while (gs!=1); //tant que le jeu n'est pas fini 
    exit(1);
}


int game_stopper(char grid[][26], int GRID_SIZE, int p){// vérification que le joueur ne peut plus aligner 3 lettres
    char joueur[30];
    int verifier=0, t=GRID_SIZE*GRID_SIZE, x1, y1, x2, y2, x3, y3, x4, y4;
    for(int x=0; x<GRID_SIZE; x++){
        for(int y=0; y<GRID_SIZE; y++){
            // la case au dessus
            x1=x-1;
            y1=y;
            // la case à gauche
            x2=x;
            y2=y-1;
            // la case à droite
            x3=x;
            y3=y+1;
            // la case en dessous
            x4=x+1;
            y4=y;
            if((grid[x][y]!=grid[x1][y1+1] || grid[x][y]!=grid[x1][y1+2])// vérification que le joueur ne peut plus aligner 3 lettres avec la case au dessus
            && (grid[x][y]!=grid[x1][y1-1] || grid[x][y]!=grid[x1][y1-2])
            && (grid[x][y]!=grid[x1][y1-1] || grid[x][y]!=grid[x1][y1+1])
            && (grid[x][y]!=grid[x1-1][y1] || grid[x][y]!=grid[x1-2][y1])
            && (grid[x][y]!=grid[x1-1][y1-1] || grid[x][y]!=grid[x1-2][y1-2])
            && (grid[x][y]!=grid[x1-1][y1+1] || grid[x][y]!=grid[x1-2][y1+2])
            && (grid[x][y]!=grid[x2][y2-1] || grid[x][y]!=grid[x2][y2-2])// vérification que le joueur ne peut plus aligner 3 lettres avec la case à gauche
            && (grid[x][y]!=grid[x2+1][y2] || grid[x][y]!=grid[x2+2][y2])
            && (grid[x][y]!=grid[x2+1][y2] || grid[x][y]!=grid[x2-1][y2])
            && (grid[x][y]!=grid[x2-1][y2] || grid[x][y]!=grid[x2-2][y2])
            && (grid[x][y]!=grid[x2+1][y2+1] || grid[x][y]!=grid[x2-1][y2-1])
            && (grid[x][y]!=grid[x2-1][y2-1] || grid[x][y]!=grid[x2-2][y2-2])
            && (grid[x][y]!=grid[x2+1][y2-1] || grid[x][y]!=grid[x2+2][y2-2])
            && (grid[x][y]!=grid[x3][y3+1] || grid[x][y]!=grid[x3][y3+2]) // vérification que le joueur ne peut plus aligner 3 lettres avec la case à droite
            && (grid[x][y]!=grid[x3+1][y3] || grid[x][y]!=grid[x3+2][y3])
            && (grid[x][y]!=grid[x3+1][y3] || grid[x][y]!=grid[x3-1][y3])
            && (grid[x][y]!=grid[x3-1][y3] || grid[x][y]!=grid[x3-2][y3])
            && (grid[x][y]!=grid[x3+1][y3+1] || grid[x][y]!=grid[x3+2][y3+2])
            && (grid[x][y]!=grid[x3-1][y3-1] || grid[x][y]!=grid[x3+1][y3+1])
            && (grid[x][y]!=grid[x3-1][y3+1] || grid[x][y]!=grid[x3-2][y3+2])
            && (grid[x][y]!=grid[x3-1][y3+1] || grid[x][y]!=grid[x3-2][y3+2])
            && (grid[x][y]!=grid[x4][y4+1] || grid[x][y]!=grid[x4][y4+2]) // vérification que le joueur ne peut plus aligner 3 lettres avec la case en dessous
            && (grid[x][y]!=grid[x4][y4-1] || grid[x][y]!=grid[x4][y4-2])
            && (grid[x][y]!=grid[x4][y4-1] || grid[x][y]!=grid[x4][y4+1])
            && (grid[x][y]!=grid[x4+1][y4] || grid[x][y]!=grid[x4+2][y4])
            && (grid[x][y]!=grid[x4+1][y4+1] || grid[x][y]!=grid[x4+2][y4+2])
            && (grid[x][y]!=grid[x4+1][y4-1] || grid[x][y]!=grid[x4+2][y4-2])
            && (grid[x][y]!=grid[x4-1][y4-1] || grid[x][y]!=grid[x4+1][y4+1])
            && (grid[x][y]!=grid[x4-1][y4+1] || grid[x][y]!=grid[x4+1][y4-1])
            && (grid[x][y]!=grid[x4-1][y4-1] || grid[x][y]!=grid[x4-2][y4-2])
            && (grid[x][y]!=grid[x4+1][y4-1] || grid[x][y]!=grid[x4+1][y4+1])
            && (grid[x][y]!=grid[x4-1][y4+1] || grid[x][y]!=grid[x4-2][y4+2])){
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
    else{
        return 0;
    }
}

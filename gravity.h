#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int grid_delete(char grid[][26], int GRID_SIZE);
void gravite_new(char grid[][26], int GRID_SIZE, int GRID_LETTERS);
int good_grid(char grid[][26], int GRID_SIZE, int GRID_LETTERS);


int grid_delete(char grid[][26], int GRID_SIZE){
    char del = ' '; // caractère qui représente une case vide
    int found_align = 0;
    for (int h = 0; h < 4; h++) { //Nombre maximum de combinaison qu'on peut créer avec un déplacement
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


void gravite_new(char grid[][26], int GRID_SIZE, int GRID_LETTERS){
    char del = ' '; //caractère qui représente une case vide
 
    for(int rep=0; rep<GRID_SIZE;rep++){ //permet d'afficher les cases vide
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

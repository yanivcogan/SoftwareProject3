#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Parser.h"
#include "Solver.h"
#include "MainAux.h"
#define DIMENSION 9
#define ROWPERBLOCK 3
#define COLPERBLOCK 3
//#define BLOCK_SIZE 3

int main (int argc, char **argv)
{
    int **arr,i;
    int **fixed;
    int **solution;
    srand(argc);

    initialize(arr,fixed,solution,DIMENSION,ROWPERBLOCK,COLPERBLOCK);

    /*int i,j;
    char* command;
    int **arr=(int**) calloc(DIMENSION, sizeof(int*));
    int **fixed=(int**) calloc(DIMENSION, sizeof(int*));
    for(i=0; i<DIMENSION; i++){
        arr[i]=(int*) calloc(DIMENSION, sizeof(int));
        fixed[i]=(int*) calloc(DIMENSION, sizeof(int));
    }*/

    /*for(i=0; i<DIMENSION; i++){
        for(j=0; j<DIMENSION; j++){
        arr[i][j]=j;
        fixed[i][j]=i;
        }
    }
    fixed[6][5]=0;
    fixed[7][4]=0;


    arr[6][5]=9;
    arr[7][4]=0;
    print_board(arr,fixed,9,3,3);
    set(arr,DIMENSION,fixed,7,4,9,3,3);
    printf("%d",arr[7][4]);*/

    /*while(1){
        get_next_command();
    }*/
    return 0;
}





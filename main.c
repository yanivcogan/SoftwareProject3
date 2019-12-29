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


int main() {

   // int i;
    //char *command;

    time_t  t;
    srand((unsigned) time(&t));
  // srand((unsigned )argv[0]);
    int **arr= (int **) malloc(DIMENSION * sizeof(int *));
    first_init(arr,DIMENSION);
    int **fixed= (int **) malloc(DIMENSION * sizeof(int *));
    first_init(fixed,DIMENSION);
    int **solution= (int **) malloc(DIMENSION * sizeof(int *));
    first_init(solution,DIMENSION);

    initialize((int(*)[9]) arr,(int(*)[9]) fixed,(int(*)[9]) solution, DIMENSION, ROWPERBLOCK, COLPERBLOCK);
   /*  while(1){
        get_next_command(arr,fixed,solution,DIMENSION,ROWPERBLOCK,COLPERBLOCK);
    }*/

    return 0;
}
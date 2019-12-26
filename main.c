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
    int **arr;
    int **fixed;
    int **solution;
    int i;
    char *command;

    //srand(argc);
    first_init(arr, fixed, solution, DIMENSION);

    initialize(arr, fixed, solution, DIMENSION, ROWPERBLOCK, COLPERBLOCK);

    /* while(1){
        get_next_command(arr,fixed,solution,DIMENSION,ROWPERBLOCK,COLPERBLOCK);
    }*/

    return 0;
}
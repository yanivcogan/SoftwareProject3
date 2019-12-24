#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Parser.h"
#include "Solver.h"
#include "MainAux.h"

void fail_memory(char *message){
printf("Error: %s has failed\n",message);
exit(0);
}

void fix_random_cells(int **fixed,int dimension,int num_fix){
    int num=0,row_fix,col_fix;
    while(num<num_fix)
    {
        row_fix= rand()%dimension;
        col_fix= rand()%dimension;
   if(fixed[row_fix][col_fix]==0) {
       fixed[row_fix][col_fix] = 1;
       num++;
   }
}
}

int check_valid_num_fix(int num_fix){
if(num_fix<0||num_fix>80)
    return 0;
return 1;
}

void dynamic_alloc(int **arr,int **fixed,int **solution,int dimension){
int num;
    arr=(int**) realloc(dimension, sizeof(int*));
    fixed=(int**) realloc(dimension, sizeof(int*));
    solution=(int**) realloc(dimension, sizeof(int*));
    for(num=0; num<dimension; num++){
        arr[num]=(int*) realloc(dimension, sizeof(int));
        fixed[num]=(int*) realloc(dimension, sizeof(int));
        solution[num]=(int*) realloc(dimension, sizeof(int));
    }
}

void initialize(int **arr,int **fixed,int **solution,int dimension,int row_per_block,int col_per_block){
    int is_ok,num_fix,is_end;

    while(1) {
        printf("Enter the number of cells to fill [0-80]:\n");
        is_end = scanf("%d", &num_fix);
        if (is_end != 1)
            exit(0);
        is_ok = check_valid_num_fix(num_fix);
        if (!is_ok) {
            printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
        } else {
            random_solve_soduko(arr,solution,dimension,row_per_block,col_per_block);
            fix_random_cells(fixed,dimension,num_fix);
            break;
        }
    }
}





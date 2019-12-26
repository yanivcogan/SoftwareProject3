#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Solver.h"
#include "MainAux.h"

void fail_memory(char *message){
    printf("Error: %s has failed\n",message);
    exit(0);
}

void first_init(int **arr,int **fixed, int **solution,int dimension){
    int i;
    arr=(int**) malloc(dimension*sizeof(int*));
    fixed=(int**) malloc(dimension*sizeof(int*));
    solution=(int**) malloc(dimension*sizeof(int*));
    if(!arr||!fixed||!solution){
        fail_memory("initialize");
    }
    for(i=0; i<dimension; i++){
        arr[i]=(int*) malloc(dimension*sizeof(int));
        fixed[i]=(int*) malloc(dimension*sizeof(int));
        solution[i]=(int*) malloc(dimension*sizeof(int));
        if(!arr[i]||!fixed[i]||!solution[i])
            fail_memory("initialize");
    }
}


void fix_random_cells(int **fixed,int dimension,int num_fix){
    int num=0,row_fix,col_fix;
    while(num<num_fix)
    {
        if(fixed[row_fix][col_fix]==0) {
        row_fix= rand()%dimension;
        col_fix= rand()%dimension;

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


void reset_boards(int **arr,int **fixed,int **solution,int dimension){
    int index_row,index_col;
    for(index_row=0; index_row<dimension; index_row++){
        for(index_col=0; index_col<dimension; index_col++) {
arr[index_row][index_col]=0;
            fixed[index_row][index_col]=0;
            solution[index_row][index_col]=0;
        }
    }
}

void initialize(int **arr,int **fixed,int **solution,int dimension,int row_per_block,int col_per_block){
    int is_ok,num_fix,is_end;
    reset_boards(arr,fixed,solution,dimension);

    while(1) {
        printf("Enter the number of cells to fill [0-80]:\n");
        is_end = scanf("%d", &num_fix);
        if (is_end != 1)
            exit(0);
        is_ok = check_valid_num_fix(num_fix);
        if (!is_ok) {
            printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
        } else {
            fix_random_cells(fixed,dimension,num_fix);
            random_solve_soduko(arr,solution,dimension,row_per_block,col_per_block);

            break;
        }
    }
}





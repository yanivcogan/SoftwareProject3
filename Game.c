#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Parser.h"
#include "Solver.h"
#include "MainAux.h"

void print_board(int **board,int **fixed,int dimension,int row_per_block,int col_per_block)
{
    int index_row,index_col,index_block,blocks_per_row;
    blocks_per_row=dimension/col_per_block;

    for(index_row=0; index_row<dimension; index_row++){
        if(index_row%row_per_block==0)
            printf("----------------------------------\n");
        for(index_block=0; index_block<blocks_per_row; index_block++){
            printf("| ");
            for(index_col=0; index_col<col_per_block; index_col++){
                if(board[index_row][index_col+col_per_block*index_block]!=0){
                    if(fixed[index_row][index_col+col_per_block*index_block]!=0)
                        printf(".%d ",board[index_row][index_col+col_per_block*index_block]);
                    else
                        printf(" %d ",board[index_row][index_col+col_per_block*index_block]);
                }
                else{
                    printf("   ");
                }
            }
        }

        printf("|\n");

    }
    printf("----------------------------------\n");
}

int in_row(const int *arr,int dimension, int value)
{
    int index;
    for(index=0; index<dimension; index++)
    {
        if(arr[index]==value)
            return 1;
    }
    return 0;
}

int in_col(const int *arr,int dimension, int value)
{
    int index;
    for(index=0; index<dimension; index++)
    {
        if(arr[index]==value)
            return 1;
    }
    return 0;
}
int in_block(int **arr,int dimension,int block_start_row,int block_start_col, int value,int row_per_block,int col_per_block)
{
    int row,col;
    for(row=0; row<row_per_block; row++){
        for(col=0; col<col_per_block; col++){
            if(arr[row+block_start_row][col+block_start_col]==value)
                return 1;
        }
    }
    return 0;
}

int is_valid(int **arr,int dimension,int row,int col, int value,int row_per_block,int col_per_block){
    if(in_block(arr,dimension,row-row%3,col-col%3,value,row_per_block,col_per_block)||in_row(arr[row],dimension,value)||in_col(arr[col],dimension,value)){
        return 0;
    }
    return 1;
}

void end_state(){

}

int check_end_cond(){

}

void set(int **arr,int dimension,int **fixed,int x,int y,int z,int row_per_block,int col_per_block) {
    if(arr[x][y]==z)
        return;
    if (fixed[x][y] == 1) {
        printf("Error: cell is fixed\n");
        return;
    }
    if(z==0){
        arr[x][y]=0;
        return;
    }
    if (is_valid(arr, dimension, x, y, z,row_per_block,col_per_block)) {
        arr[x][y] = z;
        if (check_end_cond(arr)) {
            printf("Puzzle solved successfully\n");
            end_state();
        }
    } else {
        printf("Error: value is invalid\n");
        return;
    }
}
void validate(int **arr,int **solution,int dimension,int row_per_block,int col_per_block){
    if(!solve_soduko(arr,solution,dimension,row_per_block,col_per_block)){
        printf("Validation failed: board is unsolvable\n");
        //    update_solvable(arr,dimension);
    }
    else{
        printf("Validation passed: board is solvable\n");
    }
}

void hint(int **arr,int **solution, int dimension,int x,int y){

    printf("Hint: set cell to%d\n",solution[x][y]);
}

void free_arrays(int **arr, int dimension){
    int index;
    for(index=0; index<dimension; index++){
        free(arr[index]);
    }
    free(arr);
}

void free_resources(int **arr,int** solution,int** fixed, int dimension) {
    free_arrays(arr,dimension);
    free_arrays(solution,dimension);
    free_arrays(fixed,dimension);
}


void exit_game(int** arr,int** solution, int** fixed,int dimension){
    printf("Existing...\n");
    free_resources(arr,solution,fixed,dimension);
    exit(0);
}

void restart(){

}







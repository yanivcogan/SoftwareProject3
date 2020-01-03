#include <stdlib.h>
#include <stdio.h>
#include "MainAux.h"
#include "Game.h"

/* deterministic solution for current board */
int deter_solve(int **solution, int dimension, int row_per_block, int col_per_block){
    int row, col,num;

    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            if (solution[row][col] == 0) {
                for (num = 1; num <= dimension; num++) {
                    if (is_valid(solution, dimension, row, col, num, row_per_block, col_per_block)) {

                        solution[row][col] = num;
                        if (deter_solve(solution, dimension, row_per_block, col_per_block)) {
                            return 1;
                        } else {
                            solution[row][col] = 0;
                        }
                    }

                }

                return 0;
            }
        }
    }

    return 1;
}

/* randomize solution for current board */
int random_solve(int **solution, int dimension, int row_per_block, int col_per_block){
    int row, col,num,random;
    int valid=0;
    int *arr;
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            if (solution[row][col] == 0) {
                /* array of legal values for current square*/
                arr=(int*)calloc(dimension,sizeof(int));
                if(!arr){
                    fail_memory("calloc");
                }
                for (num = 1; num <= dimension; num++) {
                    if (is_valid(solution, dimension, row, col, num, row_per_block, col_per_block)) {
                        arr[valid] = num;
                        valid++;
                    }
                }
                while(valid!=0) {
                    random = valid > 1 ? rand() % valid : 0;
                    solution[row][col] = arr[random];
                    if (random_solve(solution, dimension, row_per_block, col_per_block)) {
                        return 1;
                    } else {
                        solution[row][col] = 0;
                        while (random<dimension-1){
                            arr[random]=arr[random+1];
                            random++;
                        }
                        valid--;
                    }
                }
                free(arr);
                return 0;
            }
        }
    }

    return 1;
}
/* determine which sudoku solve method type to use */
int solve_soduko(int **arr, int **solution, int dimension, int row_per_block, int col_per_block,int is_random) {
    int row, col;
    int **temp=first_init(dimension);
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            temp[row][col] = arr[row][col];
        }

    }

    if(is_random) {
        if(random_solve(temp, dimension, row_per_block, col_per_block)) {
            copy_arrays(temp, solution,dimension);
            free(temp);
            return 1;
        }
    }
    else if(deter_solve(temp,dimension,row_per_block,col_per_block))
    {
    copy_arrays(temp,solution,dimension);
    free(temp);
    return 1;
    }
    free(temp);
    return  0;
}

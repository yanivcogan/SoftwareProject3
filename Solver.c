#include <stdio.h>
#include <stdlib.h>
#include "Solver.h"
#include "MainAux.h"
#include "Game.h"

int deter_solve(int solution[9][9], int dimension, int row_per_block, int col_per_block){
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


int random_solve(int solution[9][9], int dimension, int row_per_block, int col_per_block){
    int row, col,num,random;
    int valid=0;
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            if (solution[row][col] == 0) {
                int arr[9]={};
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
                return 0;
            }
        }
    }

    return 1;
}

int solve_soduko(int arr[9][9], int solution[9][9], int dimension, int row_per_block, int col_per_block,int is_random) {
    int row, col;
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            solution[row][col] = arr[row][col];
        }

    }

    if(is_random) {
        return random_solve(solution, dimension, row_per_block, col_per_block);
    }
    return deter_solve(solution, dimension, row_per_block, col_per_block);
}


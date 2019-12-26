#include <stdio.h>
#include <stdlib.h>
#include "Solver.h"
#include "MainAux.h"
#include "Game.h"

int random_solve(int solution[9][9], int dimension, int row_per_block, int col_per_block){
    int row, col,num;

    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            if (solution[row][col] == 0) {
                for (num = 1; num <= dimension; num++) {
                    if (is_valid(solution, dimension, row, col, num, row_per_block, col_per_block)) {

                        solution[row][col] = num;
                        if (random_solve(solution, dimension, row_per_block, col_per_block)) {
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
int random_solve_soduko(int arr[9][9], int solution[9][9], int dimension, int row_per_block, int col_per_block) {
    int row, col;
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            solution[row][col] = arr[row][col];
        }

    }


    return random_solve(solution, dimension, row_per_block, col_per_block);
}


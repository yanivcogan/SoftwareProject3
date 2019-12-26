#include <stdio.h>
#include <stdlib.h>
#include "Solver.h"
#include "MainAux.h"

int solve_soduko(int **arr, int **solution, int dimension, int row_per_block, int col_per_block) {
    int row, col, num;

    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            if (arr[row][col] == 0) {
                for (num = 1; num <= dimension; num++) {
                    if (is_valid(arr, dimension, row, col, num, row_per_block, col_per_block)) {
                        solution[row][col] = num;
                        if (solve_soduko(arr, solution, dimension, row_per_block, col_per_block)) {
                            return 1;
                        } else {
                            solution[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
        return 1;
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Solver.h"
#include "MainAux.h"
/* print board's status */
void print_board(int **board, int **fixed, int dimension, int row_per_block, int col_per_block) {
    int index_row, index_col, index_block, blocks_per_row;
    blocks_per_row = dimension / col_per_block;

    for (index_row = 0; index_row < dimension; index_row++) {
        if (index_row % row_per_block == 0)
            printf("----------------------------------\n");
        for (index_block = 0; index_block < blocks_per_row; index_block++) {
            printf("| ");
            for (index_col = 0; index_col < col_per_block; index_col++) {
                if (board[index_row][index_col + col_per_block * index_block] != 0) {

                    if (fixed[index_row][index_col + col_per_block * index_block] != 0)
                        printf(".%d ", board[index_row][index_col + col_per_block * index_block]);
                    else
                        printf(" %d ", board[index_row][index_col + col_per_block * index_block]);
                } else {
                    printf("   ");
                }
            }
        }
        printf("|\n");
    }
    printf("----------------------------------\n");
}
/* validation of value in row */
int in_row(int *arr, int dimension, int value) {
    int index;
    for (index = 0; index < dimension; index++) {
        if (arr[index] == value)
            return 1;
    }
    return 0;
}
/* validation of value in column */
int in_col(int **arr, int dimension, int col, int value) {
    int index;
    for (index = 0; index < dimension; index++) {
        if (arr[index][col] == value)
            return 1;
    }
    return 0;
}
/* validation of value in block */
int in_block(int **arr, int block_start_row, int block_start_col, int value, int row_per_block,
             int col_per_block) {
    int row, col;
    for (row = 0; row < row_per_block; row++) {
        for (col = 0; col < col_per_block; col++) {
            if (arr[row + block_start_row][col + block_start_col] == value)
                return 1;
        }
    }
    return 0;
}
/* check validation of value */
int is_valid(int **arr, int dimension, int row, int col, int value, int row_per_block, int col_per_block) {
    if (arr[row][col] == value) {
        return 1;
    }
    if ((in_block(arr, row - row % 3, col - col % 3, value, row_per_block,
                  col_per_block)) || (in_row(arr[row], dimension, value)) || (in_col(arr, dimension, col, value))) {
        return 0;
    }
    return 1;
}
/* board is full */
void end_state(int *is_over) {
*is_over=1;
}
/* check if board is full */
int check_end_cond(int **arr, int dimension) {
    int index_row, index_col;
    for (index_row = 0; index_row < dimension; index_row++) {
        for (index_col = 0; index_col < dimension; index_col++) {
            if (arr[index_row][index_col] == 0)
                return 0;
        }
    }
    return 1;
}
/* set square to input value if value is legal*/
void set(int **arr, int dimension, int **fixed, int y, int x, int z, int row_per_block, int col_per_block, int *is_over) {
    if (fixed[x][y] == 1) {
        printf("Error: cell is fixed\n");
        return;
    }
    if (z == 0) {
        arr[x][y] = 0;
        print_board(arr, fixed, dimension, row_per_block, col_per_block);
        return;
    }

    if (is_valid(arr, dimension, x, y, z, row_per_block, col_per_block)) {
        arr[x][y] = z;
        print_board(arr, fixed, dimension, row_per_block, col_per_block);
        if (check_end_cond(arr, dimension)) {
            printf("Puzzle solved successfully\n");
            end_state(is_over);
        }
    } else {
        printf("Error: value is invalid\n");
        return;
    }
}
/* check whether board is solvable */
void validate(int **arr, int **solution, int dimension, int row_per_block, int col_per_block) {
    if (!solve_soduko(arr, solution, dimension, row_per_block, col_per_block, 0)) {
        printf("Validation failed: board is unsolvable\n");
    } else {
        printf("Validation passed: board is solvable\n");
    }
}
/* hint for square's value */
void hint(int **solution, int y, int x) {
    printf("Hint: set cell to %d\n", solution[x][y]);
}
/* free memory */
void free_arrays(int **arr, int dimension) {
    int index;
    for (index = 0; index < dimension; index++) {
        free(arr[index]);
    }
    free(arr);
}

void free_resources(int **arr, int **solution, int **fixed, int dimension) {
    free_arrays(arr, dimension);
    free_arrays(solution, dimension);
    free_arrays(fixed, dimension);
}

/* exit the game */
void exit_game(int **arr, int **solution, int **fixed, int dimension) {
    printf("Exiting...\n");
    free_resources(arr, solution, fixed, dimension);
    exit(0);
}
/* start a new game */
void restart(int **arr, int **fixed, int **solution, int dimension, int row_per_block, int col_per_block,int *is_over) {
    *is_over=0;
    initialize(arr, fixed, solution, dimension, row_per_block, col_per_block);
    empty_buffer();
}

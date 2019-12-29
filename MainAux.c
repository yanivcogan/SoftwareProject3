#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Solver.h"
#include "MainAux.h"
#include "Game.h"

void fail_memory(char *message) {
    printf("Error: %s has failed\n", message);
    printf("failmem");
    exit(0);
}

void first_init(int **arr,int dimension) {
    int i;

    for (i = 0; i < dimension; i++) {
        arr[i] = (int *) malloc(dimension * sizeof(int));
        if (!arr[i] ) {
            printf("error first init");
            fail_memory("initialize");
        }
    }

}


void fix_random_cells(int fixed[9][9], int dimension, int num_fix) {
    int num = 0, row_fix, col_fix;
    while (num < num_fix) {
        row_fix = rand() % dimension;
        col_fix = rand() % dimension;
        if (fixed[row_fix][col_fix] == 0) {
            fixed[row_fix][col_fix] = 1;
            num++;
        }
    }

}

int check_valid_num_fix(int num_fix) {
    if (num_fix < 0 || num_fix > 80)
        return 0;
    return 1;
}


void reset_boards(int arr[9][9], int fixed[9][9], int solution[9][9], int dimension) {
    int index_row, index_col;
    for (index_row = 0; index_row < dimension; index_row++) {
        for (index_col = 0; index_col < dimension; index_col++) {
            arr[index_row][index_col] = 0;
            fixed[index_row][index_col] = 0;
            solution[index_row][index_col] = 0;
        }
    }
}

void initialize(int arr[9][9], int fixed[9][9], int solution[9][9], int dimension, int row_per_block, int col_per_block) {
    int is_ok, num_fix, is_end;
   // first_init(arr,fixed,solution,dimension);
printf("sas");
    reset_boards(arr, fixed, solution, dimension);

    while (1) {
        printf("Enter the number of cells to fill [0-80]:\n");

        is_end = scanf("%d", &num_fix);
        if (is_end != 1)
            exit(0);
        is_ok = check_valid_num_fix(num_fix);
        if (!is_ok) {
            printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
        } else {

            fix_random_cells(fixed, dimension, num_fix);
            solve_soduko(arr,solution,dimension,row_per_block,col_per_block,1);
            print_board(solution,fixed,dimension,row_per_block,col_per_block);
            break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "Solver.h"

void fail_memory(char *message) {
    printf("Error: %s has failed\n", message);
    exit(0);
}

int** first_init(int dimension) {
    int i;
    int **arr;
    arr= (int **) malloc(dimension * sizeof(int *));
    for (i = 0; i < dimension; i++) {
        arr[i] = (int *) malloc(dimension * sizeof(int));
        if (!arr[i] ) {
            fail_memory("malloc");
        }
    }
    return arr;

}


void fix_random_cells(int **arr,int **fixed,int **solution, int dimension, int num_fix) {
    int num = 0, row_fix, col_fix;
    while (num < num_fix) {
        row_fix = rand() % dimension;
        col_fix = rand() % dimension;
        if (fixed[row_fix][col_fix] == 0) {
            fixed[row_fix][col_fix] = 1;
            arr[row_fix][col_fix]=solution[row_fix][col_fix];
            num++;
        }
    }

}

int check_valid_num_fix(int num_fix) {
    if (num_fix < 0 || num_fix > 80)
        return 0;
    return 1;
}


void reset_boards(int **arr, int **fixed, int **solution, int dimension) {
    int index_row, index_col;
    for (index_row = 0; index_row < dimension; index_row++) {
        for (index_col = 0; index_col < dimension; index_col++) {
            arr[index_row][index_col] = 0;
            fixed[index_row][index_col] = 0;
            solution[index_row][index_col] = 0;
        }
    }
}

void initialize(int **arr, int **fixed, int **solution, int dimension, int row_per_block, int col_per_block) {
    int is_ok, num_fix, is_end, c;
    reset_boards(arr, fixed, solution, dimension);

    while (1) {
        printf("Enter the number of cells to fill [0-80]:\n");
        is_end = scanf("%d", &num_fix);
        if (is_end != 1) {
            fail_memory("scanf");
        }
        /*empty stdin buffer*/
        do{
            c = getchar();
        }while(c != '\n');
        is_ok = check_valid_num_fix(num_fix);
        if (!is_ok) {
            printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
        } else {
            solve_soduko(arr,solution,dimension,row_per_block,col_per_block,1);
            fix_random_cells(arr,fixed,solution, dimension, num_fix);
            /*print_board(arr,fixed,solution,dimension,row_per_block,col_per_block);*/
            break;
        }
    }
}
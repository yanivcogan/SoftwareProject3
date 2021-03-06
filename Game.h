#ifndef SOFTWAREPROJECT3_GAME_H
#define SOFTWAREPROJECT3_GAME_H

void restart(int **arr,int **fixed,int **solution,int dimension,int row_per_block,int col_per_block,int *is_over);

void print_board(int **board, int **fixed, int dimension, int row_per_block, int col_per_block);

int in_row(int *arr, int dimension, int value);

int in_col(int **arr, int dimension,int col, int value);

int in_block(int **arr, int block_start_row, int block_start_col, int value, int row_per_block,
             int col_per_block);

int is_valid(int **arr, int dimension, int row, int col, int value, int row_per_block, int col_per_block);

void end_state();

int check_end_cond();

void set(int **arr, int dimension, int **fixed, int x, int y, int z, int row_per_block, int col_per_block, int *pInt);

void validate(int **arr, int **solution, int dimension, int row_per_block, int col_per_block);

void hint(int **solution, int x, int y);

void free_arrays(int **arr, int dimension);

void free_resources(int **arr, int **solution, int **fixed, int dimension);

void exit_game(int **arr, int **solution, int **fixed, int dimension);

#endif

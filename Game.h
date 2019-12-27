//
// Created by LENOVO on 25/12/2019.
//

#ifndef SOFTWAREPROJECT3_GAME_H
#define SOFTWAREPROJECT3_GAME_H

void restart(int arr[9][9],int fixed[9][9],int solution[9][9],int dimension,int row_per_block,int col_per_block);

void print_board(int board[9][9], int fixed[9][9], int dimension, int row_per_block, int col_per_block);

int in_row(const int arr[9], int dimension, int value);

int in_col(const int arr[9][9], int dimension,int col, int value);

int in_block(int arr[9][9], int dimension, int block_start_row, int block_start_col, int value, int row_per_block,
             int col_per_block);

int is_valid(int arr[9][9], int dimension, int row, int col, int value, int row_per_block, int col_per_block);

void end_state();

int check_end_cond();

void set(int arr[9][9], int dimension, int fixed[9][9], int x, int y, int z, int row_per_block, int col_per_block);

void validate(int arr[9][9], int solution[9][9], int dimension, int row_per_block, int col_per_block);

void hint(int **arr, int **solution, int dimension, int x, int y);

void free_arrays(int **arr, int dimension);

void free_resources(int **arr, int **solution, int **fixed, int dimension);

void exit_game(int **arr, int **solution, int **fixed, int dimension);

void restart();

#endif //SOFTWAREPROJECT3_GAME_H

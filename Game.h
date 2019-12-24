#ifndef SODUKO_GAME_H
#define SODUKO_GAME_H

void print_board(int **board,int **fixed,int dimension,int row_per_block,int col_per_block);
int in_row(const int *arr,int dimension, int value);
int in_col(const int *arr,int dimension, int value);
int in_block(int **arr,int dimension,int block_start_row,int block_start_col, int value,int row_per_block,int col_per_block);
int is_valid(int **arr,int dimension,int row,int col, int value,int row_per_block,int col_per_block);
void end_state();
int check_end_cond();
void set(int **arr,int dimension,int **fixed,int x,int y,int z,int row_per_block,int col_per_block);
void validate(int **arr,int **solution,int dimension,int row_per_block,int col_per_block);
void hint(int **arr,int **solution, int dimension,int x,int y);
void free_arrays(int **arr, int dimension);
void free_resources(int **arr,int** solution,int** fixed, int dimension);
void exit_game(int** arr,int** solution, int** fixed,int dimension);
void restart();
#endif //SODUKO_GAME_H
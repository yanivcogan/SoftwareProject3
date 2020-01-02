#ifndef SOFTWAREPROJECT3_MAINAUX_H
#define SOFTWAREPROJECT3_MAINAUX_H

void copy_arrays(int **copy, int**paste,int dimension);

void fail_memory(char *message);

void empty_buffer();

int ** first_init(int dimension);

void initialize(int **arr, int **fixed, int **solution, int dimension, int row_per_block, int col_per_block);

void fix_random_cells(int** arr,int **fixed,int** solution, int dimension, int num_fix);

int check_valid_num_fix(int num_fix);

#endif

//
// Created by LENOVO on 25/12/2019.
//

#ifndef SOFTWAREPROJECT3_MAINAUX_H
#define SOFTWAREPROJECT3_MAINAUX_H


void fail_memory(char *message);

int ** first_init(int dimension);

void initialize(int **arr, int **fixed, int **solution, int dimension, int row_per_block, int col_per_block);

void fix_random_cells(int** arr,int **fixed,int** solution, int dimension, int num_fix);

int check_valid_num_fix(int num_fix);

#endif //SOFTWAREPROJECT3_MAINAUX_H

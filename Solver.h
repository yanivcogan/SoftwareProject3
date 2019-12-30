//
// Created by LENOVO on 25/12/2019.
//

#ifndef SOFTWAREPROJECT3_SOLVER_H
#define SOFTWAREPROJECT3_SOLVER_H

int random_solve(int **solution, int dimension, int row_per_block, int col_per_block);
int deter_solve(int **solution, int dimension, int row_per_block, int col_per_block);
int solve_soduko(int **arr, int **solution, int dimension, int row_per_block, int col_per_block,int is_random);

#endif //SOFTWAREPROJECT3_SOLVER_H

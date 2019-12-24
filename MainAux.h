

#ifndef HW3_MAINAUX_H
#define HW3_MAINAUX_H

void initialize(int **arr,int **fixed,int **solution,int dimension,int row_per_block,int col_per_block);
void fix_random_cells(int **fixed,int dimension,int num_fix);
int check_valid_num_fix(int num_fix);

#endif //HW3_MAINAUX_H

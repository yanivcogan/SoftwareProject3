#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Parser.h"
#include "Solver.h"
#include "MainAux.h"

#define DIMENSION 9
#define ROWPERBLOCK 3
#define COLPERBLOCK 3


int main() {
    struct Command *currCommand;
    int commandType;
    int* params;
    setbuf(stdout, 0);
    time_t t;
    srand((unsigned) time(&t));
    int **arr= (int **) malloc(DIMENSION * sizeof(int *));
    first_init(arr,DIMENSION);
    int **fixed= (int **) malloc(DIMENSION * sizeof(int *));
    first_init(fixed,DIMENSION);
    int **solution= (int **) malloc(DIMENSION * sizeof(int *));
    first_init(solution,DIMENSION);
    initialize((int(*)[9]) arr,(int(*)[9]) fixed,(int(*)[9]) solution, DIMENSION, ROWPERBLOCK, COLPERBLOCK);
    while(1){
        print_board((int(*)[9])arr,(int(*)[9])fixed,DIMENSION,ROWPERBLOCK, COLPERBLOCK);
        currCommand = get_next_command();
        commandType = get_move_type(currCommand);
        params = get_move_params(currCommand);
        if(get_move_type(currCommand)==0){
            continue;
        }
        switch(commandType){
            case 1:
                set((int(*)[9])arr,DIMENSION,(int(*)[9])fixed,params[0], params[1], params[2],ROWPERBLOCK, COLPERBLOCK);
                break;
            case 2:
                hint(arr,solution,DIMENSION,params[0], params[1]);
                break;
            case 3:
                validate((int(*)[9])arr,(int(*)[9])solution,DIMENSION,ROWPERBLOCK, COLPERBLOCK);
                break;
            case 4:
                restart((int(*)[9])arr,(int(*)[9])fixed,(int(*)[9])solution,DIMENSION,ROWPERBLOCK,COLPERBLOCK);
                break;
            case 5:
                exit_game(arr,solution,fixed,DIMENSION);
                return 0;
        }
    }
}
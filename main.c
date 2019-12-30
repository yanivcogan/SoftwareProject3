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
    //char *command;
    struct Command *currCommand;
    int commandType;
    int* params;
    setbuf(stdout, 0);
    time_t  t;
    int **arr,**fixed,**solution;
    srand((unsigned) time(&t));
   arr= first_init(DIMENSION);
   fixed= first_init(DIMENSION);
   solution= first_init(DIMENSION);

    initialize( arr, fixed, solution, DIMENSION, ROWPERBLOCK, COLPERBLOCK);
    //print_board(arr,fixed,DIMENSION,ROWPERBLOCK, COLPERBLOCK);
    while(1){
        print_board(arr,fixed,solution,DIMENSION,ROWPERBLOCK, COLPERBLOCK);
        currCommand = get_next_command();
        commandType = get_move_type(currCommand);
        params = get_move_params(currCommand);
        if(get_move_type(currCommand)==0){
            continue;
        }
        switch(commandType){
            case 1:
                set(arr,DIMENSION,fixed,params[0], params[1], params[2],ROWPERBLOCK, COLPERBLOCK);
                break;
            case 2:
                hint(arr,solution,DIMENSION,params[0], params[1]);
                break;
            case 3:
                validate(arr,solution,DIMENSION,ROWPERBLOCK, COLPERBLOCK);
                break;
            case 4:
                restart(arr,fixed,solution,DIMENSION,ROWPERBLOCK,COLPERBLOCK);
                break;
            case 5:
                exit_game(arr,solution,fixed,DIMENSION);
                return 0;
        }
    }


}
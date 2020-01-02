#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Parser.h"
#include "MainAux.h"

#define DIMENSION 9
#define ROWPERBLOCK 3
#define COLPERBLOCK 3


int main(int argc, char *argv[]) {
    int seed = atoi(argv[1]);
    int is_over=0;
    struct Command *currCommand;
    int commandType;
    int *params;
    int **arr, **fixed, **solution;
    time_t t;
    setbuf(stdout, 0);
    if(argc){
        srand(seed);
    }
    else{
        srand((unsigned) time(&t));
    }
    arr = first_init(DIMENSION);
    fixed = first_init(DIMENSION);
    solution = first_init(DIMENSION);

    initialize(arr, fixed, solution, DIMENSION, ROWPERBLOCK, COLPERBLOCK);
    empty_buffer();
    /*print_board(arr,fixed,DIMENSION,ROWPERBLOCK, COLPERBLOCK);*/
    while (1) {
        print_board(arr, fixed, DIMENSION, ROWPERBLOCK, COLPERBLOCK);
        currCommand = get_next_command(is_over);
        commandType = get_move_type(currCommand);
        params = get_move_params(currCommand);
        if (get_move_type(currCommand) == 0) {
            continue;
        }
        switch (commandType) {
            case 1:
                set(arr, DIMENSION, fixed, params[0] - 1, params[1] - 1, params[2], ROWPERBLOCK, COLPERBLOCK, &is_over);
                break;
            case 2:
                hint(solution, params[0] - 1, params[1] - 1);
                break;
            case 3:
                validate(arr, solution, DIMENSION, ROWPERBLOCK, COLPERBLOCK);
                break;
            case 4:
                restart(arr, fixed, solution, DIMENSION, ROWPERBLOCK, COLPERBLOCK, &is_over);
                break;
            case 5:
                exit_game(arr, solution, fixed, DIMENSION);
                is_over=1;
                return 0;
        }
    }
}

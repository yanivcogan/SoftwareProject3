#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIMITER " "
#define COMMAND_COUNT 5
#define MAX_COMMAND_LENGTH 1024
#define INVALID_COMMAND_ERROR "Error: invalid command\n"
enum commandTypes {SET=1, HINT=2, VALIDATE=3, RESTART=4, EXIT=5, INVALID=0};
typedef struct CommandSyntax{
    char* name;
    int parCount;
    enum commandTypes type;
};
typedef struct Command{
    enum commandTypes type;
    int params[3];
};
struct Command invalidMove = {
        INVALID, NULL
};
// an object containing an enum indicating the selected command type
// and an array of all parameters relevant to the current command
struct Command currMove = {
        INVALID, NULL
};
struct CommandSyntax commands[COMMAND_COUNT] = {
        {"set", 3, SET},
        {"hint", 2, HINT},
        {"validate", 0, VALIDATE},
        {"restart", 0, RESTART},
        {"exit", 0, EXIT}
};
struct Command* get_next_command(){
    char (* str)[MAX_COMMAND_LENGTH]; // the input string
    char* command; // the substring representing the command type
    char* param; // the substring of the command representing the currently processed parameter;
    int castParam; // the currently processed param after a str to int casting
    int isValidCommandType = 0; // whether the input command type is valid
    int expectedParamCount = 0; // the number of parameters we expect for the selected command
    int missingParams = 0; // whether or not a sufficient
    int i = 0;
    printf("(delete me before posting) input command\n");
    /*empty stdin buffer*/
    int c;
    do{
        c = getchar();
    }while(c != EOF && c != '\n');
    /*read command*/
    fgets(str,MAX_COMMAND_LENGTH,stdin);
    /* extract command */
    command = strtok(str, DELIMITER);
    /*look for command in commands list*/
    for(i = 0; i < COMMAND_COUNT; i++){
        if(strcmp(commands[i].name, command) == 0){
            //once a command is identified, set the validCommand flag to TRUE, and get the required number of parameters for the command.
            isValidCommandType = 1;
            expectedParamCount = commands[i].parCount;
            currMove.type = commands[i].type;
            break;
        }
    }
    //if the command is invalid - print an error
    if(!isValidCommandType){
        printf(INVALID_COMMAND_ERROR);
        return &invalidMove;
    }
    //iterate through the supplied params (space delimited), parse them as integers, and add them to the command parameters array.
    for(i = 0; i < expectedParamCount; i++){
        param = strtok(NULL, DELIMITER);
        //if there are no addition space delimited values
        if(param == NULL){
            missingParams = 1;
            break;
        }
        castParam = strtol(param, NULL, 10);
        currMove.params[i] = castParam;
    }
    //if some of the required params are missing - print an error message
    if(missingParams){
        printf(INVALID_COMMAND_ERROR);
        return &invalidMove;
    }
    printf("command: %s\n", command);
    return &currMove;
}

int* get_move_params(struct Command* move){
    return move->params;
}

int get_move_type(struct Command* move){
    return move->type;
}


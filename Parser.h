enum commandTypes {SET=1, HINT=2, VALIDATE=3, RESTART=4, EXIT=5, INVALID=0};
typedef struct CommandSyntax{
    char* name;
    int parCount;
    int afterOver; /*whether the command is valid after the game is over*/
    enum commandTypes type;
}CommandSyntax;
typedef struct Command{
    enum commandTypes type;
    int params[3];
}Command;
Command* get_next_command(int is_over);
int* get_move_params(struct Command* move);
int get_move_type(struct Command* move);

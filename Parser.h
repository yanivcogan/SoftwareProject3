#ifndef SOFTWAREPROJECT3_PARSER_H
#define SOFTWAREPROJECT3_PARSER_H

enum commandTypes {SET=1, HINT=2, VALIDATE=3, RESTART=4, EXIT=5, INVALID=0};
int get_next_command();
int* get_move_params(struct Command* move);
int get_move_type(struct Command* move);
#endif //SOFTWAREPROJECT3_PARSER_H

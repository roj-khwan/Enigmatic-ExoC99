#include <string.h>
#include "game.h"

int search(board_t board, uint8_t eside, int depth);
int findavails(board_t board, int** moves, int side);
int evaluate(board_t board, int side, int depth);

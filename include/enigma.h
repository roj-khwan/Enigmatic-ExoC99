#include <string.h>
#include "game.h"

int16_t search(board_t board, uint8_t eside, uint16_t depth);
int16_t searchwprune(board_t board, uint8_t eside, uint16_t depth);
size_t findavails(board_t board, int16_t** moves, uint8_t side);
int16_t evaluate(board_t board, uint8_t side, uint16_t depth);

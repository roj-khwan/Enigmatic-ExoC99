#include <stdint.h>
#include <stdlib.h>
#include "board.h"
#include <stdbool.h>

typedef struct MiniMaxInterface_t {
    size_t (*availmoves) (board_t, int16_t**, uint8_t); // state, first move pointer, side -> length
    int8_t (*play) (board_t, uint8_t, int16_t); // state, move, side -> status
    int16_t (*eval) (board_t, uint8_t, uint16_t); // state, side, depth -> score
} MiniMaxInterface;
typedef struct MiniMaxState_t {
    board_t board;
    uint16_t depth;
    uint8_t side;
    char ismax;
} MiniMaxState;
typedef struct MiniMaxAbsolute_t {
    uint8_t side;
    uint16_t maxdepth;
} MiniMaxAbsolute;
typedef struct MiniMaxPrune_t {
    int16_t alpha;
    int16_t beta;
} MiniMaxPrune;

// find terminal state; depth, maxdepth
// state; board
// how to continues; availmoves
// continues state; play
// evaluate state; eval
int16_t minimax(MiniMaxAbsolute* absolute, MiniMaxState state, MiniMaxInterface* interface);
int16_t bestmove(MiniMaxAbsolute* absolute, MiniMaxState state, MiniMaxInterface* interface);
int16_t minimaxpruning(MiniMaxAbsolute* absolute, MiniMaxPrune prune, MiniMaxState state, MiniMaxInterface* interface);
int16_t bestmovepruning(MiniMaxAbsolute* absolute, MiniMaxState state, MiniMaxInterface* interface);
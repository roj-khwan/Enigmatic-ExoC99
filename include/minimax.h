#include <stdint.h>
#include <stdlib.h>
#include "board.h"
#include <stdbool.h>

typedef void* GameStatePointer;
typedef struct MiniMaxInterface_t {
    size_t (*availmoves) (GameStatePointer, int16_t**); // state, first move pointer -> length
    int16_t (*eval) (GameStatePointer, GameStatePointer, uint16_t); // state, firststate, depth -> score
    int8_t (*play) (GameStatePointer, int16_t); // state, move -> status
    void* (*copy) (GameStatePointer);
    void (*destroy) (GameStatePointer);
} MiniMaxInterface;
typedef struct MiniMaxState_t {
    uint16_t depth;
    int16_t alpha;
    int16_t beta;
    char ismax;
} MiniMaxState;
typedef struct MiniMaxAbsolute_t {
    uint16_t maxdepth;
    GameStatePointer firststate;
} MiniMaxAbsolute;

// find terminal state; depth, maxdepth
// state; board
// how to continues; availmoves
// continues state; play
// evaluate state; eval
int16_t minimax(MiniMaxAbsolute* absolute, GameStatePointer state, MiniMaxState minimaxstate, MiniMaxInterface* interface);
int16_t bestmove(MiniMaxAbsolute* absolute, GameStatePointer state, uint16_t depth, MiniMaxInterface* interface);
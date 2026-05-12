#include <stdint.io>
#include "board.h"

// find terminal state; depth, maxdepth
// state; board
// how to continues; availmoves
// continues state; play
// evaluate state; eval
int8_t minimax(uint16_t maxdepth, MiniMaxState state, MiniMaxInterface* interface);

typedef struct MiniMaxInterface MiniMaxInterface;
typedef struct MiniMaxState MiniMaxState;
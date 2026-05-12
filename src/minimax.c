#include "minimax.h"

struct MiniMaxInterface {
    int (*availmoves) (board_t, int*, int); // state, first move pointer, side -> length
    int (*play) (board_t, int, int32_t); // state, move, side -> status
    int16_t (*eval) (board_t, int); // state, side -> score
}
struct MiniMaxState {
    board_t board;
    uint16_t depth;
    char side;
    char ismax;
}

// logic only work with two side game because of side logic...
// future reimprove ment make work with more than two side game.
int8_t minimax(uint16_t maxdepth, MiniMaxState state, MiniMaxInterface* interface)
{
    //check terminal
    // if score not zero return score
    // else if maxdepth == depth then return 0
    int score = interface->eval(state.board, state.side);
    if (score != 0) {
        return score;
    } else if (maxdepth == state.depth) {
        return 0;
    }

    int minimaxscore = state.ismax ? INT16_MIN : INT16_MAX;

    // fetch avails moves
    // loops for each avails move
    int* moves;
    int len = interface->availmoves(state.board, &moves, state.side); 
    for (int i = 0; i < len; i++) {
        board_t copiedboard;
        create(&copiedboard);
        copy(copiedboard, state.board);

        MiniMaxState nextstate = {
            copiedboard,
            state.depth + 1,
            1 - state.side,
            !state.ismax
        };
        
        interface->play(next.board, moves[i], state.side);  
    
        int result = minimax(maxdepth, next, interface);
    
        if (state.ismax) 
            if (result > minimaxscore) minimaxscore = result;
        else
            if (result < minimaxscore) minimaxscore = result;

        destroy(next.board);
    }
    free(moves)

    return minimaxscore;
}
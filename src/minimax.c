#include "minimax.h"

// logic only work with two side game because of side logic...
// future reimprove ment make work with more than two side game.
int16_t minimax(MiniMaxAbsolute* absolute, MiniMaxState state, MiniMaxInterface* interface)
{
    //check terminal
    // if score not zero return score
    // else if maxdepth == depth then return 0
    int16_t score = interface->eval(state.board, absolute->side, state.depth);
    if (score != 0) {
        return score;
    } else if (absolute->maxdepth == state.depth) {
        return 0;
    }

    int16_t minimaxscore = state.ismax ? INT16_MIN : INT16_MAX;

    // fetch avails moves
    // loops for each avails move
    int16_t* moves;
    size_t len = interface->availmoves(state.board, &moves, state.side); 
    for (size_t i = 0; i < len; i++) {
        board_t copiedboard;
        create(&copiedboard);
        copy(copiedboard, state.board);

        MiniMaxState nextstate = (MiniMaxState) {
            copiedboard,
            state.depth + 1,
            1 - state.side,// TODO : interface for changing size later
            !state.ismax
        };
        
        interface->play(nextstate.board, state.side, moves[i]);  
    
        int16_t result = minimax(absolute, nextstate, interface);
        
        if (state.ismax) minimaxscore = (result > minimaxscore) ? result : minimaxscore;
        else minimaxscore = (result < minimaxscore) ? result : minimaxscore;

        destroy(nextstate.board);
    }
    free(moves);

    return minimaxscore;
}

int16_t bestmove(MiniMaxAbsolute* absolute, MiniMaxState state, MiniMaxInterface* interface) {
    int16_t bestscore = INT16_MIN;
    int16_t bestplay;

    int16_t* moves;
    size_t len = interface->availmoves(state.board, &moves, state.side);
    for (size_t i = 0; i < len; i++)
    {
        board_t copiedboard;
        create(&copiedboard);
        copy(copiedboard, state.board);

        MiniMaxState nextstate = (MiniMaxState) {
            copiedboard,
            state.depth + 1,
            1 - state.side,
            !state.ismax
        };
        
        interface->play(nextstate.board, state.side, moves[i]);  
    
        int16_t result = minimax(absolute, nextstate, interface);
        
        if (bestscore < result) {
            bestscore = result;
            bestplay = moves[i];
        }

        destroy(nextstate.board);
    }
    free(moves);
    

    return bestplay;
}

int16_t minimaxpruning(MiniMaxAbsolute* absolute, MiniMaxPrune prune, MiniMaxState state, MiniMaxInterface* interface)
{
    //check terminal
    // if score not zero return score
    // else if maxdepth == depth then return 0
    int16_t score = interface->eval(state.board, absolute->side, state.depth);
    if (score != 0) {
        return score;
    } else if (absolute->maxdepth == state.depth) {
        return 0;
    }

    int16_t minimaxscore = state.ismax ? INT16_MIN : INT16_MAX;

    // fetch avails moves
    // loops for each avails move
    int16_t* moves;
    size_t len = interface->availmoves(state.board, &moves, state.side); 
    for (size_t i = 0; i < len; i++) {
        board_t copiedboard;
        create(&copiedboard);
        copy(copiedboard, state.board);

        MiniMaxState nextstate = (MiniMaxState) {
            copiedboard,
            state.depth + 1,
            1 - state.side,// TODO : interface for changing size later
            !state.ismax
        };
        
        interface->play(nextstate.board, state.side, moves[i]);  
    
        int16_t result = minimaxpruning(absolute, prune, nextstate, interface);
        
        destroy(nextstate.board);
        if (state.ismax) {
            minimaxscore = (result > minimaxscore) ? result : minimaxscore;

            prune.alpha = (minimaxscore > prune.alpha) ? minimaxscore : prune.alpha;
        } else {
            minimaxscore = (result < minimaxscore) ? result : minimaxscore;

            prune.beta = (minimaxscore < prune.beta) ? minimaxscore : prune.beta;
        }
        
        if (prune.alpha > prune.beta) break;
    }
    free(moves);

    return minimaxscore;
}

int16_t bestmovepruning(MiniMaxAbsolute* absolute, MiniMaxState state, MiniMaxInterface* interface) {
    int16_t bestscore = INT16_MIN;
    int16_t bestplay;

    MiniMaxPrune prune = {
        INT16_MIN,
        INT16_MAX
    };
    int16_t* moves;
    size_t len = interface->availmoves(state.board, &moves, state.side);
    for (size_t i = 0; i < len; i++)
    {
        board_t copiedboard;
        create(&copiedboard);
        copy(copiedboard, state.board);

        MiniMaxState nextstate = (MiniMaxState) {
            copiedboard,
            state.depth + 1,
            1 - state.side,
            !state.ismax
        };
        
        interface->play(nextstate.board, state.side, moves[i]);  
    
        int16_t result = minimaxpruning(absolute, prune, nextstate, interface);
        
        destroy(nextstate.board);
        if (bestscore < result) {
            bestscore = result;
            bestplay = moves[i];

            prune.alpha = (bestscore > prune.alpha) ? bestscore : prune.alpha;
        }
    }
    free(moves);
    

    return bestplay;
}
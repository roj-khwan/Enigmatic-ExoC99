#include "minimax.h"

// logic only work with two side game because of side logic...
// future reimprove ment make work with more than two side game.
int16_t minimax(MiniMaxAbsolute* absolute, GameStatePointer state, MiniMaxState minimaxstate, MiniMaxInterface* interface)
{
    //check terminal
    // if score not zero return score
    // else if maxdepth == depth then return 0
    int16_t score = interface->eval(state, absolute->firststate, minimaxstate.depth);
    if (score != 0) {
        return score;
    } else if (absolute->maxdepth == minimaxstate.depth) {
        return 0;
    }

    int16_t minimaxscore = minimaxstate.ismax ? INT16_MIN : INT16_MAX;

    // fetch avails moves
    // loops for each avails move
    int16_t* moves;
    size_t len = interface->availmoves(state, &moves); 
    for (size_t i = 0; i < len; i++) {
        GameStatePointer nextframe_gamestate = interface->copy(state);

        MiniMaxState nextframe_mstate = minimaxstate;
        nextframe_mstate.depth++;
        nextframe_mstate.ismax = !nextframe_mstate.ismax;

        interface->play(nextframe_gamestate, moves[i]);  
    
        int16_t score = minimax(absolute, nextframe_gamestate, nextframe_mstate, interface);
        
        destroy(nextframe_gamestate);
        if (minimaxstate.ismax) {
            minimaxscore = (score > minimaxscore) ? score : minimaxscore;

            minimaxstate.alpha = (minimaxscore > minimaxstate.alpha) ? minimaxscore : minimaxstate.alpha;
        } else {
            minimaxscore = (score < minimaxscore) ? score : minimaxscore;

            minimaxstate.beta = (minimaxscore < minimaxstate.beta) ? minimaxscore : minimaxstate.beta;
        }
        
        if (minimaxstate.alpha > minimaxstate.beta) break;
    }
    free(moves);

    return minimaxscore;
}

int16_t bestmove(MiniMaxAbsolute* absolute, GameStatePointer state, uint16_t depth, MiniMaxInterface* interface) {
    int16_t bestscore = INT16_MIN;
    int16_t bestplay;

    MiniMaxState minimaxstate = {
        depth,
        INT16_MIN,
        INT16_MAX,
        true,
    };

    int16_t* moves;
    size_t len = interface->availmoves(state, &moves);
    for (size_t i = 0; i < len; i++)
    {
        GameStatePointer nextframe_gamestate = interface->copy(state);

        MiniMaxState nextframe_mstate = minimaxstate;
        nextframe_mstate.depth++;
        nextframe_mstate.ismax = !nextframe_mstate.ismax;

        interface->play(nextframe_gamestate, moves[i]);  
    
        int16_t score = minimax(absolute, nextframe_gamestate, nextframe_mstate, interface);
        
        destroy(nextframe_gamestate);
        if (bestscore < score) {
            bestscore = score;
            bestplay = moves[i];

            minimaxstate.alpha = (bestscore > minimaxstate.alpha) ? bestscore : minimaxstate.alpha;
        }
    }
    free(moves);

    return bestplay;
}
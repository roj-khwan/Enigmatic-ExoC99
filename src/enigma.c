#include "enigma.h"
// WARN : Enigma is not Minimax! this is built for Tic Tac Toe! no need for moduling for other like Minimax Library!

// choose the best move in enigma level.
// params data (board, state, )
int16_t search(board_t board, uint8_t side, uint16_t depth) { 
  
  // TODO : find move ot execute in the avail move
  // 1) locate thru static data first
  // 2) manaully run while also addiing data to the static data too!
// int8_t minimax(uint16_t depth, uint16_t maxdepth, board_t board, char ismax,
//                int (*availmoves) (board_t, int*, int), 
//                int (*play) (board_t, int, int32_t), 
//                int16_t (*eval) (board_t, int));
  GameState state = {
    board,
    side
  };
  MiniMaxAbsolute absolute = {
    9,
    &state
  };
  MiniMaxInterface interface = {
    findavails,
    evaluate,
    playstate,
    copystate,
    destroystate
  };
  return bestmove(&absolute, &state, depth, &interface); 
}

// TODO : fix this to make malloc and stuffs
size_t findavails(GameStatePointer stateptr, int16_t** moves) {
  GameState state = *(GameState*) stateptr;
  size_t i, j = 0;
  *moves = malloc(sizeof(int16_t) * BOARD_SIZE * BOARD_SIZE);
  
  for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
    if (getpiece(state.board, i) != 0) continue;

    (*moves)[j] = i;
    j++;
  }

  *moves = realloc(*moves, sizeof(int16_t) * j);

  return j;
}

int16_t evaluate(GameStatePointer stateptr, GameStatePointer firststateptr, uint16_t depth) {
  GameState state = *(GameState*) stateptr;
  GameState firststate = *(GameState*) firststateptr;
  int16_t maxscore = 10 - depth; // 5 when turn 5, 1 when turn 9
   
  if (checkwin(state.board, firststate.side + 1)) return maxscore;
  else if (checkwin(state.board, 2 - firststate.side)) return -maxscore;

  return 0;
}

int8_t playstate(GameStatePointer stateptr, int16_t move) {
  GameState* state = (GameState*) stateptr;

  play(state->board, state->side, move);

  state->side = 1 - state->side;

  return 0;
}
void* copystate(GameStatePointer srcstateptr) {
  GameState srcstate = *(GameState*) srcstateptr;
  board_t copiedboard;
  create(&copiedboard);
  copy(copiedboard, srcstate.board);

  GameState* nextstateptr = malloc(sizeof(GameState));
  *nextstateptr = (GameState) {
    copiedboard,
    srcstate.side
  };

  return nextstateptr;
}
void destroystate(GameStatePointer stateptr) {
  GameState state = *(GameState*) stateptr;
  destroy(state.board);
  free(stateptr);
}
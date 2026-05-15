#include "enigma.h"
#include "minimax.h"
#include "stdbool.h"
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

  return bestmove(
    &(MiniMaxAbsolute) {
      side,
      9,
    },
    (MiniMaxState) {
      board,
      depth,
      side,
      true
    },
    &(MiniMaxInterface) {
      findavails,
      play,
      evaluate
    }
  ); 
}

int16_t searchwprune(board_t board, uint8_t side, uint16_t depth) { 
  
  // TODO : find move ot execute in the avail move
  // 1) locate thru static data first
  // 2) manaully run while also addiing data to the static data too!
// int8_t minimax(uint16_t depth, uint16_t maxdepth, board_t board, char ismax,
//                int (*availmoves) (board_t, int*, int), 
//                int (*play) (board_t, int, int32_t), 
//                int16_t (*eval) (board_t, int));

  return bestmovepruning(
    &(MiniMaxAbsolute) {
      side,
      9,
    },
    (MiniMaxState) {
      board,
      depth,
      side,
      true
    },
    &(MiniMaxInterface) {
      findavails,
      play,
      evaluate
    }
  ); 
}
// TODO : fix this to make malloc and stuffs
size_t findavails(board_t board, int16_t** moves, uint8_t side) {
  (void) side;
  size_t i, j = 0;
  *moves = malloc(sizeof(int16_t) * BOARD_SIZE * BOARD_SIZE);
  
  for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
    if (getpiece(board, i) != 0) continue;

    (*moves)[j] = i;
    j++;
  }

  *moves = realloc(*moves, sizeof(int16_t) * j);

  return j;
}

int16_t evaluate(board_t board, uint8_t side, uint16_t depth) {
  int16_t maxscore = 10 - depth; // 5 when turn 5, 1 when turn 9
   
  if (checkwin(board, side + 1)) return maxscore;
  else if (checkwin(board, 2 - side)) return -maxscore;

  return 0;
}
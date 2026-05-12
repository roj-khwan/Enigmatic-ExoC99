#include "enigma.h"
// WARN : Enigma is not Minimax! this is built for Tic Tac Toe! no need for moduling for other like Minimax Library!

// choose the best move in enigma level.
// params data (board, state, )
int search(board_t board, uint8_t side, int depth) { 
  
  int navails;
  int* moves;
  navails = findavails(board, &moves, side);

  // TODO : find move ot execute in the avail move
  // 1) locate thru static data first
  // 2) manaully run while also addiing data to the static data too!
// int8_t minimax(uint16_t depth, uint16_t maxdepth, board_t board, char ismax,
//                int (*availmoves) (board_t, int*, int), 
//                int (*play) (board_t, int, int32_t), 
//                int16_t (*eval) (board_t, int));

  return moves[0];
}

// TODO : fix this to make malloc and stuffs
int findavails(board_t board, int** moves, int side) {
  size_t i, j = 0;
  *moves = malloc(sizeof(int) * BOARD_SIZE * BOARD_SIZE);
  
  for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
    if (getpiece(board, i) != 0) continue;

    (*moves)[j] = i;
    j++;
  }

  *moves = realloc(*moves, sizeof(int) * j);

  return j;
}

int evaluate(board_t board, int side, int depth) {
  int maxscore = 9 - depth; // 5 when turn 4, 1 when turn 8
   
  if (checkwin(board, side + 1)) return maxscore;
  else if (checkwin(board, 2 - side)) return -maxscore;

  return 0;
}
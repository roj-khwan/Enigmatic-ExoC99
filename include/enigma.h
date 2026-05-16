#include <string.h>
#include "minimax.h"
#include "game.h"
#include <stdbool.h>

typedef struct GameState_t {
    board_t board;
    uint8_t side;
} GameState;

int16_t search(board_t board, uint8_t eside, uint16_t depth);
int16_t searchwprune(board_t board, uint8_t eside, uint16_t depth);
size_t findavails(GameStatePointer stateptr, int16_t** moves);
int16_t evaluate(GameStatePointer stateptr, GameStatePointer firststage, uint16_t depth);
int8_t playstate(GameStatePointer stateptr, int16_t move);
void* copystate(GameStatePointer srcstateptr);
void destroystate(GameStatePointer stateptr);

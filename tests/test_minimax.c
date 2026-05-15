#include "test_framework.h"
#include "board.h"
#include "minimax.h"
#include "enigma.h"
#include <stdbool.h>

int test_tictactoe_board_prune_state_scoring() {
    board_t board;
    create(&board);

    play(board, 0, 4);
    
    MiniMaxAbsolute absolute = {1, 9};
    MiniMaxInterface interface = {findavails, play, evaluate};
    MiniMaxPrune prune = {INT16_MIN, INT16_MAX};
    MiniMaxState state = {board, 1, 1, true};
    int result = minimax(&absolute, state, &interface);
    int pruneresult = minimaxpruning(&absolute, prune, state, &interface);
    ASSERT_EQUAL(result, pruneresult, "result of both no pruning and pruning should be the same");
    
    play(board, 1, 0);
    play(board, 0, 8);
    play(board, 1, 2);
    absolute = (MiniMaxAbsolute) {0, 9};
    state = (MiniMaxState) {board, 4, 1, true};
    result = minimax(&absolute, state, &interface);
    pruneresult = minimaxpruning(&absolute, prune, state, &interface);
    ASSERT_EQUAL(result, pruneresult, "result of both no pruning and pruning should be the same");

    destroy(board);
    return 0;
}
int test_tictactoe_board_state_scoring() {
    board_t board;
    create(&board);

    play(board, 0, 0);
    play(board, 1, 1);
    play(board, 0, 4);
    play(board, 1, 2);

    MiniMaxAbsolute absolute = {0, 9};
    MiniMaxInterface interface = {findavails, play, evaluate};
    MiniMaxState state = {board, 4, 0, true};
    int result = minimax(&absolute, state, &interface);
    ASSERT_EQUAL(result, 5, "this state have the best move score of 5");

    play(board, 0, 3);
    absolute = (MiniMaxAbsolute) {1, 9};
    state = (MiniMaxState) {board, 5, 1, true};
    result = minimax(&absolute, state, &interface);
    ASSERT_EQUAL(result, -3, "this state have is losing and the best move have the score of -3");

    destroy(board);
    return 0;
}
int test_tictactoe_board_best_move() {
    board_t board;
    create(&board);

    play(board, 0, 0);
    play(board, 1, 1);
    play(board, 0, 4);
    play(board, 1, 2);

    MiniMaxAbsolute absolute = {0, 9};
    MiniMaxInterface interface = {findavails, play, evaluate};
    MiniMaxState state = {board, 4, 0, true};
    int result = bestmove(&absolute, state, &interface);
    ASSERT_EQUAL(result, 8, "The best move in this state is 8");

    play(board, 0, 5);
    play(board, 1, 7);
    state = (MiniMaxState) {board, 6, 0, true};
    result = bestmove(&absolute, state, &interface);
    ASSERT_EQUAL(result, 3, "The best move in this state is 3");
    return 0;
}
int test_tictactoe_board_best_move_pruning() {
    board_t board;
    create(&board);

    play(board, 0, 0);
    play(board, 1, 1);
    play(board, 0, 4);
    play(board, 1, 2);

    MiniMaxAbsolute absolute = {0, 9};
    MiniMaxInterface interface = {findavails, play, evaluate};
    MiniMaxState state = {board, 4, 0, true};
    int result = bestmove(&absolute, state, &interface);
    int pruneresult = bestmovepruning(&absolute, state, &interface);
    ASSERT_EQUAL(result, pruneresult, "result of both no pruning and pruning should be the same");

    play(board, 0, 5);
    play(board, 1, 6);
    state = (MiniMaxState) {board, 6, 0, true};
    pruneresult = bestmovepruning(&absolute, state, &interface);
    result = bestmove(&absolute, state, &interface);
    ASSERT_EQUAL(result, pruneresult, "result of both no pruning and pruning should be the same");
    
    return 0;
}int main() {
    TEST_SUITE("MiniMax!!!");
    test_tictactoe_board_state_scoring();
    test_tictactoe_board_prune_state_scoring();
    test_tictactoe_board_best_move();
    test_tictactoe_board_best_move_pruning();
    return 0;
}
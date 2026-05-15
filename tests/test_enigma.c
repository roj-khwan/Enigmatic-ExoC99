#include "enigma.h"
#include <stdlib.h>
#include "test_framework.h"

int test_find_availables() {
    board_t board;
    create(&board);

    // int* moves;
    // int num_moves;
    
    // num_moves = findavails(board, &moves, 0);
    // assert(num_moves == BOARD_SIZE * BOARD_SIZE);
    // printf("Expected number of available moves: %d\n", num_moves);
    // assert(moves != NULL);
    // printf("Expected to not be NULL\n");
    // assert(moves[0] == 0);
    // printf("Expected first move to be 0\n");
    // free(moves);

    // play(board, 0, 0);
    // num_moves = findavails(board, &moves, 0);
    // assert(num_moves == BOARD_SIZE * BOARD_SIZE - 1);
    // printf("Expected number of available moves after one move: %d\n", num_moves);
    // assert(moves != NULL);
    // printf("Expected moves to be non-NULL after move\n");
    // assert(moves[0] == 1);
    // printf("Expected first move to be 1 after move\n");
    // free(moves);

    destroy(board);
    return 0;
}

int test_evaluation() {
    board_t board;
    create(&board);

    ASSERT_EQUAL(evaluate(board, 0, 3), 0, "Evaluation return 0 on no winning");

    place(board, 0, 0);
    place(board, 0, 1);
    place(board, 0, 2);

    ASSERT_EQUAL(evaluate(board, 0, 4), 5, "Evaluation return 5 point on fastest route of winning");
    ASSERT_EQUAL(evaluate(board, 0, 6), 3, "Evaluation return 3 point when take 3 turn to win");
    ASSERT_EQUAL(evaluate(board, 1, 4), -5, "Evaluation return -5 point on fastest route of losing");

    place(board, 1, 2);
    place(board, 1, 3);
    place(board, 1, 4);
    place(board, 0, 5);
    place(board, 0, 6);
    place(board, 1, 7);
    place(board, 0, 8);

    ASSERT_EQUAL(evaluate(board, 0, 8), 0, "Evaluation return 0 on no tie");

    destroy(board);
    return 0;
}

int main() {
    TEST_SUITE("Enigma!!!");
    test_find_availables();
    test_evaluation();
    return 0;
}
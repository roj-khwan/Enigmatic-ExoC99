#include "stdio.h"
#include "game.h"
#include "enigma.h"

int16_t requestmove() {
    int16_t pos, ret = -1;
    char* getret;
    char buf[100];

    // loop every time input was invalid
    do {
        printf("place the piece at desire position: ");
		getret = fgets(buf, sizeof(buf), stdin);
        ret = sscanf(buf, "%hd", &pos);
    } while (1 > pos || pos > 9 || ret != 1 || getret == NULL);
    
  return pos;
}

int coreloop(board_t board, int pside){
    static uint8_t side = 0;
    static uint16_t turn = 0;
    int16_t pos;

    if (side == pside) {
        pos = requestmove() - 1;
    } else {
        pos = searchwprune(board, side, turn); // TODO : fix this weird
    }
    
    if (!play(board, side, pos)) {
		printf("Can't place on position %d\n", pos + 1);
        return -1;
    }

    printf("score evaluate %d\n", evaluate(board, side, turn));
    display(board);

    if (checkwin(board, side + 1)) return side + 1;
    else if (++turn >= 9) return 0;
    
    side = 1 - side; // switch side 1 0
    return -1;
}

int getplayerinitiative() {
    char buf[100];
    char c;

    for (;;) {
        printf("Goes first? (Y/N): ");
        if (!fgets(buf, sizeof(buf), stdin)) return -1; // EOF/error
        if (sscanf(buf, " %c", &c) != 1) continue;

        if (c == 'Y' || c == 'y') return 0;
        if (c == 'N' || c == 'n') return 1;

        printf("Error: Invalid input\n");
    } 

    return -1;
}

int main() {
    int pside;

    if ((pside = getplayerinitiative()) == -1) {
        return 0;
    }

    board_t board; // this is an array of board!
    int ret = -1;
    
    create(&board);
    display(board);
    while ((ret = coreloop(board, pside)) == -1) {} 

    if (ret)
        printf("Player %d Win!!!\n", ret);
    else
        printf("TIE!!!\n");

    destroy(board);
    return 0;
}

#ifndef _OTHELLO_H
#define _OTHELLO_H

#include <stdbool.h>

#define OTHELLO_BOARD_SIZE 8

typedef enum {
	OTHELLO_CELL_EMPTY = 0,
	OTHELLO_CELL_BLACK,
	OTHELLO_CELL_WHITE,
} OthelloCellState;

typedef OthelloCellState OthelloBoard[OTHELLO_BOARD_SIZE][OTHELLO_BOARD_SIZE];

typedef struct OthelloContext {
	OthelloBoard board;
	bool isBlack;
} OthelloContext;

#endif // _OTHELLO_H

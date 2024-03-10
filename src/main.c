#include "raylib.h"
#include "./othello.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define CELL_WIDTH_PX 50
#define CELL_HEIGHT_PX 50
#define CELL_PADDING_PX 10

#define SCREEN_PADDING_X                                                   \
	(int)((SCREEN_WIDTH -                                              \
	       (OTHELLO_BOARD_SIZE * (CELL_WIDTH_PX + CELL_PADDING_PX))) / \
	      2)
#define SCREEN_PADDING_Y                                                    \
	(int)((SCREEN_HEIGHT -                                              \
	       (OTHELLO_BOARD_SIZE * (CELL_HEIGHT_PX + CELL_PADDING_PX))) / \
	      2)

void DrawCell(OthelloContext *c, int x, int y)
{
	Rectangle rec = {
		.x = x * (CELL_WIDTH_PX + CELL_PADDING_PX) + SCREEN_PADDING_X,
		.y = y * (CELL_HEIGHT_PX + CELL_PADDING_PX) + SCREEN_PADDING_Y,
		.width = CELL_WIDTH_PX,
		.height = CELL_HEIGHT_PX,
	};

	bool isEmpty = c->board[x][y] == OTHELLO_CELL_EMPTY;
	bool isClicked = IsMouseButtonReleased(MOUSE_BUTTON_LEFT) &&
			 CheckCollisionPointRec(GetMousePosition(), rec);

	if (isEmpty && isClicked) {
		c->board[x][y] = c->isBlack ? OTHELLO_CELL_BLACK :
					      OTHELLO_CELL_WHITE;
		c->isBlack = !c->isBlack;
	}

	Color color;
	switch (c->board[x][y]) {
	case OTHELLO_CELL_WHITE:
		color = WHITE;
		break;
	case OTHELLO_CELL_BLACK:
		color = BLACK;
		break;
	default:
		color = GRAY;
		break;
	}

	DrawRectangleRec(rec, color);
}

int main(void)
{
	OthelloContext c = {
		.board = { { 0 } },
		.isBlack = true,
	};

	int first = (OTHELLO_BOARD_SIZE / 2) - 1;
	int second = first + 1;

	c.board[first][first] = OTHELLO_CELL_BLACK;
	c.board[second][second] = OTHELLO_CELL_BLACK;
	c.board[first][second] = OTHELLO_CELL_WHITE;
	c.board[second][first] = OTHELLO_CELL_WHITE;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "reverc");

	while (!WindowShouldClose()) {
		if (IsKeyReleased(KEY_Q))
			break;

		BeginDrawing();
		ClearBackground(RED);

		for (int x = 0; x < OTHELLO_BOARD_SIZE; ++x) {
			for (int y = 0; y < OTHELLO_BOARD_SIZE; ++y) {
				DrawCell(&c, x, y);
			}
		}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
